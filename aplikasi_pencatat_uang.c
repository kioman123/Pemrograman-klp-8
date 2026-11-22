int dapatkanIdBerikutnya();
int simpanTransaksiBinary(CatatanKeuangan data);
int bacaSemuaTransaksi(CatatanKeuangan **daftar);

void tambahTransaksiMenu();
void hitungRingkasan(CatatanKeuangan *daftar, int jumlah, RingkasanSaldo *hasil);
void cetakKartuRingkasan(RingkasanSaldo ringkasan);
void tampilkanRiwayatDanSaldo();
