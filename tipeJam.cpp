#include "tipeJam.h"
#include <iomanip>

// --- Fungsi Bantuan ---
long tipeJam::toSeconds() const {
    return jm * 3600 + mnt * 60 + dtk;
}

void tipeJam::fromSeconds(long totalSeconds) {
    jm = (totalSeconds / 3600); // Tidak perlu modulo 24 agar bisa negatif
    mnt = (totalSeconds % 3600) / 60;
    dtk = totalSeconds % 60;
}

// --- Metode yang Ada (dengan sedikit perbaikan) ---
void tipeJam::setWaktu(int jam, int menit, int detik) {
    jm = (0 <= jam) ? jam : 0;
    mnt = (0 <= menit && menit < 60) ? menit : 0;
    dtk = (0 <= detik && detik < 60) ? detik : 0;
}

void tipeJam::dapatkanWaktu(int& jam, int& menit, int& detik) const {
    jam = jm;
    menit = mnt;
    detik = dtk;
}

void tipeJam::incrementJam() {
    jm++;
    if (jm > 23) jm = 0;
}

void tipeJam::incrementMenit() {
    mnt++;
    if (mnt > 59) {
        mnt = 0;
        incrementJam();
    }
}

void tipeJam::incrementDetik() {
    dtk++;
    if (dtk > 59) {
        dtk = 0;
        incrementMenit();
    }
}

void tipeJam::cetakWaktu() const {
    std::cout << std::setfill('0') << std::setw(2) << jm << ":"
        << std::setfill('0') << std::setw(2) << mnt << ":"
        << std::setfill('0') << std::setw(2) << dtk;
}

bool tipeJam::equalWaktu(const tipeJam& otherClock) const {
    return (jm == otherClock.jm && mnt == otherClock.mnt && dtk == otherClock.dtk);
}

// --- Constructor ---
tipeJam::tipeJam(int jam, int menit, int detik) {
    setWaktu(jam, menit, detik);
}

tipeJam::tipeJam() {
    jm = 0;
    mnt = 0;
    dtk = 0;
}

// --- Implementasi Baru ---

void tipeJam::decrementJam() {
    jm--;
    if (jm < 0) jm = 23;
}

void tipeJam::decrementMenit() {
    mnt--;
    if (mnt < 0) {
        mnt = 59;
        decrementJam();
    }
}

void tipeJam::decrementDetik() {
    dtk--;
    if (dtk < 0) {
        dtk = 59;
        decrementMenit();
    }
}

// Implementasi operator +
tipeJam tipeJam::operator+(const tipeJam& other) const {
    tipeJam result;
    result.fromSeconds(this->toSeconds() + other.toSeconds());
    return result;
}

// Implementasi operator -
tipeJam tipeJam::operator-(const tipeJam& other) const {
    tipeJam result;
    result.fromSeconds(this->toSeconds() - other.toSeconds());
    return result;
}

// Implementasi operator << untuk pencetakan (friend function)
std::ostream& operator<<(std::ostream& os, const tipeJam& jam) {
    // Menangani jam negatif untuk saldo
    if (jam.toSeconds() < 0) {
        os << "-";
        os << std::setfill('0') << std::setw(2) << abs(jam.jm) << ":"
            << std::setfill('0') << std::setw(2) << abs(jam.mnt) << ":"
            << std::setfill('0') << std::setw(2) << abs(jam.dtk);
    }
    else {
        os << std::setfill('0') << std::setw(2) << jam.jm << ":"
            << std::setfill('0') << std::setw(2) << jam.mnt << ":"
            << std::setfill('0') << std::setw(2) << jam.dtk;
    }
    return os;
}
