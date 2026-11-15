#include <iostream>
#include <string>
#include "barang.h"
#include "lokasi.h"
using namespace std;
 
int bacaIntMin(string label, int batas) {
    int x = 0;
    bool valid = false;
    while (!valid) {
        cout << label;
        cin >> x;
        if (cin.eof()) {
            x = 0;
            valid = true;
        } else if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka.\n";
        } else {
            cin.ignore(1000, '\n');
            if (x < batas) {
                cout << "Nilai minimal " << batas << ".\n";
            } else {
                valid = true;
            }
        }
    }
    return x;
}

int bacaInt(string label) {
    return bacaIntMin(label, 0);
}
 
string bacaString(string label) {
    string s = "";
    while (s == "" && !cin.eof()) {
        cout << label;
        getline(cin, s);
        if (s == "" && !cin.eof()) {
            cout << "Tidak boleh kosong.\n";
        }
    }
    return s;
}

Barang bacaDataBarang(int id) {
    Barang b;
    b.idBarang = id;
    b.namaBarang = bacaString("Nama barang: ");
    b.kategori = bacaString("Kategori: ");
    b.satuan = bacaString("Satuan: ");
    b.hargaBeli = bacaInt("Harga beli: ");
    b.hargaJual = bacaInt("Harga jual: ");
    b.stokMinimum = bacaInt("Stok min: ");
    b.totalStok = 0;
    return b;
}
 
void menuBarang(adrBarang &root) {
    int pilih = -1;
    while (pilih != 0) {
        cout << "\nMENU BARANG\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Cari Barang by ID\n";
        cout << "3. Cari Barang by Nama\n";
        cout << "4. Edit Barang\n";
        cout << "5. Hapus Barang\n";
        cout << "6. Tampil Semua Barang (Inorder, urut ID)\n";
        cout << "7. Tampil Preorder\n";
        cout << "8. Tampil Postorder\n";
        cout << "9. Jumlah Node dan Tinggi Pohon\n";
        cout << "0. Kembali\n";
        pilih = bacaInt("Pilih: ");

        if (pilih == 1) {
            int id = bacaIntMin("ID barang: ", 1);
            if (cariBarangByID(root, id) != NULL) {
                cout << "ID sudah ada!\n";
            } else {
                bool ok;
                insertBarang(root, alokasiBarang(bacaDataBarang(id)), ok);
                cout << "Berhasil ditambahkan. Stok awal 0 (diisi lewat alokasi).\n";
            }
        } else if (pilih == 2) {
            adrBarang p = cariBarangByID(root, bacaInt("Masukkan ID yang dicari: "));
            if (p != NULL) {
                tampilDetailBarang(p);
            } else {
                cout << "Barang tidak ditemukan.\n";
            }
        } else if (pilih == 3) {
            int jumlah = 0;
            cariBarangByNama(root, bacaString("Kata kunci nama: "), jumlah);
            if (jumlah == 0) {
                cout << "Tidak ada barang yang cocok.\n";
            }
        } else if (pilih == 4) {
            adrBarang p = cariBarangByID(root, bacaInt("ID yang akan diedit: "));
            if (p != NULL) {
                ubahBarang(p, bacaDataBarang(p->info.idBarang));
                cout << "Barang diperbarui.\n";
            } else {
                cout << "Barang tidak ditemukan.\n";
            }
        } else if (pilih == 5) {
            bool ok;
            deleteBarang(root, bacaInt("ID yang akan dihapus: "), ok);
            if (ok) cout << "Terhapus\n";
            else cout << "Gagal hapus, ID tidak ditemukan\n";
        } else if (pilih == 6) {
            if (root == NULL) cout << "Belum ada barang.\n";
            else tampilInorder(root);
        } else if (pilih == 7) {
            tampilPreorder(root);
        } else if (pilih == 8) {
            tampilPostorder(root);
        } else if (pilih == 9) {
            cout << "Jumlah node : " << hitungNode(root) << endl;
            cout << "Tinggi pohon: " << tinggiPohon(root) << endl;
        } else if (pilih != 0) {
            cout << "Pilihan tidak valid.\n";
        }
    }
}
 
