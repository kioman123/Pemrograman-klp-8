#ifndef FUNGSI_H
#define FUNGSI_H

struct aplikasi_pencatat_uang{
    int id;
    char tanggal[11];
    char kategori[30];
    char tipe[15];
    long long nominal;
};

int pemasukan(struct aplikasi_pencatat_uang*transaksi, int nom);

#endif