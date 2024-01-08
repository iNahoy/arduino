#define red 10
#define ylw 9
#define grn 8

void setup() {
  pinMode (red,OUTPUT);
  pinMode (ylw,OUTPUT);
  pinMode (grn,OUTPUT);
}
void vermelho(int tmp){
  digitalWrite(red,HIGH);
  digitalWrite(ylw,LOW);
  digitalWrite(grn,LOW);
  delay(tmp);
}
void verde(int tmp){
  digitalWrite(red,LOW);
  digitalWrite(ylw,LOW);
  digitalWrite(grn,HIGH);
  delay(tmp);
}
void amarelo(int tmp){
  digitalWrite(red,LOW);
  digitalWrite(ylw,HIGH);
  digitalWrite(grn,LOW);
  delay(tmp); 
}
void loop() {
  vermelho(700);
  verde(700);
  amarelo(500);
}
