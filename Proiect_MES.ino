#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  lcd.setCursor(0,0);
  Serial.begin(9600);
  lcd.print("Detector de gaze");
}
 
void loop() {
  int mq3 = analogRead(A0);
  int mq9 = analogRead(A1);
  int mq2 = analogRead(A2);
  int mq6 = analogRead(A3);

  //400
  lcd.setCursor(0,1);
  if (mq3 > 450) 
  {
    lcd.setCursor(0,1);
    lcd.print("MQ3 HIGH");
    lcd.setCursor(10, 1);
    lcd.print("ALCHOOL");
    lcd.setCursor(0, 2);
    lcd.print("METANOL");
    lcd.setCursor(0, 3);
    lcd.print("FUM");
    Serial.println("MQ3");
    Serial.print(mq3);
  }
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Detector de gaze"); 

  //100
  lcd.setCursor(0,1);
  if (mq9 > 400) 
  {
    lcd.print("MQ9 HIGH        ");
    lcd.setCursor(0, 2);
    lcd.print("MONOXID CARBON  ");
    Serial.println("MQ9");
    Serial.println(mq9);
  }
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Detector de gaze");

  //400
  if (mq2 > 450) 
  {
    lcd.setCursor(0,1);
    lcd.print("MQ2 HIGH");
    lcd.setCursor(10, 1);
    lcd.print("METAN");
    lcd.setCursor(0, 2);
    lcd.print("BUTAN");
    lcd.setCursor(0, 3);
    lcd.print("FUM");
    Serial.println("MQ2");
    Serial.println(mq2);
  }
  
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Detector de gaze");

  //300
  if (mq6 > 400) 
  {
    lcd.setCursor(0,1);
    lcd.print("MQ6 HIGH");
    lcd.setCursor(0, 2);
    lcd.print("GPL");
    lcd.setCursor(0, 3);
    lcd.print("BUTAN");
    Serial.println("MQ6");
    Serial.print(mq6);    
  }
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Detector de gaze");
}
/*
mq3 => Alchool, Metanol, Fum
mq9 => Monoxid de carbon, Gaze inflamabile
mq2 => Metan, Butan, GPL, Fum
mq6 => Butan, GPL    
*/
