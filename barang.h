#ifndef BARANG_H
#define BARANG_H

#include <string>
using namespace std;

struct Barang {
    int idBarang;
    string namaBarang, kategori, satuan;
    int hargaBeli, hargaJual, stokMinimum, totalStok;
};

typedef struct NodeBarang *adrBarang;
struct NodeBarang {
    Barang info;
    adrBarang left, right; 
};

void createTree(adrBarang &root);

adrBarang alokasiBarang(Barang x);
void insertBarang(adrBarang &root, adrBarang p, bool &berhasil);
adrBarang cariBarangByID(adrBarang root, int id);
void cariBarangByNama(adrBarang root, string kata, int &jumlah);
void ubahBarang(adrBarang p, Barang baru);
void deleteBarang(adrBarang &root, int id, bool &berhasil);

void tampilBarang(adrBarang p);

void tampilDetailBarang(adrBarang p);

void tampilInorder(adrBarang root);
void tampilPreorder(adrBarang root);
void tampilPostorder(adrBarang root);

int hitungNode(adrBarang root);
int tinggiPohon(adrBarang root);

#endif