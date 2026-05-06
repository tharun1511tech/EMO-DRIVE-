// EMO Drive - Arduino Code with Actuators
// Stress -> Vibration Motor ON
// Drowsy -> Water Pump ON

#define TEMP_PIN A0
#define GAS_PIN  A1
#define PULSE_PIN A2
#define BLINK_PIN 2

#define VIBRATION_PIN 8   // vibration motor
#define PUMP_PIN 9        // water pump (via relay/module)

unsigned long lastBlinkTime = 0;
int blinkCount = 0;

unsigned long lastSendTime = 0;
const int interval = 1000;

void setup() {
  Serial.begin(9600);

  pinMode(BLINK_PIN, INPUT);
  pinMode(VIBRATION_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);

  digitalWrite(VIBRATION_PIN, LOW);
  digitalWrite(PUMP_PIN, LOW);
}

float readTemperature() {
  int val = analogRead(TEMP_PIN);
  float voltage = val * (5.0 / 1023.0);
  return voltage * 100.0;
}

int readGas() {
  return analogRead(GAS_PIN);
}

int readBPM() {
  int signal = analogRead(PULSE_PIN);
  return map(signal, 0, 1023, 60, 120);
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

void controlActuators(float temp, int bpm, int blink_count) {
  // Stress / Anxiety condition
  if (bpm >= 90 && blink_count > 17) {
    digitalWrite(VIBRATION_PIN, HIGH);
  } else {
    digitalWrite(VIBRATION_PIN, LOW);
  }

  // Drowsiness condition
  if (bpm < 65 && blink_count < 8) {
    digitalWrite(PUMP_PIN, HIGH);
  } else {
    digitalWrite(PUMP_PIN, LOW);
  }
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

    controlActuators(temp, bpm, blinkCount);

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
