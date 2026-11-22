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
            case 1:
                tambahTransaksiMenu();
                break;
            case 2:
                tampilkanRiwayatDanSaldo();
                break;
            case 3:
                eksporLaporanBulanan();
                break;
            case 0:
                printf("Program selesai. Data tersimpan aman di %s.\n", FILE_BINARY);
                break;
           default:
                printf("[!] Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}