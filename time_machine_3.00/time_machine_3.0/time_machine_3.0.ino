#include "LCD_1602_RUS.h"

LCD_1602_RUS lcd(0x3F, 16, 2);
long timerfinal;
long timer=0;
long lasttime=0;
float flashdelayf;
int flashdelayl;
int func1=0;
int func2=0;
int buttonleft=2;
int buttonright=3;
int buttonOK=4;
int paddlesetmode=0;
int paddles=1;
unsigned long lastpressleft;
unsigned long lastpressright;
unsigned long lastpressOK;
int buttonleftflag=0;
int buttonrightflag=0;
int buttonOKflag=0;
int led_pin=5;
int lighttime=200;




void setup() {
  Serial.begin(9600);
  lcd.backlight();
  lcd.init();
  Serial.begin(9600);
  lcd.backlight();
  lcd.init(); 
  pinMode(led_pin, OUTPUT);
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
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("object.");  
  delay(2000);
  while(func1 == 0){
    if(digitalRead(6) == 1 && func2 == 0){
      
      func2=1;
      
    }
    if(digitalRead(6) == 0 && func2 == 1){
      func2=2;
      lasttime = millis();
      Serial.println("lastflash");
    }
    if(digitalRead(6) == 1 && func2 == 2){
      func2=4;
    }
    if(digitalRead(6) == 0 && func2 == 4){
      Serial.println("flash");
      timerfinal = millis() - lasttime;
      func2=5;
      func1=1;
       
    }
  }
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Please wait");
  /*
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
        paddlesetmode=2;
      }        
    }
    if(paddlesetmode == 2){
      //flashdelayl = timerfinal * paddles;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Done! Now you");
      lcd.setCursor(3, 1);
      lcd.print("can enjoy!");     
    }
    */
    //flashdelayl = round(flashdelayf / 1000);
    delay(3000);
    lcd.clear();
    lcd.print("LED ON!");
    lcd.setCursor(3, 1);
    lcd.print(timerfinal);
}

void loop() {
  while(digitalRead(4) == HIGH){
    digitalWrite(5, HIGH);
    delayMicroseconds(lighttime);
    digitalWrite(5, LOW);
    delay(timerfinal);
    if(digitalRead(buttonleft) == HIGH && buttonleftflag == 0 && millis() - lastpressleft > 50){ 
        buttonleftflag=1;     
        lastpressleft=millis();
      }
      if(digitalRead(buttonleft) == LOW && buttonleftflag == 1){
        buttonleftflag=0;
        timerfinal=timerfinal - 1;
        lcd.setCursor(3, 1);
        lcd.print(timerfinal);
      }
    if(digitalRead(buttonright) == HIGH && buttonrightflag == 0 && millis() - lastpressright > 50){ 
        buttonrightflag=1;     
        lastpressright=millis();
      }
      if(digitalRead(buttonright) == LOW && buttonrightflag == 1){
        buttonrightflag=0;
        timerfinal=timerfinal + 1;
        lcd.setCursor(3, 1);
        lcd.print(timerfinal);
      }
  }
}



















  
