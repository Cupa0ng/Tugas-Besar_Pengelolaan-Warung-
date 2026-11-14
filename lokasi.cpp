#include <iostream>
#include "lokasi.h"
using namespace std;

void createListLokasi(ListLokasi &L) {
    L.first = NULL;
}

adrLokasi alokasiLokasi(Lokasi x) {
    adrLokasi p = new ElmLokasi;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertFirstLokasi(ListLokasi &L, adrLokasi p) {
    p->next = L.first;
    L.first = p;
}

adrLokasi cariLokasi(ListLokasi L, string kode) {
    adrLokasi p = L.first;
    while (p != NULL) {
        if (p->info.kodeLokasi == kode) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void ubahLokasi(adrLokasi p, string jenisBaru, int kapasitasBaru) {
    p->info.jenisLokasi = jenisBaru;
    p->info.kapasitasMaksimal = kapasitasBaru;
}

void deleteLokasi(ListLokasi &L, string kode, bool &berhasil) {
    berhasil = false;
    if (L.first == NULL) return;

    adrLokasi p = L.first;
    if (p->info.kodeLokasi == kode) {
        L.first = p->next;
        delete p;
        berhasil = true;
    } else {
        adrLokasi prev = p;
        p = p->next;
        while (p != NULL && !berhasil) {
            if (p->info.kodeLokasi == kode) {
                prev->next = p->next;
                delete p;
                berhasil = true;
            } else {
                prev = p;
                p = p->next;
            }
        }
    }
}

void tampilLokasi(ListLokasi L) {
    adrLokasi p = L.first;
    if (p == NULL) {
        cout << "Kosong\n";
    } else {
        while (p != NULL) {
            cout << p->info.kodeLokasi << " - " << p->info.jenisLokasi 
                 << " (" << p->info.kapasitasMaksimal << ")\n";
            p = p->next;
        }
    }
}