#include <ESP8266WiFi.h>

const char* ssid = "Yari Pki Pki Te Net Apna Apna";
const char* password = "pass4wifi";

IPAddress serverIP(192, 168, 100, 2); // Change this to the IP address of the sender NodeMCU
//192.168.100.2
WiFiClient client;

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

  // Connect to the sender NodeMCU's server
  Serial.print("Connecting to server: ");
  Serial.println(serverIP);
  while (!client.connect(serverIP, 80)) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to server");
}

void loop() {
  // Read data from the sender NodeMCU
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print("Received data: ");
    Serial.println(line);
  }
}
