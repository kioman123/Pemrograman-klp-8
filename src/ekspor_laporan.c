#include "keuangan.h"

void eksporLaporanBulanan(){
    CatatanKeuangan *daftar = NULL;
    int jumlah = bacaSemuaTransaksi(&daftar);

    if (jumlah == 0){
        printf("\nTidak ada data transaksi untuk diekspor.\n");
        return;
    }
}