#define Front_Left_Ir  26      //왼쪽 앞 IR센서를 26핀으로 설정
#define Front_Right_Ir 27    //오른쪽 앞 IR센서를 27핀으로 설정
#define Back_Left_Ir   28      //왼쪽 뒤 IR센서를 28핀으로 설정
#define Back_Right_Ir  29      //오른쪽 뒤 IR센서를 29핀으로 설정

int F_L_IR();             //왼쪽 앞 IR센서의 측정값을 변환 후 거리로 반환하는 F_L_IR함수 선언
int F_R_IR();             //오른쪽 앞 IR센서의 측정값을 변환 후 거리로 반환하는 F_R_IR함수 선언
int B_L_IR();             //왼쪽 뒤 IR센서의 측정값을 변환 후 거리로 반환하는 B_L_IR함수 선언
int B_R_IR();             //오른쪽 뒤 IR센서의 측정값을 변환 후 거리로 반환하는 B_R_IR함수 선언
/*
void setup() 
{
Serial.begin(9600);               //시리얼 통신 9600(속도)으로 초기화

pinMode(Front_Left_Ir,INPUT);     //왼쪽 앞 IR센서 INPUT 모드로 설정
pinMode(Front_Right_Ir,INPUT);    //오른쪽 앞 IR센서 INPUT 모드로 설정
pinMode(Back_Left_Ir,INPUT);      //왼쪽 뒤 IR센서 INPUT 모드로 설정
pinMode(Back_Right_Ir,INPUT);     //오른쪽 뒤 IR센서 INPUT 모드로 설정
}

void loop()                            //함수들의 실행 예시
{
    int a = 0, b = 0, c = 0, d = 0;    //실행 예시를 위해 int 형 a,b,c,d를 0으로 선언과 동시에 초기화함.
  
    a = F_L_IR();                        //F_L_IR()의 할당공간을 a로 설정하며 함수 실행 -> F_L_IR의 거리가 a에 저장됨.
    b = F_R_IR();                        //F_R_IR()의 할당공간을 b로 설정하며 함수 실행 -> F_R_IR의 거리가 b에 저장됨.
    c = B_L_IR();                        //B_L_IR()의 할당공간을 c로 설정하며 함수 실행 -> B_L_IR의 거리가 c에 저장됨.
    d = B_R_IR();                        //B_R_IR()의 할당공간을 d로 설정하며 함수 실행 -> B_R_IR의 거리가 d에 저장됨.
}
*/

//==========================================================================================================================================================================================

int F_L_IR()                   //왼쪽 앞 IR센서의 측정값을 변환 후 거리로 반환하는 F_L_IR함수 정의
{
  int Front_Left_distance = 0;  //왼쪽 앞 IR센서의 거리를 저장할 변수 선언
  int Front_Left_data = 0;      //왼쪽 앞 IR센서로 부터 측정값을 읽어올 data변수 선언
  int Front_Left_volt = 0;      //왼쪽 앞 IR센서의 측정값을 일정값으로 다듬을 volt변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Left_data = analogRead(Front_Left_Ir);                   //analogRead함수를 사용해 Front_Left_Ir센서의 거리 측정값을 읽어와 Front_Left_data에 저장한다.
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Front_Left_volt = map(Front_Left_data, 0, 1023, 0, 5000);      //map함수를 사용해 Front_Left_data의 값을 0에서 5000사이의 값으로 변환해 Front_Left_volt에 저장한다.
  //측정값을 통해 거리를 계산
  Front_Left_distance = (21.61/(Front_Left_volt-0.1696))*1000;   //변환한 Front_Left_volt의 값을 거리로 변환시키고 Front_Left_distance에 저장한다.

  //delay(500);                                                  //delay부분 필요에따라 수정하면됨.  //지연시간을 500ms로 설정
  return Front_Left_distance;                                    //거리를 반환한다.
}

//==========================================================================================================================================================================================

