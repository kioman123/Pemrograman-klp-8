#ifndef KEUANGAN H
#define KEUANGAN H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_BINARY "keuangan.bin"
#define FILE_LAPORAN "laporan_bulanan.csv"

typedef struct {
    int id;
    char tanggal[15];
    char kategori[30];
    char tipe[15];
    double nominal;
} CatatnKeuangan;

typedef struct {
    int jumlahTransaksi;
    double totalPemasukan;
    double totalPengeluaran;
    double sisaSaldo;
} RingkasanSaldo


    // tempat dimintanya data user
     char nama[45];
    printf("Nama: ");
    scanf("%s", nama);

    // tempat menanyakan jumlah transaksi
    int jumlah;
    printf("mau input berapa transaksi:");
    scanf("%d", &jumlah);

    //batas jumlah transaksi 10
    if (jumlah > 10 || jumlah < 1) {
        printf("error max 10\n");
        return 0;
    }
    
    //perulangan input
    //dan printf dibawah perulangan untuk menampilkan transaksi ke-1 atau sampai ke-10
    for(int i = 0; i < jumlah; i++) {
        printf("\nTransaksi ke-%d\n", i + 1);
        transaksi[i].id = i + 1;

        //menampilkan code
        printf("Tanggal:");
        scanf("%s", transaksi[i].tanggal);
        printf("kategori: ");
        scanf("%s", transaksi[i].kategori);
        printf("Tipe (pemasukan/pengeluaran): ");
        scanf("%s", transaksi[i].tipe);
        printf("Nominal: ");
        scanf("%lld", &transaksi[i].nominal);
    }

    // tempat untuk menampilkan data
    printf("\n========== Transaksi Keuangan %s ==========\n", nama);
    for(int i = 0; i < jumlah; i++){
        printf("\nID : %d | ", transaksi[i].id);
        printf("TANGGAL : %s | ", transaksi[i].tanggal);
        printf("KATEGORI : %s | ", transaksi[i].kategori);
        printf("TIPE : %s | ", transaksi[i].tipe);
        printf("NOMINAL : Rp %lld", transaksi[i].nominal);
    }
    return 0;
}
