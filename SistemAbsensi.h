#ifndef SISTEM_ABSENSI_H
#define SISTEM_ABSENSI_H

#include "Mahasiswa.h"
#include <vector>
#include <string>

class SistemAbsensi {
private:
    std::vector<Mahasiswa> daftarMahasiswa;
    int cariMahasiswaByNIM(const std::string& nim); // Mengembalikan indeks

public:
    // Fungsi CRUD
    void tambahMahasiswa();
    void tampilkanSemuaMahasiswa();
    void ubahMahasiswa();
    void hapusMahasiswa();

    // Fungsi utama aplikasi
    void inputAbsensi();
    void tampilkanLaporanDetail();
    void exportLaporanKeTxt();
};

#endif // SISTEM_ABSENSI_H