int F_R_IR()                   //오른쪽 앞 IR센서의 측정값을 변환 후 거리로 반환하는 F_R_IR함수 정의         
{
  int Front_Right_distance = 0;  //오른쪽 앞 IR센서의 거리를 저장할 변수 선언
  int Front_Right_data = 0;      //오른쪽 앞 IR센서로 부터 측정값을 읽어올 data변수 선언
  int Front_Right_volt = 0;      //오른쪽 앞 IR센서의 측정값을 일정값으로 다듬을 volt변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Front_Right_data = analogRead(Front_Right_Ir);                 //analogRead함수를 사용해 Front_Right_Ir센서의 거리 측정값을 읽어와 Front_Right_data에 저장한다.
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Front_Right_volt = map(Front_Right_data, 0, 1023, 0, 5000);    //map함수를 사용해 Front_Right_data 값을 0에서 5000사이의 값으로 변환해 Front_Right_volt 저장한다.
  //측정값을 통해 거리를 계산
  Front_Right_distance = (21.61/(Front_Right_volt-0.1696))*1000; //변환한 Front_Right_volt 값을 거리로 변환시키고 Front_Right_distance 저장한다.

  //delay(500);                                                  //delay부분 필요에따라 수정하면됨.  //지연시간을 500ms로 설정
  return Front_Right_distance;                                    //거리를 반환한다.
}

//==========================================================================================================================================================================================

int B_L_IR()                   //왼쪽 뒤 IR센서의 측정값을 변환 후 거리로 반환하는 B_L_IR함수 정의          
{
  int Back_Left_distance = 0;    //왼쪽 뒤 IR센서의 거리를 저장할 변수 선언 
  int Back_Left_data = 0;        //왼쪽 뒤 IR센서로 부터 측정값을 읽어올 data변수 선언
  int Back_Left_volt = 0;        //왼쪽 앞 IR센서의 측정값을 일정값으로 다듬을 volt변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Left_data = analogRead(Back_Left_Ir);                     //analogRead함수를 사용해 Back_Left_Ir센서의 거리 측정값을 읽어와 Back_Left_data에 저장한다.
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Back_Left_volt = map(Back_Left_data, 0, 1023, 0, 5000);        //map함수를 사용해 Back_Left_data 값을 0에서 5000사이의 값으로 변환해 Back_Left_volt 저장한다.
  //측정값을 통해 거리를 계산
  Back_Left_distance = (21.61/(Back_Left_volt-0.1696))*1000;     //변환한 Back_Left_volt 값을 거리로 변환시키고 Back_Left_distance 저장한다.

  //delay(500);                                                  //delay부분 필요에따라 수정하면됨.  //지연시간을 500ms로 설정
  return Back_Left_distance;                                    //거리를 반환한다.
}

//==========================================================================================================================================================================================

int B_R_IR()                   //오른쪽 뒤 IR센서의 측정값을 변환 후 거리로 반환하는 B_R_IR함수 정의         
{
  int Back_Right_distance = 0;   //오른쪽 뒤 IR센서의 거리를 저장할 변수 선언
  int Back_Right_data = 0;       //오른쪽 뒤 IR센서로 부터 측정값을 읽어올 data변수 선언
  int Back_Right_volt = 0;       //오른쪽 뒤 IR센서의 측정값을 일정값으로 다듬을 volt변수 선언

  //적외선 거리 센서로 부터 측정값을 읽어온다
  Back_Right_data = analogRead(Back_Right_Ir);                   //analogRead함수를 사용해 Back_Right_Ir센서의 거리 측정값을 읽어와 Back_Right_data에 저장한다.
  //측정한 volt값을 0에서 5000사이의 값으로 변환
  Back_Right_volt = map(Back_Right_data, 0, 1023, 0, 5000);      //map함수를 사용해 Back_Right_data 값을 0에서 5000사이의 값으로 변환해 Back_Right_volt 저장한다.
  //측정값을 통해 거리를 계산
  Back_Right_distance = (21.61/(Back_Right_volt-0.1696))*1000;   //변환한 Back_Right_volt 값을 거리로 변환시키고 Back_Right_distance 저장한다.

  //delay(500);                                                  //delay부분 필요에따라 수정하면됨.  //지연시간을 500ms로 설정
  return Back_Right_distance;                                    //거리를 반환한다.
}

//==========================================================================================================================================================================================
