# Checklist Fitur StokWarung

Keterangan: `[x]` sudah jadi dan sudah diuji, `[ ]` belum.
Rencana: Tahap 1 = 30%, Tahap 2 = 60%, Tahap 3 = 100%.

**Status saat ini: Tahap 1 selesai (30%)**

---

## 1. Barang (BST), Tahap 1

| Status | Fitur | Keterangan |
|---|---|---|
| [x] | Tambah barang | Tolak ID ganda dan ID < 1 |
| [x] | Cari barang berdasarkan ID | Pencarian BST |
| [x] | Cari barang berdasarkan nama | Sequential (traversal), cocok sebagian kata |
| [x] | Edit barang | `idBarang` dan `totalStok` tidak ikut berubah |
| [x] | Hapus barang (node BST) | 3 kasus: daun, satu anak, dua anak |
| [ ] | Hapus barang beserta relasinya | Menunggu List Relasi (Tahap 2) |
| [x] | Tampil inorder (semua barang, urut ID) | |
| [x] | Tampil preorder | |
| [x] | Tampil postorder | |
| [x] | Hitung jumlah node | |
| [x] | Hitung tinggi pohon | |

## 2. Lokasi (SLL), Tahap 1

| Status | Fitur | Keterangan |
|---|---|---|
| [x] | Tambah lokasi | Insert first, tolak kode ganda dan kapasitas < 1 |
| [x] | Edit lokasi | Jenis dan kapasitas |
| [x] | Hapus lokasi (elemen list) | Awal, tengah, akhir |
| [ ] | Hapus lokasi beserta relasinya | Tahap 2 |
| [x] | Tampil semua lokasi | |
| [ ] | Tampil sisa kapasitas | Butuh data alokasi (Tahap 2) |

## 3. Alokasi Stok (MLL-02), Tahap 2

| Status | Fitur |
|---|---|
| [ ] | Struktur List Relasi (`relasi.h/.cpp`) |
| [ ] | Alokasikan stok (insert after, terurut ID_Barang) |
| [ ] | Alokasi ulang pada pasangan yang sama (stok bertambah, tanggal kedaluwarsa terdekat) |
| [ ] | Hapus alokasi |
| [ ] | Pindahkan stok antar lokasi |
| [ ] | Pantau penyebaran produk |
| [ ] | Cek isi rak |
| [ ] | Pembaruan `totalStok` otomatis |
| [ ] | Cek kapasitas maksimal lokasi |
| [x] | Validasi dan perbandingan tanggal (`tanggal.h/.cpp`) |

## 4. Laporan, Tahap 3

| Status | Fitur |
|---|---|
| [ ] | Daftar stok menipis (Total_Stok < Stok_Minimum) |
| [ ] | Daftar mendekati kedaluwarsa (urut terdekat) |
| [ ] | Total nilai stok (stok x Harga_Beli) |

## 5. Antrean (Queue DLL), Tahap 3

| Status | Fitur |
|---|---|
| [ ] | Struktur Queue (`antrean.h/.cpp`) |
| [ ] | Ajukan permintaan keluar (enqueue, tolak jika melebihi stok) |
| [ ] | Proses permintaan terdepan dengan FEFO (dequeue) |
| [ ] | Tampil antrean |
| [ ] | Batalkan permintaan jika barang sudah dihapus |

## 6. Aturan Integritas Data (proposal 2.4.7)

| Status | Aturan | Tahap |
|---|---|---|
| [ ] | Total_Stok selalu diperbarui (alokasi, hapus alokasi, antrean) | 2 dan 3 |
| [ ] | Total stok di satu lokasi tidak melebihi kapasitas | 2 |
| [ ] | Satu pasangan Barang-Lokasi hanya satu relasi | 2 |
| [ ] | Hapus barang atau lokasi menghapus relasinya dulu | 2 |
| [ ] | Permintaan keluar tidak melebihi stok | 3 |
| [ ] | Queue menyimpan ID sebagai nilai, bukan pointer | 3 |

## 7. Aturan Penulisan Mata Kuliah

| Status | Aturan |
|---|---|
| [x] | Tanpa variabel global (Tahap 1) |
| [x] | Tanpa `break` / `return` di dalam perulangan (Tahap 1) |
| [x] | ADT dipisah ke file `.h` dan `.cpp` (Tahap 1) |
| [x] | Spesifikasi I.S./F.S. pada ADT Barang dan Lokasi |
| [ ] | I.S./F.S. pada ADT Relasi dan Antrean |
| [x] | Insert first dipakai pada SLL Lokasi |
| [ ] | Insert after dipakai pada List Relasi |
| [ ] | Insert last (enqueue) dipakai pada Queue |

## 8. Daftar File

| Status | File | Tahap |
|---|---|---|
| [x] | `barang.h`, `barang.cpp` | 1 |
| [x] | `lokasi.h`, `lokasi.cpp` | 1 |
| [x] | `main.cpp` (menu Barang dan Lokasi) | 1, diperluas di 2 dan 3 |
| [x] | `tanggal.h`, `tanggal.cpp` | 2 |
| [ ] | `relasi.h`, `relasi.cpp` | 2 |
| [ ] | `antrean.h`, `antrean.cpp` | 3 |
| [ ] | `laporan.h`, `laporan.cpp` (opsional) | 3 |

---

## Ringkasan Progres

| Kelompok | Selesai | Total |
|---|---|---|
| Barang (BST) | 10 | 11 |
| Lokasi (SLL) | 4 | 6 |
| Alokasi (MLL-02) | 1 | 10 |
| Laporan | 0 | 3 |
| Antrean (Queue) | 0 | 5 |

Fitur Tahap 1 yang tersisa (hapus beserta relasi, sisa kapasitas) memang bergantung pada Tahap 2, jadi bukan kekurangan Tahap 1.
