#define piezoPin A0
#define relayPin 7
#define buzzerPin 8

int piezoValue = 0;
int threshold = 300;  // Adjust based on sensor sensitivity

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(relayPin, HIGH); // Pump OFF (Active LOW Relay)
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);
  Serial.println("Piezoelectric Sensor Based Farming System Started");
}

void loop() {
  piezoValue = analogRead(piezoPin);
  Serial.print("Piezo Value: ");
  Serial.println(piezoValue);

  if (piezoValue > threshold) {
    digitalWrite(relayPin, LOW);   // Pump ON
    digitalWrite(buzzerPin, HIGH); // Alert
    Serial.println("Vibration Detected - Irrigation ON");
    delay(3000);
  } else {
    digitalWrite(relayPin, HIGH);  // Pump OFF
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}
