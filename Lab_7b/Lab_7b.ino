int piezoPin = A8;
 
const int sensorPin = A5;    // pin that the sensor is attached to

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 500;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


int greenPin =  17;


void setup() {

  pinMode(greenPin, OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

 
void loop() {
 
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(greenPin, sensorValue);

  if( sensorValue > 50){
  tone(piezoPin, 500, sensorValue);
  }
  //tone(piezoPin, 1000, 500);
  //delay(sensorValue);
 
}
