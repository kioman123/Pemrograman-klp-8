#include "keuangan.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        return prosesArgumenCLI(argc, argv);
    }

    return 0;
}