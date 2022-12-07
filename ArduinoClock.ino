boolean buttonPressed = false;
int hours = 0;
int minutes = 0;
int seconds = 0;

void setTimer(void);

void setup() {
   pinMode(4, INPUT);
   pinMode(5, INPUT); //setting pins to input
   
   Serial.begin(9600);
   Serial.println("Give hours");
    while(Serial.available()==0)
    {
      // waits till we get numbers
    }
    hours = Serial.parseInt();

    Serial.println("Give minutes");
    while(Serial.available()==0)
    {
      // waits till we get numbers
    }
    minutes = Serial.parseInt();
    Serial.println("Give seconds");
    while(Serial.available()==0)
    {
      // waits till we get numbers
    }
    seconds = Serial.parseInt();
    setTimer();
}

ISR(TIMER1_COMPA_vect){
  if (buttonPressed == true){
    if (seconds == 60)
    {
      seconds = 0;
      minutes++;
    }
    if (minutes == 60)
    {
      minutes = 0;
      hours++;
    }
    seconds++;
  }
  else {
    //do nothing
  }
  
}


void loop(){
    timeController();
    timePrint();
    delay(1000);
}

void setTimer(void){
  noInterrupts(); //disables interrupts for the function

  TCCR1A = 0;
  TCCR1B = 0; //setting the timer/counter1 control registers to 0

  TCCR1B |= (1 << WGM12); // Turns WGM12 bit on, turning the CTC mode on.
  TCCR1B |= (0 << CS10);
  TCCR1B |= (0 << CS11);
  TCCR1B |= (1 << CS12); //By turning CS10 and CS11 off and CS12 on, we turn the prescaler to divide the 16 MHz clock signal with 256. This was selected due to ORC1A register being 16-bit and not being able to hold a larger value

  
  OCR1A = 62500;  //Output Compare Registers given the value of clock ticks made in a second.
  
  TIMSK1 |= (1 << OCIE1A); //Turn on Output Compare Interrupt Enable

  interrupts();
}

void timePrint(){
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.println(seconds);
}

void timeController(void){
  int val = digitalRead(4);
  int val2 = digitalRead(5);
  
  if(val == HIGH){
    if(buttonPressed == false){
      Serial.println("starting the timer");
      buttonPressed = true;
    }
  }
  if(val2 == HIGH){
      if (buttonPressed == true){
      Serial.println("stopping the timer");
      buttonPressed = false;
    }
  }
}
