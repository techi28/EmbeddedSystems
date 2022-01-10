/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/
/*
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 6;     // the number of the pushbutton pin
const int ledPin = 8;      // the number of the LED pin
const int buzzer = 9;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int time1 = 300;
int time2 = 500;
int time3 = 900;
void setup() {
    Serial.begin(9600);

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
   digitalWrite(ledPin, LOW);
   digitalWrite(buzzer, LOW);

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println(" ON ");

  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println(" OFF ");
  }

*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 1);

const  int led = 8;
const int button =6; 
const int buzzer = 9;
int buttonState =0;
// digital pin 2 has a pushbutton attached to it. Give it a name:
//int pushButton = 6;
 // the setup routine runs once when you press reset:
void setup(){
    Serial.begin(9600);
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    lcd.setCursor(1,0);
    pinMode( button, INPUT );
    pinMode( led, OUTPUT );
    pinMode( buzzer, OUTPUT );
    Serial.println("Welcome to Arduino-Uno morse decoder");
    lcd.print("Welcome to Arduino-Uno morse decoder");
    //while(buttonState != 1);
}
// the loop routine runs over and over again forever:
void loop() {
  //if (Serial.available()){
  // read the input pin:
int buttonState = digitalRead(button);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability
  if (buttonState == HIGH){ 
    digitalWrite (led, HIGH);
    digitalWrite (buzzer, HIGH);
    Serial.println("LED is turned ON"); // send action to Serial Monitor

    } else {
    digitalWrite (led, LOW);
    digitalWrite (buzzer, LOW);
    Serial.println("LED is turned OFF"); // send action to Serial Monitor
   // }
    
}
}
