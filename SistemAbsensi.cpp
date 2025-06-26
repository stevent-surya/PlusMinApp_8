#include "SistemAbsensi.h"
#include "Tampilan.h"
#include <iostream>
#include <fstream>
#include <limits>

// Fungsi bantuan untuk mencari mahasiswa
int SistemAbsensi::cariMahasiswaByNIM(const std::string& nim) {
    for (size_t i = 0; i < daftarMahasiswa.size(); ++i) {
        if (daftarMahasiswa[i].getNIM() == nim) {
            return i;
        }
    }
    return -1; // Tidak ditemukan
}

// 1. Create
void SistemAbsensi::tambahMahasiswa() {
    UI::header("TAMBAH MAHASISWA");
    std::string nim, nama;

    std::cout << "Masukkan NIM  : ";
    std::cin >> nim;
    if (cariMahasiswaByNIM(nim) != -1) {
        std::cout << "\nError: Mahasiswa dengan NIM " << nim << " sudah ada!\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Masukkan Nama : ";
    std::getline(std::cin, nama);

    daftarMahasiswa.push_back(Mahasiswa(nim, nama));
    std::cout << "\nSukses! Mahasiswa " << nama << " berhasil ditambahkan.\n";
}

// 2. Read
void SistemAbsensi::tampilkanSemuaMahasiswa() {
    UI::header("DAFTAR SEMUA MAHASISWA");
    if (daftarMahasiswa.empty()) {
        std::cout << "Belum ada data mahasiswa.\n";
    }
    else {
        for (size_t i = 0; i < daftarMahasiswa.size(); ++i) {
            std::cout << "--- Mahasiswa " << i + 1 << " ---\n";
            daftarMahasiswa[i].tampilkanDataDasar();
            std::cout << std::endl;
        }
    }
}

// 3. Update
void SistemAbsensi::ubahMahasiswa() {
    UI::header("UBAH DATA MAHASISWA");
    if (daftarMahasiswa.empty()) {
        std::cout << "Belum ada data mahasiswa.\n";
        return;
    }
    std::string nim, namaBaru;
    std::cout << "Masukkan NIM mahasiswa yang akan diubah: ";
    std::cin >> nim;

    int index = cariMahasiswaByNIM(nim);
    if (index == -1) {
        std::cout << "\nError: NIM tidak ditemukan.\n";
    }
    else {
        std::cout << "\nData ditemukan. Masukkan nama baru: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, namaBaru);
        daftarMahasiswa[index].setNama(namaBaru);
        std::cout << "\nSukses! Data berhasil diubah.\n";
    }
}

// 4. Delete
void SistemAbsensi::hapusMahasiswa() {
    UI::header("HAPUS MAHASISWA");
    if (daftarMahasiswa.empty()) {
        std::cout << "Belum ada data mahasiswa.\n";
        return;
    }
    std::string nim;
    std::cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
    std::cin >> nim;

    int index = cariMahasiswaByNIM(nim);
    if (index == -1) {
        std::cout << "\nError: NIM tidak ditemukan.\n";
    }
    else {
        char konfirmasi;
        std::cout << "\nYakin ingin menghapus " << daftarMahasiswa[index].getNama() << "? (y/t): ";
        std::cin >> konfirmasi;
        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            daftarMahasiswa.erase(daftarMahasiswa.begin() + index);
            std::cout << "\nSukses! Data telah dihapus.\n";
        }
        else {
            std::cout << "\nPenghapusan dibatalkan.\n";
        }
    }
}

// 5. Input Absensi
void SistemAbsensi::inputAbsensi() {
    UI::header("INPUT ABSENSI MINGGUAN");
    if (daftarMahasiswa.empty()) {
        std::cout << "Belum ada data mahasiswa.\n";
        return;
    }
    std::string nim;
    std::cout << "Masukkan NIM mahasiswa: ";
    std::cin >> nim;

    int index = cariMahasiswaByNIM(nim);
    if (index == -1) {
        std::cout << "\nError: NIM tidak ditemukan.\n";
    }
    else {
        daftarMahasiswa[index].inputAbsensiMingguan();
        std::cout << "\nSukses! Absensi berhasil diinput.\n";
    }
}

// 6. Tampilkan Laporan
void SistemAbsensi::tampilkanLaporanDetail() {
    UI::header("LAPORAN DETAIL MAHASISWA");
    if (daftarMahasiswa.empty()) {
        std::cout << "Belum ada data mahasiswa.\n";
        return;
    }
    std::string nim;
    std::cout << "Masukkan NIM mahasiswa: ";
    std::cin >> nim;

    int index = cariMahasiswaByNIM(nim);
    if (index == -1) {
        std::cout << "\nError: NIM tidak ditemukan.\n";
    }
    else {
        UI::bersihkanLayar();
        UI::header("LAPORAN UNTUK " + daftarMahasiswa[index].getNama());
        daftarMahasiswa[index].tampilkanLaporanDetail();
    }
}

// 7. Export ke File
void SistemAbsensi::exportLaporanKeTxt() {
    UI::header("EXPORT LAPORAN KE FILE");
    if (daftarMahasiswa.size() < 3) {
        std::cout << "Error: Data minimal harus 3 mahasiswa untuk dapat diexport.\n";
        return;
    }

    std::ofstream file("Laporan_Absensi_Jam.txt");
    if (!file.is_open()) {
        std::cout << "Error: Gagal membuat file laporan.\n";
        return;
    }

    file << "==========================================================\n";
    file << "        LAPORAN ABSENSI MAHASISWA - JAM PLUS & MINUS       \n";
    file << "==========================================================\n\n";

    for (const auto& mhs : daftarMahasiswa) {
        file << "NIM  : " << mhs.getNIM() << "\n";
        file << "Nama : " << mhs.getNama() << "\n\n";
        file << "--- Absensi Mingguan ---\n";
        const auto& absensi = mhs.getAbsensi();
        for (const auto& absen : absensi) {
            file << "  - Hari " << absen.hari << ": ";
            if (absen.hadir) {
                file << "Hadir (Plus: " << absen.jamPlus << ", Minus: " << absen.jamMinus << ")\n";
            }
            else {
                file << "Tidak Hadir\n";
            }
        }
        file << "\n--- Akumulasi ---\n";
        file << "Total Jam Plus : " << mhs.getTotalJamPlus() << "\n";
        file << "Total Jam Minus: " << mhs.getTotalJamMinus() << "\n";
        file << "Saldo Jam Akhir: " << mhs.getSaldoJam() << "\n";
        file << "==========================================================\n\n";
    }

    file.close();
    std::cout << "Sukses! Laporan telah diexport ke 'Laporan_Absensi_Jam.txt'.\n";
}
