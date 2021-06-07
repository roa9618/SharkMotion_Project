#include <Servo.h>
#include <IRremote.h>

IRrecv irrecv(13);
decode_results results;
Servo servo1, servo2, servo3, servo4;

void mouth(int angle1, int angle2, int seconds1, int seconds2)
{
  for (int i = angle1; i <= angle2; i++)
  {
    servo1.write(i);
    delay(seconds1);
  }
  for (int i = angle2; i >= angle1; i--)
  {
    servo1.write(i);
    delay(seconds2);
  }
}

void tail(int angle1, int angle2, int seconds)
{
  for (int i = angle1; i < angle2; i++)
  {
    servo2.write(i);
    delay(seconds);
  }

  for (int i = angle2; i > angle1; i--)
  {
    servo2.write(i);
    delay(seconds);
  }
}

void body(int angle1, int angle2, int seconds1, int seconds2)
{
  for (int i = angle1; i <= angle2; i++)
  {
    servo3.write(i);
    delay(seconds1);
    servo4.write(i);
    delay(seconds2);
  }
  for (int i = angle2; i >= angle2; i--)
  {
    servo3.write(i);
    delay(seconds1);
    servo4.write(i);
    delay(seconds2);
  }
}

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo1.attach(12);
  servo2.attach(11);
  servo3.attach(10);
  servo4.attach(9);
}

void loop()
{
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  if (irrecv.decode(&results) == true)
  {
    switch (results.value)
    {
      case 0xFF30CF :
        while (i <= 10)
        {
          mouth(45, 150, 3, 6);
          delay(1500);
          i++;
        }
        break;
      case 0xFF18E7 :
        while (j <= 5)
        {
          tail(45, 135, 10);
          j++;
        }
        break;
      case 0xFF7A85 :
        while (k <= 5)
        {
          body(0, 180, 1, 10);
          k++;
        }
        break;
      case 0xFF10EF :
        while (l <= 5)
        {
          for (int i = 0; i <= 180; i++)
          {
            servo3.write(i);
            delay(1);
            servo4.write(i);
            delay(10);
          }
          for (int i = 45; i < 135; i++)
          {
            servo2.write(i);
            delay(5);
          }
          for (int i = 180; i >= 0; i--)
          {
            servo3.write(i);
            delay(1);
            servo4.write(i);
            delay(10);
          }
          for (int i = 135; i > 45; i--)
          {
            servo2.write(i);
            delay(5);
          }
          l++;
        }
        break;
    }
  }
  irrecv.resume();
}
