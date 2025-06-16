#ifndef IndoTimer_h
#define IndoTimer_h

#include <Arduino.h>

typedef void (*fungsi_timer)();

class IndoTimer {
  public:
    IndoTimer();

    int aturInterval(unsigned long jeda, fungsi_timer fungsi);
    int aturSekali(unsigned long jeda, fungsi_timer fungsi);
    void hapusTimer(int id);
    void jalankan();

  private:
    static const int MAKS_TIMER = 10;

    unsigned long waktuSebelumnya[MAKS_TIMER];
    unsigned long jedaTimer[MAKS_TIMER];
    fungsi_timer daftarFungsi[MAKS_TIMER];
    bool aktif[MAKS_TIMER];
    bool hanyaSekali[MAKS_TIMER];
};

#endif
