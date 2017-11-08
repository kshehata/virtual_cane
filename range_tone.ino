#include <Maxbotix.h>

const int ULTRASOUND_PIN = 6;
const int SPEAKER_PIN = 9;

const double MIN_DISTANCE = 10.0;
const double MAX_DISTANCE = 400.0;
const double MIN_TONE = 400.0;
const double MAX_TONE = 4000;
const int TONE_DURATION = 500;

Maxbotix rangeSensorPW(ULTRASOUND_PIN, Maxbotix::PW, Maxbotix::LV);

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long start = millis();
  double range = rangeSensorPW.getRange();
  int tone_freq = MAX_TONE - (constrain(range, MIN_DISTANCE, MAX_DISTANCE) - MIN_DISTANCE)
                  * (MAX_TONE - MIN_TONE) / (MAX_DISTANCE - MIN_DISTANCE);
  Serial.print("Range: ");
  Serial.print(range);
  Serial.print(" freq: ");
  Serial.print(tone_freq);
  
  tone(SPEAKER_PIN, tone_freq, TONE_DURATION);
  delay(10);
  Serial.print(" loop time: ");
  Serial.println(millis() - start);
}
