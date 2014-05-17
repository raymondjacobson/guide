#include "temperature.h" 
#include "speaker.h"
#include "waterlevel.h"

// Define pinouts
int tempSensorPin = 2;
int speakerPin = 3;
int chargingPin = 4;

int waterLevelPowerPin = 4;
int waterLevelR0 = A0;
int waterLevelR1 = A1;
int waterLevelR2 = A2;
// Keep track of previous values as we fill cup
bool passed0 = false;
bool passed1 = false;
bool passed2 = false;

bool hot = false;
bool charging = false;
//float hot_temp = 60.46; /*Defines Hot Temperature*/
float hot_temp = 22;
// Initialize objects
GuideTemperature guideTemp(tempSensorPin);
GuideSpeaker guideSpeaker(speakerPin);
GuideWaterlevel guideWaterlevel(waterLevelPowerPin, waterLevelR0, waterLevelR1, waterLevelR2);

void setup(void) {
  pinMode(tempSensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(chargingPin, INPUT);
  Serial.begin(9600);
}

void loop(void) {
  float temperature = guideTemp.getTemp();
  Serial.println(temperature);
  delay(300);
  int isCharging = digitalRead(chargingPin);
  if (isCharging == 1 && !charging){
    guideSpeaker.beep(700, 1, 1000);
    charging = true;
  } 
  if (isCharging == 0 && charging){
    charging = false; 
  }
  
  
  if (temperature > hot_temp && !hot){
    Serial.println("Guide says it's too hot!");
    guideSpeaker.beep(800, 3, 200);
    hot = true;
  }
  if (temperature < hot_temp && hot){
    Serial.println("Guide says safe to drink");
    guideSpeaker.beep(600, 3, 600);
    hot = false;
  }
  // Check all three water level sensors
  guideWaterlevel.checkSubmerge();
  if (guideWaterlevel.r2read && !passed2){
    Serial.println("Guide passed top sensor");
    guideSpeaker.beep(500, 3, 50);
    passed2 = true;
  }
  if (!guideWaterlevel.r2read && passed2){
    passed2 = false;
  }
  if (guideWaterlevel.r1read && !passed1){
    Serial.println("Guide passed middle sensor");
    guideSpeaker.beep(500, 2, 50);
    passed1 = true;
  }
  if (!guideWaterlevel.r1read && passed1){
    passed1 = false; 
  }
  if (guideWaterlevel.r0read && !passed0){
    Serial.println("Guide passed bottom sensor");
    guideSpeaker.beep(500, 1, 50);
    passed0 = true;
  }
  if (!guideWaterlevel.r0read && passed0){
    passed0 = false;
  }
}
