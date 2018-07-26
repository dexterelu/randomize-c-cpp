#define SAMPLES (255)

void randomize(uint8_t * data) {
  uint8_t marker[SAMPLES];
  uint16_t idx, tmp, rnd;
  memset(marker, 0, SAMPLES);
  for(idx = 0; idx < SAMPLES - 1; idx++) {
    if(marker[idx]) continue;
    tmp = data[idx];
    rnd = (esp_random() % (SAMPLES - idx)) + idx;
    marker[rnd] = 1;
    // switch contents
    data[idx] = data[rnd];
    data[rnd] = tmp;    
  }
}

uint8_t x[SAMPLES];
uint32_t timer;

void setup() {
  Serial.begin(115200);
  for(int i = 0; i < SAMPLES; i++) {
    x[i] = i;
  }
  timer = micros();
  randomize(x);
  timer = micros() - timer;
  Serial.println(String(timer, DEC) + " microseconds");
  for(int i = 0; i < SAMPLES; i++) {
    Serial.println(String(i, DEC) + ": " + String(x[i], DEC));
  }
}

void loop() {
 
}
