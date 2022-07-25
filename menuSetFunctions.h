
//Примеры простейших внешних функций:
//*************************Lights*********************
void ledOn1 () {
  bulbValue = 1;
  digitalWrite(bulbPin, bulbValue);
}
void ledOff1 () {
  bulbValue = 0;
  digitalWrite(bulbPin, bulbValue);
}


//*************Led screen*************************

void brigh_upLed1 () {
  analogWrite(ledPin, ledBrigh);
  ledBrigh += 10;
  ledBrigh = constrain (ledBrigh, 0, 250);
}
void brigh_downLed1 () {
  analogWrite(ledPin, ledBrigh);
  ledBrigh -= 10;
  ledBrigh = constrain (ledBrigh, 0, 250);
}


//**********************Screen 4**********************

void LcdLightOn() {
  flag = 1;
  lcd.setBacklight(flag);
  flagind = flag;
}
void LcdLightOff() {
  flag = 0;
  lcd.setBacklight(flag);
  flagind = flag;
}
