#define FL_1 2
#define FL_2 3
#define FR_1 4
#define FR_2 5
#define RL_1 6
#define RL_2 7
#define RR_1 8
#define RR_2 9

// 구동 바퀴 위치
// 첫 번째의 F(front)와 R(rear)은 앞바퀴, 뒷바퀴
// 두 번째의 L(left)와 R(right)은 왼쪽바퀴, 오른쪽바퀴 

// 회전 방향
// 세 번째의 1은 전진, 2는 후진


void setup() { // 모터제어에 필요한 핀 8개를 OUTPUT으로 설정
  for(int i=2;i<10;i++){
    pinMode(i, OUTPUT);
  }
}

// 기본적인 전진 구동을 위해 moveFront()함수를 실행
void loop() {
  moveFront();
}


void moveFront(float F_Sonic,float R_Sonic,float fl_IR,float fr_IR,float rl_IR,float rr_IR) {
  analogWrite(FL_1, 200);
  analogWrite(FR_1, 200);

  if(F_Sonic < 30){
    analogWrite(FL_1, 10);
    analogWrite(FR_1, 10); 
    //delay(50);

    if(fl_IR < 10 && fr_IR < 10) {
      analogWrite(FL_1, 0); // 감속
      analogWrite(FR_1, 0);
      //delay(10);
      analogWrite(FL_2, (F_Sonic * 15)); // 후진
      analogWrite(FR_2, 100);
      //delay(100);
      analogWrite(FR_1, 250); // 좌회전
      analogWrite(RR_1, 40);
      analogWrite(FL_1, 50);
      //delay(300);
      analogWrite(FL_1, 250); // 우회전
      analogWrite(RL_1, 40);
      analogWrite(FR_1, 50);
      //delay(300);
    }
    else if(fl_IR < 10) {
      analogWrite(FR_1, 250); // 우회전                     
      analogWrite(RR_1, 40);
      analogWrite(FL_1, 50);
      //delay(300);
    }
    else if(fr_IR < 10) {
      analogWrite(FR_1, 250); // 좌회전
      analogWrite(RR_1, 40);
      analogWrite(FL_1, 50);
      //delay(300);
    }
    //웬만해서는 쓰이지 않겠지만 후진의 경우
    else if(R_Sonic < 30) {
      analogWrite(FL_2, 10); // 감속
      analogWrite(FR_2, 10);
      //delay(150);
      if(rl_IR < 10) {
        analogWrite(RL_2, 250); // 우회전
        analogWrite(RR_2, 40);
        analogWrite(FL_2, 50);
        //delay(300);
      }
      else if(rr_IR < 10) {
        analogWrite(RR_2, 250); // 좌회전
        analogWrite(RL_2, 40);
        analogWrite(FR_2, 50);
        //delay(300); 
      }
    }
  }
}
