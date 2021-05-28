#include <IRremote.h>

int RECV_PIN = 13;
int LED_PIN1 = 5;
int LED_PIN2 = 6;
int i = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results) == true)
  {
    Serial.println(results.value);
  }
  switch (results.value)
  {
    case 0xFF30CF : digitalWrite(LED_PIN1, HIGH); break;
    case 0xFF18E7 : digitalWrite(LED_PIN1, LOW); break;
    case 0xFF7A85 : digitalWrite(LED_PIN2, HIGH); break;
    case 0xFF10EF : digitalWrite(LED_PIN2, LOW); break;
    case 0xFF6897 :
      while (i < 6)
      {
        if (i != 5)
        {
          digitalWrite(LED_PIN1, HIGH);
          delay(100);
          digitalWrite(LED_PIN2, LOW);
          delay(100);
          digitalWrite(LED_PIN1, LOW);
          delay(100);
          digitalWrite(LED_PIN2, HIGH);
          delay(100);
          digitalWrite(LED_PIN1, LOW);
          delay(100);
          digitalWrite(LED_PIN2, LOW);
          delay(100);
          i++;
        }
        else
          break;
      }
  }
  irrecv.resume();
}
