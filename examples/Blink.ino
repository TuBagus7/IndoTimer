// Panggil library buatan sendiri
#include <IndoTimer.h>

// Buat objek timer
IndoTimer waktu;

// Fungsi ini akan menyalakan dan mematikan LED bergantian
void kedipLED() {
  // Baca status LED sekarang (nyala atau mati)
  int statusSekarang = digitalRead(LED_BUILTIN);

  // Kalau nyala, matikan. Kalau mati, nyalakan.
  if (statusSekarang == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void setup() {
  // Atur pin LED sebagai output
  pinMode(LED_BUILTIN, OUTPUT);

  // Jalankan fungsi kedipLED setiap 1000 milidetik (1 detik)
  waktu.aturInterval(1000, kedipLED);
}

void loop() {
  // Jalankan timer setiap loop
  waktu.jalankan();
}
