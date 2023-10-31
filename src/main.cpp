#include <Arduino.h>

//Wifi Manager
#include <WiFiManager.h>
#define CAPTIVE_PORTAL_TIMEOUT 30

//PH sensor
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads; /* Use this for the 16-bit version */
unsigned long int avgValue;
int buf[100], temp;
float calibration_value = 21.34;  //20.24 - 0.7;  //21.34 - 0.7
int16_t ph_adc;
float ph_volt, phValue;

//EC sensor
#include "DFRobot_ESP_EC.h"
#include "EEPROM.h"
DFRobot_ESP_EC ec;
int16_t ec_adc;
float ec_volt, sub_temp, ecValue;

//DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
const int oneWireBus = 13;            // GPIO where the DS18B20 is connected to
OneWire oneWire(oneWireBus);          // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);  // Pass our oneWire reference to Dallas Temperature sensor
float temperatureC, temperatureF;

//SCD-30 CO2 Sensor
#include <Adafruit_SCD30.h>
Adafruit_SCD30 scd30;

//HTTP server
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <SSL_certificate.h>
const char* serverName = "https://us-central1-plotbot-a8e8f.cloudfunctions.net/sensorsApi?deviceId=dr3w4rc45t4t3";
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
WiFiClientSecure client;


//General Variables
float EC_reading, PH_reading, Sub_temp_reading, Temp_reading, Hum_reading, CO2_reading;

void setup() {
 Serial.begin(115200);
  EEPROM.begin(32);  //needed EEPROM.begin to store calibration k in eeprom

  if (!runWiFiManager()) {
    //couldn't connect
    Serial.println("[main] Couldn't connect to WiFi after multiple attempts");
    delay(30000);
    ESP.restart();
  }
  Serial.println("WiFi Connected");

  if (!ads.begin(0x48)) {
    Serial.println("Failed to initialize ADS.");
    while (1)
      ;
  }
  Serial.println("External ADC initialized");

  ec.begin();  //by default lib store calibration k since 10 change it by set ec.begin(30); to start from 30
  Serial.println("EC sensor initialized");

  if (!scd30.begin()) {
    Serial.println("Failed to find SCD30 chip");
    while (1) { delay(10); }
  }
  Serial.println("SCD30 initialized");

  client.setCACert(test_root_ca);

  Serial.println("\nStarting connection to server...");
  if (!client.connect(serverName, 443))
    Serial.println("Connection failed!");
  else {
    Serial.println("Connected to server!");
  }
}

void loop() {
    ec.calibration(ec_volt, sub_temp);  // calibration process by Serail CMD

  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient https;

      // Your Domain name with URL path or IP address with path
      https.begin(client, serverName);

      //Get readings
      EC_reading = EC_value();
      PH_reading = PH_value();
      Sub_temp_reading = DS18B20_temp();
      Temp_reading = scd30.temperature;
      Hum_reading = scd30.relative_humidity;
      CO2_reading = scd30.CO2;

      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");

      // Specify content-type header
      https.addHeader("Content-Type", "application/x-www-form-urlencoded");

      // Data to send with HTTP POST
      String httpsRequestData = "{\r\n    \"ph\": {\r\n        \"value\": " + String(PH_reading) + "\r\n    },\r\n    \"wt\": {\r\n        \"value\": " + String(Sub_temp_reading) + "\r\n    },\r\n    \"at\": {\r\n        \"value\": " + String(Temp_reading) + "\r\n    },\r\n    \"ec\": {\r\n        \"value\": " + String(EC_reading) + "\r\n    },\r\n    \"co2\": {\r\n        \"value\": " + String(CO2_reading) + "\r\n    },\r\n    \"hum\": {\r\n        \"value\": " + String(Hum_reading) + "\r\n    }\r\n}";

      // Send HTTP POST request
      int httpsResponseCode = https.POST(httpsRequestData);

      Serial.print("HTTPS Response code: ");
      Serial.println(httpsResponseCode);

      // Free resources
      https.end();
    } else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}