/* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

//Variables for the 1st Chamber
const int Intensity1 = 4;    // Connect Black cable to digital pin 4
const int greenLEDPin1 = 5;    // Connect Orange cable to digital pin 5
const int redLEDPin1 = 6;     // Connect Yellow cable to digital pin 6
const int blueLEDPin1 = 7;    // Connect Green cable to digital pin 7

const int redSensorPin1 = A0;  // pin with the photoresistor with the red gel
const int greenSensorPin1 = A1;   // pin with the photoresistor with the green gel
const int blueSensorPin1 = A2;   // pin with the photoresistor with the blue gel
const int blackSensorPin1 = A3;   // pin with the photoresistor with the black gel

int redValue1 = 0; // value to write to the red LED
int greenValue1 = 0; // value to write to the green LED
int blueValue1 = 0; // value to write to the blue LED
int blackValue1 = 0; // value to write to the black LED

int redSensorValue1 = 0; // variable to hold the value from the red sensor
int greenSensorValue1 = 0; // variable to hold the value from the green sensor
int blueSensorValue1 = 0; // variable to hold the value from the blue sensor
int blackSensorValue1 = 0; // variable to hold the value from the black sensor

// Defines Variables for the 2nd Chamber
const int greenLEDPin2 = 8;    // LED connected to Orange cable 8
const int redLEDPin2 = 9;     // LED connected to Yellow cable 9
const int blueLEDPin2 = 10;    // LED connected to Green cable 10
const int Intensity2 = 11;    // Connect Black cable to digital pin 11

const int redSensorPin2 = A4;  // pin with the photoresistor with the red gel
const int greenSensorPin2 = A5;   // pin with the photoresistor with the green gel
const int blueSensorPin2 = A6;   // pin with the photoresistor with the blue gel
const int blackSensorPin2 = A7;   // pin with the photoresistor with the black gel

int redValue2 = 0; // value to write to the red LED
int greenValue2 = 0; // value to write to the green LED
int blueValue2 = 0; // value to write to the blue LED
int blackValue2 = 0; // value to write to the black LED

int redSensorValue2 = 0; // variable to hold the value from the red sensor
int greenSensorValue2 = 0; // variable to hold the value from the green sensor
int blueSensorValue2 = 0; // variable to hold the value from the blue sensor
int blackSensorValue2 = 0; // variable to hold the value from the black sensor

// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;
// defines variables
long duration;
int distance;

void setup() {
// set the digital pins as outputs
  pinMode(greenLEDPin1, OUTPUT);
  pinMode(redLEDPin1, OUTPUT);
  pinMode(blueLEDPin1, OUTPUT);
  pinMode(Intensity1, OUTPUT);

  pinMode(greenLEDPin2, OUTPUT);
  pinMode(redLEDPin2, OUTPUT);
  pinMode(blueLEDPin2, OUTPUT);
  pinMode(Intensity2, OUTPUT);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {

   //Read the sensors on the chambers 1st chamber first:

  // read the value from the red-filtered photoresistor:
  redSensorValue1 = analogRead(redSensorPin1);
  // give the ADC a moment to settle
  delay(5);
  // read the value from the green-filtered photoresistor:
  greenSensorValue1 = analogRead(greenSensorPin1);
  // give the ADC a moment to settle
  delay(5);
  // read the value from the blue-filtered photoresistor:
  blueSensorValue1 = analogRead(blueSensorPin1);
 // read the value from the black-filtered photoresistor:
  blackSensorValue1 = analogRead(blackSensorPin1);
  
  // print out the values to the serial monitor
  Serial.print("raw sensor Values \t red: ");
  Serial.print(redSensorValue1);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue1);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue1);
  Serial.print("\t Black: ");
  Serial.println(blackSensorValue1);

  /*
  In order to use the values from the sensor for the LED,
  you need to do some math. The ADC provides a 10-bit number,
  but analogWrite() uses 8 bits. You'll want to divide your
  sensor readings by 4 to keep them in range of the output.
  */
  redValue1 = redSensorValue1 / 4;
  greenValue1 = greenSensorValue1 / 4;
  blueValue1 = blueSensorValue1 / 4;
  blackValue1 = blackSensorValue1 / 4;

  //  print out the mapped values
  Serial.print("Mapped sensor Values \t red: ");
  Serial.print(redValue1);
  Serial.print("\t green: ");
  Serial.print(greenValue1);
  Serial.print("\t Blue: ");
  Serial.println(blueValue1);
  Serial.print("\t Black: ");
  Serial.println(blackValue1);

  /*
  Now that you have a usable value, it's time to PWM the LED.
  */
  analogWrite(redLEDPin1, redValue1);
  analogWrite(greenLEDPin1, greenValue1);
  analogWrite(blueLEDPin1, blueValue1);
  analogWrite(Intensity1, blackValue1);


   //Read the sensors on the chambers 2nd chamber second:

  // read the value from the red-filtered photoresistor:
  redSensorValue2 = analogRead(redSensorPin2);
  // give the ADC a moment to settle
  delay(5);
  // read the value from the green-filtered photoresistor:
  greenSensorValue2 = analogRead(greenSensorPin2);
  // give the ADC a moment to settle
  delay(5);
  // read the value from the blue-filtered photoresistor:
  blueSensorValue2 = analogRead(blueSensorPin2);
 // read the value from the black-filtered photoresistor:
  blackSensorValue2 = analogRead(blackSensorPin2);
  
  // print out the values to the serial monitor
  Serial.print("raw sensor Values \t red: ");
  Serial.print(redSensorValue2);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue2);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue2);
  Serial.print("\t Black: ");
  Serial.println(blackSensorValue2);

  /*
  In order to use the values from the sensor for the LED,
  you need to do some math. The ADC provides a 10-bit number,
  but analogWrite() uses 8 bits. You'll want to divide your
  sensor readings by 4 to keep them in range of the output.
  */
  redValue2 = redSensorValue2 / 4;
  greenValue2 = greenSensorValue2 / 4;
  blueValue2 = blueSensorValue2 / 4;
  blackValue2 = blackSensorValue2 / 4;

  //  print out the mapped values
  Serial.print("Mapped sensor Values \t red: ");
  Serial.print(redValue2);
  Serial.print("\t green: ");
  Serial.print(greenValue2);
  Serial.print("\t Blue: ");
  Serial.println(blueValue2);
  Serial.print("\t Black: ");
  Serial.println(blackValue2);

  /*
  Now that you have a usable value, it's time to PWM the LED.
  */
  analogWrite(redLEDPin2, redValue2);
  analogWrite(greenLEDPin2, greenValue2);
  analogWrite(blueLEDPin2, blueValue2);
  analogWrite(Intensity1, blackValue2);


  
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
