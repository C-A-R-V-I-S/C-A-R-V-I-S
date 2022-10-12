#define Front_Left_Ir  26      //왼쪽 앞 IR센서 26핀 설정
#define Front_Right_Ir 27    //오른쪽 앞 IR센서 27핀 설정
#define Back_Left_Ir   28      //왼쪽 뒤 IR센서 28핀 설정
#define Back_Right_Ir  29      //오른쪽 뒤 IR센서 29핀 설정

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
