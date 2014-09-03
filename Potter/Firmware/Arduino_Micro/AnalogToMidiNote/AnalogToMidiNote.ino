#define midiNoteA3 69
#define DELAY 200

int sensorA = A0;
int led = 13;

int sensorValue = 0;

void midiSend(int cmd, int note, int velocity) {
  Serial1.write(cmd);
  Serial1.write(note);
  Serial1.write(velocity);
}

void midiNoteOn(int note, int velocity) {
  midiSend(0x90, note, velocity);
}

void setup() {
  pinMode(led, OUTPUT);
  Serial1.begin(31250);
}

void loop() {
  int ledValue, noteValue;
  sensorValue = analogRead(sensorA);
  ledValue = map(sensorValue, 0, 1023, 0, 255); 
  noteValue = map(sensorValue, 600, 1000, 0x1E, 0x5A);
  analogWrite(led, ledValue);
  midiNoteOn(noteValue, 127);
  delay(DELAY);
}


