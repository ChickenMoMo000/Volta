/*************************************************************
  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */

#define BLYNK_TEMPLATE_ID "TMPL6AaUezwlK"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "8FULwEo9_9M0E6JR1D5d6-kICN-bJ2hb"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Robi";
char pass[] = "1234567890";
float thresholdVoltage = 6.0;

// Define relay pins
#define relay1_pin 13
#define relay2_pin 12
#define relay3_pin 14
#define relay4_pin 27
#define relay5_pin 26
#define relay6_pin 25
#define relay7_pin 33
#define relay8_pin 32

BlynkTimer timer;
bool relay1_autoOff = true;
bool relay2_autoOff = true;
bool relay3_autoOff = true;
bool relay4_autoOff = true;
bool relay5_autoOff = true;
bool relay6_autoOff = true;
bool relay7_autoOff = true;
bool relay8_autoOff = true;
bool relay1_manual = false;
bool relay2_manual = false;
bool relay3_manual = false;
bool relay4_manual = false;
bool relay5_manual = false;
bool relay6_manual = false;
bool relay7_manual = false;
bool relay8_manual = false;

void checkVoltage() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    float voltage = data.toFloat();
    
    // Checking if voltage exceeds threshold
    if (voltage > thresholdVoltage) {
       String warningMessage = "Warning: Your voltage level is increasing. Voltage: " + String(voltage, 2) + " V. Take actions...";
       
       Serial.println(warningMessage);
       Blynk.logEvent("voltage_alert", warningMessage);
       Blynk.virtualWrite(V1, voltage); // Sending voltage value to virtual pin V1
       
       // Turn on relays
       digitalWrite(relay1_pin, HIGH);
       digitalWrite(relay2_pin, HIGH);
       digitalWrite(relay3_pin, HIGH);
       digitalWrite(relay4_pin, HIGH);
       digitalWrite(relay5_pin, HIGH);
       digitalWrite(relay6_pin, HIGH);
       digitalWrite(relay7_pin, HIGH);
       digitalWrite(relay8_pin, HIGH);

       // Starting timer for each relay
       timer.setTimeout(15000L, []() {  // 15 seconds delay
         if (!relay1_manual) digitalWrite(relay1_pin, LOW);
         if (!relay2_manual) digitalWrite(relay2_pin, LOW);
         if (!relay3_manual) digitalWrite(relay3_pin, LOW);
         if (!relay4_manual) digitalWrite(relay4_pin, LOW);
         if (!relay5_manual) digitalWrite(relay5_pin, LOW);
         if (!relay6_manual) digitalWrite(relay6_pin, LOW);
         if (!relay7_manual) digitalWrite(relay7_pin, LOW);
         if (!relay8_manual) digitalWrite(relay8_pin, LOW);
       });
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(relay1_pin, OUTPUT);
  pinMode(relay2_pin, OUTPUT);
  pinMode(relay3_pin, OUTPUT);
  pinMode(relay4_pin, OUTPUT);
  pinMode(relay5_pin, OUTPUT);
  pinMode(relay6_pin, OUTPUT);
  pinMode(relay7_pin, OUTPUT);
  pinMode(relay8_pin, OUTPUT);

  timer.setInterval(100L, checkVoltage);
}

void loop() {
  Blynk.run();
  timer.run();
}

/// Blynk button control handlers
BLYNK_WRITE(V1) {
  int state = param.asInt();
  digitalWrite(relay1_pin, state);
  relay1_manual = (state == HIGH);
}

BLYNK_WRITE(V2) {
  int state = param.asInt();
  digitalWrite(relay2_pin, state);
  relay2_manual = (state == HIGH);
}

BLYNK_WRITE(V3) {
  int state = param.asInt();
  digitalWrite(relay3_pin, state);
  relay3_manual = (state == HIGH);
}

BLYNK_WRITE(V4) {
  int state = param.asInt();
  digitalWrite(relay4_pin, state);
  relay4_manual = (state == HIGH);
}

BLYNK_WRITE(V5) {
  int state = param.asInt();
  digitalWrite(relay5_pin, state);
  relay5_manual = (state == HIGH);
}

BLYNK_WRITE(V6) {
  int state = param.asInt();
  digitalWrite(relay6_pin, state);
  relay6_manual = (state == HIGH);
}

BLYNK_WRITE(V7) {
  int state = param.asInt();
  digitalWrite(relay7_pin, state);
  relay7_manual = (state == HIGH);
}

BLYNK_WRITE(V8) {
  int state = param.asInt();
  digitalWrite(relay8_pin, state);
  relay8_manual = (state == HIGH);
}
