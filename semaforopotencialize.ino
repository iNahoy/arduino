const int btn = 3;    // Pino do botão
const int red = 13;   // Pino do LED vermelho
const int ylw = 12;   // Pino do LED amarelo
const int grn = 11;   // Pino do LED verde

bool interromper = false;  // Variável para rastrear o estado de interrupção

void setup() {
  pinMode(red, OUTPUT);
  pinMode(ylw, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void verificarBotao() {
  if (digitalRead(btn) == LOW) { // Botão pressionado
    interromper = true;          // Ativa a interrupção
  }
}

void atrasoComInterrupcao(int tempo) {
  // Executa o atraso dividido em partes pequenas e verifica o botão
  for (int i = 0; i < tempo; i += 10) {
    delay(10); // Atraso curto de 10 ms
    verificarBotao();
    if (interromper) return; // Interrompe imediatamente se necessário
  }
}

void semaforo() {
  // Sinal vermelho
  digitalWrite(red, HIGH);
  atrasoComInterrupcao(3000);

  // Sinal amarelo
  digitalWrite(red, LOW);
  digitalWrite(ylw, HIGH);
  atrasoComInterrupcao(1500);

  // Sinal verde
  digitalWrite(ylw, LOW);
  digitalWrite(grn, HIGH);
  atrasoComInterrupcao(3000);

  // Desliga o verde após o ciclo
  digitalWrite(grn, LOW);
}

void loop() {
  verificarBotao(); // Verifica o estado do botão

  if (interromper) {
    // Interrompido: Retorna ao sinal vermelho
    digitalWrite(red, HIGH);
    digitalWrite(ylw, LOW);
    digitalWrite(grn, LOW);
    interromper = false; // Reseta o estado de interrupção
  } else {
    semaforo(); // Executa o ciclo normal do semáforo
  }
}
