#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*************************************************************************
LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT
*************************************************************************/
byte smile1_left [8] = 
{
    B00000,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
};

byte smile2_left [8] = 
{
    B01111,
    B00000,
    B00000,
    B00000,
    B00000,
    B10000,
    B01111,
    B00000,
};

byte smile3_left [8] = 
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B10000,
    B01100,
    B00011,
};

byte smile4_left [8] = 
{
    B00000,
    B10000,
    B11000,
    B10100,
    B10010,
    B10001,
    B01000,
    B01000,
};

byte smile5_left [8] = 
{
    B00100,
    B00010,
    B00001,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
};

byte smile6_left [8] = 
{
    B00000,
    B00000,
    B00000,
    B10000,
    B01100,
    B00011,
    B00000,
    B00000,
};

byte smile7_left [8] = 
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B10000,
};

byte smile8_left [8] = 
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
};
/*************************************************************************
LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT_LEFT
*************************************************************************/

/****************************************************************************
RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT
****************************************************************************/
byte smile1_right [8] = 
{
    B00000,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
};

byte smile2_right [8] = 
{
    B11110,
    B00000,
    B00000,
    B00000,
    B00000,
    B00001,
    B11110,
    B00000,
};

byte smile3_right [8] = 
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00001,
    B00110,
    B11000,
};

byte smile4_right [8] = 
{
    B00000,
    B00001,
    B00011,
    B00101,
    B01001,
    B10001,
    B00010,
    B00010,
};

byte smile5_right [8] = 
{
    B00100,
    B01000,
    B10000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
};

byte smile6_right [8] = 
{
    B00000,
    B00000,
    B00000,
    B00001,
    B00110,
    B11000,
    B00000,
    B00000,
};

byte smile7_right [8] = 
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00001,
};
byte smile8_right [8] = 
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
};
/****************************************************************************
RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT_RIGHT
****************************************************************************/

void setup()
{
  	lcd.begin(32,4);
}

void smile_left()
{
    lcd.clear();
    lcd.createChar(1, smile1_left);
    lcd.createChar(2, smile2_left);
    lcd.createChar(3, smile3_left);
    lcd.createChar(4, smile4_left);
    lcd.createChar(5, smile5_left);
    lcd.createChar(6, smile6_left);
    lcd.createChar(7, smile7_left);
    lcd.createChar(8, smile8_left);
    lcd.setCursor(7,1);
    lcd.write(byte(1));
    lcd.setCursor(6,0);
    lcd.write(byte(7));
    lcd.setCursor(6,1);
    lcd.write(byte(2));
    lcd.setCursor(5,0);
    lcd.write(byte(3));
    lcd.setCursor(4,0);
    lcd.write(byte(4));
    lcd.setCursor(4,1);
    lcd.write(byte(5));
    lcd.setCursor(5,1);
    lcd.write(byte(6));
/*
    lcd.setCursor(8,1);
    lcd.write(byte(8));
    lcd.setCursor(9,0);
    lcd.write(byte(8));
    lcd.setCursor(9,1);
    lcd.write(byte(8));
    lcd.setCursor(10,0);
    lcd.write(byte(8));
    lcd.setCursor(11,0);
    lcd.write(byte(8));
    lcd.setCursor(11,1);
    lcd.write(byte(8));
    lcd.setCursor(10,1);
    lcd.write(byte(8));*/
}

void smile_right() 
{ 
    lcd.clear();
    lcd.createChar(1, smile1_right);
    lcd.createChar(2, smile2_right);
    lcd.createChar(3, smile3_right);
    lcd.createChar(4, smile4_right);
    lcd.createChar(5, smile5_right);
    lcd.createChar(6, smile6_right);
    lcd.createChar(7, smile7_right);
    lcd.createChar(8, smile8_right);
    lcd.setCursor(8,1);
    lcd.write(byte(1));
    lcd.setCursor(9,0);
    lcd.write(byte(7));
    lcd.setCursor(9,1);
    lcd.write(byte(2));
    lcd.setCursor(10,0);
    lcd.write(byte(3));
    lcd.setCursor(11,0);
    lcd.write(byte(4));
    lcd.setCursor(11,1);
    lcd.write(byte(5));
    lcd.setCursor(10,1);
    lcd.write(byte(6));
/*
    lcd.setCursor(7,1);
    lcd.write(byte(8));
    lcd.setCursor(6,0);
    lcd.write(byte(8));
    lcd.setCursor(6,1);
    lcd.write(byte(8));
    lcd.setCursor(5,0);
    lcd.write(byte(8));
    lcd.setCursor(4,0);
    lcd.write(byte(8));
    lcd.setCursor(4,1);
    lcd.write(byte(8));
    lcd.setCursor(5,1);
    lcd.write(byte(8));*/
}



void loop() 
{
    delay(10);
    smile_left();
    delay(10);
    smile_right();
}
  
