/*
 * Project ParticleToWeb
 * Description: This is a first attempt at creating a project with a sensor which uploads data to the Web
 * Author: Matthew Gray
 * Date: 02 Apr 21
 */

#include "Adafruit_DHT.h"

#include "JsonParserGeneratorRK.h"

#define DHTPIN D2

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const char * eventName = "MyFirstWebhook";

void createWebhookPayload(float temp, float humidity)
{
  JsonWriterStatic<256> jsonwrite;
  {
    JsonWriterAutoObject obj(&jsonwrite);

    jsonwrite.insertKeyValue("temp", temp);
    jsonwrite.insertKeyValue("humidity", humidity);
  }

  Particle.publish(eventName, jsonwrite.getBuffer(), PRIVATE);
}

// setup() runs once, when the device is first turned on.
void setup() {
  
  // Put initialization like pinMode and begin functions here.
  dht.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  delay(30000);

  float temp = (dht.getTempCelcius());

  float humidity = (dht.getHumidity());

  createWebhookPayload(temp, humidity);


}