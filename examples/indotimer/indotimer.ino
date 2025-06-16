#include <IndoTimer.h>

// Buat satu objek timer global
IndoTimer waktu;

// Fungsi yang akan dipanggil secara berulang
void tampilkanPesanBerkala() {
  Serial.println("Ini pesan setiap 15 detik");
}

// Fungsi yang hanya dipanggil sekali
void tampilkanSekaliSaja() {
  Serial.println("Ini hanya muncul sekali setelah 10 detik");
}

// Fungsi yang dipanggil terbatas (misal 10 kali)
void tampilkanSepuluhKali() {
  static int jumlah = 0;
  jumlah++;
  Serial.print("Dipanggil ke-");
  Serial.print(jumlah);
  Serial.println(" kali dari 10");
}

void setup() {
  Serial.begin(9600);

  Serial.println("Contoh penggunaan IndoTimer");
  Serial.println("-----------------------------");
  Serial.println("1. Fungsi pertama akan berjalan setiap 15 detik");
  Serial.println("2. Fungsi kedua hanya sekali setelah 10 detik");
  Serial.println("3. Fungsi ketiga hanya akan dipanggil 10 kali");

  // Atur fungsi-fungsi berdasarkan waktu
  waktu.aturInterval(15000, tampilkanPesanBerkala);    // setiap 15 detik
  waktu.aturSekali(10000, tampilkanSekaliSaja);        // sekali setelah 10 detik

  // Fungsi dibatasi 10x bisa kamu tambahkan nanti jika versi IndoTimer sudah support setTimer(durasi, fungsi, jumlah)
  // Untuk sekarang contoh hanya dua fungsi: interval dan sekali
}

void loop() {
  waktu.run(); // aktifkan pengecekan timer setiap loop
}
