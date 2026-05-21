const int sensorPin = A0;
const int ledPin = 4;
const int buzzerPin = 7;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int rawReading = analogRead(sensorPin);
  float voltage = rawReading * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;

  if (temperatureC < 0) {
    digitalWrite(ledPin, HIGH);
    noTone(buzzerPin);
  } 
  else if (temperatureC >= 30 && temperatureC <= 40) {
    digitalWrite(ledPin, LOW);
    tone(buzzerPin, 1000);
  } 
  else if (temperatureC > 40) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  } 
  else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(500);
}