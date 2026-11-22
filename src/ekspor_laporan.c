#include "keuangan.h"

void eksporLaporanBulanan(){
    CatatanKeuangan *daftar = NULL;
    int jumlah = bacaSemuaTransaksi(&daftar);

    if (jumlah == 0){
        printf("\nTidak ada data transaksi untuk diekspor.\n");
        return;
    }
        FILE *fp = fopen(FILE_LAPORAN, "w");
    if (!fp) {
        perror("Gagal membuat file laporan CSV");
        free(daftar);
        return;
    }

    //Header kolom CSV
    fprintf(fp, "ID, Tanggal, Tipe, Kategori, Nominal\n");

    for(int i = 0; i < jumlah; i++){
        fprintf(fp, "%d,%s,%s,%s,%.2f\n",
                daftar[i].id, daftar[i].tanggal, daftar[i].tipe,
                daftar[i].kategori, daftar[i].nominal);
    }  
    RingkasanSaldo ringkasan;
    hitungRingkasan(daftar, jumlah, &ringkasan);

    fprintf(fp, "\n,,,Jumlah Transaksi,%d\n", ringkasan.jumlahTransaksi);
    fprintf(fp, ",,,Total Pemasukan,%.2f\n", ringkasan.totalPemasukan);
    fprintf(fp, ",,,Total Pengeluaran,%.2f\n", ringkasan.totalPengeluaran);
    fprintf(fp, ",,,Sisa Saldo,%.2f\n", ringkasan.sisaSaldo);

    fclose(fp);
    free(daftar);
    printf("\n[OK] Laporan berhasil diekspor ke '%s'!\n", FILE_LAPORAN);

}