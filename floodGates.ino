int pos  = 0;
int val = 0;
int gate = LOW;

int waterH = 6;
int waterM = 5;

int redLED = 2;
int redState = LOW;
int oraLED = 3;
int oraState = LOW;

int openGate = 48;
int closeGate = 150;

void setup() {
  pinMode(waterH, INPUT);
  pinMode(waterM, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(oraLED, OUTPUT);
  pinMode(9, OUTPUT);
  for (byte i = openGate; i < closeGate; i++) { 
      servo_pwm(i,9);              
    }
 digitalWrite(9, HIGH);
}

void loop() {
  if (!digitalRead(waterH) == HIGH) {
    RED();
  } else if (!digitalRead(waterM) == HIGH) {
    redState = LOW;
    ORANGE();
  } else {
    redState = LOW;
    oraState = LOW;
  }

  GATE();
}


void GATE() {
  if (redState == HIGH && gate == LOW) {
    gate = HIGH;
    for (byte i = closeGate; i > openGate; i--) { 
      servo_pwm(i,9);              
    }
  } else if(redState == LOW && gate == HIGH) {
    gate = LOW;
    for (byte i = openGate; i < closeGate; i++) { 
      servo_pwm(i,9);              
    }
  }
  digitalWrite(redLED, LOW) ; 
  digitalWrite(oraLED, LOW) ; 
}



void RED() {
  redState = HIGH;
  digitalWrite(redLED, HIGH);
  digitalWrite(oraLED, HIGH);
  delay(150);
  digitalWrite(redLED, LOW) ; 
  digitalWrite(oraLED, LOW) ; 
  delay(150);
}

void ORANGE() {
  oraState = HIGH;
  digitalWrite(oraLED, HIGH);
  delay(500);
  digitalWrite(oraLED, LOW) ; 
  delay(500);
}

void servo_pwm(int x, int pin){
    if( x%14 == 0){
      digitalWrite(redLED, HIGH);
      digitalWrite(oraLED, HIGH);
    }
    else if( x%7 == 0){
      digitalWrite(redLED, LOW) ; 
      digitalWrite(oraLED, LOW) ;
    }
  int val = (x*10.25)+500;
  digitalWrite(pin,HIGH);
  delayMicroseconds(val);
  digitalWrite(pin,LOW);
  delay(20);
  }
