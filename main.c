#include <stdio.h>
#include <stdlib.h>

#include "racional.h"

int main() {

    tRacional* racional1;

    racional1 = criaRacional(1,2);

    imprimeCSV(racional1);

    destroiRacional(racional1);

    return 0;

}
