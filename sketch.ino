#include<WiFi.h>
#include <DHTesp.h>
#include <HTTPClient.h>
#define led 17
const char* ssid = "Wokwi-GUEST";
const char* password = "";
String apiKey = "MJLA4YVV0WFI5P3Q";
DHTesp dht;
void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.println("connecting");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nconnected");
  dht.setup(15, DHTesp::DHT22);

}
void loop(){
  if(WiFi.status()==WL_CONNECTED){
    TempAndHumidity data = dht.getTempAndHumidity();
  
  if(data.temperature>30){
    digitalWrite(led, HIGH);}
    else{
      digitalWrite(led, LOW);
    }
    Serial.print("Temp: ");
    Serial.print(data.temperature);
    Serial.print(" | Hum: ");
    Serial.println(data.humidity);

    int score = 100;
    String status;
    if(data.temperature>25) score-=25;
    if(data.humidity>70) score-=20;
   
    if(score>70) status="GOOD";
    else if(score>40) status="Modarate";
    else status = "poor";
    Serial.print("Focus score:");
    Serial.println(score);
    Serial.print("status:");
    Serial.println(status);

    HTTPClient http;
    String url = "http://api.thingspeak.com/update?api_key=" +apiKey +
                 "&field1=" + String(data.temperature) + "&field2="+ 
                 String(data.humidity) + "&field3=" + 
                 String(score) + "&field4=" + String(status);
    http.begin(url);
    int httpResponseCode=http.GET();
    Serial.print("sent! Response: ");
    Serial.println(httpResponseCode);
    http.end();
  }
  delay(15000);
}