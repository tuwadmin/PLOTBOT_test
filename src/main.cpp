#include <Arduino.h>

//-----------------------------------------------------------------Wifi Manager
#include <WiFiManager.h>
#define CAPTIVE_PORTAL_TIMEOUT 30

bool runWiFiManager()
{
  /*
   * Initialize WiFi and start captive portal to set connection credentials
   */
  WiFi.setHostname("PLOTBOT");
  WiFi.mode(WIFI_AP); // explicitly set mode, esp defaults to STA+AP
  WiFi.enableAP(true);

  WiFiManager wifiManager;
  // wifiManager.setDebugOutput(true);
  //  wifiManager.debugPlatformInfo();
  wifiManager.setTitle("PlotBot Configuration Portal");
  wifiManager.setParamsPage(true);
  //  const char *bufferStr = R"(

  //   <!-- INPUT SELECT -->
  //   <br/>
  //   <label for='input_select'>INPUT 1</label>
  //   <select name="input_select" id="input_select" class="button">
  //   <option value="0">Analog </option>
  //   <option value="1" selected>Digital</option>
  //   </select>
  //   )";

  //   WiFiManagerParameter custom_html_inputs(bufferStr);
  //   wifiManager.addParameter(&custom_html_inputs);
  wifiManager.setSaveParamsCallback([&wifiManager]()
                                    {
                                      // inputs(*DI1);
                                    });

  wifiManager.setDarkMode(true);

  // wifiManager.setConfigPortalTimeout(CAPATITIVE_PORTAL_TIMEOUT / 1000); //if nobody logs in to the portal, continue after timeout
  wifiManager.setTimeout(CAPTIVE_PORTAL_TIMEOUT); // if nobody logs in to the portal, continue after timeout
  wifiManager.setConnectTimeout(CAPTIVE_PORTAL_TIMEOUT);
  // wifiManager.setSaveConnect(true);
  wifiManager.setAPClientCheck(true); // avoid timeout if client connected to softap
  Serial.println("[main] Start capatitive portal");

  if (wifiManager.startConfigPortal("PLOTBOT", "246810"))
  {
    return true;
  }
  else
  {
    return wifiManager.autoConnect("PLOTBOT", "246810");
  }
}

//-----------------------------------------------------------------DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
const int oneWireBus = 13;           // GPIO where the DS18B20 is connected to
OneWire oneWire(oneWireBus);         // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature sensor
float temperatureC, temperatureF;

float DS18B20_temp()
{
  sensors.requestTemperatures();
  temperatureC = sensors.getTempCByIndex(0);
  temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");

  return temperatureC;
}

//-----------------------------------------------------------------PH sensor
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads; /* Use this for the 16-bit version */
unsigned long int avgValue;
int buf[100], temp;
float calibration_value = 21.34; // 20.24 - 0.7;  //21.34 - 0.7
int16_t ph_adc;
float ph_volt, phValue;

float PH_value()
{
  ph_volt = ads.computeVolts(ph_adc);
  Serial.print("PH raw: ");
  Serial.print(ph_adc);

  Serial.print("PH Voltage = ");
  Serial.print(ph_volt, 4);
  Serial.println("V");

  phValue = (-5.70 * ph_volt) + calibration_value;
  Serial.print("pH =");
  Serial.println(phValue);

  return phValue;
}

//-----------------------------------------------------------------EC sensor
#include "DFRobot_ESP_EC.h"
#include "EEPROM.h"
DFRobot_ESP_EC ec;
int16_t ec_adc;
float ec_volt, sub_temp, ecValue;

float EC_value()
{
  ec_adc = ads.readADC_SingleEnded(0);
  Serial.print("EC raw: ");
  Serial.println(ec_adc);

  ec_volt = ads.computeVolts(ec_adc);
  Serial.print("EC voltage:");
  Serial.println(ec_volt, 4);

  sub_temp = DS18B20_temp();

  ecValue = ec.readEC(ec_volt, sub_temp); // convert voltage to EC with temperature compensation
  Serial.print("EC:");
  Serial.print(ecValue, 4);
  Serial.println("ms/cm");

  return ecValue;
}

//-----------------------------------------------------------------SCD-30 CO2 Sensor
#include <Adafruit_SCD30.h>
Adafruit_SCD30 scd30;

//-----------------------------------------------------------------HTTP server
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <SSL_certificate.h>
const char *serverName = "https://us-central1-plotbot-a8e8f.cloudfunctions.net/sensorsApi?deviceId=dr3w4rc45t4t3";
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
WiFiClientSecure client;

