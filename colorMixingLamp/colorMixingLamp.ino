const int redLedPin = 10;
const int greenLedPin = 9;
const int blueLedPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // Serial opens up communication so you can view values
  Serial.begin(9600);

  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(1);
  redValue = redSensorValue/4;
  greenSensorValue = analogRead(greenSensorPin);
  delay(1);
  greenValue = greenSensorValue/4;
  blueSensorValue = analogRead(blueSensorPin);
  delay(1);
  blueValue = blueSensorValue/4;

  analogWrite(redLedPin, redValue);
  analogWrite(greenLedPin, greenValue);
  analogWrite(blueLedPin, blueValue);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t\tGreen: ");
  Serial.print(greenSensorValue);
  Serial.print("\tBlue: ");
  Serial.print(blueSensorValue);
  Serial.print("\n");

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t\tGreen: ");
  Serial.print(greenValue);
  Serial.print("\tBlue: ");
  Serial.print(greenValue);
  Serial.print("\n");

}
