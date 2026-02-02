#define rainSensor A0
#define waterLevelSensor A1
#define relayPin 7
#define buzzer 8

int rainValue = 0;
int waterLevel = 0;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(relayPin, HIGH);  // Pump OFF (Relay Active LOW)
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
  Serial.println("Automatic Water Harvesting System Started");
}

void loop() {
  rainValue = analogRead(rainSensor);
  waterLevel = analogRead(waterLevelSensor);

  Serial.print("Rain Sensor: ");
  Serial.print(rainValue);
  Serial.print(" | Water Level: ");
  Serial.println(waterLevel);

  // Rain detected
  if (rainValue < 500) {  
    // Tank not full
    if (waterLevel < 700) {
      digitalWrite(relayPin, LOW);   // Pump ON
      digitalWrite(buzzer, HIGH);
      Serial.println("Rain Detected - Collecting Water");
    }
    // Tank full
    else {
      digitalWrite(relayPin, HIGH);  // Pump OFF
      digitalWrite(buzzer, LOW);
      Serial.println("Tank Full - Pump OFF");
    }
  }
  // No rain
  else {
    digitalWrite(relayPin, HIGH);    // Pump OFF
    digitalWrite(buzzer, LOW);
    Serial.println("No Rain - System Idle");
  }

  delay(1000);
}
