#include <DHT_U.h>

#include "ThingSpeak.h"
#include "WiFi.h"

char ssid[] = "Rajendra";
char pass[] = "raju@1998";

#define HTU21DPIN 21  
#define HTU22DPIN 22

const int trigger = 21;                                                            
const int echo = 22;
long T;
float distanceCM;
WiFiClient client;

//-------ThingSpeak Details------//
unsigned long myChannelField = 1644746;
const int ChannelField = 3;
const int ChannelField2 = 4;
const char * myWriteAPIKey = "LDCNV3ZCQJ2R0NW7";

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT); 
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);

}

void loop() {
  // -------------WiFi--------------//

  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
    
  while(WiFi.status()!= WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(5000);
  }

  Serial.println("\nConnected");
}

digitalWrite(trigger, LOW);
delay(1);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
T = pulseIn(echo, HIGH);
distanceCM = (T * 0.034)/2;
Serial.print("\nDistance in cm: ");
Serial.print(distanceCM);

ThingSpeak.writeField(myChannelField, ChannelField, distanceCM, myWriteAPIKey);
ThingSpeak.writeField(myChannelField, ChannelField2, T, myWriteAPIKey);

delay(1000);
}