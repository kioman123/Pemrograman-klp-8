
#ifndef KEUANGAN_H
#define KEUANGAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_BINARY "keuangan.bin"
#define FILE_LAPORAN "laporan_bulanan.csv"

typedef struct {
    int id;
    char tanggal[15];      // Format: DD-MM-YYYY
    char kategori[30];     // Contoh: Makan, Transportasi, Gaji
    char tipe[15];         // "Pemasukan" atau "Pengeluaran"
    double nominal;
};

#endif