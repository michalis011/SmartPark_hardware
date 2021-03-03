# SmartPark_hardware

This is the hardware component of the University of Warwick, School of Engineering, ES410 Intelligent Transport Systems project of 2020-2021.

### Overview
Each component in hardware infrastructure has its own programming code. 

WiFi module (Wemos D1 Mini) is flashed with the Arduino Integrated Development Environment (IDE) which is a cross-platform application that is written in C++ Programming language. 

Rasbperry Pi 4 and the cloud server (in that case windows 10 PC) run Node-RED whcich is a flow-based development tool written in JavaScript Programming language.

## Prerequisites

### Arduino IDE
Please visit the official website of Arduino and download the latest version of Arduino IDE in windows 10.

Once downloaded, go to Tools > Manage Libraries, search and install the latest version of both "ESP8622 Microgear" and "PubSubClient" libraries.

Once installed, go to Tools > Board > ESP8622 Boards, and choose the "LOLIN (WEMOS) D1 R2 & mini".

Everything is set! Connect the Wemos D1 mini to the windows 10 mchine through a USB cable. 

#### For entrance barrier Wi-Fi module:
Verify and Upload the "Wemos_MQTT_connection_sender_parking_entrance.ino" script.

#### For slots Wi-Fi module:
Verify and Upload the "Wemos_MQTT_connection_sender_parking_slots.ino" script.

### Node-red
#### Windows 10 Installation
Please download the latest 12.x LTS version of Node.js from the official Node.js home page. 

Once installed, install Node-RED as a global module to your system path, executing the following at the command prompt:
```sh
npm install -g --unsafe-perm node-red
  ```
Following the details given in the command prompt, launch Node-red locally and import the "Windows_10_flow.js" scrip and Deploy.

#### Raspberry Pi 4 Rasbian Installation
Please download the Node.js, executing the following at the command prompt:
```sh
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
  ```
Once installed, run node-red locally by executing the following at the command prompt:
```sh
node-red
  ```
On a local web-broser (e.g. Google Chrome) run the IP address of the PI 4 as follows:
```sh
http://XXX.XXX.XX.XXX:1880/
  ```
Import the "Raspberry_PI_4_flow.js" scrip and Deploy.

#### Node-red Packages Installation
##### Please Install the following required packages:
###### Raspberry Pi Camera node
```sh
pi@raspberry:~ $ sudo npm install -g node-red-contrib-camerapi
  ```
###### Raspberry Pi SQLite Database
```sh
pi@raspberry:~ $ sudo apt-get install sqlite3
pi@raspberry:~/.node-red $ npm install node-red-node-sqlite
  ```
###### Raspberry Pi/ Cloud Server Mosquitto Broker
```sh
For Pi4: sudo apt install -y mosquitto mosquitto-clients
For Windows 10 Cloud Server: download the latest version of Eclipse Mosquitto from https://mosquitto.org/download/
  ```
