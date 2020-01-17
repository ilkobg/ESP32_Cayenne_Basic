#include <CayenneMQTTESP32.h>
#include <DHT.h>
#include "credetentials.h"

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

#define DHT_PIN        22
#define DHT_TYPE       DHT11
#define MEAS_INTERVAL  10     /**< In seconds. */

// WiFi network info.
char ssid[] = SSID;
char wifiPassword[] = PASSWORD;

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = CAYENNE_USERNAME;
char password[] = CAYENNE_PASSWORD;
char clientID[] = CAYENNE_CLIENTID;

DHT dht (DHT_PIN, DHT_TYPE);

void setup() 
{
	Serial.begin(9600);
  dht.begin();
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() 
{
  Cayenne.loop();

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();  
   
  #ifdef CAYENNE_DEBUG
  Serial.println("temp: ");
  Serial.println(temp);
  Serial.println("hum: ");
  Serial.println(hum);
  #endif

  Cayenne.celsiusWrite(0, temp);
  delay(5);
  Cayenne.virtualWrite(1, hum);
  delay(5);
  ESP.deepSleep(MEAS_INTERVAL * 1000000LL);
}

