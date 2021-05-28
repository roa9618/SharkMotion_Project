#include <Servo.h>
#include <IRremote.h>

IRrecv irrecv(13);
decode_results results;
Servo servo1, servo2;

int i = 0;

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
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo1.attach(8);
  servo2.attach(9);
}

void loop()
{
  if (irrecv.decode(&results) == true)
  {
    Serial.println(results.value);
  }
  switch (results.value)
  {
    case 0xFF30CF :
      while (i < 10)
      {
        mouth(45, 150, 3, 6);
        delay(1500);
        i++;
      }
  }
  irrecv.resume();
}
