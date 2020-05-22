int tDelay   = 50;
int dataPin  = 12;      
int latchPin = 11;      
int clockPin = 9;      


bool DirectionState = 0;


void updateShiftRegister(byte leds){
    digitalWrite(latchPin, LOW);
    if (DirectionState == false) {
        shiftOut(dataPin, clockPin, LSBFIRST, leds);
    } else {
        shiftOut(dataPin, clockPin, MSBFIRST, leds);
    }
    digitalWrite(latchPin, HIGH);
}


void setup(){
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin,  OUTPUT);  
    pinMode(clockPin, OUTPUT);
}


void loop(){
    byte leds = 0B00000000;
    updateShiftRegister(leds);
    for (int i = 0; i < 8; i++){
        bitSet(leds, i);
        updateShiftRegister(leds);
        delay(tDelay);
    }
    DirectionState = !DirectionState;
}
