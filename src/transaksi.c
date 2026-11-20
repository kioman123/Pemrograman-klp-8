#include "keuangan.h"

int dapatkanIdBerikutnya() {
    FILE *file = fopen(FILE_BINARY, "rb");
    if (!file) return 1;

    fseek(file, 0, SEEK_END);
    long ukuranFile = ftell(file);
    fclose(file);

    return (ukuranFile / sizeof(CatatanKeuangan)) + 1;
}

// Menerima struct Catatan keuangan
int simpanTransaksiBinary(CatatanKeuangan data) {
    FILE *file = fopen(FILE_BINARY, "ab");
    if (!file) {
        perror("Gagal membuka file binary");
        return 0;
    }

    size_t tertulis = fwrite(&data, sizeof(CatatanKeuangan), 1, file);
    fclose(file);
    return tertulis == 1;
}

// Mengalokasikan array struct lewat pointer
int bacaSemuaTransaksi(CatatanKeuangan **daftar) {
    FILE *file = fopen(FILE_BINARY, "rb");
    if (!file) return 0;

    fseek(file, 0, SEEK_END);
    long ukuranFile = ftell(file);
    int jumlahData = ukuranFile / sizeof(CatatanKeuangan);
    rewind(file);

    if (jumlahData > 0) {
        *daftar = (CatatanKeuangan *)malloc(jumlahData * sizeof(CatatanKeuangan));
        if (*daftar != NULL) {
            fread(*daftar, sizeof(CatatanKeuangan), jumlahData, file);
        } else {
            jumlahData = 0;
        }
    }

    fclose(file);
    return jumlahData;
