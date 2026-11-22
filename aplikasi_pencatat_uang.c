#include "keuangan.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        return prosesArgumenCLI(argc, argv);
    }

    #include "keuangan.h"
    int pilihan;
    do {
        printf("\n=== APLIKASI PENCATAT KEUANGAN PRIBADI ===\n");
        printf("1. Tambah Transaksi Baru\n");
        printf("2. Lihat Riwayat & Ringkasan Saldo\n");
    
        return 0;
}