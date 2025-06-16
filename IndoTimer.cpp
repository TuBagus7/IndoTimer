#include "IndoTimer.h"

IndoTimer::IndoTimer() {
  for (int i = 0; i < MAKS_TIMER; i++) {
    aktif[i] = false;
    daftarFungsi[i] = nullptr;
  }
}

int IndoTimer::aturInterval(unsigned long jeda, fungsi_timer fungsi) {
  for (int i = 0; i < MAKS_TIMER; i++) {
    if (!aktif[i]) {
      jedaTimer[i] = jeda;
      waktuSebelumnya[i] = millis();
      daftarFungsi[i] = fungsi;
      aktif[i] = true;
      hanyaSekali[i] = false;
      return i;
    }
  }
  return -1;
}

int IndoTimer::aturSekali(unsigned long jeda, fungsi_timer fungsi) {
  for (int i = 0; i < MAKS_TIMER; i++) {
    if (!aktif[i]) {
      jedaTimer[i] = jeda;
      waktuSebelumnya[i] = millis();
      daftarFungsi[i] = fungsi;
      aktif[i] = true;
      hanyaSekali[i] = true;
      return i;
    }
  }
  return -1;
}

void IndoTimer::hapusTimer(int id) {
  if (id >= 0 && id < MAKS_TIMER) {
    aktif[id] = false;
    daftarFungsi[id] = nullptr;
  }
}

void IndoTimer::jalankan() {
  unsigned long sekarang = millis();
  for (int i = 0; i < MAKS_TIMER; i++) {
    if (aktif[i] && daftarFungsi[i]) {
      if (sekarang - waktuSebelumnya[i] >= jedaTimer[i]) {
        waktuSebelumnya[i] = sekarang;
        daftarFungsi[i]();
        if (hanyaSekali[i]) {
          hapusTimer(i);
        }
      }
    }
  }
}
