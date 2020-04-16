#include <SoftwareSerial.h>
// 블루투스 사용을 위한 라이브러리 헤더파일을 불러온다
SoftwareSerial BLTH(9,10);
// (9번과 10번핀에 연결)객체를 선언한다
// (TX, RX순)

// left motor pins
// 3번과 5번핀 이용
#define IN1 3
#define IN2 5

// right motor pins
// 6번과 11번핀 이용
#define IN3 6
#define IN4 11

// set motors to move forward
void go(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//정지 함수
void stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2000);
  return;
}
//좌회전 함수
void left(){
  stop();
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
//우회전 함수
void right(){
  stop();
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void setup() {
  // set up serial port
  Serial.begin(9600);
  BLTH.begin(9600);
  
  // set all the motor pins OUTPUT mode
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // wait 2 seconds after power up
  delay(2000);
  go();

}

void loop() {
  // 물체 인식시 정지를 구현
  if(BLTH.available()){
    char get_C = BLTH.read();
    if(get_C=='l'){
      left();
    }
    else if(get_C=='r'){
      right();
    }
    BLTH.write(BLTH.read());
    delay(5000);
  }
}
