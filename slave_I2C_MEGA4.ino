
#include <Wire.h>                                     // подключаем библиотеку для работы с шиной I2C
#include <iarduino_I2C_connect.h>                     // подключаем библиотеку для соединения arduino по шине I2C
// Объявляем переменные и константы:
iarduino_I2C_connect I2C2;                            // объявляем переменную для работы c библиотекой iarduino_I2C_connect
          
      int            adc0 = 0;           
      int            adc1 = 0;               
      int            adc2 = 0;            
      int            adc3 = 0;           
      int            adc4 = 0;              
      int            adc5 = 0;                  
      
      byte           i2cdata[12];              // объявляем массив, данные которого будут доступны для чтения/записи по шине I2C

void setup(){

  Wire.begin(0x02);                          // инициируем подключение к шине I2C в качестве ведомого (slave) устройства, с указанием своего адреса на шине.
  I2C2.begin(i2cdata);                       // инициируем возможность чтения/записи данных по шине I2C, из/в указываемый массив
}

void loop(){

  adc0 = analogRead(A0);    
  adc1 = analogRead(A1);    
  adc2 = analogRead(A2);    
  adc3 = analogRead(A3);    
  adc4 = analogRead(A4);    
  adc5 = analogRead(A5);  
  
  
  i2cdata[0]    = adc0>>8;      // Сохраняем старший байт значения adc0 в 1 byte i2cdata[12];
  i2cdata[1]    = adc0;         // Сохраняем младший байт значения adc0 в 2 byte i2cdata[12]; 
  i2cdata[2]    = adc1>>8;      // Сохраняем старший байт значения adc1 в 3 byte i2cdata[12];
  i2cdata[3]    = adc1;         // Сохраняем младший байт значения adc1 в 4 byte i2cdata[12];
  i2cdata[4]    = adc2>>8;      // Сохраняем старший байт значения adc2 в 5 byte i2cdata[12];
  i2cdata[5]    = adc2;         // Сохраняем младший байт значения adc2 в 6 byte i2cdata[12];
  i2cdata[6]    = adc3>>8;      // Сохраняем старший байт значения adc3 в 7 byte i2cdata[12];
  i2cdata[7]    = adc3;         // Сохраняем младший байт значения adc3 в 8 byte i2cdata[12]; 
  i2cdata[8]    = adc4>>8;      // Сохраняем старший байт значения adc4 в 9 byte i2cdata[12];
  i2cdata[9]    = adc4;         // Сохраняем младший байт значения adc4 в 10 byte i2cdata[12];
  i2cdata[10]   = adc5>>8;      // Сохраняем старший байт значения adc5 в 11 byte i2cdata[12];
  i2cdata[11]   = adc5;         // Сохраняем младший байт значения adc5 в 12 byte i2cdata[12];

}
