#include <Servo.h>

#define joyX1 A0
#define joyY1 A1
#define joyX2 A2
#define joyY2 A3

int xValue1 = analogRead(joyX1);
int yValue1 = analogRead(joyY1);
int xValue2 = analogRead(joyX2);
int yValue2 = analogRead(joyY2);


int initial_position1 = 90;
int initial_position2 = 90;
int initial_position3 = 90;
int initial_position4 = 90;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


void setup() {
  Serial.begin(9600);
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo1.write(initial_position1);
  servo2.write(initial_position2);
  servo3.write(initial_position3);
  servo4.write(initial_position4);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

}

void loop() {

  xValue1 = analogRead(joyX1);
  yValue1 = analogRead(joyY1);
  xValue2 = analogRead(joyX2);
  yValue2 = analogRead(joyY2);

  int xAngle1 = map(xValue1, 0, 1023, 0, 180);
  int yAngle1 = map(yValue1, 0, 1023, 0, 180);
  int xAngle2 = map(xValue2, 0, 1023, 0, 180);
  int yAngle2 = map(yValue2, 0, 1023, 0, 180);

  servo1.write(xAngle1);
  servo2.write(yAngle1);
  servo3.write(xAngle2);
  servo4.write(yAngle2);

  Serial.print("Joystick1: ");
  Serial.print(xValue1);
  Serial.print(", ");
  Serial.print(yValue1);
  Serial.print("Joystick2: ");
  Serial.print(xValue2);
  Serial.print(", ");
  Serial.print(yValue2);
}
