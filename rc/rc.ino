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
