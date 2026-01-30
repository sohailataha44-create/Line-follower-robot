#define black 1
#define white 0
#define IN1 7
#define IN2 8
#define ENA1 5
#define speed 225
#define IN3 9
#define IN4 10
#define ENA2 6
#define rsensor 3
#define lsensor 2
void forward();
void left();
void right();
void stop();
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(rsensor, INPUT);
  pinMode(lsensor, INPUT);
}

void loop() {
  if (digitalRead(lsensor)  == black && digitalRead(rsensor) == black) {
    stop();
  } else if (digitalRead(lsensor) == black && digitalRead(rsensor) == white) {
    left();
  } else if (digitalRead(lsensor) == white && digitalRead(rsensor) == black) {
    right();
  } else if (digitalRead(lsensor) == white && digitalRead(rsensor) == white) {
    forward();
  }
}
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA1, speed);
  analogWrite(ENA2, speed);
}
void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA1, speed);
  analogWrite(ENA2, speed);
}
void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA1, speed);
  analogWrite(ENA2, speed);
}
void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA1, LOW);
  analogWrite(ENA2, LOW);
}
