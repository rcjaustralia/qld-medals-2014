#define LED 1
//#define CAPACITIVE

void setup(){
  pinMode(LED,OUTPUT);
  //flash three times
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
}

#ifndef CAPACITIVE
void loop(){
  for(int i=0; i<255;i++;){
    analogWrite(LED,i);
    delay(10);
  }
  for(int i=255;i>0;i--;){
    analogWrite(LED,i);
    delay(10);
  }
  delay(200);
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
}
#endif

#ifdef CAPACITIVE
void loop(){
  
}
#endif
