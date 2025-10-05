#include "analyse.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <sourcefile.c>\n", argv[0]);
        return 1;
    }

    analyseFile(argv[1]);
    return 0;
}
