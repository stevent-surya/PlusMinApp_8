#ifndef ABSENSI_HARIAN_H
#define ABSENSI_HARIAN_H

#include "tipeJam.h"
#include <string>
#include <iostream>

class AbsensiHarian {
public:
    std::string hari;
    bool hadir;
    tipeJam jamPlus;
    tipeJam jamMinus;

    // Constructor
    AbsensiHarian(std::string namaHari = "") : hari(namaHari), hadir(false), jamPlus(), jamMinus() {}

    // Fungsi untuk input data absensi (LOGIKA DIPERBARUI)
    void inputAbsen() {
        char status;
        std::cout << "- Absensi hari " << hari << " (h/t - Hadir/Tidak Hadir): ";
        std::cin >> status;

        int j, m, d;

        if (status == 'h' || status == 'H') {
            hadir = true;
            std::cout << "  -> Masukkan Jam Plus (JJ MM DD): ";
            std::cin >> j >> m >> d;
            jamPlus.setWaktu(j, m, d);

            std::cout << "  -> Masukkan Jam Minus (JJ MM DD): ";
            std::cin >> j >> m >> d;
            jamMinus.setWaktu(j, m, d);
        }
        else if (status == 't' || status == 'T') {
            hadir = false; // Dianggap tidak hadir
            jamPlus.setWaktu(0, 0, 0); // Jam plus otomatis nol

            std::cout << "  -> Masukkan Jam Minus (karena tidak hadir) (JJ MM DD): ";
            std::cin >> j >> m >> d;
            jamMinus.setWaktu(j, m, d);
        }
        else {
            // Jika input lain, dianggap alpa tanpa denda jam
            std::cout << "  -> Status tidak valid, dianggap Tidak Hadir tanpa denda.\n";
            hadir = false;
            jamPlus.setWaktu(0, 0, 0);
            jamMinus.setWaktu(0, 0, 0);
        }
    }

    // Fungsi untuk menampilkan data
    void tampilkanData() const {
        std::cout << "  - Hari " << hari << ": ";
        if (hadir) {
            std::cout << "Hadir (Plus: " << jamPlus << ", Minus: " << jamMinus << ")" << std::endl;
        }
        else {
            // Jika tidak hadir tapi ada jam minus, tampilkan sebagai denda
            if (jamMinus.equalWaktu(tipeJam(0, 0, 0))) {
                std::cout << "Tidak Hadir" << std::endl;
            }
            else {
                std::cout << "Tidak Hadir (Denda: " << jamMinus << ")" << std::endl;
            }
        }
    }
};

#endif // ABSENSI_HARIAN_H
