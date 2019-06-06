/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
 
int latchPin = 15;
int clockPin = 16;
int dataPin = 14;
 
const char common = 'c';
const char anode = 'a';
const int pushButton = 9;

int j = 0;
int i = 0;
byte bits = 0;
byte bits2 = 0;

volatile boolean push = false;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(9, INPUT);

attachInterrupt(digitalPinToInterrupt(9), buttonPressed, CHANGE);
}
 
void loop() 
{

  for (j = 0; j <= 9; j++) {
  bits2 = myfnNumToBits(j) ;
  for (i = 0; i <= 9; i++) {
    bits = myfnNumToBits(i) ;
//      if(push)
//      {
//        bits = 0; 
//        bits2 = 0;
//        buttonPressed();
//      }
    myfnUpdateDisplay2(bits, bits2);    // display alphanumeric digit
    delay(800);                 // pause for 1/2 second
  }
  }
    
}

void buttonPressed() { 
//  if(push)
//  {
//    push = false;
      j = 0; 
      i = 0;
      bits2 = myfnNumToBits(j) ;
      bits = myfnNumToBits(i) ;    
      myfnUpdateDisplay2(bits, bits2);
//  } else {
//    push = true;
//  }
  
}


void myfnUpdateDisplay2(byte eightBits, byte eightBits2) {
  if (common == 'c') {                  // using a common anonde display?
    eightBits = eightBits ^ B11111111;  // then flip all bits using XOR 
    eightBits2 = eightBits2 ^ B11111111; 
  }
  digitalWrite(latchPin, LOW);  // prepare shift register for data
  shiftOut(dataPin, clockPin, MSBFIRST, eightBits2); // send data
    shiftOut(dataPin, clockPin, MSBFIRST, eightBits); // send data
  digitalWrite(latchPin, HIGH); // update display
}

byte myfnNumToBits(int someNumber) {

    
//  if (digitalRead(pushButton)) {
//  buttonPressed();
//  }
  switch (someNumber) {
    case 0:
      return B01111110;
      break;
    case 1:
      return B00010010;
      break;
    case 2:
      return B10111100;
      break;
    case 3:
      return B10110110;
      break;
    case 4:
      return B11010010;
      break;
    case 5:
      return B11100110;
      break;
    case 6:
      return B11101110;
      break;
    case 7:
      return B00110010;
      break;
    case 8:
      return B11111110;
      break;
    case 9:
      return B11110010;
      break;

    default:
      return B10010010; // Error condition, displays three vertical bars
      break;   
  }
}
