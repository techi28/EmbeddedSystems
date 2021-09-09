int buzzer = 9;
 
void setup () {

pinMode(buzzer, OUTPUT) ;
}

void loop () {
  int i=0;
  for (i = 0; i< 2 ; i++){
    tone(buzzer, 450);
    delay(200);
    noTone(buzzer);
    delay(200); 
}
delay(3000);
}
