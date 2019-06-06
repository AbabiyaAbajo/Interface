/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
 
int latchPin = 15;
int clockPin = 16;
int dataPin = 14;
 
byte leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}
 
void loop() 
{
  
  leds = 0;
  updateShiftRegister();
  delay(1000);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(1000);
  }
  leds = 0;
    for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegisterB();
    delay(1000);
  }
    leds = 0;
    for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegisterC();
    delay(1000);
  }
    leds = 0;
    for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegisterD();
    delay(1000);
  }
    
}
 
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST , 0);
   shiftOut(dataPin, clockPin, LSBFIRST , leds);
   digitalWrite(latchPin, HIGH);
}

void updateShiftRegisterB()
{
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST , leds);
      shiftOut(dataPin, clockPin, MSBFIRST , 255);
      digitalWrite(latchPin, HIGH);
      
}

void updateShiftRegisterC()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST , leds);
   shiftOut(dataPin, clockPin, LSBFIRST , 0);
   digitalWrite(latchPin, HIGH);
}

void updateShiftRegisterD()
{
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST , 255);
      shiftOut(dataPin, clockPin, MSBFIRST , leds);
      digitalWrite(latchPin, HIGH);
      
}
