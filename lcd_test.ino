#include <LiquidCrystal.h>

#define HEALTH_LED 13

LiquidCrystal lcd(4,5,6,7,8,9);

void setup()
{
 pinMode(HEALTH_LED, OUTPUT);
 lcd.begin(16,2);
 lcd.clear(); 
}

void PrintStringToLCD(String strText, int xPos, int yPos)
{
  lcd.setCursor(yPos, xPos);
  lcd.print(strText);
}

void PrintIntToLCD(int nNum, int nPosX, int nPosY)
{
  lcd.setCursor(nPosY, nPosX);
  lcd.print(nNum);
} 

void loop()
{
  PrintStringToLCD("Hello World", 0, 0);
  PrintIntToLCD(12345, 1, 0);
  
  int i = 0;
  for(i = 0; i < 5; i++)
  {
   digitalWrite(HEALTH_LED, HIGH);
   delay(1000);
   digitalWrite(HEALTH_LED, LOW);
   delay(1000);
  }
 }
