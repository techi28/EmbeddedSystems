#include "OneButton.h"                              //we need the OneButton library
 
int led = 8;
int buzzer = 9; 
OneButton button(6, true);                          

void setup() {
 
  pinMode(led, OUTPUT);                              
  pinMode(buzzer, OUTPUT);                              
  
     
  button.attachDoubleClick(doubleclick);              
  button.attachClick(singleclick);                   
  button.attachLongPressStop(longclick);            
} 
  
 
 
void loop() {
  
  button.tick();                                     
 
  delay(10);                                       
} // loop
 
 
 
void doubleclick() {                                  
 digitalWrite(led,HIGH);                             // light the LED
 digitalWrite(buzzer,HIGH);
 delay(1000);                                       // wait one second
 digitalWrite(led,LOW);
 digitalWrite(buzzer, LOW);                             // turn off LED
} 
 
void singleclick(){                                 //when the button is clicked
 digitalWrite(led,HIGH);                             // light the  LED
 digitalWrite(buzzer,HIGH);
 delay(1000);                                       // wait one second
 digitalWrite(led,LOW);
 digitalWrite(buzzer, LOW);                              // turn off the led
}
 
void longclick(){                                   // when buton is long-pressed
 digitalWrite(led,HIGH);                             // light the  LED
 digitalWrite(buzzer,HIGH);
 delay(1000);                                       // wait one second
 digitalWrite(led,LOW);
 digitalWrite(buzzer, LOW);                             // turn off the LED
}
