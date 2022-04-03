
#include "WebHandler.h"

const char* ssid     = "yourssid";
const char* password = "yourpsw";

WebHandler webHandler;

void setup() {

  Serial.begin(115200);

  /****************************************************************
       Connect to Wi-Fi
  ****************************************************************/
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  /****************************************************************
       Print ESP32 Local IP Address
  ****************************************************************/
  Serial.println(WiFi.localIP());

  /****************************************************************
         Initialize SPIFFS
  ****************************************************************/

  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  webHandler.init(80);

}

void loop() {

  webHandler.loop();

}
