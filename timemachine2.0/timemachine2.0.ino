#include "LCD_1602_RUS.h"

LCD_1602_RUS lcd(0x3F, 16, 2);

int sensvalue;
int lighttime=50;
int led_pin=2;
unsigned long flashdelay;
unsigned long timerfinal;
unsigned long timer1;
unsigned long timer2;
int buttonleft=6;
int buttonleftflag=0;
int buttonright=7;
int buttonrightflag=0;
int buttonOK=8;
int buttonOKflag=0;
int flag=0;
int darkreg;
int paddles=1;
int paddlesetmode=0;
int timeregmode=0;
int flashmaregemode=0;
unsigned long lastpressleft;
unsigned long lastpressright;
unsigned long lastpressOK;
int timer=0;
int interruptflag=0;
int lastinterrupt=0;
int donedisplay=0;
int interruptstate=0;
int func1;
int func2;
int func22;

void setup() {
  
  Serial.begin(9600);
  lcd.backlight();
  lcd.init(); 
  pinMode(led_pin, OUTPUT);
  pinMode(3, INPUT);
  pinMode(buttonleft, INPUT);
  pinMode(buttonright, INPUT);
  pinMode(buttonOK, INPUT);
  lcd.setCursor(5, 0);
  lcd.print("Welcome");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please point the");
  lcd.setCursor(1, 1);
  lcd.print("sensor to the");
  delay(3000);
  lcd.clear();
  sensvalue=analogRead(3);
  if(sensvalue < 220 && func1 != 1){
    timer1=micros();
    func1=1;
  }
  if(func1 == 1 && sensvalue < 220 && func2 != 1){
    while(func22 == 0){
      if(analogRead(3) < 220){
        interruptstate=1;
      }
      if(analogRead(3) > 220 && interruptstate == 1){
        interruptstate=2;
      }
      if(analogRead(3) < 220 && interruptstate == 2){
        timer2=micros();
        func2=1;
        interruptstate=3;
        timerfinal = timer2 - timer1;
        func22=1;
      }
    }
    
  } 
    lcd.setCursor(0, 0);
    lcd.print("object in 3");
    delay(1000); 
    lcd.setCursor(0, 0);
    lcd.print("object in 2");
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("object in 1");
    delay(1000);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Please wait");
    paddlesetmode=1; 
    
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Now tell me");
      lcd.setCursor(0, 1);
      lcd.print("paddle quantity");
      delay(3000);
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("<");
      lcd.setCursor(7, 0);
      lcd.print(">");
      
      lcd.setCursor(3, 1);
      lcd.print("Press OK");
    while(paddlesetmode == 1){
      lcd.setCursor(6, 0);
      lcd.print(paddles);
      if(digitalRead(buttonleft) == HIGH && buttonleftflag == 0 && millis() - lastpressleft > 50){ 
        buttonleftflag=1;     
        lastpressleft=millis();
      }
      if(digitalRead(buttonleft) == LOW && buttonleftflag == 1){
        buttonleftflag=0;
        lcd.setCursor(6, 0);
        paddles=paddles - 1;
        lcd.print(paddles);
      }
      if(digitalRead(buttonright) == HIGH && buttonrightflag == 0 && millis() - lastpressright > 50){ 
        buttonrightflag=1;     
        lastpressright=millis();
      }
      if(digitalRead(buttonright) == LOW && buttonrightflag == 1){
        buttonrightflag=0;
        lcd.setCursor(6, 0);
        paddles=paddles + 1;
        lcd.print(paddles);
      }
      if(digitalRead(buttonOK) == HIGH && buttonOKflag == 0 && millis() - lastpressright > 50){ 
        buttonOKflag=1;
        lastpressOK=millis();
      }
      if(digitalRead(buttonOK) == LOW && buttonOKflag == 1){
        buttonOKflag=0;
        donedisplay=1;
        paddlesetmode=2;
      }
      
        
    }
    if(paddlesetmode == 2){
      flashdelay = timerfinal * paddles;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Done! Now you");
      lcd.setCursor(3, 1);
      lcd.print("can enjoy!");
      
    }
    delay(3000);
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Light will turn");
     lcd.setCursor(3, 1);
     lcd.print("on in: 3");     
     delay(1000);
     lcd.clear();
     lcd.print("on in: 2");     
     delay(1000);
     lcd.clear();
     lcd.print("on in: 1");     
     delay(1000);
     lcd.clear();
     lcd.setCursor(5, 0);
     lcd.print("LED ON!");
 }




void loop() {
    
    digitalWrite(led_pin, HIGH);
    delayMicroseconds(lighttime);
    digitalWrite(led_pin, LOW);
    delayMicroseconds(flashdelay);
    Serial.println(flashdelay);
    if(paddlesetmode == 2){
      timeregmode=1;
      if(digitalRead(buttonleft) == HIGH && buttonleftflag == 0 && millis() - lastpressleft > 50 && timeregmode == 1){      
        buttonleftflag=1;
        lastpressleft=millis();
      }
      if(digitalRead(buttonleft) == LOW && buttonleftflag == 1 && timeregmode == 1){
        buttonleftflag=0;
        flashdelay = flashdelay - 1;
      }
      if(digitalRead(buttonright) == HIGH && buttonrightflag == 0 && millis() - lastpressright > 50 && timeregmode == 1){
        buttonrightflag=1;
        lastpressright=millis();
      }
      if(digitalRead(buttonright) == LOW && buttonrightflag == 1 && timeregmode == 1){
        buttonrightflag=0;
        flashdelay = flashdelay + 1;
      }
      
      
    }
  
}
