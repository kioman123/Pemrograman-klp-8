#include "keuangan.h"

void tambahTransaksiMenu() {
    CatatanKeuangan baru;
    baru.id = dapatkanIdBerikutnya();

    printf("\n--- Tambah Transaksi Baru ---\n");
    printf("Tanggal (DD-MM-YYYY) [ketik 'today' untuk hari ini]: ");
    fgets(baru.tanggal, sizeof(baru.tanggal), stdin);
    baru.tanggal[strcspn(baru.tanggal, "\n")] = 0;

    if (strcmp(baru.tanggal, "today") == 0) {
        dapatkanTanggalHariIni(baru.tanggal);
    }

    printf("Tipe (Pemasukan / Pengeluaran): ");
    fgets(baru.tipe, sizeof(baru.tipe), stdin);
    baru.tipe[strcspn(baru.tipe, "\n")] = 0;

    printf("Kategori (contoh: Makan, Gaji, Transport): ");
    fgets(baru.kategori, sizeof(baru.kategori), stdin);
    baru.kategori[strcspn(baru.kategori, "\n")] = 0;

    printf("Nominal (Rp): ");
    while (scanf("%lf", &baru.nominal) != 1 || baru.nominal <= 0) {
        while (getchar() != '\n');
        printf("[!] Nominal tidak valid. Masukkan angka > 0: ");
    }
    getchar();

    if (simpanTransaksiBinary(baru)) {
        printf("[OK] Transaksi ID #%d berhasil disimpan!\n", baru.id);
    } else {
        printf("[ERROR] Gagal menyimpan transaksi.\n");
    }
}

// Pass by pointer: memodifikasi isi struct RingkasanSaldo secara langsung
void hitungRingkasan(CatatanKeuangan *daftar, int jumlah, RingkasanSaldo *hasil) {
    hasil->jumlahTransaksi = jumlah;
    hasil->totalPemasukan = 0;
    hasil->totalPengeluaran = 0;

    for (int i = 0; i < jumlah; i++) {
        if (strcasecmp(daftar[i].tipe, "Pemasukan") == 0) {
            hasil->totalPemasukan += daftar[i].nominal;
        } else {
            hasil->totalPengeluaran += daftar[i].nominal;
        }
    }
    hasil->sisaSaldo = hasil->totalPemasukan - hasil->totalPengeluaran;
}

// Pass by value: menerima salinan struct RingkasanSaldo untuk ditampilkan
void cetakKartuRingkasan(RingkasanSaldo ringkasan) {
    printf("------------------------------------------------------------------\n");
    printf("Jumlah Transaksi : %d\n", ringkasan.jumlahTransaksi);
    printf("Total Pemasukan  : Rp %.2f\n", ringkasan.totalPemasukan);
    printf("Total Pengeluaran: Rp %.2f\n", ringkasan.totalPengeluaran);
    printf("Sisa Saldo       : Rp %.2f\n", ringkasan.sisaSaldo);
    printf("------------------------------------------------------------------\n");
}

void tampilkanRiwayatDanSaldo() {
    CatatanKeuangan *daftar = NULL;
    int jumlah = bacaSemuaTransaksi(&daftar);

    if (jumlah == 0) {
        printf("\nBelum ada data transaksi tersimpan.\n");
        return;
    }

    printf("\n%-4s | %-12s | %-13s | %-15s | %s\n", "ID", "Tanggal", "Tipe", "Kategori", "Nominal");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-4d | %-12s | %-13s | %-15s | Rp %.2f\n",
               daftar[i].id, daftar[i].tanggal, daftar[i].tipe,
               daftar[i].kategori, daftar[i].nominal);
    }

    RingkasanSaldo ringkasan;
    hitungRingkasan(daftar, jumlah, &ringkasan); // Pass by pointer
    cetakKartuRingkasan(ringkasan);             // Pass by value

    free(daftar);
}