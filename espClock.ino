#include "GyverEncoder.h"
#include "menu.h"
#include "pinsControl.h"
//#include "menuSetFunctions.h"
#include "clockBig.h"

int value = 0;
//Объект меню


void encoderHandler() {
  //enc1.tick();
  if (enc1.isTurn() or enc1.isPress() or enc1.isRelease() or  enc1.isClick()) {
    timerBacklight = millis();
    menuActive = true;

  }

  if (enc1.isTurn()) {       // если был совершён поворот (индикатор поворота в любую сторону)
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print(value);  // выводим значение при повороте
    Serial.println(value);
    
  };

  if (lineSelected == 0) {
    if (enc1.isRight()) {
      value++;
    };
    if (enc1.isLeft()) {
      value--;// Событие перемещения по списку строк вверх (предыдущая строка)
    };
    if (enc1.isClick()) {
      lineSelected = 1;
      value = 10;
    };
    if (enc1.isRightH()) {
      //  currnum++;// Событие переключения следующего экрана меню (ПРАВЫЙ нажатый поворот энкодера)
    };
    if (enc1.isLeftH()) {
      //  currnum--;// Событие переключения предыдущего экрана меню (ЛЕВЫЙ нажатый поворот энкодера)
    };
  } else if (lineSelected == 1) {
    if (enc1.isRight()) {
      //  currnum++;//Событие для прикрепленной функции 1
    };
    if (enc1.isLeft()) {
      //  currnum--; //Событие для прикрепленной функции 2
    };
    if (enc1.isClick()) {
      //  lineSelected = 0;
      value = 5;
    };
    if (enc1.isRightH()) {
      //menu_main.MakeMenu( 2, 1);  // Событие переключения следующего экрана меню (ПРАВЫЙ нажатый поворот энкодера)
    };
    if (enc1.isLeftH()) {
      //menu_main.MakeMenu( 2, 0); // Событие переключения предыдущего экрана меню (ЛЕВЫЙ нажатый поворот энкодера)
    };
  }
}


void potHandler() {
  if (lineSelected != 1 and potHandlerEnable == true) {
    int potValueLast;

    potValue = analogRead(potPin);
    if (potValueLast != potValue) {
      menuActive = true;
      timerBacklight = millis();
      potValueLast = potValue;
    }
    int percentage = map(potValue, 0, 1023, 0, 100);
    Serial.println(potPin);
    Serial.print("= ");
    Serial.print(percentage);
    //outputValue = map(sensorValue, 0, 1023, 0, 255);
    delay(2);
  }
}


void clockHandler() {
  if (millis() - timerBacklight > BacklightDelay and menuActive == true) {
    lcd.clear();
    menuActive = false;
    lcd.clear();
  }
  //while
  if (menuActive == false) {
    // if(millis() - timer > TimerDelay){}
    if (millis() % 1000 == 0) {                           // если прошла 1 секунда
      DateTime now = rtc.now();
      lcd.setCursor(6, 0);
      lcd.print('.');
      lcd.setCursor(6, 1);
      lcd.print('.');
      /*   lcd.setCursor(13, 0);
         lcd.print('.');
         lcd.setCursor(13, 1);
         lcd.print('.'); */


      uint16_t currSecond = now.second();
      if (currSecond < 10) {
        lcd.setCursor(13, 0);
        lcd.print('.');
        lcd.print('0');
        lcd.print(now.second(), DEC);
      } else {
        lcd.setCursor(13, 0);
        lcd.print('.');
        lcd.print(now.second(), DEC);
      }
      bigNum.displayLargeInt(now.minute(), 7, 0, 2, true);
      bigNum.displayLargeInt(now.hour(), 0, 0, 2, true);

      /*  Serial.println(now.minute());
        Serial.println(now.hour());
        Serial.println(now.day());
        Serial.println(now.month());
        Serial.println(now.year()); */

      lcd.setCursor(14, 1);
      lcd.print(round(rtc.getTemperature() - 5));

    }
  }
}


void setup () {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT);
  pinMode(bulbPin, OUTPUT);
  digitalWrite(bulbPin, LOW);
  pinMode(ledPin, OUTPUT);
  //analogWrite(ledPin , ledValue);

  lcd.clear(); // clear display
  lcd.init(); // setup LCD rows and columns
  lcd.backlight();
  bigNum.begin(); // set up BigNumbers
  clockSetup();
  enc1.setTickMode(AUTO);
  lcd.clear(); // clear display

  //Обновляем информацию на экране
  menuActive = true;
  timerBacklight = millis();
}




void loop () {
  //enc1.tick();
  digitalWrite(ledPin, HIGH);
  encoderHandler();
  //potHandler();
  clockHandler();


}
