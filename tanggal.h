#ifndef TANGGAL_H
#define TANGGAL_H

struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

// Mengembalikan true kalau tahun adalah tahun kabisat (kabisat yang tahunya punya hari lebih banyak)
bool isKabisat(int tahun);

// nentuin berapa hari maksimal yang ada di bulan dan tahun yang dipilih.
int jumlahHariDalamBulan(int bulan, int tahun);

// ngecek apakah tanggal yang dimasukkan sudah benar dan sesuai kalender.
bool isTanggalValid(Tanggal t);

// Membandingkan dua tanggal yang dimasukkan:
// - ngehasilin -1 kalau tanggal pertama lebih dulu dari tanggal kedua
// - ngehasilin 0 kalau kedua tanggal sama
// - ngehasilin 1 kalau tanggal pertama lebih akhir dari tanggal kedua
int bandingTanggal(Tanggal t1, Tanggal t2);

// I.S. tanggal yang dimasukkan sudah tersedia dan valid
// F.S. nampilin tanggal ke layar dengan format DD/MM/YYYY
void tampilTanggal(Tanggal t);

#endif