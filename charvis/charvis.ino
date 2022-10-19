#define FL_1 2
#define FL_2 3
#define FR_1 4
#define FR_2 5
#define BL_1 6
#define BL_2 7
#define BR_1 8
#define BR_2 9

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


void moveFront(int spd, int t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇ms 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == 1000){
    return;
  }
  analogWrite(FL_1, spd);
  analogWrite(FR_1, spd);
}

void moveLeft(int spd, int t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇ms 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == 1000){
    return;
  }
  analogWrite(FL_1, spd/10);
  analogWrite(BR_1, spd/10);
  analogWrite(FR_1, spd);
}

void moveright(int spd, int t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇ms 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == 1000){
    return;
  }
  analogWrite(FR_1, spd/10);
  analogWrite(BL_1, spd/10);
  analogWrite(FL_1, spd);
}

void moveBack(int spd, int t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇ms 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == 1000){
    return;
  }
  analogWrite(FL_2, spd);
  analogWrite(FR_2, spd);
}
