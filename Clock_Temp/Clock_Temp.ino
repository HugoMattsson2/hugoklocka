
// By Hugo Mattsson
#include<RTClib.h>
#include <Wire.h>
#include "U8glib.h"
#include "Servo.h"
char t[32];

const int buttonPin = 3;
int buttonPresses = 0;
int number = 0;

DateTime now;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);
RTC_DS3231 rtc;
Servo myservo;
#define servoPin 9

void setup() {
Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    u8g.setFont(u8g_font_unifont);
  pinMode(buttonPin, INPUT);
  for(int i= 4; i <= 6; i++){
    pinMode(i, OUTPUT);
  myservo.attach(servoPin);
  }
}

int lastButtonState = LOW;
unsigned long lastDebounceTime = 0; 
const unsigned long debounceDelay = 0; 
void loop() {
  now = rtc.now();

  oledWrite(getTime(), getTemp());
  servoWrite(getTemp());

  int reading = digitalRead(buttonPin);

    if (reading != lastButtonState) {
      lastButtonState = reading;

      if (reading != LOW) {
        buttonPresses += 1;
      }
    }
}

String getTime(){
DateTime now = rtc.now();
  sprintf(t, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());  
  Serial.print(F("The time is: "));
  Serial.println(t);
  delay(200);

  Serial.println(getTemp());

}

float getTemp(){

int Vo;
float R1 = 10000;
float logR2;
float R2;
float T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;

Vo = analogRead(A0);
R2 = R1 * (1023.0 / (float)Vo - 1.0);
logR2 = log(R2);
T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
T = T - 273.15;

return T;
}

void oledWrite(String time, float temp){
  String temp_str = String(temp,2);
    String button_str = "Presses: " + String(buttonPresses); 

  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(10, 20, time.c_str());
    u8g.drawStr(10, 40, "Temp: ");

    u8g.drawStr(50, 40, temp_str.c_str());
    u8g.drawStr(10, 60, button_str.c_str()); 



  } while (u8g.nextPage());
}


void servoWrite(float temperature){
  myservo.write(temperature);
}
