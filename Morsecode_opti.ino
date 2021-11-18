
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 1);
////////////////////////////////////     VARIABLES   /////////////////////////////////////
int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


int LED = 8;
int Buzzer = 9;
int STime = 100;
int LTime = 300;
String incode = "Abc";
byte Lmcode = 0;
int timing = 500;




void setup () {
  //Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
    // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("    ");
  lcd.print(incode);
}
unsigned char LETTERS[] = {
    0b01001000, // A = .-
                // => 010 01000
                //   3 high bits encode the length of the pattern: here 2 characters
                //   5 low bits encode the pattern itself: here 01 means .-
                //     and the 000 at the end is just filler

    
    0b10010000,  // b
    0b10010100, // c
    0b01110000, // d
    0b00100000,// e
    0b10000100, // f
    0b01111000, // g
    0b10000000, // h
    0b01000000, // i
    0b10001110, // j
    0b01110100, // k
    0b10001000, // l
    0b01011000, // m
    0b01010000, // n
    0b01111100, // o
    0b10001100, // p
    0b10011010, // q
    0b01101000, // r
    0b01100000, // s
    0b00110000, // t
    0b01100100, // u
    0b10000010, // v
    0b01101100, // w
    0b10010010, // x
    0b10010110, // y
    0b10011000, // z
};
unsigned char NUMBERS[] = {
    0b10111111, // 0 = -----
    0b10101111, // 1 = -----
    0b10100111, // 2 = -----
    0b10100011, // 3 = -----
    0b10100001, // 4 = -----
    0b10100000, // 5 = -----
    0b10110000, // 6 = -----
    0b10111000, // 7 = -----
    0b10111100, // 8 = -----
    0b10111110, // 9 = -----
};

// '0' == 48 -> NUMBERS[0]
// 'A' == 65 -> LETTERS[0]
// 'B' == 66 -> LETTERS[1]
// 'Z' == 90 -> LETTERS[25]
// 'a' == 97 -> LETTERS[0]
// 'e' == 101 -> LETTERS[4]
unsigned char asciiToMorse(unsigned char asciiChar) {
    // use the LETTERS and NUMBERS arrays to look-up
    // the corresponding encoded Morse code
    
    if (asciiChar >=97 && asciiChar <= 122 ){
    int letterIndex = asciiChar - 'a';
    return LETTERS[letterIndex];
    }
    else if( asciiChar>= 65 && asciiChar <= 90 ){
        int letterIndex = asciiChar - 'A';
    return LETTERS[letterIndex];
    }
/*    else if( asciiChar >= 0 && asciiChar<=9){
        int letterIndex = asciiChar - '0';
    return NUMBERS[letterIndex];
    }*/

}

void printBinary(unsigned char number) {
    for (int i = 7; i >= 0; i--) {
        if (((number >> i) & 1) == 0) printf("0");
        else printf("1");
    }
    printf("\n");
}
void showMorse(unsigned char asciiChar) {
    // use the bits of the encoded Morse code
    // to display it, e.g. blink the LED accordingly
    
    unsigned char morseChar = asciiToMorse(asciiChar);
    
    // split morseChar into (3 bit for pattern length) AND (5 bits for the pattern)
    // for each bit in the pattern <- USE bitwise operations &, |, ^, ~, <<, >>
    //     print DOT if bit == 0
    //     else print DASH
    // & EXAMPLE: 10001111 & 00010001 == 00000001
    // >> EXAMPLE: 10001111 >> 3 == 10001
    printf("\n");

    printBinary(morseChar);
  printBinary(morseChar >> 3);
  printBinary(morseChar >> 3 & 1);
  
  // read bit nr. i -> shift right by (i - 1) and then mask lowest bit

    int length = morseChar >> 5;

    for (int i = 0; i < length; i++) {
        int shift = 4 - i;
        if ((morseChar >> shift & 1) == 0) dot (); 
        else dash();
        
        if (i < length - 1) printf(", ");
    }
    
}

void showMorseString(unsigned char *input) {
    // show all the characters after each other
    for (int i = 0; i < strlen(input); i++) {
        showMorse(input[i]);
     }
}

void myswitch (int timing) {
  // This sends high voltage to the specified pin
  digitalWrite(LED, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(timing);
  digitalWrite(LED, LOW);
  digitalWrite(Buzzer, LOW);
  delay(timing*2);
}
//////////////////   Morse Code dot and dash functions
void dot(){
  printf("Dot");
  myswitch(STime);
}
void dash(){
  printf("Dash");
  myswitch(LTime);
}



void loop () {
    unsigned char *input = "Abc";
 // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // do morse code:
      showMorseString(input);
   } else {
    // do nothing :
    Serial.println("switch is off");
 
   }

  
}
