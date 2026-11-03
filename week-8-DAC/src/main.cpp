#include <Arduino.h>

#define DAC_PIN     25
#define PWM_PIN     16

// Core 2 mein channel define karna compulsory hai
#define PWM_CHANNEL 0
#define PWM_FREQ    5000  // 5 kHz
#define PWM_RES     8     // 8-bit (0-255)

void setup()
{
  Serial.begin(115200);

  // 1. Channel setup karein
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);

  // 2. Pin ko channel ke sath attach karein
  ledcAttachPin(PWM_PIN, PWM_CHANNEL);
}

void loop()
{
  // DAC output (0-255)
  dacWrite(DAC_PIN, 128);

  // Core 2 mein pin nahi, balki channel number diya jata hai
  ledcWrite(PWM_CHANNEL, 128);

  Serial.println("DAC=128 | PWM duty=128");
  delay(1000);
}