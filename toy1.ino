
//Pin to clear the register
// const int clearPin = 7;
//Pin connected to latch pin (RCK) of TPIC6B595
const int latchPin = 8;
//Pin connected to clocuk pin (SRCK) of TPIC6B595
const int clockPin = 12;
////Pin connected to Data in (SER IN) of TPIC6B595
const int dataPin = 11;

int counter = 0;
int numLedsInUse = 8;

//switch
int sw1 = 2;
int sw2 = 3;
int sw3 = 4;
int sw4 = 5;
int sw5 = 6;
int sw6 = 9;
int sw7 = 10;
int sw8 = 7;

int tsw1 = 0;
int tsw2 = 0;
int tsw3 = 0;
int tsw4 = 0;
int tsw5 = 0;
int tsw6 = 0;
int tsw7 = 0;
int tsw8 = 0;


void setup() {
  //set pins to output because they are addressed in the main loop
  //pinMode(clearPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);
  pinMode(sw6, INPUT_PULLUP);
  pinMode(sw7, INPUT_PULLUP);
  pinMode(sw8, INPUT);

  Serial.begin(9600);
  Serial.println("*");

  // Always start by setting SRCLR high
//  digitalWrite( clearPin, HIGH);

  // delay a little and then set
  delay(100);
}

void loop() {

  if (digitalRead(sw1) == 0) {
    delay(50);
    tsw1 = 1 - tsw1;
    if (tsw1 == 1) {

      registerWrite((sw1 - 2), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw1 - 2), LOW);
      delay( 50 );
    }
  }


  if (digitalRead(sw2) == 0) {
    delay(50);
    tsw2 = 1 - tsw2;
    if (tsw2 == 1) {

      registerWrite((sw2 - 2), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw2 - 2), LOW);
      delay( 50 );
    }
  }

  if (digitalRead(sw3) == 0) {
    delay(50);
    tsw3 = 1 - tsw3;
    if (tsw3 == 1) {

      registerWrite((sw3 - 2), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw3 - 2), LOW);
      delay( 50 );
    }
  }

  if (digitalRead(sw4) == 0) {
    delay(50);
    tsw4 = 1 - tsw4;
    if (tsw4 == 1) {

      registerWrite((sw4 - 2), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw4 - 2), LOW);
      delay( 50 );
    }
  }

  if (digitalRead(sw5) == 0) {
    delay(50);
    tsw5 = 1 - tsw5;
    if (tsw5 == 1) {

      registerWrite((sw5 - 2), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw5 - 2), LOW);
      delay( 50 );
    }
  }

  if (digitalRead(sw6) == 0) {
    delay(50);
    tsw6 = 1 - tsw6;
    if (tsw6 == 1) {

      registerWrite((sw6 - 4), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw6 - 4), LOW);
      delay( 50 );
    }
  }

  if (digitalRead(sw7) == 0) {
    delay(50);
    tsw7 = 1 - tsw7;
    if (tsw7 == 1) {

      registerWrite((sw7 - 4), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw7 - 4), LOW);
      delay( 50 );
    }
  }



  if (digitalRead(sw8) == 0) {
    delay(50);
    tsw8 = 1 - tsw8;
    if (tsw8 == 1) {

      registerWrite((sw8), HIGH);
      delay( 50 );
    } else {
      registerWrite((sw8), LOW);
      delay( 50 );
    }
  }

  delay( 100 );
}

// This method sends bits to the shift register:

void registerWrite(int whichPin, int whichState) {
  Serial.println(whichPin);

  // the bits you want to send
  byte bitsToSend = 0;
  // write number as bits
  bitWrite(bitsToSend, whichPin, whichState);

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);
  Serial.println(bitsToSend);
  Serial.println("_");

  // shift the bits out
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);

  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
}

