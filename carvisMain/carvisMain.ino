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


// 초음파 센서

float F_S = 0,B_S = 0;
//F_S:앞쪽 초음파센서의 값을 받아오는 변수
//B_S:뒤쪽 초음파센서의 값을 받아오는 변수
float F_Sonic()                        //거리값을 받아올 함수.     
{
   float Front_Length = 0;            //앞쪽 초음파의 송수신 길이를 저장하는 변수 선언
   float Front_Distance = 0;          //최종거리 저장 변수 선언
   //Front_Trig 신호 발생 (10us)
   digitalWrite(Front_Trig,LOW);
   delay(2);
   digitalWrite(Front_Trig,HIGH);
   delay(10);
   digitalWrite(Front_Trig,LOW);

   //Front_Echo 신호 입력                    
   Front_Length = pulseIn(Front_Echo, HIGH);  //pulseIn 함수를 통해 echo핀에 초음파가 돌아오는 시간을 측정   
                                          
   //입력받은 신호를 거리로 계산
   Front_Distance = ((float)(340*Front_Length)/10000)/2;

   F_S = Front_Distance;          
}

float B_Sonic()                        //거리값을 받아올 함수.     
{
   float Back_Length = 0;             //뒤쪽 초음파의 송수신 길이를 저장하는 변수 선언
   float Back_Distance = 0;           //최종거리 저장 변수 선언
   //Back_Trig 신호 발생 (10us)
   digitalWrite(Back_Trig,LOW);       
   delay(2);
   digitalWrite(Back_Trig,HIGH);      
   delay(10);
   digitalWrite(Back_Trig,LOW);      

   //Back_Echo 신호 입력                       
   Back_Length = pulseIn(Back_Echo, HIGH);     //pulseIn 함수를 통해 Back_Echo핀에 초음파가 돌아오는 시간을 측정   
                                          
   //입력받은 신호를 거리로 계산
   Back_Distance = ((float)(340*Back_Length)/10000)/2;      
   
   B_S = Back_Distance;                                    
}


//IR센서

float F_L,F_R,B_L,B_R = 0;
//F_L : 왼쪽 앞 IR센서 측정값 받는 변수
//F_R : 오른쪽 앞 IR센서 측정값 받는 변수
//B_L : 왼쪽 뒤 IR센서 측정값 받는 변수
//B_R : 오른쪽 뒤 IR센서 측정값 받는 변수

float F_L_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  float Front_Left_distance = 0;  //IR센서의 거리 저장 변수 선언 
  float Front_Left_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언
  float Front_Left_volt = 0;      //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Left_data = analogRead(Front_Left_Ir);                   
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Front_Left_volt = map(Front_Left_data, 0, 1023, 0, 5000);      
  //측정값을 통해 거리를 계산
  Front_Left_distance = (21.61/(Front_Left_volt-0.1696))*1000;   
  //delay(500);                                                  
  F_L = Front_Left_distance;                              
}

float F_R_IR()                   //오른쪽 앞 IR센서의 측정값 저장하는 함수       
{
  float Front_Right_distance = 0;  //IR센서의 거리 저장 변수 선언 
  float Front_Right_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언
  float Front_Right_volt = 0;      //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Right_data = analogRead(Front_Right_Ir);                 
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Front_Right_volt = map(Front_Right_data, 0, 1023, 0, 5000);      
  //측정값을 통해 거리를 계산  
  Front_Right_distance = (21.61/(Front_Right_volt-0.1696))*1000; 
  //delay(500);                                                  
  F_R = Front_Right_distance;                                    
}

float B_L_IR()                   //왼쪽 뒤 IR센서의 측정값 저장하는 함수        
{
  float Back_Left_distance = 0;    //IR센서의 거리 저장 변수 선언 
  float Back_Left_data = 0;        //IR센서로 부터 측정값 읽는 변수 선언
  float Back_Left_volt = 0;        //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Left_data = analogRead(Back_Left_Ir);                     
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Back_Left_volt = map(Back_Left_data, 0, 1023, 0, 5000);        
  //측정값을 통해 거리를 계산
  Back_Left_distance = (21.61/(Back_Left_volt-0.1696))*1000;     
  //delay(500);                                                  
  B_L = Back_Left_distance;                                    
}

