#include <stdio.h>
#include <string.h>

struct aplikasi_pencatat_uang{
    int id;
    char tanggal[11];
    char kategori[30];
    char tipe[15];
    long long nominal;
};



int main(){

    struct aplikasi_pencatat_uang transaksi[10];
    
    // variabel untuk pengeluaran,pemasukan dan saldo
    long long total_pemasukan = 0;
    long long total_pengeluaran = 0;
    long long saldo = 0;

    // tempat untuk isi data
    transaksi[0].id = 1;
    transaksi[0].nominal = 25000;

    strcpy(transaksi[0].tanggal,"15-10-2026");
    strcpy(transaksi[0].kategori,"Makan Burger");
    strcpy(transaksi[0].tipe,"pengeluaran");

    // tempat untuk menampilkan data
    printf("========== Transaksi Keuangan Irfan ==========\n");
    for(int i = 0; i <1; i++){
        printf("\nID : %d | ", transaksi[i].id);
        printf("TANGGAL : %s | ", transaksi[i].tanggal);
        printf("KATEGORI : %s | ", transaksi[i].kategori);
        printf("TIPE : %s | ", transaksi[i].tipe);
        printf("NOMINAL : Rp %lld", transaksi[i].nominal);
    }
    return 0;
}
