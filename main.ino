#include <Servo.h>

Servo servo;

void mouth(int angle1, int angle2, int seconds1, int seconds2)
{
  for (int i = angle1; i <= angle2; i++)
  {
    servo.write(i);
    delay(seconds1);
  }
  for (int i = angle2; i >= angle1; i--)
  {
    servo.write(i);
    delay(seconds2);
  }
}

void setup()
{
  servo.attach(10);
}

void loop()
{
  mouth(45, 150, 3, 6);
  delay(1500);
}
