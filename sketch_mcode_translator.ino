////////////////////////////////////     VARIABLES   /////////////////////////////////////
int LED = 13;
int Buzzer = 9;
int STime = 300;
int LTime = 900;
String mcode = "sos";
byte Lmcode = 0;
char j;
int timing = 600;
void setup () {
  //Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}
 /////////////////// Outputs /////////////////////
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
  myswitch(STime);
}
void dash(){
  myswitch(LTime);
}
/////////////////////////  Translate functions //////////////////////
void Translatec2m(){
  switch(j){
    case 'a' :
    dot();
    delay(timing);
    dash();
    delay(timing);
    break; 
  case 'b' :
    dash();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    break; 
  case 'c' :
    dash();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'd' :
    dash();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'e' :
    dot();
    delay(timing);
    break;
  case 'f' :
    dot();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'g' :
    dash();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'h' :
    dot();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'i' :
    dot();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'j' :
    dot();
    delay(timing);
    dash();
    delay(timing);
    dash();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'k' :
    dash();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'l' :
    dot();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'm' :
    dash();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'n' :
    dash();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'o' :
    dash();
    delay(timing);
    dash();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'p' :
    dot();
    delay(timing);
    dash();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 'q' :
    dash();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'r' :
    dot();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    break;
  case 's' :
    dot();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    break;
    case 't' :
    dash();
    delay(timing);
    break;
  case 'u' :
    dot();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'v' :
    dot();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'w' :
    dot();
    delay(timing);
    dash();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'x' :
    dash();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'y' :
    dash();
    delay(timing);
    dot();
    delay(timing);
    dash();
    delay(timing);
    dash();
    delay(timing);
    break;
  case 'z':
    dash();
    delay(timing);
    dash();
    delay(timing);
    dot();
    delay(timing);
    dot();
    delay(timing);
    break;
    
    
    }
}
void doString(){
 Lmcode = mcode.length(); 
 for (int x= 0; x<=Lmcode; x++){
  j = mcode.charAt(x);
  Translatec2m();
  }
}
void loop () {
//while (Serial.available()){
     // char mchar = (char)Serial.read();
     // mcode += mchar; 
      //if (mchar == '/n'){
          //Serial.println(mcode);
          doString();
//  }
delay(LTime);
//mcode= " ";
//}
}

