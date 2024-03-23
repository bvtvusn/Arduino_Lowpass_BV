#include "Lowpass_BV.h"

int sampleTimeMS = 200;
Lowpass_BV lowpass_pv(sampleTimeMS / 1000.0, 0.5);


void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Generate a random value between 0 and 1023
  float randomFloatValue = random(1000) / 1000.0;
  float filteredPv = lowpass_pv.update(randomFloatValue);
  // Output random value and fixed value (10) to the serial console
  Serial.print("RandomValue: ");
  Serial.print(randomFloatValue);
  Serial.print("\t FilteredValue: ");
  Serial.println(filteredPv);

  // Delay for a short period before repeating
  delay(sampleTimeMS);
}
