#include <stdio.h>

static int Front_Trig = 30;         //Front_Trig(초음파 보내는 핀)를 30번핀으로 설정한다.
static int Front_Echo = 31;         //Front_Echo(초음파 받는 핀)를 31번핀으로 설정한다.
static int Back_Trig = 32;          //Back_Trig(초음파 보내는 핀)를 32번핀으로 설정한다.
static int Back_Echo = 33;          //Back_Echo(초음파 받는 핀)를 33번핀으로 설정한다.

void F_Sonic(float F_S);            //Front_Ultrasonic의 거리값을 받아올 함수를 선언해준다.     //매개변수로 float형 공간을 받는다.
void B_Sonic(float B_S);            //Back_Ultrasonic의 거리값을 받아올 함수를 선언해준다.      //매개변수로 float형 공간을 받는다.

void setup() 
{
  Serial.begin(9600);               //시리얼 통신을 9600(속도)으로 초기화

  pinMode(Front_Trig,OUTPUT);       //Front_Trig(보내는 핀)를 OUTPUT모드로 설정한다.
  pinMode(Front_Echo,INPUT);        //Front_Echo(보내는 핀)를 INPUT모드로 설정한다.
  pinMode(Back_Trig,OUTPUT);        //Back_Trig(보내는 핀)를 OUTPUT모드로 설정한다.
  pinMode(Back_Echo,INPUT);         //Back_Echo(보내는 핀)를 INPUT모드로 설정한다.
}
void loop()                         //함수들의 실행 예시
{
  int a = 0, b = 0;                 //실행 예시를 위해 int a,b를 0으로 선언과 동시에 초기화. 
  F_Sonic(a);                       //F_Sonic()의 매개변수로 a를 넘겨주며 함수 실행 -> F_Sonic()의 거리값이 a에 들어감
  B_Sonic(b);                       //B_Sonic()의 매개변수로 b를 넘겨주며 함수 실행 -> B_Sonic()의 거리값이 b에 들어감
}

//==========================================================================================================================================================================================

void F_Sonic(float F_S)               //Front_Ultrasonic의 거리값을 받아올 함수 정의.     //매개변수로 받은 F_S에 거리 데이터를 넣는다. 
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

   F_S = Front_Distance;                                    //매개변수로 받은 F_S에 최종거리 값을 넣는다.
}

//==========================================================================================================================================================================================

void B_Sonic(float B_S)               //Back_Ultrasonic의 거리값을 받아올 함수 정의.     //매개변수로 받은 B_S에 거리 데이터를 넣는다.
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
   
   B_S = Back_Distance;                                     //매개변수로 받은 B_S에 최종거리 값을 넣는다.
}

//==========================================================================================================================================================================================
