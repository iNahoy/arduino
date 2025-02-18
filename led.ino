#define red 4
#define ylw 9
#define grn 8
#define btn 3

void setup (){
  pinMode(red,OUTPUT);
  pinMode(btn,INPUT_PULLUP);
}

void loop(){
  if (digitalRead (btn) == LOW){
    digitalWrite (red, HIGH);
  } else {
    digitalWrite(red,LOW);
  }
}
