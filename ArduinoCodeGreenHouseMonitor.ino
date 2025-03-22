#include <WiFi.h>
#include <ThingSpeak.h>
#include <Arduino.h>
#include <DHT.h>

#define RELAY_PIN 4
#define RELAY_PIN1 5
#define RELAY_PIN2 18
#define DHTPIN 27
#define DHTTYPE DHT22
const int MQ135_PIN = A3;
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

const char* ssid = "Mrutyunjaya";
const char* password = "mrutyunjaya@15";
const char* apiKey = "QBNCAMP34V9MDNMH";
const unsigned long channelId =2447500;

void setup() {
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

  // Initialize DHT sensor
  dht.begin();

  // Initialize relay pins
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
}

void loop() {
  // Read LDR sensor value
  int ldrValue = analogRead(A5);
  Serial.println(ldrValue);
  if (ldrValue > 3100) {
    Serial.println(" => DARK");
    digitalWrite(RELAY_PIN, LOW);
  } else {
    Serial.println(" => LIGHT");
    digitalWrite(RELAY_PIN, HIGH);
  }
  // Read temperature and humidity from DHT sensor
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Print temperature and humidity
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Control relay based on temperature
  if (temp > 30) {
    Serial.println(" => HOT");
    digitalWrite(RELAY_PIN1, LOW);
  } else {
    Serial.println(" => COOL");
    digitalWrite(RELAY_PIN1, HIGH);
  }



  // Read soil moisture sensor value
  int moisture = analogRead(A0);
  // Map the raw sensor value to a percentage (0-100)
  int moisturePercentage = map(moisture, 0, 4095, 100, 0);
  // Print the moisture percentage
  Serial.print("Soil Moisture Percentage: ");
  Serial.println(moisturePercentage);
  // Control relay based on soil moisture
  if (moisturePercentage < 50) {
    Serial.println(" => DRY");
    digitalWrite(RELAY_PIN2, LOW);
  } else {
    Serial.println(" => WET");
    digitalWrite(RELAY_PIN2, HIGH);
  }
  float co2Percentage = readCO2Percentage();
  
  Serial.print("CO2 Percentage: ");
  Serial.print(co2Percentage);
  Serial.println("%");

  // Send data to ThingSpeak
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, moisturePercentage);
  ThingSpeak.setField(4, co2Percentage);
  ThingSpeak.setField(5, ldrValue);
  ThingSpeak.writeFields(channelId, apiKey);

  // Wait before sending the next data point
  delay(2000);
}
float readCO2Percentage() {
  int sensorValue = analogRead(MQ135_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);
  float co2Resistance = (5.0 - voltage) / voltage;
  float co2Percentage = 116.6020682 * pow(co2Resistance, -2.769034857);

  return co2Percentage;
}