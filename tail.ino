#include <Servo.h>

Servo servo3;

void tail(int angle1, int angle2, int seconds)
{
  for (int i = angle1; i < angle2; i++)
  {
    servo3.write(i);
    delay(seconds);
  }

  for (int i = angle2; i > angle1; i--)
  {
    servo3.write(i);
    delay(seconds);
  }
}

void setup()
{
  servo3.attach(8);
}

void loop()
{
  tail(40, 135, 10);
}
