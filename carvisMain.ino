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

#define Front_Left_Ir  26      //왼쪽 앞 IR센서를 26핀으로 설정
#define Front_Right_Ir 27    //오른쪽 앞 IR센서를 27핀으로 설정
#define Back_Left_Ir   28      //왼쪽 뒤 IR센서를 28핀으로 설정
#define Back_Right_Ir  29      //오른쪽 뒤 IR센서를 29핀으로 설정

#define Front_Trig 30         //Front_Trig(초음파 보내는 핀)를 30번핀으로 설정한다.
#define Front_Echo 31         //Front_Echo(초음파 받는 핀)를 31번핀으로 설정한다.
#define Back_Trig  32          //Back_Trig(초음파 보내는 핀)를 32번핀으로 설정한다.
#define Back_Echo  33          //Back_Echo(초음파 받는 핀)를 33번핀으로 설정한다.

//모터 구동 부분
void moveFront(float F_Sonic,float R_Sonic,float fl_IR,float fr_IR,float rl_IR,float rr_IR) {
  analogWrite(FL_1, 200);
  analogWrite(FR_1, 200);

  if(F_Sonic < 30){
    analogWrite(FL_1, 10);
    analogWrite(FR_1, 10); 
    delay(50);

    if(fl_IR < 10 && fr_IR < 10) {
      analogWrite(FL_1, 0); // 감속
      analogWrite(FR_1, 0);
      delay(10);
      analogWrite(FL_2, (F_Sonic * 15)); // 후진
      analogWrite(FR_2, 100);
      delay(100);
      analogWrite(FR_1, 250); // 좌회전
      analogWrite(RR_1, 40);
      analogWrite(FL_1, 50);
      delay(300);
      analogWrite(FL_1, 250); // 우회전
      analogWrite(RL_1, 40);
      analogWrite(FR_1, 50);
      delay(300);
    }
    else if(fl_IR < 10) {
      analogWrite(FR_1, 250); // 우회전                     
      analogWrite(RR_1, 40);
      analogWrite(FL_1, 50);
      delay(300);
    }
    else if(fr_IR < 10) {
      analogWrite(FR_1, 250); // 좌회전
      analogWrite(RR_1, 40);
      analogWrite(FL_1, 50);
      delay(300);
    }
    //웬만해서는 쓰이지 않겠지만 후진의 경우
    else if(R_Sonic < 30) {
      analogWrite(FL_2, 10); // 감속
      analogWrite(FR_2, 10);
      delay(150);
      if(rl_IR < 10) {
        analogWrite(RL_2, 250); // 우회전
        analogWrite(RR_2, 40);
        analogWrite(FL_2, 50);
        delay(300);
      }
      else if(rr_IR < 10) {
        analogWrite(RR_2, 250); // 좌회전
        analogWrite(RL_2, 40);
        analogWrite(FR_2, 50);
        delay(300); 
      }
    }
  }
}


//IR 센서 부분
int F_L_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  int Front_Left_distance = 0;  //IR센서의 거리 저장 변수 선언 
  int Front_Left_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언
  int Front_Left_volt = 0;      //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Left_data = analogRead(Front_Left_Ir);                   
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Front_Left_volt = map(Front_Left_data, 0, 1023, 0, 5000);      
  //측정값을 통해 거리를 계산
  Front_Left_distance = (21.61/(Front_Left_volt-0.1696))*1000;   
  //delay(500);                                                  
  return Front_Left_distance;                              
}

int F_R_IR()                   //오른쪽 앞 IR센서의 측정값 저장하는 함수       
{
  int Front_Right_distance = 0;  //IR센서의 거리 저장 변수 선언 
  int Front_Right_data = 0;      //IR센서로 부터 측정값 읽는 변수 선언
  int Front_Right_volt = 0;      //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Right_data = analogRead(Front_Right_Ir);                 
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Front_Right_volt = map(Front_Right_data, 0, 1023, 0, 5000);      
  //측정값을 통해 거리를 계산  
  Front_Right_distance = (21.61/(Front_Right_volt-0.1696))*1000; 
  //delay(500);                                                  
  return Front_Right_distance;                                    
}

