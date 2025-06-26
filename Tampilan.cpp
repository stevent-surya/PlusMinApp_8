#include "Tampilan.h"
#include <iostream>
#include <cstdlib>

void UI::bersihkanLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void UI::jeda() {
    std::cout << "\nTekan Enter untuk melanjutkan...";
    std::cin.ignore();
    std::cin.get();
}

void UI::header(const std::string& judul) {
    std::cout << "======================================================\n";
    std::cout << "          " << judul << "           \n";
    std::cout << "======================================================\n\n";
}

void UI::menuUtama() {
    UI::bersihkanLayar();
    std::cout << "======================================================\n";
    std::cout << "     SISTEM ABSENSI MAHASISWA - JAM PLUS & MINUS      \n";
    std::cout << "======================================================\n";
    std::cout << R"(
       _..----.._
     .'     o    '.
    /   o       o  \
   |o        o     o|
   /'-.._o     __.-'\
   \      ```     /
    `'._         .'`
        ``'---'``
    )" << '\n';
    std::cout << "MENU UTAMA:\n";
    std::cout << "1. Tambah Mahasiswa\n";
    std::cout << "2. Tampilkan Semua Mahasiswa\n";
    std::cout << "3. Ubah Data Mahasiswa\n";
    std::cout << "4. Hapus Mahasiswa\n";
    std::cout << "5. Input Absensi Mingguan Mahasiswa\n";
    std::cout << "6. Tampilkan Laporan Detail Mahasiswa\n";
    std::cout << "7. Export Laporan ke File (.txt)\n";
    std::cout << "0. Keluar\n";
    std::cout << "======================================================\n";
    std::cout << "Masukkan pilihan Anda: ";
}

