#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 6
#define DIO 7

#define TEST_DELAY   2000

TM1637Display display(CLK, DIO);
int Led_1_green = 13; 
int Led_1_yelow = 12; 
int Led_1_red = 11; 
int Led_2_green = 10;
int Led_2_red = 9;
int switch_pin=8;
boolean last_buttom= LOW;
boolean LedOn=false;


void setup() {
  pinMode(Led_1_green, OUTPUT);
 pinMode(Led_1_yelow,OUTPUT);
 pinMode(Led_1_red,OUTPUT);
 pinMode(Led_2_green,OUTPUT);
 pinMode(Led_2_red,OUTPUT);
 pinMode(switch_pin,INPUT);
}

void loop() {
  display.setBrightness(0x0f);

  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
 digitalWrite(Led_1_green, HIGH);
 digitalWrite(Led_2_red, HIGH);
 display.showNumberDec(15, false, 3, 1);
 
 if (digitalRead(switch_pin)==HIGH ){
  for (int i = 15 ;i>=0;i--){
    display.showNumberDec(i, false, 3, 1);
    delay(1000);
  }
  for (int i =0;i<3;i++){
   digitalWrite(Led_1_green, HIGH);
   delay(1000);
   digitalWrite(Led_1_green, LOW);
   delay(1000);
  }
  digitalWrite(Led_1_yelow, HIGH);
  delay(5000);
  digitalWrite(Led_1_yelow, LOW);
  digitalWrite(Led_1_red, HIGH);
  digitalWrite(Led_2_red, LOW);
  digitalWrite(Led_2_green, HIGH);
  delay(10000);
  for (int i =0;i<3;i++){
   digitalWrite(Led_2_green, HIGH);
   delay(1000);
   digitalWrite(Led_2_green, LOW);
   delay(1000);
  }
  digitalWrite(Led_2_red, HIGH);
  digitalWrite(Led_1_red, LOW);
  
  digitalWrite(Led_1_yelow, HIGH);
  delay(5000);
  digitalWrite(Led_1_yelow, LOW);
 }

}
