volatile int timerfinal;
volatile unsigned long timer1=0;
volatile unsigned long timer2=0;
volatile int interruptflag=0;
volatile int func1;
volatile int func2;
volatile unsigned long timecountmode=0;
volatile int interruptstate=0;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  
  if(timecountmode == 0){
    attachInterrupt(1, sensor2, FALLING);
    if(func2 == 1){
      
      noInterrupts();
      attachInterrupt(1, sensor1, FALLING);
    }
    
    if(func1 == 1){
      
      noInterrupts();
    }
    timerfinal=timer2-timer1;
    
  }
  Serial.println(timerfinal);
}
void sensor1(){  
  timer1=micros();
  func1=1;
}
void sensor2(){
  while(digitalRead(3) == 1){
    while(digitalRead(3) == 0){
    interruptstate=1;
    }
  }
  
  if(digitalRead(3) == 1 && interruptstate == 1){
    timer2=micros();
    func2=1;
  }
  
}
  
