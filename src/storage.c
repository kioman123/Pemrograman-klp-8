#include "keuangan.h"
int dapatkanldBerikutnya(){
  FILE *file= fopen (FILE_BINARY, "rb");
  if (!file) return 1;

