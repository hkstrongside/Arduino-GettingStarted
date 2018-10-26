const int SensorPin = A0;
const float BaselineTemp = 68.0;
float voltage;
float temperature;

void setup() {
  // open a serial port
  Serial.begin(9600); 

  // turn leds off
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(SensorPin);
  
  // sensor has a range of 1024, then from 0 to 5 volts represents temperature
  voltage = (sensorVal/1024.0)*5.0;
  
  // because I live in the US, convert to Fahrenheit
  temperature = (((voltage - 0.5)*100)*1.8)+32;  
  
  
  Serial.print("\nSensor Value: ");
  Serial.print(sensorVal);
  Serial.print(" Voltage: ");
  Serial.print(voltage);
  Serial.print(" Temperature: ");
  Serial.print(temperature);

  if(temperature < BaselineTemp){
      for(int pinNumber = 2; pinNumber < 5; pinNumber++){
        digitalWrite(pinNumber, LOW);
    }
  } else if(temperature < BaselineTemp+5){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature < BaselineTemp+10){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature < BaselineTemp+15){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(10);
}
