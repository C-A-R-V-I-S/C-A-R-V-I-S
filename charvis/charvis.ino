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

// 구동 바퀴 위치
// 첫 번째의 F(front)와 B(back)은 앞바퀴, 뒷바퀴
// 두 번째의 L(left)와 R(right)은 왼쪽바퀴, 오른쪽바퀴 

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
  
  analogWrite(FL_1, 128);
  analogWrite(FR_1, 128);
  analogWrite(BL_1, 128);
  analogWrite(BR_1, 128);
}

void moveLeft() {
  digitalWrite(LED_FL, HIGH);
  digitalWrite(LED_BL, HIGH);
  digitalWrite(LED_FR, LOW);
  digitalWrite(LED_BR, LOW);
  
  analogWrite(BL_1, 128/3);
  analogWrite(FL_1, 128/3);
  analogWrite(BR_1, 128);
  analogWrite(FR_1, 128);
}

void moveRight() {
  digitalWrite(LED_FR, HIGH);
  digitalWrite(LED_BR, HIGH);
  digitalWrite(LED_FL, LOW);
  digitalWrite(LED_BL, LOW);
  
  analogWrite(BR_1, 128/3);
  analogWrite(FR_1, 128/3);
  analogWrite(BL_1, 128);
  analogWrite(FL_1, 128);
}

void moveBack() {
  digitalWrite(LED_BL, HIGH);
  digitalWrite(LED_BR, HIGH);
  digitalWrite(LED_FL, LOW);
  digitalWrite(LED_FR, LOW);
  
  analogWrite(FL_2, 128);
  analogWrite(FR_2, 128);
  analogWrite(BL_2, 128);
  analogWrite(BR_2, 128);
}
