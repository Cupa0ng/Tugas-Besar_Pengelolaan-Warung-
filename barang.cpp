#include <iostream>
#include "barang.h"
using namespace std;

void createTree(adrBarang &root) {
    root = NULL;
}

adrBarang alokasiBarang(Barang x) {
    adrBarang p = new NodeBarang;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertBarang(adrBarang &root, adrBarang p, bool &berhasil) {
    if (root == NULL) {
        root = p;
        berhasil = true;
    } else if (p->info.idBarang < root->info.idBarang) {
        insertBarang(root->left, p, berhasil);
    } else if (p->info.idBarang > root->info.idBarang) {
        insertBarang(root->right, p, berhasil);
    } else {
        berhasil = false;
    }
}

adrBarang cariBarangByID(adrBarang root, int id) {
    if (root == NULL || root->info.idBarang == id) {
        return root;
    }
    if (id < root->info.idBarang) {
        return cariBarangByID(root->left, id);
    }
    return cariBarangByID(root->right, id);
}

void cariBarangByNama(adrBarang root, string kata, int &jumlah) {
    if (root != NULL) {
        cariBarangByNama(root->left, kata, jumlah);
        if (root->info.namaBarang.find(kata) != string::npos) {
            tampilBarang(root);
            jumlah++;
        }
        cariBarangByNama(root->right, kata, jumlah);
    }
}

void ubahBarang(adrBarang p, Barang baru) { 
    p->info.namaBarang  = baru.namaBarang;
    p->info.kategori    = baru.kategori;
    p->info.satuan      = baru.satuan;
    p->info.hargaBeli   = baru.hargaBeli;
    p->info.hargaJual   = baru.hargaJual;
    p->info.stokMinimum = baru.stokMinimum;
}
 
static adrBarang lepasMinimum(adrBarang &root) {
    adrBarang m;
    if (root->left == NULL) {
        m = root;
        root = root->right;
        m->left = NULL;
        m->right = NULL;
    } else {
        m = lepasMinimum(root->left);
    }
    return m;
}

void deleteBarang(adrBarang &root, int id, bool &berhasil) {
    if (root == NULL) {
        berhasil = false;
    } else if (id < root->info.idBarang) {
        deleteBarang(root->left, id, berhasil);
    } else if (id > root->info.idBarang) {
        deleteBarang(root->right, id, berhasil);
    } else {
        adrBarang hapus = root;
        if (hapus->left == NULL) {
            root = hapus->right;
        } else if (hapus->right == NULL) {
            root = hapus->left;
        } else {
            adrBarang pengganti = lepasMinimum(hapus->right);
            pengganti->left = hapus->left;
            pengganti->right = hapus->right;
            root = pengganti;
        }
        delete hapus;
        berhasil = true;
    }
}

void tampilBarang(adrBarang p) {
    cout << p->info.idBarang << " - " << p->info.namaBarang
         << " | Stok: " << p->info.totalStok << endl;
}

void tampilDetailBarang(adrBarang p) {
    cout << "ID           : " << p->info.idBarang << endl;
    cout << "Nama         : " << p->info.namaBarang << endl;
    cout << "Kategori     : " << p->info.kategori << endl;
    cout << "Satuan       : " << p->info.satuan << endl;
    cout << "Harga beli   : " << p->info.hargaBeli << endl;
    cout << "Harga jual   : " << p->info.hargaJual << endl;
    cout << "Stok minimum : " << p->info.stokMinimum << endl;
    cout << "Total stok   : " << p->info.totalStok << endl;
}

void tampilInorder(adrBarang root) {
    if (root != NULL) {
        tampilInorder(root->left);
        tampilBarang(root);
        tampilInorder(root->right);
    }
}

void tampilPreorder(adrBarang root) {
    if (root != NULL) {
        tampilBarang(root);
        tampilPreorder(root->left);
        tampilPreorder(root->right);
    }
}

void tampilPostorder(adrBarang root) {
    if (root != NULL) {
        tampilPostorder(root->left);
        tampilPostorder(root->right);
        tampilBarang(root);
    }
}

int hitungNode(adrBarang root) {
    if (root == NULL) return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int tinggiPohon(adrBarang root) {
    if (root == NULL) return 0;
    int l = tinggiPohon(root->left);
    int r = tinggiPohon(root->right);
    return 1 + (l > r ? l : r);
}