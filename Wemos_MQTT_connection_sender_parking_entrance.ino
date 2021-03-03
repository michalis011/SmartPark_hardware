#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Network SSID
const char* ssid = "Upstairs"; // Local WiFi connection
const char* password = "";
const char* mqtt_server = "192.168.10.132"; // IP address of the subscriper
int IRsensor = 14; // IR sensor connected to D5 of Wemos

WiFiClient espClient;
PubSubClient client(espClient);

// Establish the WiFi connection
void setup_wifi() {
  Serial.begin(115200);
  delay(10);
  
  WiFi.begin(ssid, password);
}

// Callback function to ensure connection
void callback(String topic, byte* message, unsigned int length) {
    String messageTemp;
    
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
}

// Setup connections of the WiFi module
void setup() {
  // Setup the IOpins
  pinMode(IRsensor, INPUT); // Set the IO pins

  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883); // Setup the client (Raspberry Pi 4)
  client.setCallback(callback);
}


void reconnect() {
  // Loop until reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect

    if (client.connect("ESP8266_entrance")) {
      Serial.println("connected");  
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266_entrance");

  int statusSensor = digitalRead(IRsensor); // Set variables to the outputs of the sensors
  
  if (statusSensor == 0){
    Serial.println("1");
    client.publish("parking/entrance", "1"); // Publish outputs of the two sensors to the client
  }
}
