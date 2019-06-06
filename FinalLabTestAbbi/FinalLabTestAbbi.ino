const int latch = 15; //Latch pin
const int data = 14; //Data pin
const int clockP = 16; //Clock pin
const int potentiometerPin = 23;

int potentiometerValue = 0;

//1 means OFF and 0 means ON
int segmentArray[] = {
  B00001001, // value 0 on 7 segment
  B00111110, // value 1 on 7 segment
  B01000101, // value 2 on 7 segment
  B00010100, // value 3 on 7 segment
  B00110011, // value 4 on 7 segment
  B10010000, // value 5 on 7 segment
  B10000001, // value 6 on 7 segment
  B00111100, // value 7 on 7 segment
  B00000001, // value 8 on 7 segment
  B00110000 //  value 9 on 7 segment
};

void setup() {
  // initializing
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clockP, OUTPUT);
}

// **************** Using Potentiometer, makes 7segment light up one at a time ************************************
void loop()                     
{
  // read the pot position 
  potentiometerValue = (analogRead(potentiometerPin)); 

  // used to display and trouble shoot the potentiometer value
  Serial.print("potentiometerValue: ");
  Serial.println(potentiometerValue);
  // used to display and trouble shoot the tens position value
  Serial.print("tens Position: ");
  Serial.println((potentiometerValue / 10) % 10);
  
  digitalWrite(latch, LOW);// prepare shift register for data
  shiftOut(data, clockP, LSBFIRST , segmentArray[((potentiometerValue / 10) % 10)]); // send data
  digitalWrite(latch, HIGH);// update display
  delay(1000); //delay of 1 seconds
}
