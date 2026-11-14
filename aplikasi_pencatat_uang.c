#include <stdio.h>
#include <string.h>

struct aplikasi_pencatat_uang{
    int id;
    char tanggal[11];
    char kategori[30];
    char tipe[15];
    long long nominal;
};



int main(){

    struct aplikasi_pencatat_uang transaksi[10];
    
    // variabel untuk pengeluaran,pemasukan dan saldo
    long long total_pemasukan = 0;
    long long total_pengeluaran = 0;
    long long saldo = 0;

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
    //dan printf dibawah perulangan untuk menampilkan transaksi ke-1 sampai ke-10
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
    }
    return 0;
}
