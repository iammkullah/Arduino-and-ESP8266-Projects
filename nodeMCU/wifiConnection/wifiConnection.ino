#include <ESP8266WiFi.h>

const char* ssid = "Yari Pki Pki Te Net Apna Apna";     // replace with your Wi-Fi network name (SSID)
const char* password = "pass4wifi"; // replace with your Wi-Fi network password

void setup() {
  Serial.begin(115200);
  delay(100);

  // Connect to Wi-Fi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your code here
}
