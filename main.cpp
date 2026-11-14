#include <iostream>
#include <string>
#include "barang.h"
#include "lokasi.h"
using namespace std;

// Fungsi input biasa ala mahasiswa, tanpa cin.fail() yang ribet
int bacaInt(string label) {
    int x;
    cout << label;
    cin >> x;
    return x;
}

string bacaString(string label) {
    string s;
    cout << label;
    cin >> ws; // membersihkan buffer
    getline(cin, s);
    return s;
}

void menuBarang(adrBarang &root) {
    int pilih = -1;
    while (pilih != 0) {
        cout << "\nMENU BARANG\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Cari Barang by ID\n";
        cout << "3. Tampil Inorder\n";
        cout << "4. Hapus Barang\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            int id;
            cout << "ID barang: ";
            cin >> id;
            
            if (cariBarangByID(root, id) != NULL) {
                cout << "ID sudah ada!\n";
            } else {
                Barang b;
                b.idBarang = id;
                b.namaBarang = bacaString("Nama barang: ");
                b.kategori = bacaString("Kategori: ");
                b.satuan = bacaString("Satuan: ");
                b.hargaBeli = bacaInt("Harga beli: ");
                b.hargaJual = bacaInt("Harga jual: ");
                b.stokMinimum = bacaInt("Stok min: ");
                b.totalStok = 0;
                
                bool ok;
                insertBarang(root, alokasiBarang(b), ok);
                cout << "Berhasil ditambahkan.\n";
            }
        } else if (pilih == 2) {
            int id = bacaInt("Masukkan ID yang dicari: ");
            adrBarang p = cariBarangByID(root, id);
            if (p != NULL) {
                tampilBarang(p);
            } else {
                cout << "Ketemu: Tidak ada.\n";
            }
        } else if (pilih == 3) {
            tampilInorder(root);
        } else if (pilih == 4) {
            bool ok;
            int id = bacaInt("ID yang akan dihapus: ");
            deleteBarang(root, id, ok);
            if (ok) cout << "Terhapus\n";
            else cout << "Gagal hapus\n";
        }
    }
}

void menuLokasi(ListLokasi &L) {
    int pilih = -1;
    while (pilih != 0) {
        cout << "\nMENU LOKASI\n";
        cout << "1. Tambah Lokasi\n";
        cout << "2. Tampil Lokasi\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            Lokasi x;
            x.kodeLokasi = bacaString("Kode lokasi: ");
            x.jenisLokasi = bacaString("Jenis lokasi: ");
            x.kapasitasMaksimal = bacaInt("Kapasitas: ");
            insertFirstLokasi(L, alokasiLokasi(x));
            cout << "Lokasi disisipkan.\n";
        } else if (pilih == 2) {
            tampilLokasi(L);
        }
    }
}

int main() {
    adrBarang root;
    ListLokasi lokasi;
    createTree(root);
    createListLokasi(lokasi);

    int pilih = 0;
    do {
        cout << "\n=== APLIKASI WARUNG ===\n";
        cout << "1. Menu Barang\n";
        cout << "2. Menu Lokasi\n";
        cout << "0. Exit\n";
        cout << "Pilihan: ";
        cin >> pilih;

        if (pilih == 1) {
            menuBarang(root);
        } else if (pilih == 2) {
            menuLokasi(lokasi);
        }
    } while (pilih != 0);

    cout << "Program selesai.\n";
    return 0;
}