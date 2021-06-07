#include <Servo.h>
#include <IRremote.h>

IRrecv irrecv(13);
decode_results results;
Servo servo1, servo3;

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
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo1.attach(10);
  servo3.attach(6);
}

void loop()
{
  int i = 0;
  int j = 0;
  if (irrecv.decode(&results) == true)
  {
    switch (results.value)
    {
      case 0xFF30CF :
        while (i <= 5)
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
    }
  }
  irrecv.resume();
}
