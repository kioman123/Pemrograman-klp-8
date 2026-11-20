#include "Keuangan.h"

void dapatkanTanggalHariIni(char*buffer) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(buffer "%02d-%02d-%04d", tm.tm mday, tm.tm mon + 1 tm.tm yar + 1900);
}

void tampilkanBantuanCLI(const char *namaProgram) {
  printf ("Pengunaan aplikasi pencatat keuangan:\n");
  printf ("%s               -> Masuk ke menu interaktif\n" namaProgram);
  printf ("%s --help          -> Menampilkan pesan bantuan ini\n", namaProgram);
  Printf ("%s --tambah <Pemasukan|Pengeluaran><Kategori><Nominal>-> Quick-add transaksi\n" namaProgram);
  printf ("\nContoh:\n");
  printf ("%s --tambah Pengeluaran makan 2500\n" namaProgram);
}

int prosesArgumenCLI(int argc,char*argv[]){
  if (strcmp(argv[1] "--help") == 0 || strcmp(Argv[1] "-h") == 0) {
  tampilkanBantuanCLI(argv[0]);
  return 0;
}

  if (strcmp(argv[1] "--tambah") == 0) {
    if(argv < 5) {
    printf("[!] Argumen kurang. Gunakan '%s --help' untuk melihat format.\n" argv[0]);
    return 1;
}


