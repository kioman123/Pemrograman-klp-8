int dapatkanIdBerikutnya();
int simpanTransaksiBinary(CatatanKeuangan data);
int bacaSemuaTransaksi(CatatanKeuangan **daftar);

void tambahTransaksiMenu();
void hitungRingkasan(CatatanKeuangan *daftar, int jumlah, RingkasanSaldo *hasil);
void cetakKartuRingkasan(RingkasanSaldo ringkasan);
void tampilkanRiwayatDanSaldo();

void eksporLaporanBulanan();

void dapatkanTanggalHariIni(char *buffer);
void tampilkanBantuanCLI(const char *namaProgram);
int prosesArgumenCLI(int argc, char *argv[]);

#endif