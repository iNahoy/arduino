#define led 4
#define btn 3
int clc = 0;
int lib = 0;

void onoff(){
  if(digitalRead(led)==HIGH){
    digitalWrite(led,LOW);
  }else{
    digitalWrite(led,HIGH);
  }
}
void bonof(){
  if((clc == 1) and (lib == 1)){
    clc = 0;
    lib = 0;
    onoff();
  }
}
void setup(){
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT);
}
void loop(){
  if(digitalRead(btn) == HIGH){
    clc = 1;
    lib = 0;
  } else {
    lib = 1;
  }
  bonof();
}
