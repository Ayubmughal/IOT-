#include <Arduino.h>

#define BUZZER_PIN 18  // Changed to Pin 18
#define PWM_CHANNEL 0
#define PWM_RESOLUTION 8
#define PWM_INITIAL_FREQ 1000

// Note frequencies for Classical Tune (Für Elise snippet)
#define NOTE_E5  659
#define NOTE_DS5 622
#define NOTE_B4  494
#define NOTE_D5  587
#define NOTE_C5  523
#define NOTE_A4  440
#define NOTE_C4  262
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_B3  247

// Generate a tone
void playTone(int frequency, int duration) {
  if (frequency == 0) {
    ledcWriteTone(PWM_CHANNEL, 0);
  } else {
    ledcWriteTone(PWM_CHANNEL, frequency);
  }
  delay(duration);

  ledcWriteTone(PWM_CHANNEL, 0);
  delay(50);
}

// Pattern 1: Rising tones
void toneSequence() {
  playTone(300, 500);
  playTone(600, 500);
  playTone(1000, 500);
  playTone(1500, 500);
  playTone(2000, 500);
}

// Pattern 2: Alarm
void alarmSound() {
  for (int i = 0; i < 5; i++) {
    playTone(1000, 300);
    playTone(2000, 300);
  }
}

// Pattern 3: Doorbell
void doorbell() {
  playTone(1000, 300);
  playTone(1500, 600);
  delay(300);
  playTone(1000, 300);
  playTone(1500, 600);
}

// Pattern 4: Short beeps
void shortBeeps() {
  for (int i = 0; i < 5; i++) {
    playTone(2000, 100);
    delay(100);
  }
}

// Pattern 5: Simple melody
void melody() {
  playTone(523, 300);   // C5
  playTone(587, 300);   // D5
  playTone(659, 300);   // E5
  playTone(698, 300);   // F5
  playTone(784, 300);   // G5
  playTone(880, 300);   // A5
  playTone(988, 300);   // B5
  playTone(1047, 600);  // C6
}

// Pattern 6: Classical & Soulful Tone (Für Elise) ❤️
void classicalMelody() {
  playTone(NOTE_E5, 250);
  playTone(NOTE_DS5, 250);
  playTone(NOTE_E5, 250);
  playTone(NOTE_DS5, 250);
  playTone(NOTE_E5, 250);
  playTone(NOTE_B4, 250);
  playTone(NOTE_D5, 250);
  playTone(NOTE_C5, 250);
  playTone(NOTE_A4, 400);
  
  delay(200);
  
  playTone(NOTE_C4, 200);
  playTone(NOTE_E4, 200);
  playTone(NOTE_A4, 200);
  playTone(NOTE_B4, 400);
  
  delay(200);
  
  playTone(NOTE_E4, 200);
  playTone(NOTE_G4, 200);
  playTone(NOTE_B4, 200);
  playTone(NOTE_C5, 400);
}

void setup() {
  Serial.begin(115200);

  // Configure PWM
  ledcSetup(PWM_CHANNEL, PWM_INITIAL_FREQ, PWM_RESOLUTION);

  // Attach PWM channel to GPIO 18
  ledcAttachPin(BUZZER_PIN, PWM_CHANNEL);

  Serial.println("PWM Buzzer Ready on GPIO 18!");
}

void loop() {
  Serial.println("1. Rising Tone Sequence");
  toneSequence();
  delay(500);

  Serial.println("2. Alarm");
  alarmSound();
  delay(500);

  Serial.println("3. Doorbell");
  doorbell();
  delay(500);

  Serial.println("4. Short Beeps");
  shortBeeps();
  delay(500);

  Serial.println("5. Simple Melody");
  melody();
  delay(500);

  Serial.println("6. Classical Soulful Tone (Für Elise) ❤️");
  classicalMelody();
  delay(2500);
}