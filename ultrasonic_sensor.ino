#define Front_Trig 30         //Front_Trig(초음파 보내는 핀)를 30번핀으로 설정한다.
#define Front_Echo 31         //Front_Echo(초음파 받는 핀)를 31번핀으로 설정한다.
#define Back_Trig  32          //Back_Trig(초음파 보내는 핀)를 32번핀으로 설정한다.
#define Back_Echo  33          //Back_Echo(초음파 받는 핀)를 33번핀으로 설정한다.

float F_Sonic();            //Front_Ultrasonic의 거리값을 받아올 함수를 선언해준다.
float B_Sonic();            //Back_Ultrasonic의 거리값을 받아올 함수를 선언해준다.

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
  float a = F_Sonic();                       //F_Sonic()의 매개변수로 a를 넘겨주며 함수 실행 -> F_Sonic()의 거리값이 a에 들어감
  float b = B_Sonic();                       //B_Sonic()의 매개변수로 b를 넘겨주며 함수 실행 -> B_Sonic()의 거리값이 b에 들어감
}

//==========================================================================================================================================================================================

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

//==========================================================================================================================================================================================

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

//==========================================================================================================================================================================================
