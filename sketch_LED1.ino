int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int T1 = 100;
int T2 = 500; 

void setup() {
  // put your setup code here, to run once:
      pinMode(LED1, OUTPUT);
      pinMode(LED2, OUTPUT);
      pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1 , HIGH);
delay(T1);
digitalWrite(LED1 , LOW);
delay(T2);

digitalWrite(LED2 , HIGH);
delay(T1);
digitalWrite(LED2 , LOW);
delay(T2);

digitalWrite(LED3 , HIGH);
delay(T1);
digitalWrite(LED3 , LOW);
delay(T2);
}
