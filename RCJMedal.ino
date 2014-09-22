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
  delay(500);
  
  //for 10 minutes
  while(millis() < 600000){
    //slowly ramp up to full
    for(int i=0; i<255;i++){
      analogWrite(LED,i);
      delay(10);
    }
    delay(200); //keep at max
    
    //slowly ramp down
    for(int i=255;i>0;i--){
      analogWrite(LED,i);
      delay(10);
    }
    
    //flash on for a second
    delay(200);
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(200);
  }
}

void loop(){
}