int B_L_IR()                   //왼쪽 뒤 IR센서의 측정값 저장하는 함수        
{
  int Back_Left_distance = 0;    //IR센서의 거리 저장 변수 선언 
  int Back_Left_data = 0;        //IR센서로 부터 측정값 읽는 변수 선언
  int Back_Left_volt = 0;        //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Left_data = analogRead(Back_Left_Ir);                     
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Back_Left_volt = map(Back_Left_data, 0, 1023, 0, 5000);        
  //측정값을 통해 거리를 계산
  Back_Left_distance = (21.61/(Back_Left_volt-0.1696))*1000;     
  //delay(500);                                                  
  return Back_Left_distance;                                    
}

int B_R_IR()                   //오른쪽 뒤 IR센서의 측정값 저장하는 함수       
{
  int Back_Right_distance = 0;   //IR센서의 거리 저장 변수 선언 
  int Back_Right_data = 0;       //IR센서로 부터 측정값 읽는 변수 선언
  int Back_Right_volt = 0;       //IR센서의 측정값을 다듬을 변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Right_data = analogRead(Back_Right_Ir);                   
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Back_Right_volt = map(Back_Right_data, 0, 1023, 0, 5000);      
  //측정값을 통해 거리를 계산
  Back_Right_distance = (21.61/(Back_Right_volt-0.1696))*1000;   
  //delay(500);                                                  
  return Back_Right_distance;                                    
}


//초음파 센서 부분
float F_Sonic()                        //Front_Ultrasonic의 거리값을 받아올 함수 정의.     
{
   float Front_Length = 0;            //앞쪽 초음파의 송수신 길이를 저장하는 Front_Length변수 선언
   float Front_Distance = 0;          //최종적으로 초음파 센서가 측정한 값을 거리로 나타내어 저장할 Front_Distance 변수 선언
   //Front_Trig 신호 발생 (10us)
   digitalWrite(Front_Trig,LOW);      //Front_Trig를 LOW로 초기화시킨다.
   delay(2);
   digitalWrite(Front_Trig,HIGH);     //Front_Trig를 HIGH 신호를 발생 시킨다.
   delay(10);
   digitalWrite(Front_Trig,LOW);      //Front_Trig를 LOW로 초기화 시킨다.

   //Front_Echo 신호 입력                         //pulseIn 함수를 통해 echo핀에 초음파가 돌아오는 시간을 측정
   Front_Length = pulseIn(Front_Echo, HIGH);    //pulseIn()함수는 아두이노 기본 함수로 입력신호가 High또는 LOW가 되는 시간을 측정해주는 함수    
                                          
   //입력받은 신호를 거리로 계산
   Front_Distance = ((float)(340*Front_Length)/10000)/2;    //입력받은 신호 결과를 거리로 변환하기 위한 계산 후 Front_Distance변수에 넣는다. 

   return Front_Distance;                                   //거리를 반환한다.
}

float B_Sonic()                        //Back_Ultrasonic의 거리값을 받아올 함수 정의.     
{
   float Back_Length = 0;             //뒤쪽 초음파의 송수신 길이를 저장하는 Back_Length변수 선언
   float Back_Distance = 0;           //최종적으로 초음파 센서가 측정한 값을 거리로 나타내어 저장할 Back_Distance 변수 선언
   //Back_Trig 신호 발생 (10us)
   digitalWrite(Back_Trig,LOW);       //Back_Trig를 LOW로 초기화시킨다.
   delay(2);
   digitalWrite(Back_Trig,HIGH);      //Back_Trig를 HIGH 신호를 발생 시킨다.
   delay(10);
   digitalWrite(Back_Trig,LOW);       //Back_Trig를 LOW로 초기화 시킨다.

   //Back_Echo 신호 입력                        //pulseIn 함수를 통해 Back_Echo핀에 초음파가 돌아오는 시간을 측정
   Back_Length = pulseIn(Back_Echo, HIGH);    //pulseIn()함수는 아두이노 기본 함수로 입력신호가 High또는 LOW가 되는 시간을 측정해주는 함수    
                                          
   //입력받은 신호를 거리로 계산
   Back_Distance = ((float)(340*Back_Length)/10000)/2;      //입력받은 신호 결과를 거리로 변환하기 위한 계산 후 Back_Distance변수에 넣는다. 
   
   return Back_Distance;                                    //거리를 반환한다.
}