float B_R_IR()                   //오른쪽 뒤 IR센서의 측정값 저장하는 함수       
{
  float Back_Right_distance = 0;   //IR센서의 거리 저장 변수 선언 
  float Back_Right_data = 0;       //IR센서로 부터 측정값 읽는 변수 선언
  float Back_Right_volt = 0;       //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Right_data = analogRead(Back_Right_Ir);                   
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Back_Right_volt = map(Back_Right_data, 0, 1023, 0, 5000);      
  //측정값을 통해 거리를 계산
  Back_Right_distance = (21.61/(Back_Right_volt-0.1696))*1000;   
  //delay(500);                                                  
  B_R = Back_Right_distance;                                    
}


// 모터
// 구동 바퀴 위치
// 첫 번째의 F(front)와 B(back)은 앞바퀴, 뒷바퀴
// 두 번째의 L(left)와 R(right)은 왼쪽바퀴, 오른쪽바퀴 

// 회전 방향
// 세 번째의 1은 전진, 2는 후진

void moveFront(int spd, float t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇초 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == t*1000){
    return;
  }
  digitalWrite(LED_FL, HIGH);
  digitalWrite(LED_FR, HIGH);
  
  analogWrite(FL_1, spd);
  analogWrite(FR_1, spd);
}

void moveLeft(int spd, float t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇ms 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == t*1000){
    return;
  }
  digitalWrite(LED_FL, HIGH);
  digitalWrite(LED_BL, HIGH);
  
  analogWrite(FL_1, spd/10);
  analogWrite(BR_1, spd/10);
  analogWrite(FR_1, spd);
}

void moveright(int spd, float t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇ms 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == t*1000){
    return;
  }
  digitalWrite(LED_FR, HIGH);
  digitalWrite(LED_BR, HIGH);
  
  analogWrite(FR_1, spd/10);
  analogWrite(BL_1, spd/10);
  analogWrite(FL_1, spd);
}

void moveBack(int spd, float t) {
  //spd는 0~255의 값으로 모터 속력을 의미
  //t는 time의 약어로 몇ms 동안 이동할지를 의미
  unsigned char prev_m = 0;
  unsigned char curr_m = 0;
  curr_m = millis();
  if(curr_m - prev_m == t*1000){
    return;
  }
  digitalWrite(LED_BL, HIGH);
  digitalWrite(LED_BR, HIGH);
  
  analogWrite(FL_2, spd);
  analogWrite(FR_2, spd);
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
  pinMode(Front_Trig,INPUT);
  pinMode(Front_Echo, OUTPUT);
  pinMode(Back_Trig,INPUT); 
  pinMode(Back_Echo, OUTPUT);
  Serial.println("CARVIS START!"); 
}

void loop() {
    BT();
    if(mode == 0){
      F_Sonic();
      B_Sonic();
      F_L_IR();
      F_R_IR();
      B_L_IR();
      B_R_IR();
      
      if(F_S < 20){ // 앞족에서 거리에 물체가 감지 되면
        moveFront(20,5); // 속도 줄이기
        if(F_L < 10 && F_R < 10 ){ // 앞쪽 양측에서 물체가 감지 되면
          if(B_L > 10){ // 왼쪽 뒤에 물체가 감지 되지 않으면
            moveright(100,10);
            moveBack(100,10);
          }
          else if(B_R > 10){  // 오른쪽 뒤에 물체가 감지 되지 않으면
            moveLeft(100,10);
            moveBack(100,10);
          }
          else //둘다 물체가 감지되면
          {
            if(B_S < 5) // 더이상 뒤로 갈 수 없으면
            moveFront(50,10);
            else
            moveBack(100,10);
          }
          
        }
        else if(F_L < 10){ // 좌측에만 물체가 감지 되면
            moveright(100,10); // 우회전
        }
        else if(F_R < 10){ // 우측에만 물체가 감지 되면
            moveLeft(100,10); // 좌회전
        }
      }
      else{
        moveFront(200,10);
      }
    }
    else{
      switch (mode)
      {
      case 1:
        moveFront(255,5);
        break;
      case 2:
        moveBack(255,5);
        break;
      case 3:
        moveLeft(100,5);
        break;
      case 4:
        moveright(100,5);
        break;
      case 5:
        moveFront(0,1);
        moveBack(0,1);
        break;
      }
    }
}