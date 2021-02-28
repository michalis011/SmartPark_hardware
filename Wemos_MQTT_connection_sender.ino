#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Network SSID
const char* ssid = "Upstairs";
const char* password = "";
const char* mqtt_server = "192.168.10.132";
int IRsensor1 = 14; // LED conncected to D2 of Wemos
int IRsensor2 = 16; // IR sensor connected to D0 of Wemos

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.begin(115200);
  delay(10);
 
//  // Connect WiFi
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
  
    WiFi.begin(ssid, password);
// 
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("");
//  Serial.println("WiFi connected");
// 
//  // Print the IP address
//  Serial.print("IP address: ");
//  Serial.print(WiFi.localIP());
}

void callback(String topic, byte* message, unsigned int length) {
//  Serial.print("Message arrived on topic: ");
//  Serial.print(topic);
//  Serial.print(". Message: ");
    String messageTemp;
//  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
//  Serial.println();

  // If a message is received on the topic room/lamp, you check if the message is either on or off. Turns the lamp GPIO according to the message
//  if(topic=="home/lamp"){
//      Serial.print("Changing Room lamp to ");
//      if(messageTemp == "on"){
//        digitalWrite(lamp, HIGH);
//        Serial.print("On");
//      }
//      else if(messageTemp == "off"){
//        digitalWrite(lamp, LOW);
//        Serial.print("Off");
//      }
//  }
  Serial.println();
}

void setup() {
  // Setup the IOpins
  pinMode(IRsensor1, INPUT);
  pinMode(IRsensor2, INPUT);

  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}


void reconnect() {
  // Loop until we're reconnected
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
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      // client.subscribe("home/lamp");
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

  int statusSensor1 = digitalRead(IRsensor1);
  int statusSensor2 = digitalRead(IRsensor2);
  
  if ((statusSensor1 == 0) && (statusSensor2 == 0)){
    Serial.println("1");
    client.publish("room/IR", "1");
  }
  
    //else
   // {
     // Serial.println("0");
     // client.publish("room/IR", "0");
    //}
  }
