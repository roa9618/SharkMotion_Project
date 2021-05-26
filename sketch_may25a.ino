#include <Servo.h>

int servoPin = 9;

Servo servo;

int angle = 0; //servo position in degrees

void setup()
{
  servo.attach(servoPin);
}

void loop()
{
  for (angle = 0; angle < 270; angle++)
  {
    servo.write(angle);
    delay(5);
  }
  for (angle = 270; angle > 0; angle—)
  {
    servo.write(angle);
    delay(5);
  }
}
