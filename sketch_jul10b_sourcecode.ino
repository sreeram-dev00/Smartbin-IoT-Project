#include <Servo.h>

Servo myservo;
int pos = 20;
const int trigPin = 5;
const int echoPin = 6;
const int led = 13;

long duration;
float distance;

void setup() {
  myservo.attach(11);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 20) {
    digitalWrite(led, HIGH);
    myservo.write(pos + 160); // Open lid
    delay(1000);              // Stay open for 1 sec
  } else {
    digitalWrite(led, LOW);
    myservo.write(pos);       // Close lid
  }

  delay(300); // Small delay before next reading
}
