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

#define Front_Left_Ir  26      //왼쪽 앞 IR센서 26핀 설정
#define Front_Right_Ir 27    //오른쪽 앞 IR센서 27핀 설정
#define Back_Left_Ir   28      //왼쪽 뒤 IR센서 28핀 설정
#define Back_Right_Ir  29      //오른쪽 뒤 IR센서 29핀 설정

#define Front_Trig 30         //Front_Trig 30번핀으로 설정.
#define Front_Echo 31         //Front_Echo 31번핀으로 설정.
#define Back_Trig  32          //Back_Trig 32번핀으로 설정.
#define Back_Echo  33          //Back_Echo 33번핀으로 설정.

#include <SoftwareSerial.h>

static char isTurnLight = 1;
// 초음파 센서

float F_S = 0,B_S = 0;
//F_S:앞쪽 초음파센서의 값을 받아오는 변수
//B_S:뒤쪽 초음파센서의 값을 받아오는 변수
void F_Sonic()                        //거리값을 받아올 함수.     
{
   float Front_Length = 0;            //앞쪽 초음파의 송수신 길이를 저장하는 변수 선언
   //Front_Trig 신호 발생 (10us)
   digitalWrite(Front_Trig,LOW);
   delayMicroseconds(2);
   digitalWrite(Front_Trig,HIGH);
   delayMicroseconds(10);
   digitalWrite(Front_Trig,LOW);

   //Front_Echo 신호 입력                    
   Front_Length = pulseIn(Front_Echo, HIGH);  //pulseIn 함수를 통해 echo핀에 초음파가 돌아오는 시간을 측정   
                                          
   //입력받은 신호를 거리로 계산
   F_S = Front_Length * 17 / 1000;
}

void B_Sonic()                        //거리값을 받아올 함수.     
{
   float Back_Length = 0;             //뒤쪽 초음파의 송수신 길이를 저장하는 변수 선언
   //Back_Trig 신호 발생 (10us)
   digitalWrite(Back_Trig,LOW);       
   delayMicroseconds(2);
   digitalWrite(Back_Trig,HIGH);      
   delayMicroseconds(10);
   digitalWrite(Back_Trig,LOW);      

   //Back_Echo 신호 입력                       
   Back_Length = pulseIn(Back_Echo, HIGH);     //pulseIn 함수를 통해 Back_Echo핀에 초음파가 돌아오는 시간을 측정   
                                          
   //입력받은 신호를 거리로 계산
   B_S = Back_Length * 17 / 1000;                                      
}



//IR센서

float F_L,F_R,B_L,B_R = 0;
//F_L : 왼쪽 앞 IR센서 측정값 받는 변수
//F_R : 오른쪽 앞 IR센서 측정값 받는 변수
//B_L : 왼쪽 뒤 IR센서 측정값 받는 변수
//B_R : 오른쪽 뒤 IR센서 측정값 받는 변수

void F_L_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  float Front_Left_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Left_data = analogRead(Front_Left_Ir);
  //측정값을 통해 거리를 계산                   

  F_L = 10650.08 * pow(Front_Left_data,-0.935) - 10;  //단위는 cm
}

void F_R_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  float Front_Right_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Right_data = analogRead(Front_Right_Ir);
  //측정값을 통해 거리를 계산                   
  F_R = 10650.08 * pow(Front_Right_data,-0.935) - 10;  //단위는 cm
}

void B_L_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  float Back_Left_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Left_data = analogRead(Back_Left_Ir);
  //측정값을 통해 거리를 계산                   

  B_L = 10650.08 * pow(Back_Left_data,-0.935) - 10;  //단위는 cm
}

void B_R_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  float Back_Right_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Right_data = analogRead(Back_Right_Ir);
  //측정값을 통해 거리를 계산                   
  B_R = 10650.08 * pow(Back_Right_data,-0.935) - 10;  //단위는 cm                                                                                                                                                         
}

// 모터
// 구동 바퀴 위치
// 첫 번째의 F(front)와 B(back)은 앞바퀴, 뒷바퀴
// 두 번째의 L(left)와 R(right)은 왼쪽바퀴, 오른쪽바퀴 

