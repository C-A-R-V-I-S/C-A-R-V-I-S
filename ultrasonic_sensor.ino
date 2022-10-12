#define Front_Trig 30         //Front_Trig 30번핀으로 설정.
#define Front_Echo 31         //Front_Echo 31번핀으로 설정.
#define Back_Trig  32          //Back_Trig 32번핀으로 설정.
#define Back_Echo  33          //Back_Echo 33번핀으로 설정.

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

   return Front_Distance;          
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
   
   return Back_Distance;                                    
}
