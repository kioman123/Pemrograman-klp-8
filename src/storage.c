#include "keuangan.h"
int dapatkanldBerikutnya(){
  FILE *file= fopen (FILE_BINARY, "rb");
  if (!file) return 1;

fseek(file, 0, SEEK_END);
long ukuranFile = ftell(file);
fclose(file);
return (ukuranFile / sizeof (CatatanKeungan))+ 1;
}
//menerima struct catatankeuangan secara pass by value
int simpanTransaksiBinary(CatatanKeuangan data){
  FILE *file = fopen(FILE_BINARY, "ab");
if (!file){
perror("Gagal membuka file binary");
return 0;
}
size_t tertulis = fwrite(&data, sizeof(CatatanKeungan), 1, file);
fclose(file);
return tertulis == 1;
}
//Mengalokasikan array struct secara dinamis lewat pointer
int bacaSemuaTransaksi(CatatanKeungan **daftar){
  FILE *file = fopen(FILE_BINARY, "rb");
if (!file) return 0;

