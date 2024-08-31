
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <EEPROM.h>

#include "ap_page.h"

#define HOTSPOT_SSID "IOT_RELAY"
#define HOTSPOT_PSWD "tryit" //Create any password you want for your Access point
#define HOTSPOT_CHANNEL 1
#define HIDE_SSID false
#define NO_OF_CONNECT 1

AsyncWebServer server(80);

String t; // to store time

const char* TIME = "TI"; // name feild of the input html form is "TI" which is stored in TIME.

String encoma[4];

//int swst = 0;
int relay_led = 3; 
unsigned long time_now = 0;
bool count = false;
bool flag = true;
unsigned long time_sec=0;

String getmacod(){
 String macvar = WiFi.macAddress();
 encoma[0] = macvar[12];
 encoma[1] = macvar[13];
 encoma[2] = macvar[15];
 encoma[3] = macvar[16];
 String fcode = encoma[0]+encoma[1]+encoma[2]+encoma[3];
 return fcode;
}

void generate_AP(){
   WiFi.mode(WIFI_AP);
   IPAddress local_IP(192, 168, 1, 2);
   IPAddress gateway(192, 168, 1, 2);
   IPAddress subnet(255, 255, 255, 0);
   WiFi.softAPConfig (local_IP, gateway, subnet);
   WiFi.softAP(String(HOTSPOT_SSID) +"("+getmacod()+")", HOTSPOT_PSWD, HOTSPOT_CHANNEL, HIDE_SSID, NO_OF_CONNECT);
   IPAddress IP = WiFi.softAPIP();
   Serial.println(IP);
}

void serve_page(){
 server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html);
   if (request->hasParam(TIME)) 
   {
     t = request->getParam(TIME)->value();
   } 
   Serial.println(t);
   EEPROM.put(1,t);
   EEPROM.commit();
   EEPROM.put(100,"w");
   EEPROM.commit();
 });
 server.begin(); 
}


void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  String check;
  EEPROM.get(100,check);
  if(check != "w")
  {
   Serial.println("Location 100 is empty");
   t="1"; //initially if flash is erased then there is no "w" at location hundred, t is made 1 in this case.
   EEPROM.put(1,t);
   EEPROM.commit();
  }
  generate_AP();
  Serial.println("Access point set");
  serve_page();
  Serial.println("Webpage is active");
  String tim;
  EEPROM.get(1,tim);
  Serial.println(tim);
  int time_saved = tim.toInt();
  time_sec = time_saved * 1000;
  pinMode(relay_led,OUTPUT);
}

void loop() {
 if(count == false){ 
  digitalWrite(relay_led,HIGH);
  if(millis() >= time_now + time_sec){
        time_now += time_sec;
        count = !count;
  }
 }
 else if(count == true){
   digitalWrite(relay_led,LOW);
 }

}
