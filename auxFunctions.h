#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//
// Created by Luis Eduardo Boiko Ferreira on 10/09/2018.
//

#ifndef SGBD_AUXFUNCTIONS_H
#define SGBD_AUXFUNCTIONS_H

#endif //SGBD_AUXFUNCTIONS_H

//
// Created by Luis Eduardo Boiko Ferreira on 10/09/2018.
//


typedef struct tTuple {
    int ti, tj;
}tTuple;

typedef struct Processo {
    int tempo, id;
    char operacao[10], atributo[10];
}Processo;

typedef struct Vida
{
    int id;
    int nascimento;
    int morte;
}Vida;

extern bool isRepeated(int toCompare, int *lista, int size);

extern bool compare_strings(char a[], char b[]);

extern void checkTransactions(int chao, int teto, int size, int *realSize, int * arr, Processo *struct_transactions);

extern void buildGraph(int chao, int teto, Processo *struct_transactions, int *sizeTuple, tTuple *struct_tuples,
                       char op1[10], char op2[10], int maxArr, int adj[][maxArr]);

extern int countWrites(int chao, int teto, Processo *struct_transactions);

extern void printVisao (bool controle, int count, int numTransacoes);

extern void testeVisao(int chao, int teto, Processo *struct_transactions, int numTransacoes);

extern void printTransactions(int n, Processo *struct_transactions);
