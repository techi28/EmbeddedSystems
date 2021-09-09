  // Here we declare a few variables that we'll use later in the code
// We define variables so it's easy to change and uniform throughout the code
int LED = 13;
int Buzzer = 9;
int STime = 300;
int LTime = 900;

void setup () {
  // This sets the pin 9 in output mode
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop () {
  //  Letter S
  LEDswitch(STime);
  Buzzerswitch(STime);
  LEDswitch(STime);
  Buzzerswitch(STime);
  LEDswitch(STime);
  Buzzerswitch(STime);

  // This delay is to separate the letters
  delay(LTime);

  // Letter O
  LEDswitch(LTime);
  Buzzerswitch(LTime);

  LEDswitch(LTime);
  Buzzerswitch(LTime);

  LEDswitch(LTime);
  Buzzerswitch(LTime);

  delay(LTime);

  // Letter S
  LEDswitch(STime);
  Buzzerswitch(STime);

  LEDswitch(STime);
  Buzzerswitch(STime);

  LEDswitch(STime);
  Buzzerswitch(STime);

  delay(LTime);
  delay(LTime);
  delay(LTime);
}

void LEDswitch (int timing) {
  // This sends high voltage to the specified pin
  digitalWrite(LED, HIGH);
  delay(timing);
  digitalWrite(LED, LOW);
  delay(STime);
}

void Buzzerswitch (int timing) {
  digitalWrite(Buzzer, HIGH);
  delay(timing);
  digitalWrite(Buzzer, LOW);
  delay(STime);
} 
