
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

//toggle
int tsw1 = 0;
int tsw2 = 0;
int tsw3 = 0;
int tsw4 = 0;
int tsw5 = 0;
int tsw6 = 0;
int tsw7 = 0;
int tsw8 = 0;

//array of state
int state[8] = {0, 0, 0, 0, 0, 0, 0, 0};

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
      state[0] = 1;
      delay( 50 );
    } else {
      state[0] = 0;
      delay( 50 );
    }
  }


  if (digitalRead(sw2) == 0) {
    delay(50);
    tsw2 = 1 - tsw2;
    if (tsw2 == 1) {
      state[1] = 1;
      delay( 50 );
    } else {
      state[1] = 0;
      delay( 50 );
    }
  }

  if (digitalRead(sw3) == 0) {
    delay(50);
    tsw3 = 1 - tsw3;
    if (tsw3 == 1) {
      state[2] = 1;
      delay( 50 );
    } else {
      state[2] = 0;
      delay( 50 );
    }
  }

  if (digitalRead(sw4) == 0) {
    delay(50);
    tsw4 = 1 - tsw4;
    if (tsw4 == 1) {
      state[3] = 1;
      delay( 50 );
    } else {
      state[3] = 0;
      delay( 50 );
    }
  }

  if (digitalRead(sw5) == 0) {
    delay(50);
    tsw5 = 1 - tsw5;
    if (tsw5 == 1) {
      state[4] = 1;
      delay( 50 );
    } else {
      state[4] = 0;
      delay( 50 );
    }
  }

  if (digitalRead(sw6) == 0) {
    delay(50);
    tsw6 = 1 - tsw6;
    if (tsw6 == 1) {
      state[5] = 1;
      delay( 50 );
    } else {
      state[5] = 0;
      delay( 50 );
    }
  }

  if (digitalRead(sw7) == 0) {
    delay(50);
    tsw7 = 1 - tsw7;
    if (tsw7 == 1) {
      state[6] = 1;
      delay( 50 );
    } else {
      state[6] = 0;
      delay( 50 );
    }
  }

  if (digitalRead(sw8) == 0) {
    delay(50);
    tsw8 = 1 - tsw8;
    if (tsw8 == 1) {
      state[7] = 1;
      delay( 50 );
    } else {
      state[7] = 0;
      delay( 50 );
    }
  }
  registerWrite(state);
  delay( 100 );
}

// This method sends bits to the shift register:

void registerWrite(int state[]) {
  //  Serial.println(whichPin);

  // the bits you want to send
  byte bitsToSend = 0;
  // write number as bits
  bitWrite(bitsToSend, 0, state[0]);
  bitWrite(bitsToSend, 1, state[1]);
  bitWrite(bitsToSend, 2, state[2]);
  bitWrite(bitsToSend, 3, state[3]);
  bitWrite(bitsToSend, 4, state[4]);
  bitWrite(bitsToSend, 5, state[5]);
  bitWrite(bitsToSend, 6, state[6]);
  bitWrite(bitsToSend, 7, state[7]);

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);

  //digitalWrite(clockPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);

  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
}

