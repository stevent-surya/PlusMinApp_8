#include "Mahasiswa.h"
#include <iostream>
#include <numeric>

// Constructor
Mahasiswa::Mahasiswa(std::string nim, std::string nama) {
    this->nim = nim;
    this->nama = nama;
    const std::string hari[] = { "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu" };
    for (int i = 0; i < 7; ++i) {
        absensiMingguan[i].hari = hari[i];
    }
}

// Setters
void Mahasiswa::setNama(std::string nama) {
    this->nama = nama;
}

// Getters
std::string Mahasiswa::getNIM() const {
    return nim;
}

std::string Mahasiswa::getNama() const {
    return nama;
}

const std::array<AbsensiHarian, 7>& Mahasiswa::getAbsensi() const {
    return absensiMingguan;
}

// Fungsi Utama
void Mahasiswa::inputAbsensiMingguan() {
    std::cout << "Input Absensi untuk " << nama << " (NIM: " << nim << ")\n";
    for (int i = 0; i < 7; ++i) {
        absensiMingguan[i].inputAbsen();
    }
}

tipeJam Mahasiswa::getTotalJamPlus() const {
    tipeJam total; // Inisialisasi ke 00:00:00
    for (const auto& absen : absensiMingguan) {
        total = total + absen.jamPlus;
    }
    return total;
}

tipeJam Mahasiswa::getTotalJamMinus() const {
    tipeJam total; // Inisialisasi ke 00:00:00
    for (const auto& absen : absensiMingguan) {
        total = total + absen.jamMinus;
    }
    return total;
}

tipeJam Mahasiswa::getSaldoJam() const {
    return getTotalJamPlus() - getTotalJamMinus();
}

void Mahasiswa::tampilkanDataDasar() const {
    std::cout << "NIM  : " << nim << std::endl;
    std::cout << "Nama : " << nama << std::endl;
}

void Mahasiswa::tampilkanLaporanDetail() const {
    tampilkanDataDasar();
    std::cout << "\nLaporan Absensi Mingguan:\n";
    for (const auto& absen : absensiMingguan) {
        absen.tampilkanData();
    }
    std::cout << "\n----------------------------------------\n";
    std::cout << "Total Jam Plus : " << getTotalJamPlus() << std::endl;
    std::cout << "Total Jam Minus: " << getTotalJamMinus() << std::endl;
    std::cout << "Saldo Jam Akhir: " << getSaldoJam() << std::endl;
    std::cout << "----------------------------------------\n";
}
