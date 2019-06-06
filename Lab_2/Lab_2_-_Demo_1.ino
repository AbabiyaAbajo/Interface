//these teensy pins are PWM capable pins
int greenLED = 3;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 4;//2.3V, ~111ohm
int redLED = 5;//1.6V, ~189ohm

//these pins are NOT PWM capable pins
//int greenLED = 7;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
//int blueLED = 8;//2.3V, ~111ohm
//int redLED = 12;//1.6V, ~189ohm

int pushButton = 11;
int counter;  

long dutyCycleRandNumber;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(0, INPUT);//use this open circuited pin for a seed to the random number generator

  
//  attachInterrupt(pushButton, changeLights, CHANGE);//for task 6, demo #4   
}

//void loop() {
//DEMO 1 SHOULD INVOLVE A COMBINATION OF ON/OFF CYCLES OF ALL LED AND SHOULD RESEMBLE THE FOLLOWING
//int myDelay = 500;
//
//   digitalWrite(greenLED, 1);
//   delay(myDelay);
//   digitalWrite(greenLED, 0);
//
//    digitalWrite(redLED, 1);
//   delay(myDelay);
//   digitalWrite(redLED, 0);
//
//    digitalWrite(blueLED, 1);
//   delay(myDelay);
//   digitalWrite(blueLED, 0);

//DEMO 2 SHOULD INVOLVE A COMBINATION OF PWM CYCLES OF ALL LED AND SHOULD RESEMBLE THE FOLLOWING
//    randomSeed(analogRead(0));
//    dutyCycleRandNumber = random(255);
//    analogWrite(greenLED, dutyCycleRandNumber);
//    dutyCycleRandNumber = random(65);
//    analogWrite(redLED, dutyCycleRandNumber);
//    dutyCycleRandNumber = random(135);
//    analogWrite(blueLED, dutyCycleRandNumber);
//    delay(500);

//DEMO 3 IF COLOUR CYCLING IS DONE WITH DIGITALWRITE()BE CERTAIN TO USE NON-PWM PINS
//THE CODE IMMEDIATE BELOW IS ANALOGWRITE, AND BELOW THAT IS THE DIGITALWRITE VERSION
//RESPECTIVE SETUP() CODE IS COMMENTED IN/OUT WHEN NECESSARY  

void loop() {
  // put your main code here, to run repeatedly:

counter = 0;
  while(counter < 1)
  { 
    Serial.println("in the while loop");
 
 randomSeed(analogRead(0));
 
    dutyCycleRandNumber = random(255);
    analogWrite(greenLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(255);
    analogWrite(redLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(255);
    analogWrite(blueLED, dutyCycleRandNumber);
    delay(500);
    
    if(digitalRead(pushButton) == HIGH)//first press of pushbutton
    {
       Serial.println("First button press");
      counter++;
     
        digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
     // delay(1000);
    }
  }//end while loop

  while(counter > 0 && counter < 10)
  {
    //Serial.println("In the next while loop");
    if(digitalRead(pushButton)== HIGH)//out of the loop., now all subsequent press of pushbutton
    {
      Serial.println("another button press");
      freezeLight();
    }   
 }
  
}//end main

void freezeLight()
{
dutyCycleRandNumber = random(255);
    analogWrite(greenLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(255);
    analogWrite(redLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(255);
    analogWrite(blueLED, dutyCycleRandNumber);
    delay(500);
}

//DEMO 4 INTERRUPT WITH DIGITALWRITE COLOUR CYCLING FOR CONVENIENCE USE THREE SEQUENTIAL PINS TO EXPLOIT RANDOM NUMBER GENERATION
//REFER TO THE ATTACHINTERRUPT LINE OF CODE IN THE SETUP() FUNCTION - IT IS COMMENTED OUT
//THIS WAS EASIER TO IMPLEMENT USING FUNCTIONS CHANGELIGHTS AND RANDOMLIGHTS
//void loop(){
// 
//   while(counter < 1)
//   {
//    randomLights();
//   }
// 
//}//end main
////
//void changeLights()
//{
//  int onPin, offPin_1, offPin_2;
//
//  counter++;
//
//  int beacon = counter % 3;
//     
//   if(beacon == 0)
//   {
//    onPin = greenLED;
//    offPin_1 = redLED;
//    offPin_2 = blueLED;
//   }
//   else if(beacon == 1)
//   {
//    onPin = redLED;
//    offPin_1 = greenLED;
//    offPin_2 = blueLED;
//   }
//   else
//   {
//    onPin = blueLED;
//    offPin_1 = greenLED;
//    offPin_2 = redLED;
//   }
//
//  digitalWrite(onPin, HIGH);
//  digitalWrite(offPin_1, LOW);
//  digitalWrite(offPin_2, LOW);
//  delay(200);
//}
////
//void randomLights()
//{
//   int onPin = random(0, 3);
//   
//   int offPin_1;
//   int offPin_2;
//   
//   if(onPin == greenLED)
//   {
//    offPin_1 = redLED;
//    offPin_2 = blueLED;
//   }
//   else if(onPin == redLED)
//   {
//    offPin_1 = greenLED;
//    offPin_2 = blueLED;
//   }
//   else
//   {
//    offPin_1 = greenLED;
//    offPin_2 = redLED;
//   }
//  
//    digitalWrite(onPin, HIGH);
//    digitalWrite(offPin_1, LOW);
//    digitalWrite(offPin_2, LOW);
//    delay(100);
//
//
//  
//}//end main



// the loop() methor runs over and over again,
// as long as the board has power
