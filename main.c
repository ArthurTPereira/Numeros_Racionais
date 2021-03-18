#include <stdio.h>

#include "racional.h"

int main() {

    tRacional* racional1;
    tRacional* racional2;
    tRacional* subtracao;

    long int n1,d1,n2,d2;
    scanf("%ld %ld %ld %ld",&n1,&d1,&n2,&d2);

    racional1 = criaRacional(n1,d1);
    racional2 = criaRacional(n2,d2);

    subtracao = subtraiRacional(racional1,racional2);
    subtracao = reduzRacional(subtracao);


    imprimeRacional(subtracao);

    destroiRacional(racional1);
    destroiRacional(racional2);
    destroiRacional(subtracao);
    return 0;

}
