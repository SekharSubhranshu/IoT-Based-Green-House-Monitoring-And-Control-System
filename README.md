# IoT-Based-Green-House-Monitoring-And-Control-System-
This project is an IoT-based Greenhouse Monitoring System that uses ESP32, DHT22, MQ135, and LDR sensors to track environmental conditions. The data is logged to ThingSpeak for remote monitoring, and relays are used to automate greenhouse controls. Ideal for smart farming and precision agriculture applications.

# 🌱 IoT-Based Greenhouse Monitoring System  

## 📌 Project Overview  
This project uses **ESP32, DHT22, MQ135, LDR sensors, and ThingSpeak** to monitor greenhouse conditions.  
It automatically controls devices using **relays** and logs data to **ThingSpeak** for remote monitoring.  

## 🚀 Features  
✅ **Temperature & Humidity Monitoring** (DHT22 Sensor)  
✅ **Air Quality Detection** (MQ135 Sensor)  
✅ **Light Intensity Measurement** (LDR Sensor)  
✅ **Automated Control System** (Relays for controlling devices)  
✅ **Cloud Data Logging** on **ThingSpeak**  
✅ **Wi-Fi Connectivity** for real-time monitoring  

## 🛠️ Hardware Used  
- **ESP32-WROOM** (Microcontroller)  
- **DHT22 Sensor** (Temperature & Humidity)  
- **MQ135 Sensor** (Air Quality / Gas Detection)  
- **LDR Sensor** (Light Intensity Measurement)  
- **Relay Module** (Controls external devices)  

## 📡 Software & Technologies  
- **Arduino IDE** (Programming ESP32)  
- **ThingSpeak API** (Cloud Data Visualization)  
- **Wi-Fi Communication** (ESP32 connects to a network)


#Install Required Libraries

Open Arduino IDE → Library Manager → Install:
WiFi.h (Built-in for ESP32)
ThingSpeak.h
DHT.h (DHT Sensor Library)


#Update Wi-Fi Credentials in the Code

Open complete_code.ino
Replace these lines with your actual Wi-Fi credentials:
const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";


#Update ThingSpeak API Key

Sign up at ThingSpeak and create a new channel.
Replace apiKey and channelId in the code:
const char* apiKey = "Your_ThingSpeak_API_Key";
const unsigned long channelId= Your_Channel_ID;


Monitor Data on ThingSpeak
Go to ThingSpeak Dashboard to see real-time sensor data.

📜 License
This project is open-source under the MIT License.
