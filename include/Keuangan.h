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
} CatatanKeuangan;

typedef struct {
    int jumlahTransaksi;
    double totalPemasukan;
    double totalPengeluaran;
    double sisaSaldo;
} RingkasanSaldo;

int dapatkanIdBerikutnya();
int simpanTransaksiBinary(CatatanKeuangan data);
int bacaSemuaTransaksi(CatatanKeuangan **daftar);

#endif