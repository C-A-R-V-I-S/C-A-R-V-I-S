#define FL_F 2
#define FL_R 3
#define FR_F 4
#define FR_R 5
#define RL_F 6
#define RL_R 7
#define RR_F 8
#define RR_R 9
 

 
void setup() { // setup()함수에선 모터제어에 필요한 핀 8개를 OUTPUT으로 설정합니다
  for(int i=2;i<10;i++){
    pinMode(i, OUTPUT);
  }
}

// loop()함수에선 기본적으로 전진을 설정하기에 moveFront()함수를 실행합니다
void loop() {
  moveFront();
}


void moveFront(float F_Sonic,float R_Sonic,float fl_IR,float fr_IR,float rl_IR,float rr_IR){
  analogWrite(FL_F, 200);
  analogWrite(FR_F, 200);
  if(F_Sonic < 30){
    analogWrite(FL_F, 10);
    analogWrite(FR_F, 10); 
    delay(50);
    if(fl_IR < 10 && fr_IR < 10){
      analogWrite(FL_F, 0); // 감속
      analogWrite(FR_F, 0);
      delay(10);
      analogWrite(FL_R, (F_Sonic * 15)); // 후진
      analogWrite(FR_R, 100);
      delay(100);
      analogWrite(FR_F, 250); // 좌회전
      analogWrite(RR_F, 40);
      analogWrite(FL_F, 50);
      delay(300);
      analogWrite(FL_F, 250); // 우회전
      analogWrite(RL_F, 40);
      analogWrite(FR_F, 50);
      delay(300);
      }
    else if(fl_IR < 10){
      analogWrite(FR_F, 250); // 우회전                     
      analogWrite(RR_F, 40);
      analogWrite(FL_F, 50);
      delay(300);
    }
    else if(fr_IR < 10)
      analogWrite(FR_F, 250); // 좌회전
      analogWrite(RR_F, 40);
      analogWrite(FL_F, 50);
      delay(300);
    }
    //웬만해서는 쓰이지 않겠지만 후진의 경우
    else if(R_Sonic < 30){
      analogWrite(FL_R, 10); // 감속
      analogWrite(FR_R, 10);
      delay(150);
        if(rl_IR < 10){
          analogWrite(RL_R, 250); // 우회전
          analogWrite(RR_R, 40);
          analogWrite(FL_R, 50);
          delay(300);
        }
        else if(rr_IR < 10)
          analogWrite(RR_R, 250); // 좌회전
          analogWrite(RL_R, 40);
          analogWrite(FR_R, 50);
          delay(300);
        }
  }
