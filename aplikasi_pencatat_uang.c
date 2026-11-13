#include <stdio.h>
#include <string.h>

struct aplikasi_pencatat_uang {
    int id;
    char tanggal[11];
    char kategori[30];
    char tipe[15];
    long long nominal;
};

int main(){

    struct aplikasi_pencatat_uang transaksi;
    
    // tempat untuk isi data
    transaksi.id = 1;
    transaksi.nominal = 25000;

    strcpy(transaksi.tanggal,"15-10-2026");
    strcpy(transaksi.kategori,"Makan Burger");
    strcpy(transaksi.tipe,"pengeluaran");

    // tempat untuk menampilkan data
    printf("========== Transaksi Keuangan Irfan ==========\n");
    printf("ID       : %d\n", transaksi.id);
    printf("TANGGAL  : %s\n", transaksi.tanggal);
    printf("KATEGORI : %s\n", transaksi.kategori);
    printf("TIPE     : %s\n", transaksi.tipe);
    printf("NOMINAL  : %s\n", transaksi.nominal);

    return 0;
}
