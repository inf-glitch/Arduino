#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

short photores_volt;
short light_intensity;
short order_volume ;
bool flag;

void setup()
{
  pinMode (5, OUTPUT);
  Serial.begin (1200);
  lcd.begin(16, 2);
  lcd.print ("Say your order");
  //delay (5000);
}

void loop()
{
  lcd.setCursor(0, 1);
  photores_volt = analogRead (A0);
  light_intensity = photores_volt / 4;
  analogWrite (5, light_intensity);
  
  if (Serial.available () != 0 && flag == false) {
    String order = Serial.readString ();
    //Serial.println ("data sent");    
    if (order == "odd") {
      Serial.println ("Odd data sent");
      lcd.clear ();
      lcd.print ("Can't do...");
    }
    
    else {
      Serial.println ("data sent");
      lcd.clear ();
      lcd.print (order);
      lcd.setCursor (0, 1);
      lcd.print ("will be soon!");
    flag = true;
  	}
    
  }
  
}