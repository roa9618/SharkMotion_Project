#include <Servo.h>

Servo servo1, servo2, servo3;

void setup()
{
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(11);
}

void loop()
{
  for (int i = 0; i <= 180; i++)
  {
    servo1.write(i);
    delay(1);
    servo2.write(i);
    delay(10);
  }
  for (int i = 45; i < 135; i++)
  {
    servo3.write(i);
    delay(10);
  }
  for (int i = 180; i >= 0; i--)
  {
    servo1.write(i);
    delay(1);
    servo2.write(i);
    delay(10);
  }
  for (int i = 135; i > 45; i--)
  {
    servo3.write(i);
    delay(10);
  }
}
