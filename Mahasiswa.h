#ifndef MAHASISWA_H
#define MAHASISWA_H

#include "AbsensiHarian.h"
#include <string>
#include <array>

class Mahasiswa {
private:
    std::string nim;
    std::string nama;
    std::array<AbsensiHarian, 7> absensiMingguan;

public:
    Mahasiswa(std::string nim, std::string nama);

    // Setters
    void setNama(std::string nama);

    // Getters
    std::string getNIM() const;
    std::string getNama() const;
    const std::array<AbsensiHarian, 7>& getAbsensi() const;

    // Fungsi utama
    void inputAbsensiMingguan();
    tipeJam getTotalJamPlus() const;
    tipeJam getTotalJamMinus() const;
    tipeJam getSaldoJam() const;

    void tampilkanDataDasar() const;
    void tampilkanLaporanDetail() const;
};

#endif // MAHASISWA_H
