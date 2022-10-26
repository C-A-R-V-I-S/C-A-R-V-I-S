#define Front_Left_Ir  26      //왼쪽 앞 IR센서 26핀 설정
#define Front_Right_Ir 27    //오른쪽 앞 IR센서 27핀 설정
#define Back_Left_Ir   28      //왼쪽 뒤 IR센서 28핀 설정
#define Back_Right_Ir  29      //오른쪽 뒤 IR센서 29핀 설정
#define VOLTS_PER_UNIT .0049F //아날로그 값을 volt 단위로 변환하기위한 변수 설정

float F_L,F_R,B_L,B_R = 0;
//F_L : 왼쪽 앞 IR센서 측정값 받는 변수
//F_R : 오른쪽 앞 IR센서 측정값 받는 
//B_L : 왼쪽 뒤 IR센서 측정값 받는 
//B_R : 오른쪽 뒤 IR센서 측정값 받는 


void F_L_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  //IR센서로 부터 측정값 읽는 변수 선언
  //적외선 거리 센서로 부터 측정값을 읽어온다   
  int Front_Left_data = analogRead(Front_Left_Ir);
  // 아날로그값을 volt 단위로 변환
  float volts = (float)Front_Left_data * VOLTS_PER_UNIT;
  // 측정전압에 따른 cm단위 거리 계산
  F_L = 60.495 * pow(volts,-1.1904);  
}

void F_R_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  //IR센서로 부터 측정값 읽는 변수 선언
  //적외선 거리 센서로 부터 측정값을 읽어온다   
  int Front_Right_data = analogRead(Front_Right_Ir);
  // 아날로그값을 volt 단위로 변환
  float volts = (float)Front_Right_data * VOLTS_PER_UNIT;
  // 측정전압에 따른 cm단위 거리 계산
  F_R = 60.495 * pow(volts,-1.1904);  
}

void B_L_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  //IR센서로 부터 측정값 읽는 변수 선언
  //적외선 거리 센서로 부터 측정값을 읽어온다
  int Back_Left_data = analogRead(Back_Left_Ir);
  // 아날로그값을 volt 단위로 변환
  float volts = (float)Back_Left_data * VOLTS_PER_UNIT;
  // 측정전압에 따른 cm단위 거리 계산
  B_L = 60.495 * pow(volts,-1.1904);  
}

void B_R_IR()                   //왼쪽 앞 IR센서의 측정값 저장하는 함수
{
  //IR센서로 부터 측정값 읽는 변수 선언
  //적외선 거리 센서로 부터 측정값을 읽어온다   
  int Back_Right_data = analogRead(Back_Right_Ir);
  // 아날로그값을 volt 단위로 변환
  float volts = (float)Back_Right_data * VOLTS_PER_UNIT;
  // 측정전압에 따른 cm단위 거리 계산
  B_R = 60.495 * pow(volts,-1.1904);                                                                                                                                                    
}
