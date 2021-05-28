#include <Servo.h>

Servo servo1, servo2;

void mouth(int angle1, int angle2, int seconds1, int seconds2)
{
  for (int i = angle1; i <= angle2; i++)
  {
    servo1.write(i);
    servo2.write(i);
    delay(seconds1);
  }
  for (int i = angle2; i >= angle1; i--)
  {
    servo1.write(i);
    servo2.write(i);
    delay(seconds2);
  }
}

void setup()
{
  servo1.attach(10);
  servo2.attach(6);
}

void loop()
{
  mouth(45, 150, 3, 6);
  delay(1500);
}
