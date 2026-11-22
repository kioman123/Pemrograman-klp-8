#include "Keuangan.h"

void dapatkanTanggalHariIni(char*buffer) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(buffer, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1 tm.tm_year + 1900);
}

void tampilkanBantuanCLI(const char *namaProgram) {
  printf ("Pengunaan aplikasi pencatat keuangan:\n");
  printf ("%s               -> Masuk ke menu interaktif\n", namaProgram);
  printf ("%s --help          -> Menampilkan pesan bantuan ini\n", namaProgram);
  Printf ("%s --tambah <Pemasukan|Pengeluaran> <Kategori> <Nominal> -> Quick-add transaksi\n", namaProgram);
  printf ("\nContoh:\n");
  printf ("%s --tambah Pengeluaran makan 2500\n", namaProgram);
}

int prosesArgumenCLI(int argc,char*argv[]){
  if (strcmp(argv[1], "--help") == 0 || strcmp(Argv[1], "-h") == 0) {
    tampilkanBantuanCLI(argv[0]);
    return 0;
}

  if (strcmp(argv[1], "--tambah") == 0) {
    if(argv < 5) {
      printf("[!] Argumen kurang. Gunakan '%s --help' untuk melihat format.\n", argv[0]);
      return 1;
}

    if(strcasecmp(argv[2], "Pemasukan") !=0 && strcasecmp(argv[2], "pengeluaran") !=0) {
      printf("[!] Error: Harus 'Pemasukan' atau 'Pengeluaran'.\n");
      return 1;
}

    double nominal = atof(argv[4]);
    if(nominal <= 0) {
      printf("[!] Error: Nominal harus berupa angka lebih dari 0.\n");
      return 1;
}

  CatatanKeuangan cepat;
  cepat.id = dapatkanIdBerikutnya();
  dapatkanTanggalHariIni(cepat.tanggal);
  strncpy(cepat.tipe, argv [2], sizeof(cepat.tipe) - 1);
  cepat.tipe[sizeof(cepat.tipe) - 1] = '\0';
  strncpy(cepat.kategori, argv[3], sizeof(cepat.kategori) - 1);
  cepat.kategori[sizeof(cepat.kategori) - 1] = '\0';
  cepat.nominal =nominal;

  if(simpanTransaksiBinary(cepat)) {
    printf("[Quick-Add Berhasil] #%d | %s | %s (%s): Rp %.2f\n",
      cepat.id, cepat.tanggal, cepat.tipe, cepat.kategori, cepat.nominal);
    return 0;
  } else {
    printf("[!] Gagal menyimpan data ke database.\n");
    return 1;
  }
}

  printf("[!] Argumen '%s' tidak dikenali. Ketik '%s --help' untuk bantuan.\n", argv[1], argv[0]);
  return 1;
}





