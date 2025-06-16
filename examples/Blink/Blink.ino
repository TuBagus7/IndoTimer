// Panggil library
#include <IndoTimer.h>

//objek timer
IndoTimer waktu;

// Fungsi ini untuk menghidupkan dan  mematikan LED bergantian
void kedipLED() {
    int statusSekarang = digitalRead(LED_BUILTIN);

  if (statusSekarang == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void setup() {
  // Atur pin LED sebagai output
  pinMode(LED_BUILTIN, OUTPUT);

  waktu.aturInterval(1000, kedipLED);
}

void loop() {
  waktu.jalankan();
}
