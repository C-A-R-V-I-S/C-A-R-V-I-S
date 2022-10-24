#include <SoftwareSerial.h>
  
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
}

void setup() {
  Serial.begin(9600);       
  Serial1.begin(9600);         
  //Serial1 == 18 19번핀
  Serial.println("HELLO!"); 
}