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

}