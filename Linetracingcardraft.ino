
#define AIN1 26
#define AIN2 27
#define PWMA 14

#define IR1 34
#define IR2 35
#define IR3 32
#define IR4 33
#define IR5 25

#define PWM_CHANNEL 0

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);

  ledcSetup(PWM_CHANNEL, 1000, 8);
  ledcAttachPin(PWMA, PWM_CHANNEL);
}

void loop() {
  int s1 = digitalRead(IR1);
  int s2 = digitalRead(IR2);
  int s3 = digitalRead(IR3);
  int s4 = digitalRead(IR4);
  int s5 = digitalRead(IR5);

  // ===== CASE =====

  // đi thẳng
  if (s3 == 0) {
    forward(180);
  }

  // lệch nhẹ trái
  else if (s2 == 0) {
    turnLeft(150);
  }

  // lệch mạnh trái
  else if (s1 == 0) {
    turnLeft(200);
  }

  // lệch nhẹ phải
  else if (s4 == 0) {
    turnRight(150);
  }

  // lệch mạnh phải
  else if (s5 == 0) {
    turnRight(200);
  }

  // mất line
  else {
    stopMotor();
  }

  delay(5);
}

// ===== Control =====

void forward(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWM_CHANNEL, speed);
}

void turnLeft(int speed) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  ledcWrite(PWM_CHANNEL, speed);
}

void turnRight(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWM_CHANNEL, speed);
}

void stopMotor() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWM_CHANNEL, 0);
}
