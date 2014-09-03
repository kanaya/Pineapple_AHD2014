#define DELAY 100

#define SENSOR_RIBBON_MIN 600
#define SENSOR_RIBBON_MAX 1000

int sensorA = A0;
int led = 13;

int sensorValue = 0;

void midiSend(int cmd, int p1, int p2) {
  Serial1.write(cmd);
  Serial1.write(p1);
  Serial1.write(p2);
}

void midiNoteOn(int note, int velocity) {
  midiSend(0x90, note, velocity);
}

void midiControlChange(int control, int parameter) {
  midiSend(0xB0, control, parameter);
}

void setup() {
  pinMode(led, OUTPUT);
  Serial1.begin(31250);
}

void loop() {
  int ledValue, paramValue;
  sensorValue = analogRead(sensorA);
  ledValue = map(sensorValue, SENSOR_RIBBON_MIN, SENSOR_RIBBON_MAX, 0, 255); 
  paramValue = map(sensorValue, SENSOR_RIBBON_MIN, SENSOR_RIBBON_MAX, 0, 127);
  analogWrite(led, ledValue);
  midiControlChange(13, paramValue);
  delay(DELAY);
  analogWrite(led, 0);
  delay(DELAY);
}


