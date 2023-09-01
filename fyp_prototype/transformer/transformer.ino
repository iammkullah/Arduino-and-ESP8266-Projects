#include <ESP8266WiFi.h>

const char* ssid = "Yari Pki Pki Te Net Apna Apna";
const char* password = "pass4wifi";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

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

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Wait for a client to connect
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Send data to the other NodeMCU
  client.write("Hello from NodeMCU 1!");
}
