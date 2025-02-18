#include <Servo.h>

int fumaceiro = 0;         // Variável para sensor de fumaça
int luzDeAviso = 6;        // LED para sinalizar fumaça no ambiente
int barulhinho = 7;        // Piezo para sinalizar emergência
Servo ventilacao;          // Objeto servo para o sistema de ventilação

void setup() {
  pinMode(A0, INPUT);      // Entrada do sensor de fumaça (pino A0)
  Serial.begin(9600);
  pinMode(luzDeAviso, OUTPUT);
  pinMode(barulhinho, OUTPUT);

  ventilacao.attach(5);    // Conecta o servo ao pino 9
  ventilacao.write(0);     // Servo inicial na posição 0 (parado)
}

void loop() {
  fumaceiro = analogRead(A0);  // Obtém a fumaça do ambiente

  // Aciona o LED se detectar fumaça
  if (fumaceiro >= 350) {
    digitalWrite(luzDeAviso, HIGH);
  } else {
    digitalWrite(luzDeAviso, LOW);
  }

  // Aciona o piezo e o servo se detectar muita fumaça
  if (fumaceiro >= 475) {
    digitalWrite(barulhinho, HIGH);
    ventilacao.write(90);   // Gira o servo para posição 90 graus (acionando ventilação)
  } else {
    digitalWrite(barulhinho, LOW);
    ventilacao.write(0);    // Retorna o servo para posição inicial
  }

  delay(10);
}
