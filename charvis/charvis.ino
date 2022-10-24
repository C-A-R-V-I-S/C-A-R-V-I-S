#define FL_1 2
#define FL_2 3
#define FR_1 4
#define FR_2 5
#define BL_1 6
#define BL_2 7
#define BR_1 8
#define BR_2 9

#define LED_FL 22
#define LED_FR 23
#define LED_BL 24
#define LED_BR 25

// 구동 바퀴 및 LED 위치
// 첫 번째의 F(front)와 B(back)은 앞쪽, 뒤쪽
// 두 번째의 L(left)와 R(right)은 왼쪽, 오른쪽 

// 회전 방향
// 세 번째의 1은 전진, 2는 후진


void setup() {
  for(int i=2;i<10;i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  
}

void offLED(){
  digitalWrite(LED_FL, LOW);
  digitalWrite(LED_FR, LOW);
  digitalWrite(LED_BL, LOW);
  digitalWrite(LED_BR, LOW);
}


void moveFront() {
  digitalWrite(LED_FL, HIGH);
  digitalWrite(LED_FR, HIGH);
  digitalWrite(LED_BL, LOW);
  digitalWrite(LED_BR, LOW);
  
  analogWrite(FL_1, 200);
  analogWrite(FR_1, 200);
  analogWrite(BL_1, 200);
  analogWrite(BR_1, 200);
  analogWrite(FL_2, 0);
  analogWrite(FR_2, 0);
  analogWrite(BL_2, 0);
  analogWrite(BR_2, 0);
}

void moveLeft() {
  digitalWrite(LED_FL, HIGH);
  digitalWrite(LED_BL, HIGH);
  digitalWrite(LED_FR, LOW);
  digitalWrite(LED_BR, LOW);
  
  digitalWrite(BL_1, 200/3);
  digitalWrite(FL_1, 200/3);
  digitalWrite(BR_1, 200);
  digitalWrite(FR_1, 200);  
  digitalWrite(BL_2, 0);
  digitalWrite(FL_2, 0);
  digitalWrite(BR_2, 0);
  digitalWrite(FR_2, 0);
}

void moveRight() {
  digitalWrite(LED_FR, HIGH);
  digitalWrite(LED_BR, HIGH);
  digitalWrite(LED_FL, LOW);
  digitalWrite(LED_BL, LOW);
  
  analogWrite(BR_1, 200/3);
  analogWrite(FR_1, 200/3);
  analogWrite(BL_1, 200);
  analogWrite(FL_1, 200);
  analogWrite(BR_2, 0);
  analogWrite(FR_2, 0);
  analogWrite(BL_2, 0);
  analogWrite(FL_2, 0);
}

void moveBack() {
  digitalWrite(LED_BL, HIGH);
  digitalWrite(LED_BR, HIGH);
  digitalWrite(LED_FL, LOW);
  digitalWrite(LED_FR, LOW);
  
  analogWrite(FL_2, 200);
  analogWrite(FR_2, 200);
  analogWrite(BL_2, 200);
  analogWrite(BR_2, 200);
  analogWrite(FL_1, 0);
  analogWrite(FR_1, 0);
  analogWrite(BL_1, 0);
  analogWrite(BR_1, 0);
}

void StopMotor(){
  for(int i=0;i<8;i++){
    digitalWrite(i+2, LOW);
  }
}
