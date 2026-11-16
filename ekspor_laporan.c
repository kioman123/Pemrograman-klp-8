#include "keuangan.h"

void eksporLaporanBulanan() {
    CatatanKeuangan *daftar = NULL;
    int jumlah = bacaSemuaTransaksi(&daftar);

    if (jumlah == 0) {
       
        return;
    }

    FILE *fp = fopen(FILE_LAPORAN, "w");
    if (!fp) {
        perror("Gagal membuat file laporan");
        free(daftar);
        return;
    }

    // Header CSV
    fprintf(fp, "ID,Tanggal,Tipe,Kategori,Nominal\n");

    double totalMasuk = 0, totalKeluar = 0;
    for (int i = 0; i < jumlah; i++) {
        fprintf(fp, "%d,%s,%s,%s,%.2f\n",
                daftar[i].id, daftar[i].tanggal, daftar[i].tipe,
                daftar[i].kategori, daftar[i].nominal);

        if (strcasecmp(daftar[i].tipe, "Pemasukan") == 0) {
            totalMasuk += daftar[i].nominal;
        } else {
            totalKeluar += daftar[i].nominal;
        }
    }

    fprintf(fp, "\n,,,Total Pemasukan,%.2f\n", totalMasuk);
    fprintf(fp, ",,,Total Pengeluaran,%.2f\n", totalKeluar);
    fprintf(fp, ",,,Sisa Saldo,%.2f\n", totalMasuk - totalKeluar);

    fclose(fp);
    free(daftar);
    printf("\n[OK] Laporan berhasil diekspor ke '%s'!\n", FILE_LAPORAN);
}