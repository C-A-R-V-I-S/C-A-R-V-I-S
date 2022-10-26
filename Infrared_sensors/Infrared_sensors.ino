#define Front_Left_Ir  26      //왼쪽 앞 IR센서 26핀 설정
#define Front_Right_Ir 27    //오른쪽 앞 IR센서 27핀 설정
#define Back_Left_Ir   28      //왼쪽 뒤 IR센서 28핀 설정
#define Back_Right_Ir  29      //오른쪽 뒤 IR센서 29핀 설정

float F_L,F_R,B_L,B_R = 0;
//F_L : 왼쪽 앞 IR센서 측정값 받는 변수
//F_R : 오른쪽 앞 IR센서 측정값 받는 
//B_L : 왼쪽 뒤 IR센서 측정값 받는 
//B_R : 오른쪽 뒤 IR센서 측정값 받는 


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
