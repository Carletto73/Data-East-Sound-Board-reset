int sensorValue = 0;
int busy_level = 0;
int old_busy_level = 0;
int counter_busy_level = 0;
#define LED_BUILTIN 1
#define RESET_SOUND_BOARD 2
#define ANALOG_INPUT_U20 4

void setup()
{
  pinMode(ANALOG_INPUT_U20, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RESET_SOUND_BOARD, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(RESET_SOUND_BOARD, LOW);
}

void loop()
{
  sensorValue = analogRead(2); // THIS IS P4, P4 is analog input 2, so when you are using analog read, you refer to it as 2.

  if (sensorValue > 360)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RESET_SOUND_BOARD, HIGH);
    delay(100);
    digitalWrite(RESET_SOUND_BOARD, LOW);
    busy_level = 4;
  }
  else if (sensorValue > 270)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    busy_level = 3;
  }
  else if (sensorValue > 180)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    busy_level = 2;
  }
  else if (sensorValue > 90)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    busy_level = 1;
  }
  else
  {
    busy_level = 0;
  }

  delay(1000);
  if (old_busy_level != busy_level)
  {
    counter_busy_level = 0;
  }
  else
  {
    counter_busy_level = counter_busy_level + 1;
  }
  if (counter_busy_level > 60)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RESET_SOUND_BOARD, HIGH);
    delay(100);
    digitalWrite(RESET_SOUND_BOARD, LOW);
    delay(1000);
    counter_busy_level = 0;
  }
  old_busy_level = busy_level;
}
