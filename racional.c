//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>


#include "racional.h"

//Struct de número racional
struct racional {
    long int num;
    long int den;
};

//Algoritmo euclideano que encontra o maior divisor comum entre dois valores
long int algoritmoEuclideano(long int x, long int y) {
    if (x == 0) return y;
    if (y == 0) return x;

    if (x > y) {
        return algoritmoEuclideano((x % y), y);
    } else {
        return algoritmoEuclideano(x, (y % x));
    }
}

//Alocação de um número racional
tRacional* alocaRacional() {
    tRacional* racional = (tRacional*) malloc(sizeof(tRacional));
    if (racional == NULL) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    return racional;
}

//Criação de um número racional e atribuição dos valores dos parâmetros
tRacional* criaRacional(long int num, long int den) {
    tRacional* racional = alocaRacional();
    racional->num = num;
    racional->den = den;
    return racional;
}

//Libera o espaço de memória alocado por um número racional
void destroiRacional(tRacional* racional) {
    free(racional);
}

//Função que copia um número racional para um outro racional
tRacional* copiaRacional(tRacional* racional) {
    tRacional* novoRacional = criaRacional(racional->num, racional->den);
    return novoRacional;
}

//Função para comparar se dois números racionais são iguais
int comparaRacional(tRacional* racional1, tRacional* racional2) {

    long double value1 = racional1->num * racional2->den;
    long double value2 = racional2->num * racional1->den;

    if (value1 < value2) return -1;
    if (value1 == value2) return 0;
    else return 1;
}

//Função que verifica se dois racionais são equivalentes
int verificaEquivalencia(tRacional* racional1, tRacional* racional2) {
    tRacional *temp1;
    tRacional *temp2;

    temp1 = reduzRacional(racional1);
    temp2 = reduzRacional(racional2);

    if (temp1->num == temp2->num && temp1->den == temp2->den) {
        return 1;
    } else return 0;
}

//Verifica se o denominador é zero
int verificaDenominador(tRacional* racional) {
    if (racional->den == 0) {
        return 1;
    } else return 0;
}

//Verifica se o numerador é zero
int verificaNumerador(tRacional* racional) {
    if (racional->num == 0) {
        return 1;
    } else return 0;
}

//Verifica se ambos (denominador e numerador) são zeros
int verificaAmbos(tRacional* racional) {
    if (verificaDenominador(racional) == 1 && verificaNumerador(racional) == 1) {
        return 1;
    } else return 0;
}


//Soma dois números racionais
tRacional* somaRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* soma = alocaRacional();
    soma->den = racional1->den * racional2->den;
    soma->num = (racional2->den * racional1->num) + (racional1->den * racional2->num);
    return soma;
}

//Acumula um segundo racional ao primeiro
tRacional* acumulaSoma(tRacional* racional1, tRacional* racional2) {
    racional1 = somaRacional(racional1,racional2);
    return racional1;
}

//Subtrai dois números racionais
tRacional* subtraiRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* diferenca = alocaRacional();
    diferenca->den = racional1->den * racional2->den;
    diferenca->num = (racional2->den * racional1->num) - (racional1->den * racional2->num);
    return diferenca;
}

//Calcula o produto entre dois números racionais
tRacional* multiplicaRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* produto = alocaRacional();
    produto->num = racional1->num * racional2->num;
    produto->den = racional1->den * racional2->den;
    return produto;
}

//Faz o produto de dois racionais e atribui ao primeiro
tRacional* acumulaProduto(tRacional* racional1, tRacional* racional2) {
    racional1->num = racional1->num * racional2->num;
    racional1->den = racional1->den * racional2->den;
    return racional1;
}

//Faz a divisão entre dois números racionais
tRacional* divideRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* divisao = alocaRacional();
    divisao->num = racional1->num * racional2->den;
    divisao->den = racional1->den * racional2->num;
    return divisao;
}

//Calcula o quadrado de um número racional
tRacional* quadradoRacional(tRacional* racional1) {
    tRacional* quadrado = alocaRacional();
    quadrado->num = racional1->num * racional1->num;
    quadrado->den = racional1->den * racional1->den;
    return quadrado;
}

//Reduz um número racional a uma fração irredutível
tRacional* reduzRacional(tRacional* racional) {
    long int mdc = algoritmoEuclideano(racional->num,racional->den);
    racional->num = racional->num / mdc;
    racional->den = racional->den / mdc;
    return racional;
}

//Imprime um número racional
void imprimeRacional(tRacional* racional) {
    printf("%ld/%ld\n",racional->num, racional->den);
}

//Converte um número racional para decimal
double converteRacional(tRacional* racional) {
    double value = (double)racional->num / (double)racional->den;
    return value;
}