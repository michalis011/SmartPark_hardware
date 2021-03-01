#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Network SSID
const char* ssid = "Upstairs"; // Local WiFi connection
const char* password = "";
const char* mqtt_server = "192.168.10.132"; // IP address of the subscriper
int IRsensor1 = 14; // LED conncected to D2 of Wemos
int IRsensor2 = 16; // IR sensor connected to D0 of Wemos

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
  pinMode(IRsensor1, INPUT); // Set the IO pins
  pinMode(IRsensor2, INPUT);

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
    /*
     YOU MIGHT NEED TO CHANGE THIS LINE, IF YOU'RE HAVING PROBLEMS WITH MQTT MULTIPLE CONNECTIONS
     To change the ESP device ID, you will have to give a new name to the ESP8266.
     Here's how it looks:
       if (client.connect("ESP8266Client")) {
     You can do it like this:
       if (client.connect("ESP1_Office")) {
     Then, for the other ESP:
       if (client.connect("ESP2_Garage")) {
      That should solve your MQTT multiple connections problem
    */
    if (client.connect("ESP8266Client")) {
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
    client.connect("ESP8266Client");

  int statusSensor1 = digitalRead(IRsensor1); // Set variables to the outputs of the sensors
  int statusSensor2 = digitalRead(IRsensor2);
  
  if ((statusSensor1 == 0) && (statusSensor2 == 0)){
    Serial.println("1");
    client.publish("room/IR", "1"); // Publish outputs of the two sensors to the client
  }
}
