#define READPERIOD 5

unsigned long lastReadWrite;
const int ledPin = 2;

void setup() {
  Serial.begin(9600);
  lastReadWrite = millis();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (millis() - lastReadWrite > READPERIOD) {
    int readValue = analogRead(A0);
    Serial.print(readValue);
    Serial.println();

    Serial.flush();
    lastReadWrite = millis();

    if (readValue > 900) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}

