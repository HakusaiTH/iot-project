#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "cKcMww1oSRDoLihsT2zlvFLBa53b_-Y8"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "FF1_15";
char pass[] = "123456789";

//vcc = 3v, GND = GND, IN = D0
//video https://youtu.be/5Y-1LgwY-Kw
int relay = D0;

BLYNK_WRITE(V0) {
  if(param.asInt() == 1){
    digitalWrite(relay,HIGH);  
  }
  else {
    digitalWrite(relay,LOW);
  }
}


void setup() {
  pinMode(relay, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(relay,LOW);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
