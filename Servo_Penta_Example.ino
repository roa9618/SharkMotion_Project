#include <Servo.h>

int servoPin1 = 8;
int servoPin2 = 9;
int servoPin3 = 10;
int servoPin4 = 11;
int servoPin5 = 12;

Servo servo1, servo2, servo3, servo4, servo5;

int angle = 0;

void setup()
{
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
}

void loop()
{
  for (angle = 0; angle < 360; angle++)
  {
    servo1.write(angle);
    servo2.write(angle);
    servo3.write(angle);
    servo4.write(angle);
    servo5.write(angle);
    delay(1);
  }
  for (angle = 360; angle > 0; angle--)
  {
    servo1.write(angle);
    servo2.write(angle);
    servo3.write(angle);
    servo4.write(angle);
    servo5.write(angle);
    delay(1);
  }
}
