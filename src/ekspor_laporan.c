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

}