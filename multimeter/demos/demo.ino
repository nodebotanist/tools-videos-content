byte pwmPowerLevel = 0;
bool upswing = true;
int digitalPowerLevel = 0;
int digitalPowerCounter = 0;

void setup()
{
	pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  if (upswing) {
    pwmPowerLevel += 5;
  } else {
    pwmPowerLevel -= 5;    
  }
  if (pwmPowerLevel >= 255) {
    upswing = false;
  } else if (pwmPowerLevel <= 0) {
    upswing = true;
  }
  analogWrite(3, pwmPowerLevel);

  digitalPowerCounter += 1;
  if(digitalPowerCounter >= 51) {
    digitalPowerCounter = 0;
    if(digitalPowerLevel == 0){
      digitalPowerLevel = 1;
    } else {
      digitalPowerLevel = 0;
    }
    digitalWrite(2, digitalPowerLevel);
  }
  delay(20);
}
