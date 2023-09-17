#include <Wire.h>
#include <TaskScheduler.h>
#include <iarduino_I2C_connect.h>               // подключаем библиотеку для соединения arduino по шине I2C
#include "Adafruit_ST7735.h"
#include "display.h"

#if DISP1_ACTIVE && defined DISP1_USE_ST7735_SPI
 Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
#endif

#define EGT1_LED 3  //pwm
#define EGT2_LED 5  //pwm
#define EGT3_LED 6  //pwm
#define EGT4_LED 9  //pwm
#define EGT5_LED 10 //pwm
#define EGT6_LED 11 //pwm

// Объявляем переменные и константы:
iarduino_I2C_connect I2C2;                      // объявляем переменную для работы c библиотекой iarduino_I2C_connect

void driveDisplay();

 int adc0, adc1, adc2, adc3, adc4, adc5;  


Scheduler ts;


void setup() { //VOID SETUP ()

 initialise_display();     
  Wire.begin();                // Инициализация I2C 

pinMode(EGT1_LED, OUTPUT);
pinMode(EGT2_LED, OUTPUT);
pinMode(EGT3_LED, OUTPUT);
pinMode(EGT4_LED, OUTPUT);
pinMode(EGT5_LED, OUTPUT);
pinMode(EGT6_LED, OUTPUT);

pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT_PULLUP);
pinMode(A5, INPUT_PULLUP);
pinMode(A6, INPUT);
pinMode(A7, INPUT);
 
}

void loop() {

ts.execute();

 //Считываем данные:
 adc0  = I2C2.readByte(0x02,0)<<8;   // Считываем старший байт значения потенциометра ведомого (адрес ведомого 0x02, номер элемента 1), сдвигаем полученный байт на 8 бит влево, т.к. он старший
 adc0 += I2C2.readByte(0x02,1);      // Считываем младший байт значения потенциометра ведомого (адрес ведомого 0x02, номер элемента 2), добавляя его значение к ранее полученному старшему байту
 adc1  = I2C2.readByte(0x02,2)<<8;  // Считываем старший байт значения потенциометра ведомого (адрес ведомого 0x02, номер элемента 3), сдвигаем полученный байт на 8 бит влево, т.к. он старший
 adc1 += I2C2.readByte(0x02,3);     // Считываем младший байт значения потенциометра ведомого (адрес ведомого 0x02, номер элемента 4), добавляя его значение к ранее полученному старшему байту
 adc2  = I2C2.readByte(0x02,4)<<8;  // Считываем старший байт значения потенциометра ведомого (адрес ведомого 0x02, номер элемента 5), сдвигаем полученный байт на 8 бит влево, т.к. он старший
 adc2 += I2C2.readByte(0x02,5);     // Считываем младший байт значения потенциометра ведомого (адрес ведомого 0x02, номер элемента 6), добавляя его значение к ранее полученному старшему байту
 adc3  = I2C2.readByte(0x02,6)<<8;   
 adc3 += I2C2.readByte(0x02,7);      
 adc4  = I2C2.readByte(0x02,8)<<8;  
 adc4 += I2C2.readByte(0x02,9);     
 adc5  = I2C2.readByte(0x02,10)<<8;  
 adc5 += I2C2.readByte(0x02,11); 

}

void driveDisplayTask() {

driveDisplay();
}

Task t1(10, TASK_FOREVER, &driveDisplayTask, &ts, true);
