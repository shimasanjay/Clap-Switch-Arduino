int micPin = A0;       // Pin connected to the microphone
int gndPin = A1;
int powerPin = A2;

int micValue1 = 0;
int micValue2 = 0;     // Microphone value

int led1 = 13;
boolean lightOn = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(micPin, INPUT);

  digitalWrite(gndPin, LOW);
  delay(500);
  digitalWrite(powerPin, HIGH);

  Serial.begin(9600); // For serial monitoring
}

void loop() {
  micValue1 = analogRead(micPin);  // Read mic value
  Serial.println(micValue1);
  delay(1);

  micValue2 = analogRead(micPin);
  Serial.println(micValue2);

  if (micValue1 - micValue2 > 2 || micValue2 - micValue1 > 2) {
    lightOn = !lightOn;
    delay(100);
    digitalWrite(led1, lightOn);
  }
}