void menuLokasi(ListLokasi &L) {
    int pilih = -1;
    while (pilih != 0) {
        cout << "\nMENU LOKASI\n";
        cout << "1. Tambah Lokasi\n";
        cout << "2. Edit Lokasi\n";
        cout << "3. Hapus Lokasi\n";
        cout << "4. Tampil Lokasi\n";
        cout << "0. Kembali\n";
        pilih = bacaInt("Pilih: ");

        if (pilih == 1) {
            Lokasi x;
            x.kodeLokasi = bacaString("Kode lokasi: ");
            if (cariLokasi(L, x.kodeLokasi) != NULL) {
                cout << "Kode lokasi sudah ada!\n";
            } else {
                x.jenisLokasi = bacaString("Jenis lokasi: ");
                x.kapasitasMaksimal = bacaIntMin("Kapasitas: ", 1);
                insertFirstLokasi(L, alokasiLokasi(x));
                cout << "Lokasi disisipkan.\n";
            }
        } else if (pilih == 2) {
            adrLokasi p = cariLokasi(L, bacaString("Kode yang akan diedit: "));
            if (p != NULL) {
                string jenis = bacaString("Jenis baru: ");
                int kap = bacaIntMin("Kapasitas baru: ", 1);
                ubahLokasi(p, jenis, kap);
                cout << "Lokasi diperbarui.\n";
            } else {
                cout << "Lokasi tidak ditemukan.\n";
            }
        } else if (pilih == 3) {
            bool ok;
            deleteLokasi(L, bacaString("Kode yang akan dihapus: "), ok);
            if (ok) cout << "Lokasi dihapus.\n";
            else cout << "Lokasi tidak ditemukan.\n";
        } else if (pilih == 4) {
            tampilLokasi(L);
        } else if (pilih != 0) {
            cout << "Pilihan tidak valid.\n";
        }
    }
}
 
void isiBarang(adrBarang &root, int id, string nama, string kat, string sat,
               int beli, int jual, int minimum) {
    Barang b;
    bool ok;
    b.idBarang = id; b.namaBarang = nama; b.kategori = kat; b.satuan = sat;
    b.hargaBeli = beli; b.hargaJual = jual; b.stokMinimum = minimum;
    b.totalStok = 0;
    insertBarang(root, alokasiBarang(b), ok);
}

void isiLokasi(ListLokasi &L, string kode, string jenis, int kap) {
    Lokasi x;
    x.kodeLokasi = kode; x.jenisLokasi = jenis; x.kapasitasMaksimal = kap;
    insertFirstLokasi(L, alokasiLokasi(x));
}

void muatDataContoh(adrBarang &root, ListLokasi &L) {
    if (root != NULL || L.first != NULL) {
        cout << "Data contoh hanya bisa dimuat saat data masih kosong.\n";
    } else {
        isiBarang(root, 102, "Minyak Goreng 2L", "Sembako", "pcs", 32000, 35000, 20);
        isiBarang(root, 101, "Beras 5kg", "Sembako", "pcs", 60000, 65000, 15);
        isiBarang(root, 105, "Gula 1kg", "Sembako", "kg", 14000, 16000, 20);
        isiBarang(root, 103, "Indomie Goreng", "Jajanan", "dus", 95000, 105000, 5);
        isiBarang(root, 110, "Teh Celup", "Minuman", "dus", 8000, 10000, 10);
        isiLokasi(L, "RAK-DPN-1", "Rak Depan", 200);
        isiLokasi(L, "GDG-BLK", "Gudang Belakang", 1000);
        cout << "Data contoh dimuat (5 barang, 2 lokasi).\n";
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
        cout << "3. Muat Data Contoh\n";
        cout << "0. Exit\n";
        pilih = bacaInt("Pilihan: ");

        if (pilih == 1) {
            menuBarang(root);
        } else if (pilih == 2) {
            menuLokasi(lokasi);
        } else if (pilih == 3) {
            muatDataContoh(root, lokasi);
        } else if (pilih != 0) {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 0);

    cout << "Program selesai.\n";
    return 0;
}