#include <avr/sleep.h>
#include <avr/power.h>

int capread(int pin){
  //Drive the pin high
  pinMode(pin,OUTPUT);
  digitalWrite(pin,HIGH);
  //Prepare to read
  pinMode(pin,INPUT);
  digitalWrite(pin,LOW);
  int t=millis();
  //Wait until pin is low or 0.8 seconds have elapsed
  while(digitalRead(pin) && millis() -t < 800);
  t=millis()-t;
  //If it took more than half a second, return 0
  if(t >=500){
    return 0;
  } else{
    return 1;
  }
}


void setup(){
  pinMode(1,OUTPUT);
  digitalWrite(1,1);
  delay(1000);
}


int zeroCount=0;
int sleep=0;
void loop(){
  int input = capread(2);
  if(input==1){
    zeroCount=0;
  }else{
    zeroCount+=1;
  }
  digitalWrite(1, input);
  if(zeroCount > 100){
    while(!capread(2)){
      if(millis() > 600000) sleep=1;
      delay(100);
    }
    zeroCount = 0;
  }
  delay(100);
  if(sleep){ //Power down
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
  }
}
