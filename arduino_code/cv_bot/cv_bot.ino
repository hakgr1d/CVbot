//тест esp 32 devkit v1

#include "ArduinoJson.h"

// пины PWM драйвера двигателей
#define IN1_PIN 2
#define IN2_PIN 4
#define IN3_PIN 18
#define IN4_PIN 19

#define LED_PIN 13



// json буфер для пакетов от  raspberry pi (RPI)
StaticJsonDocument<200> jsondoc;

// глобальные переменные скорости
int16_t speedA = 0;
int16_t speedB = 0;


#define UART_SPEED 115200

void setup() {
  Serial.begin(UART_SPEED);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  DeserializationError err = deserializeJson(jsondoc, Serial);  // получаем сообщение от RPI через uart
  if (err == DeserializationError::Ok)                          // если cообщение принято
  {
    speedA = (float)jsondoc["speedA"] * 2.55;  // приходит диапазон [-100; 100]
    speedB = (float)jsondoc["speedB"] * 2.55;  // расширяем до [-255; 255]
  } else {
    while (Serial.available() > 0) Serial.read();  // чистим буфер
  }
  moveA(speedA);  // обновляем состояние скоростей моторов
  moveB(speedB);
  delay(10);
}

void moveA(int16_t speed) {
  //speed = -speed;
  if (speed >= 0) {
    analogWrite(IN1_PIN, LOW);
    analogWrite(IN2_PIN, abs(speed));
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    analogWrite(IN1_PIN, abs(speed));
    analogWrite(IN2_PIN, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void moveB(int16_t speed) {
  if (speed >= 0) {
    analogWrite(IN3_PIN, LOW);
    analogWrite(IN4_PIN, abs(speed));
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    analogWrite(IN3_PIN, abs(speed));
    analogWrite(IN4_PIN, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
