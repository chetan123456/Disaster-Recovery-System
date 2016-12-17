#include <DallasTemperature.h>
#include <OneWire.h>

//PIR
int ledPin = 9;                // choose the pin for the LED
int inputPin = 13;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

//----------------------------------

//Temprature Sensor

int greenLedPin = 2;           // Pin Green LED is connected to
int yellowLedPin = 3;          // Pin Yellow LED is connected to
int redLedPin = 4;           // Pin Red LED is connected to
//int pirLedPin = 13;          // Pir Led connected output 13

int temp_sensor = 5;       // Pin DS18B20 Sensor is connected to
//int pir_sensor = 9;        // Pir sesor input connected 9

float temperature = 0;      //Variable to store the temperature in
int lowerLimit = 15;      //define the lower threshold for the temperature
int upperLimit = 35;      //define the upper threshold for the temperature


OneWire oneWirePin(temp_sensor);

DallasTemperature sensors(&oneWirePin);

void setup(void){
  Serial.begin(9600);

  
  //PIR
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  //----------------------------------

  //Temprature Sensor
  
  //Setup the LEDS to act as outputs for Temprature sensor
  pinMode(redLedPin,OUTPUT);
  pinMode(greenLedPin,OUTPUT);
  pinMode(yellowLedPin,OUTPUT);

  //pinMode(pir_sensor, INPUT);//pin 9 pir sensor output
  //pinMode(pirLedPin, OUTPUT);
  
  sensors.begin();
}

void loop(){

//PIR

val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.print(3);
      Serial.print(",");
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }

//--------------------------------------------------------

//Temprature Sensor

  //Serial.print("Requesting Temperatures from sensors: ");
  sensors.requestTemperatures(); 
  //Serial.println("DONE");
  
  temperature = sensors.getTempCByIndex(0);
    
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  
  //Serial.print("Temperature is ");
  Serial.print(1);
  Serial.print(",");
  Serial.print(int(temperature));
  Serial.print(",");
  
  //Setup the LEDS to act as outputs
  if(temperature <= lowerLimit){
    //Serial.println(", Yellow LED is Activated");
    digitalWrite(yellowLedPin, HIGH);
  }
  else if(temperature > lowerLimit && temperature < upperLimit){
    //Serial.println(", Green LED is Activated");
    digitalWrite(greenLedPin, HIGH);
  }
  else if(temperature >= upperLimit){
    Serial.println(", Red LED is Activated");
    digitalWrite(redLedPin, HIGH);
  }
  delay(2);
}

