/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/SIT210_Projects_NWS/Particle_Data_ToWeb/ParticleToWeb/src/ParticleToWeb.ino"
/*
 * Project ParticleToWeb
 * Description: This is a first attempt at creating a project with a sensor which uploads data to the Web
 * Author: Matthew Gray
 * Date: 02 Apr 21
 */

#include "Adafruit_DHT.h"

void setup();
void loop();
#line 10 "d:/SIT210_Projects_NWS/Particle_Data_ToWeb/ParticleToWeb/src/ParticleToWeb.ino"
#define DHTPIN D2

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  dht.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  delay(2000);

  String temp = String(dht.getTempCelcius());

  String humidity = String(dht.getHumidity());

  String dewp = String(dht.getDewPoint());

  Particle.publish("temp", temp, PRIVATE);
  Particle.publish("humidity", humidity, PRIVATE);


}