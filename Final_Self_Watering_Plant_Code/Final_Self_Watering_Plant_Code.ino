#include "arduino_secrets.h"
// Example of sending and receiving MQTT messages via AdafruitIO

#include <WiFi.h>
#include <AdafruitIO_WiFi.h>
#include "M5CoreInk.h" 

// initialize WiFi connection:
WiFiClient wifi;
AdafruitIO_WiFi io(SECRET_AIO_USERNAME, SECRET_AIO_KEY, SECRET_SSID, SECRET_PASS);
AdafruitIO_Feed *sensorFeed = io.feed("plantfeed");
AdafruitIO_Feed *ledFeed = io.feed("ledfeed");


const int sensorPin = 36;
const int AirValue = 2250;
const int WaterValue = 950;
const int pumpPin = 32;
int pumpState = 0;
int lowMoistureThreshhold = 30;
int highMoistureThreshhold = 70;
int soilMoistureValue = 0;
int soilMoisturePercent=0;
unsigned long sensorTimer = 0;
bool firstMessageReceived = false;  


void setup() {
  
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  pinMode(pumpPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(pumpPin, LOW);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the ledFeed:
  ledFeed->onMessage(handleMessage);
  
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  ledFeed->get();

  // print connection status
  Serial.println(io.statusText());
}

void loop() {
  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.  
  io.run();
  
  soilMoistureValue = analogRead(sensorPin);  //put Sensor insert into soil
  //Serial.print(soilMoistureValue);
  //Serial.println("%");
  soilMoisturePercent = map(soilMoistureValue, WaterValue, AirValue, 100, 0);

  Serial.print(soilMoisturePercent);
  Serial.println("%");
  
  if (soilMoisturePercent > highMoistureThreshhold) {
    digitalWrite(pumpPin, LOW);
  }

  // publish message every 2 seconds:
  if(millis() > sensorTimer + 2000) {

    // print soilMoisturePercent to Serial port:
    Serial.print("send soilMoisturePercent: ");
    Serial.println(soilMoisturePercent);

    sensorFeed->save(soilMoisturePercent);
    
    sensorTimer = millis();
  }
  delay(200);
}

void handleMessage(AdafruitIO_Data *data) {
 
  Serial.print("received: ");
  Serial.println(data->value());

  if(firstMessageReceived == false) { 

   // ignore first message and set global variable:

   firstMessageReceived = true;
  }
  else {
    //digitalWrite(pumpPin, HIGH);
    // code to trigger the relay
    if (strcmp((char*)data->value(), "OFF")) {
      Serial.println("OFF message");
      if (soilMoisturePercent < lowMoistureThreshhold) {
        digitalWrite(pumpPin, HIGH);
        delay(4000); // time pump is on
        digitalWrite(pumpPin, LOW);
        delay(8000); // time for sensor to read new moisture level
      }
    }
    else {
      //if (strcmp((char*)data->value(), "ON")) {
        Serial.println("ON message");        
        digitalWrite(pumpPin, LOW);
      //}
    } 
   // }
  }
}