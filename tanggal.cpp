#include <iostream>
#include "tanggal.h"
using namespace std;

bool isKabisat(int tahun) {
    return (tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0);
}

int jumlahHariDalamBulan(int bulan, int tahun) {
    if (bulan == 2) {
        return isKabisat(tahun) ? 29 : 28;
    }
    if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {
        return 30;
    }
    if (bulan >= 1 && bulan <= 12) {
        return 31;
    }
    return 0;
}

bool isTanggalValid(Tanggal t) {
    if (t.tahun < 1 || t.bulan < 1 || t.bulan > 12) {
        return false;
    }
    int maxHari = jumlahHariDalamBulan(t.bulan, t.tahun);
    return (t.hari >= 1 && t.hari <= maxHari);
}

int bandingTanggal(Tanggal t1, Tanggal t2) {
    if (t1.tahun != t2.tahun) {
        return (t1.tahun < t2.tahun) ? -1 : 1;
    }
    if (t1.bulan != t2.bulan) {
        return (t1.bulan < t2.bulan) ? -1 : 1;
    }
    if (t1.hari != t2.hari) {
        return (t1.hari < t2.hari) ? -1 : 1;
    }
    return 0;
}

void tampilTanggal(Tanggal t) {
    if (t.hari < 10) cout << "0";
    cout << t.hari << "/";
    if (t.bulan < 10) cout << "0";
    cout << t.bulan << "/" << t.tahun;
}