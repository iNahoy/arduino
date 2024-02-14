#include <Servo.h>

Servo servo_9;
const int triggerPin = 7;
const int echoPin = 6;
const int numSamples = 5;
const int margemHisterese = 3;
const int alcance = 30;

long readUltrasonicDistance()
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

int filtrarLeituras()
{
  int somaLeituras = 0;
  for (int i = 0; i < numSamples; ++i) {
    somaLeituras += 0.01723 * readUltrasonicDistance();
    delay(10);
  }
  return somaLeituras / numSamples;
}

void setup()
{
  servo_9.attach(9, 500, 2500);
  pinMode(triggerPin, OUTPUT);
}

void loop()
{
  int distancia = filtrarLeituras();

  if (distancia <=  (alcance - margemHisterese)) {
    servo_9.write(90);
    delay(3000);
  } else {
    servo_9.write(0);
  }
}
