#ifndef LOKASI_H
#define LOKASI_H

#include <string>
using namespace std;
 
struct Lokasi {
    string kodeLokasi, jenisLokasi;
    int kapasitasMaksimal;
};

typedef struct ElmLokasi *adrLokasi;
struct ElmLokasi {
    Lokasi info;
    adrLokasi next;
};

struct ListLokasi {
    adrLokasi first;
};
 
void createListLokasi(ListLokasi &L);
adrLokasi alokasiLokasi(Lokasi x);
void insertFirstLokasi(ListLokasi &L, adrLokasi p);
adrLokasi cariLokasi(ListLokasi L, string kode);
void ubahLokasi(adrLokasi p, string jenisBaru, int kapasitasBaru);
void deleteLokasi(ListLokasi &L, string kode, bool &berhasil);
void tampilLokasi(ListLokasi L);

#endif
