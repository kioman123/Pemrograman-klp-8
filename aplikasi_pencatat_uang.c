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
        printf("3. Ekspor Laporan Bulanan (.csv)\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");

        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            pilihan = -1;
        }
        getchar(); 
    
        switch (pilihan) {
            return 0;

}