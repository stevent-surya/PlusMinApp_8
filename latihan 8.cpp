#include "SistemAbsensi.h"
#include "Tampilan.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    SistemAbsensi sistem;
    int pilihan;
    char yt;

awal:
    UI::menuUtama();
    cin >> pilihan;

    while (cin.fail()) {
        cout << "Input tidak valid! Harap masukkan angka menu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> pilihan;
    }

    UI::bersihkanLayar();
    switch (pilihan) {
    case 1: sistem.tambahMahasiswa(); break;
    case 2: sistem.tampilkanSemuaMahasiswa(); break;
    case 3: sistem.ubahMahasiswa(); break;
    case 4: sistem.hapusMahasiswa(); break;
    case 5: sistem.inputAbsensi(); break;
    case 6: sistem.tampilkanLaporanDetail(); break;
    case 7: sistem.exportLaporanKeTxt(); break;
    case 0:
        cout << "Terima kasih telah menggunakan sistem ini!\n";
        goto akhir;
    default:
        cout << "Pilihan tidak valid!\n";
    }

    UI::jeda();

    cout << endl << endl;
    cout << "Kembali ke Menu Utama (y/t) ? ";
    cin >> yt;
    cout << endl;

    if (yt == 'Y' || yt == 'y') {
        goto awal;
    }
    if (yt == 'T' || yt == 't') {
        goto akhir;
    }

akhir:
    cout << "Program Selesai." << endl;
    return 0;
}
