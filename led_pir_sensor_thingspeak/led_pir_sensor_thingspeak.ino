#include <DHT_U.h>

#include "ThingSpeak.h"
#include "WiFi.h"

char ssid[] = "Rajendra";
char pass[] = "raju@1998";

int ledPin = 21;
int PIR = 2;
int pirState = LOW;
int val =0;
int PersonCount;
int LEDCount;
WiFiClient client;

//----ThingSpeak Details----//

unsigned long myChannelField = 1644746;
const int ChannelField = 5;
const int ChannelField2 = 6;
const char * myWriteAPIKey = "LDCNV3ZCQJ2R0NW7";

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
pinMode(PIR, INPUT);
Serial.begin(115200);
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);

}

void loop() {
  //--------WiFi--------//
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);

    while(WiFi.status()!=WL_CONNECTED)
    {
      WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nConnected");
}
  // put your main code here, to run repeatedly:
val = digitalRead(PIR);
if (val == HIGH) 
{
digitalWrite(ledPin, HIGH);
if(pirState == LOW)
{
  Serial.println("Motion dedected!");
PersonCount++;
LEDCount++;
  pirState = HIGH;
}
}
else {
  digitalWrite(ledPin, LOW);
  if(pirState == HIGH)
  {
    Serial.println("Motion ended!");
    pirState = LOW;
  }
}


ThingSpeak.writeField(myChannelField, ChannelField, PersonCount, myWriteAPIKey);
ThingSpeak.writeField(myChannelField, ChannelField2, LEDCount, myWriteAPIKey);

delay(1000);
}