//블루투스 부분
void Forward(){
  analogWrite(FL_1, 200);
  analogWrite(FR_1, 200);
  delay(100);
}
void Back(){
  analogWrite(FL_2, 100); // 후진
  analogWrite(FR_2, 100);
  delay(100);
}
void Left(){
  analogWrite(RR_2, 250); // 좌회전
  analogWrite(RL_2, 40);
  analogWrite(FR_2, 50);
  delay(100); 
}
void Right(){
  analogWrite(FR_1, 250); // 우회전                
  analogWrite(RR_1, 40);
  analogWrite(FL_1, 50);
  delay(100);
}
void Stop(){
  analogWrite(FL_1, 0);
  analogWrite(FL_2, 0);
  analogWrite(FR_1, 0);
  analogWrite(FR_2, 0);
  analogWrite(RL_1, 0);
  analogWrite(RL_2, 0);
  analogWrite(RR_1, 0);
  analogWrite(RR_2, 0);
  delay(100);
}
void BT(){
  if (BT.available()) {
    char bt_value = Serial1.read(); // 앞 : g / 뒤 : b / 좌 : l / 우 : r / 정지 : s
    switch(bt_value){
      case 'g':
        Forward(); // 앞으로가는 함수
        break;
      case 'b':
        Back();    // 뒤로가는 함수
        break;
      case 'l':
        Left();    // 왼쪽으로 가는 함수
        break;
      case 'r':
        Right();   // 오른쪽으로 가는 함수
        break;
      case 's':
        Stop();    // 멈추는 함수
        break;
    }
  }
}


//실제 실행 부분
void setup(){
    Serial.begin(9600);               //시리얼 통신 9600(속도)으로 초기화
    Serial1.begin(9600);
    //모터 제어 핀
    for(int i=2;i<10;i++){
        pinMode(i, OUTPUT);           //모터 제어에 필요한 핀 8개를 OUTPUT모드로 설정한다.
    }
    //초음파 센서 핀
    pinMode(Front_Trig,OUTPUT);       //Front_Trig(보내는 핀)를 OUTPUT모드로 설정한다.
    pinMode(Front_Echo,INPUT);        //Front_Echo(보내는 핀)를 INPUT모드로 설정한다.
    pinMode(Back_Trig,OUTPUT);        //Back_Trig(보내는 핀)를 OUTPUT모드로 설정한다.
    pinMode(Back_Echo,INPUT);         //Back_Echo(보내는 핀)를 INPUT모드로 설정한다.
    //적외선 센서 핀
    pinMode(Front_Left_Ir,INPUT);     //왼쪽 앞 IR센서 INPUT 모드로 설정
    pinMode(Front_Right_Ir,INPUT);    //오른쪽 앞 IR센서 INPUT 모드로 설정
    pinMode(Back_Left_Ir,INPUT);      //왼쪽 뒤 IR센서 INPUT 모드로 설정
    pinMode(Back_Right_Ir,INPUT);     //오른쪽 뒤 IR센서 INPUT 모드로 설정
    
}

void loop(){
    //초음파 센서 정보
    float front = F_Sonic();    //F_Sonic()의 매개변수로 front를 넘겨주며 함수 실행 -> F_Sonic()의 거리값이 front에 들어감
    float back = B_Sonic();     //B_Sonic()의 매개변수로 back를 넘겨주며 함수 실행 -> B_Sonic()의 거리값이 back에 들어감
    //적외선 센서 정보
    int front_left = F_L_IR();    //F_L_IR()의 할당공간을 a로 설정하며 함수 실행 -> F_L_IR의 거리가 a에 저장됨.
    int front_right = F_R_IR();   //F_R_IR()의 할당공간을 b로 설정하며 함수 실행 -> F_R_IR의 거리가 b에 저장됨.
    int back_left = B_L_IR();     //B_L_IR()의 할당공간을 c로 설정하며 함수 실행 -> B_L_IR의 거리가 c에 저장됨.
    int back_right = B_R_IR();    //B_R_IR()의 할당공간을 d로 설정하며 함수 실행 -> B_R_IR의 거리가 d에 저장됨.
    //모터 제어부
    moveFront(front, back, front_left, front_right, back_left, back_right); // moveFront(float F_Sonic, float R_Sonic, float fl_IR, float fr_IR, float rl_IR, float rr_IR )
    //블루투스 정보
    BT();
}