// 회전 방향
// 세 번째의 1은 전진, 2는 후진

void offLED(){
  digitalWrite(LED_FL, LOW);
  digitalWrite(LED_FR, LOW);
  digitalWrite(LED_BL, LOW);
  digitalWrite(LED_BR, LOW);
  delay(400);
}

void moveFront() {  
  digitalWrite(LED_FL, 1);
  digitalWrite(LED_FR, 1);
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
  digitalWrite(LED_FL, isTurnLight);
  digitalWrite(LED_BL, isTurnLight);
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
  delay(400);
}

void moveRight() {
  digitalWrite(LED_FR, isTurnLight);
  digitalWrite(LED_BR, isTurnLight);
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
  digitalWrite(LED_BL, 1);
  digitalWrite(LED_BR, 1);
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



//블루투스 
int mode;

void BT(){
  if (Serial1.available()) {
    char bt_value = Serial1.read(); // 앞 : g / 뒤 : b / 좌 : l / 우 : r / 정지 : s
    switch(bt_value){
      case 'g':
        mode = 1; 
        // 앞으로가는 모드
        break;
      case 'b':
        mode = 2;    
        // 뒤로가는 모드
        break;
      case 'l':
        mode = 3;    
        // 왼쪽으로 가는 모드
        break;
      case 'r':
        mode = 4;   
        // 오른쪽으로 가는 모드
        break;
      case 's':
        mode = 5;   
        // 모드를 바꾸는 모드
        break;
    }
  }
  else mode = 0;
}

void setup() {
  Serial.begin(9600);       
  Serial1.begin(9600);         
  //Serial1 == 18 19번핀
  for(int i=2;i<10;i++){
    pinMode(i, OUTPUT);
  }
  for(int i=22;i<26;i++){
    pinMode(i, OUTPUT);
  }
  for(int i=26;i<30;i++){
    pinMode(i, INPUT);
  }
  pinMode(Front_Trig,OUTPUT);
  pinMode(Front_Echo, INPUT);
  pinMode(Back_Trig,OUTPUT); 
  pinMode(Back_Echo, INPUT);
  Serial.println("CARVIS START!"); 
}
static unsigned long curr_m,prev_m=0;

void loop() {
  
  curr_m = millis();
  if(curr_m - prev_m > 400){
    prev_m = curr_m;
    if(isTurnLight == 0){
      isTurnLight = 1;
    }
    else{
      offLED();
      isTurnLight = 0;
    }
  }
    BT();
    if(mode == 0){
      F_Sonic();
      B_Sonic();
      F_L_IR();
      F_R_IR();
      B_L_IR();
      B_R_IR();
      
      if(F_S < 10){ // 앞족에서 거리에 물체가 감지 되면
        if(F_L < 10 && F_R < 10 ){ // 앞쪽 양측에서 물체가 감지 되면
          if(B_L > 10){ // 왼쪽 뒤에 물체가 감지 되지 않으면
            moveRight();
            delay(5);
            moveBack();
            delay(5);
          }
          else if(B_R > 10){  // 오른쪽 뒤에 물체가 감지 되지 않으면
            moveLeft();
            delay(5);
            moveBack();
            delay(5);
          }
          else //둘다 물체가 감지되면
          {
            if(B_S < 5) // 더이상 뒤로 갈 수 없으면
            moveFront();
            else
            moveBack();
          }
          
        }
        else if(F_L < 10){ // 좌측에만 물체가 감지 되면
            moveRight(); // 우회전
        }
        else if(F_R < 10){ // 우측에만 물체가 감지 되면
            moveLeft(); // 좌회전
        }
      }
      else{
        moveFront();
      }
    }
    else{
      switch (mode)
      {
      case 1:
        moveFront();
        offLED();
        break;
      case 2:
        moveBack();
        offLED();
        break;
      case 3:
        moveLeft();
        offLED();
        break;
      case 4:
        moveRight();
        offLED();
        break;
      case 5:
        StopMotor();
        offLED();
        break;
      }
    }
}
