#ifndef TIPE_JAM_H
#define TIPE_JAM_H

#include <iostream>

class tipeJam {
public:
    void setWaktu(int, int, int);
    void dapatkanWaktu(int&, int&, int&) const;
    void cetakWaktu() const;

    void incrementDetik();
    void incrementMenit();
    void incrementJam();

    // Fungsi baru untuk decrement
    void decrementDetik();
    void decrementMenit();
    void decrementJam();

    bool equalWaktu(const tipeJam&) const;

    // Operator overloading untuk penambahan, pengurangan, dan output
    tipeJam operator+(const tipeJam& other) const;
    tipeJam operator-(const tipeJam& other) const;
    friend std::ostream& operator<<(std::ostream& os, const tipeJam& jam);

    tipeJam(int, int, int);
    tipeJam();

private:
    int jm;  // Jam
    int mnt; // Menit
    int dtk; // Detik

    // Fungsi bantuan untuk konversi ke total detik
    long toSeconds() const;
    // Fungsi bantuan untuk konversi dari total detik
    void fromSeconds(long totalSeconds);
};

#endif // TIPE_JAM_H
