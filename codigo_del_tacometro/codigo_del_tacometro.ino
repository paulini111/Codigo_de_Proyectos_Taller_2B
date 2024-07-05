const int hallPin = 2;
const int maxCnt = 100;

void setup() {
  Serial.begin(9600);
  pinMode(hallPin, INPUT);
}

void loop() {
  unsigned long start = micros();
  int old = 1;
  int cnt = 0;
  while (cnt < maxCnt) {
    int val = digitalRead(hallPin);
    if (!val && val != old) cnt++;
    old = val;
  }
  float seconds = (micros() - start) / 1000000.0;
  float rpm = cnt / seconds * 60.0;
  Serial.print("rpm: ");
  Serial.println(rpm);
}
