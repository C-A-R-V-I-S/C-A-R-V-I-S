#define Front_Trig 30         //Front_Trig 30번핀으로 설정.
#define Front_Echo 31         //Front_Echo 31번핀으로 설정.
#define Back_Trig  32          //Back_Trig 32번핀으로 설정.
#define Back_Echo  33          //Back_Echo 33번핀으로 설정.

float F_S,B_S = 0;
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
   delay(2);
   digitalWrite(Back_Trig,HIGH);      
   delay(10);
   digitalWrite(Back_Trig,LOW);      

   //Back_Echo 신호 입력                       
   Back_Length = pulseIn(Back_Echo, HIGH);     //pulseIn 함수를 통해 Back_Echo핀에 초음파가 돌아오는 시간을 측정   
                                          
   //입력받은 신호를 거리로 계산
   B_S = Back_Length * 17 / 1000;                                      
}
