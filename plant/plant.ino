#define READPERIOD 5

unsigned long lastReadWrite;


void setup() {
  Serial.begin(9600);
  lastReadWrite = millis();

}

void loop() {
  if (millis() - lastReadWrite > READPERIOD) {
    int readValue = analogRead(A0);
    Serial.print(readValue);
    Serial.println();

    Serial.flush();
    lastReadWrite = millis();


  }
}

