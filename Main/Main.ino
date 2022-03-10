//Bord Name :- NodeMcu 1.0 (ESP-12E Module)
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80); // port 80

#define led D7

void setup() {
  
  Serial.begin(9600);
  WiFi.softAP("Shantonu NodeMcu", "12345678"); // Make A hostport
  
  Serial.println();
  Serial.println("Shantonu NodeMcu Started..!");
  Serial.print("Node Mcu IP Address : ");
  Serial.println(WiFi.softAPIP()); // Print Ip 
  server.begin();

  pinMode(led, OUTPUT);
} // Void Setup End




void loop() { // Void Lopp Start
  client = server.available();


  if (client == 1){
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();

    if (request == "GET /LedOn HTTP/1.1"){
      digitalWrite(led,HIGH);
    }

    else if (request == "GET /LedOff HTTP/1.1"){
      digitalWrite(led,LOW);
    }


  }







  
}// Void Loop End
