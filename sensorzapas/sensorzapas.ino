sensvalue=digitalRead(sensorpin);
  if(sensvalue == 0 && func1 != 1){
    timer1=micros();
    func1=1;
  }
  if(func1 == 1 && sensvalue == 0 && func2 != 1){
    while(func22 == 0){
      while(digitalRead(sensorpin) == 0){
        interruptstate=1;
      }
      if(digitalRead(sensorpin) == 1 && interruptstate == 1){
        interruptstate=2;
      }
      if(digitalRead(sensorpin) == 0 && interruptstate == 2){
        timer2=micros();
        func2=1;
        func22=1;
        interruptstate=3;
        timerfinal = timer2 - timer1; 
      }
    }  
  } 
  if(sensvalue == 1 && func1 != 1){
    timer1=micros();
    func1=1;
  }
  if(func1 == 1 && sensvalue == 1 && func2 != 1){
    while(func22 == 0){
      while(digitalRead(sensorpin) == 01){
        interruptstate=1;
      }
      if(digitalRead(sensorpin) && interruptstate == 1){
        interruptstate=2;
      }
      if(digitalRead(sensorpin) && interruptstate == 2){
        timer2=micros();
        func2=1;
        func22=1;
        interruptstate=3;
        timerfinal = timer2 - timer1; 
      }
    }  
  }
