#include <IRremote.h>

int RECV_PIN = 11;
int LED_PIN1 = 12;
int LED_PIN2 = 13;

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
  }
  irrecv.resume();
}
