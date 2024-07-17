#include "Wire.h"
#include "SFE_BMP180.h"
#include <LiquidCrystal.h>
#include <MQ2.h>  // библиотека для датчика

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SFE_BMP180 pressure; // создаем объект pressure

#define PIN_MQ2 A0    // имя пина для подключения MQ2
#define ALTITUDE 171.0 // высота офиса SparkFun, штат Колорадо, в метрах

//-----------------------------------------------------------------
MQ2 mq2(PIN_MQ2);   // создаём объект для работы с датчиком
int lpg, co;
float smoke;
double T, p0;
//----------------------------------------------------------------

byte C_degree [8] = {
  	B11000,
  	B11000,
  	B00110,
  	B01001,
  	B10000,
  	B10000,
  	B01001,
  	B00110,
	};

void setup(){
  Serial.begin(9600);  // запускаем монитор порта
  lcd.begin(20, 4);
  pressure.begin();     // запускаем датчик давления
  mq2.begin();
  lcd.createChar(1, C_degree);
}

void gas_measure () {
  float* values = mq2.read(true);

   // получаем информацию с датчика
   // выводим данные на монитор порта
  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();
  //  Serial.println("lpg = ",lpg, "smoke =  ", smoke, "co = ", co);
  //  Serial.println(co);
  //  Serial.println(smoke);
  
  // включаем светодиод при превышении концентрации CO
  //  if (co > 1000) { digitalWrite(LED, HIGH); }
  //  else { digitalWrite(LED, LOW); }

  //  delay(200);
}

void meteo()
{
  char status;
  double P,a;

   // для точного измерения, следует знать высоту, на которой производятся замеры
   // в этом примере используется константа ALTITUDE
  //  Serial.println();
  //  Serial.print("provided altitude: ");
  //  Serial.print(ALTITUDE,0);
  //  Serial.println(" meters");
  
   // перед измерением давления, следует узнать температуру
   // если запрос успешен, то возвращается время ожидания в миллисекундах
   // если запрос на измерение температуры не успешен, то возвращается 0
   status = pressure.startTemperature();
   if (status != 0){
      delay(status);

      // результат измерения температуры сохраняется в переменной T
      status = pressure.getTemperature(T);
      if (status != 0){
         Serial.print("temperature: ");
         Serial.print(T,2);
         Serial.println(" deg C");

         // запускаем измерение давления
         // если запрос успешен, возвращается время ожидания в миллисекундах
         // если запрос на измерение давления не успешен, возвращается 0
         status = pressure.startPressure(3);
         if (status != 0){
            delay(status);

            status = pressure.getPressure(P,T);
            if (status != 0){
              //  Serial.print("absolute pressure: ");
              //  Serial.print(P,2);
              //  Serial.print(" mb, ");
              //  Serial.print(P*0.0295333727,2);
              //  Serial.println(" inHg");

              // датчик bmp180 возвращает абсолютное давление, которое зависит от высоты
              // параметры: P = абсолютное давление в мб, ALTITUDE = текущая высота в м.
              // результат: p0 = давление с компенсацией на уровне моря в мбар
              p0 = pressure.sealevel(P,ALTITUDE);
              Serial.print("relative (sea-level) pressure: ");
              Serial.print(p0,2);
              Serial.print(" mb, ");
              Serial.print(p0*0.750062,2);
              Serial.println(" inHg");
           }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");

  // delay(1000);
}

void lcd_printout () {
  lcd.clear ();
  lcd.setCursor(0,1);
  lcd.print("temperature: ");
  lcd.print(T);
  lcd.print(" ");
  lcd.write(byte(1));
  lcd.setCursor(0,2);
  lcd.print("pressure: ");
  lcd.print(p0*0.750062,1);
  lcd.print(" mmHg");
  lcd.setCursor (0, 3);
  lcd.print ("SMOKE: ");
  lcd.print (smoke * 100000);
  lcd.print (" ppm");
}

void loop()
{
  meteo();
  gas_measure ();
  lcd_printout ();
  delay (2000);
}