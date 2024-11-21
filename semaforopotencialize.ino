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

  // Inicializa os LEDs com o vermelho ligado
  digitalWrite(red, HIGH);
  digitalWrite(ylw, LOW);
  digitalWrite(grn, LOW);
}

void verificarBotao() {
  static bool btnApertadoAnterior = false; // Estado anterior do botão
  bool estadoAtual = digitalRead(btn) == LOW; // Botão pressionado?

  if (estadoAtual && !btnApertadoAnterior) {
    interromper = !interromper; // Alterna o estado de interrupção
  }

  btnApertadoAnterior = estadoAtual; // Atualiza o estado anterior
}

void semaforo() {
  digitalWrite(red, HIGH);
  digitalWrite(ylw, LOW);
  digitalWrite(grn, LOW);
  delay(3000);

  digitalWrite(red, LOW);
  digitalWrite(ylw, HIGH);
  delay(1500);

  digitalWrite(ylw, LOW);
  digitalWrite(grn, HIGH);
  delay(3000);

  digitalWrite(grn, LOW);
}

void loop() {
  verificarBotao(); // Verifica o estado do botão

  if (interromper) {
    // Estado interrompido: apenas o vermelho ligado
    digitalWrite(red, HIGH);
    digitalWrite(ylw, LOW);
    digitalWrite(grn, LOW);
  } else {
    // Ciclo normal do semáforo
    semaforo();
  }
}
