#include "Keuangan.h"

void dapatkanTanggalHariIni(char*buffer)
  time_t t = time(NULL)
  struct tm tm = *localtime(&t)
  sprintf(buffer "%02d-%02d-%04d", tm.tm mday, tm.tm mon + 1 tm.tm yar + 1900)

void tampilkanBantuanCLI(const char *aplikasipencatatuang) //namaprogram
  printf ("Pengunaan aplikasi pencatat keuangan:\n")
  printf ("%s", 
