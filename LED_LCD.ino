

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 1);

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

void setup() {
  // put your setup code here, to run once:
      pinMode(LED1, OUTPUT);
      pinMode(LED2, OUTPUT);
      pinMode(LED3, OUTPUT);

  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello, World!");
  lcd.setCursor(0,1);
  lcd.print("robot Arduino!");

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1 , HIGH);
delay(500);
digitalWrite(LED1 , LOW);
delay(500);

digitalWrite(LED2 , HIGH);
delay(500);
digitalWrite(LED2 , LOW);
delay(500);

digitalWrite(LED3 , HIGH);
delay(500);
digitalWrite(LED3 , LOW);
delay(500);


 
}
