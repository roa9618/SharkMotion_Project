int Buzzer_Pin = 8;
int Tones[7] = {261, 294, 330, 349, 392, 440, 494};
int Tones_Number;

void setup()
{
  
}

void loop()
{
  for (Tones_Number = 0; Tones_Number < 7; Tones_Number++)
  {
    tone(Buzzer_Pin, Tones[Tones_Number]);
    delay(500);
  }
  noTone(Buzzer_Pin);

  delay(1000);
}
