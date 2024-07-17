#include <LiquidCrystal.h>
#include <Keypad.h> 

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const byte ROWS = 4; //число строк лавиатуры
const byte COLS = 4; //число столбцов клавиатуры

// создаем массив с названиями клавиш клавиатуры

char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

//создаем выводы 

byte rowPins[ROWS] = {8, 0, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad (makeKeymap (keys), rowPins,
                              colPins, ROWS, COLS);

//задаем матрицы для информационных символов, 
//синдрома и декомбинатора синдрома

bool a[4], c[4], s[4], d[5];
byte i = 0;
int r;

//задаем параметры дисплея 
 
void setup () 
{
  lcd.begin (16, 2);
  //Serial.begin(9600); 
}

void loop () 
{  
  r = 0;
  i = 0;
  
  char customKey = customKeypad.getKey ();
  
  if (customKey)
  {
    lcd.clear ();
    
    //ввод вектора
    
    while (r == 0)
    {
      customKey = customKeypad.getKey ();
      
      if (customKey)
      {  
        
      if (customKey == '1')
      {
        a[i] = true;
        lcd.print (a[i]);
        i++;
      }
        
      else if (customKey == '0')
      {
        a[i] = false;
        lcd.print (a[i]);
        i++;
      }
        
      if(i == 4)
        break;
        
      }
    }
    
    //формирование избыточной части
    
    c[0] = a[0] xor a[1] xor a[2];
    c[1] = a[1] xor a[2] xor a[3];
    c[2] = a[0] xor a[2] xor a[3];
    c[3] = a[0] xor a[1] xor a[3];
    
    lcd.print (" ");
    
    for(i = 0; i < 4; i++)
      lcd.print (c[i]);
    
    lcd.print (" ");
    
    //внедрение ошибки
    while (r == 0)
    {
      customKey = customKeypad.getKey ();
      
      if (customKey == '1')
      {
        a[0] = !a[0];
        lcd.print ("1");
      }
      
      if (customKey == '2')
      {
        a[1] = !a[1];
        lcd.print("2");
      }
      
      if(customKey == '3')
      {
        a[2] = !a[2];
        lcd.print("3");
      }
      
      if(customKey == '4')
      {
        a[3] = !a[3];
        lcd.print("4");
      }

      if (customKey == 'A'){
        lcd.print("");
        break;}
    }
     
    for (i = 0; i < 4; i ++)
      lcd.print (a[i]);
    
    lcd.print (" ");
    
	lcd.setCursor (0, 1);
    
     //формирование синдрома
    
     s[0] = a[0]  xor a[1] xor a[2] xor c[0];
     s[1] = a[1] xor a[2] xor a[3] xor c[1];
     s[2] = a[0] xor a[2] xor a[3] xor c[2];
     s[3] = a[0]xor a[1] xor a[2] xor a[3]
       		xor c[0] xor c[1] xor c[2] xor c[3];
    
     for(i = 0; i < 4; i++)
       lcd.print(s[i]);
    
     //декомбинатор синдрома
    
     d[0] = s[0] && !s[1] && s[2] && s[3];
     d[1] = s[0] && s[1] && !s[2] && s[3];
     d[2] = s[0] && s[1] && s[2] && s[3];
     d[3] = !s[0] && s[1] && s[2] && s[3];
     d[4] = (s[0] || s[1] || s[2]) && !s[3];
    
     lcd.print (" ");
    
     for(i = 0; i < 5; i++)
       lcd.print (d[i]);
    
     lcd.print (" ");
    
     //исправление/стирание и вывод полученного сообщения на экран
    
     for(i = 0; i < 4; i++)
       lcd.print ((d[i] xor a[i]) && !d[4]);
  }
}