//-----------------------------------------------------------------OTA setup
#include <HTTPUpdate.h>
#include <OTA_cert.h>
String FirmwareVer = {"1.0"};
#define URL_fw_Version "https://github.com/Abdullah-python/esp32-ota/blob/master/firmware_version.txt"
#define URL_fw_Bin "https://raw.githubusercontent.com/Abdullah-python/esp32-ota/master/firmware.bin"
unsigned long previousMillis = 0; // will store last time LED was updated
const long interval = 60000;

int FirmwareVersionCheck(void)
{
  String payload;
  int httpCode;
  String fwurl = "";
  fwurl += URL_fw_Version;
  fwurl += "?";
  fwurl += String(rand());
  Serial.println(fwurl);
  WiFiClientSecure *client = new WiFiClientSecure;

  if (client)
  {
    client->setCACert(CAcert);

    // Add a scoping block for HTTPClient https to make sure it is destroyed before WiFiClientSecure *client is
    HTTPClient https;

    if (https.begin(*client, fwurl))
    { // HTTPS
      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      delay(100);
      httpCode = https.GET();
      delay(100);
      if (httpCode == HTTP_CODE_OK) // if version received
      {
        payload = https.getString(); // save received version
      }
      else
      {
        Serial.print("error in downloading version file:");
        Serial.println(httpCode);
      }
      https.end();
    }
    delete client;
  }

  if (httpCode == HTTP_CODE_OK) // if version received
  {
    payload.trim();
    if (payload.toFloat() > FirmwareVer.toFloat())
    {
      Serial.printf("\nDevice already on latest firmware version:%s\n", FirmwareVer);
      return 0;
    }
    else if (payload.equals(FirmwareVer))
    {
      Serial.printf("\nDevice already on latest firmware version:%s\n", FirmwareVer);
      return 0;
    }
    else
    {
      Serial.println(payload);
      Serial.println("New firmware detected");
      return 1;
    }
  }
  return 0;
}

void firmwareUpdate(void)
{
  WiFiClientSecure client;
  client.setCACert(CAcert);
  httpUpdate.setLedPin(2, LOW);
  t_httpUpdate_return ret = httpUpdate.update(client, URL_fw_Bin);

  switch (ret)
  {
  case HTTP_UPDATE_FAILED:
    Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
    break;

  case HTTP_UPDATE_NO_UPDATES:
    Serial.println("HTTP_UPDATE_NO_UPDATES");
    break;

  case HTTP_UPDATE_OK:
    Serial.println("HTTP_UPDATE_OK");
    break;
  }
}

void OTA_firmware_check()
{
  Serial.print("Firmware Version: ");
  Serial.println(FirmwareVer);
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis) >= interval)
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    if (FirmwareVersionCheck())
    {
      firmwareUpdate();
    }
  }
}

//-----------------------------------------------------------------General Variables
float EC_reading, PH_reading, Sub_temp_reading, Temp_reading, Hum_reading, CO2_reading;

void setup()
{
  Serial.begin(115200);
  Serial.print("Active firmware version:");
  Serial.println(FirmwareVer);
  EEPROM.begin(32); // needed EEPROM.begin to store calibration k in eeprom

  if (!runWiFiManager())
  {
    // couldn't connect
    Serial.println("[main] Couldn't connect to WiFi after multiple attempts");
    delay(30000);
    ESP.restart();
  }
  Serial.println("WiFi Connected");

  if (!ads.begin(0x48))
  {
    Serial.println("Failed to initialize ADS.");
    while (1)
      ;
  }
  Serial.println("External ADC initialized");

  ec.begin(); // by default lib store calibration k since 10 change it by set ec.begin(30); to start from 30
  Serial.println("EC sensor initialized");

  if (!scd30.begin())
  {
    Serial.println("Failed to find SCD30 chip");
    while (1)
    {
      delay(10);
    }
  }
  Serial.println("SCD30 initialized");

  client.setCACert(test_root_ca);

  Serial.println("\nStarting connection to server...");
  if (!client.connect(serverName, 443))
    Serial.println("Connection failed!");
  else
  {
    Serial.println("Connected to server!");
  }
}

void loop()
{
  ec.calibration(ec_volt, sub_temp); // calibration process by Serail CMD

  OTA_firmware_check();

  if ((millis() - lastTime) > timerDelay)
  {
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED)
    {
      HTTPClient https;

      // Your Domain name with URL path or IP address with path
      https.begin(client, serverName);

      // Get readings
      EC_reading = EC_value();
      PH_reading = PH_value();
      Sub_temp_reading = DS18B20_temp();
      Temp_reading = scd30.temperature;
      Hum_reading = scd30.relative_humidity;
      CO2_reading = scd30.CO2;

      // If you need Node-RED/server authentication, insert user and password below
      // http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");

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
    }
    else
    {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}