// ─────────────────────────────────────────────
// EMO Drive - Arduino Sensor Code
// Sends: temp,bpm,gas,blink,blink_count
// ─────────────────────────────────────────────

#define TEMP_PIN A0
#define GAS_PIN  A1
#define PULSE_PIN A2
#define BLINK_PIN 2

unsigned long lastBlinkTime = 0;
int blinkCount = 0;

unsigned long lastSendTime = 0;
const int interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(BLINK_PIN, INPUT);
  Serial.println("EMO Drive Sensor Started...");
}

float readTemperature() {
  int val = analogRead(TEMP_PIN);
  float voltage = val * (5.0 / 1023.0);
  float tempC = voltage * 100.0;
  return tempC;
}

int readGas() {
  return analogRead(GAS_PIN);
}

int readBPM() {
  int signal = analogRead(PULSE_PIN);
  int bpm = map(signal, 0, 1023, 60, 120);
  return bpm;
}

int detectBlink() {
  int blink = digitalRead(BLINK_PIN);

  if (blink == LOW) {
    if (millis() - lastBlinkTime > 300) {
      blinkCount++;
      lastBlinkTime = millis();
      return 1;
    }
  }
  return 0;
}

void loop() {
  if (millis() - lastSendTime >= interval) {
    lastSendTime = millis();

    float temp = readTemperature();
    int gas = readGas();
    int bpm = readBPM();
    int blink = detectBlink();

    static unsigned long blinkWindow = millis();
    if (millis() - blinkWindow >= 60000) {
      blinkCount = 0;
      blinkWindow = millis();
    }

    Serial.print(temp);
    Serial.print(",");
    Serial.print(bpm);
    Serial.print(",");
    Serial.print(gas);
    Serial.print(",");
    Serial.print(blink);
    Serial.print(",");
    Serial.println(blinkCount);
  }
}
