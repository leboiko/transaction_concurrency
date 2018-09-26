#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "auxFunctions.h"


extern bool isRepeated(int toCompare, int *lista, int size) {
    bool status = false;
    for (int i = 0; i < size; ++i) {
        if (lista[i] == toCompare) {
            status = true;
        }
    }
    
    return status;
}

extern bool compare_strings(char a[], char b[])
{
    int c = 0;
    
    while (a[c] == b[c]) {
        if (a[c] == '\0' || b[c] == '\0')
            break;
        c++;
    }
    
    if (a[c] == '\0' && b[c] == '\0')
        return true;
    else
        return false;
}

extern void checkTransactions(int chao, int teto, int size, int *realSize, int * arr, Processo *struct_transactions)
{
    for (int i = chao; i < teto; ++i) {
        if (i == chao){
            arr[*realSize] = struct_transactions[i].id;
            *realSize += 1;
        }
        if (!isRepeated(struct_transactions[i].id, arr, size)) {
            arr[*realSize] = struct_transactions[i].id;
            *realSize += 1;
        }
    }
}

extern void buildGraph(int chao, int teto, Processo *struct_transactions, int *sizeTuple, tTuple *struct_tuples,
                       char op1[10], char op2[10], int maxArr, int adj[][maxArr]) {
    tTuple newTuple;
    for (int i = chao; i < teto; ++i) {
        if(compare_strings(struct_transactions[i].operacao, op1)) {
            for (int j = i + 1; j < teto; ++j) {
                if(compare_strings(struct_transactions[j].operacao, op2) &&
                   compare_strings(struct_transactions[j].atributo, struct_transactions[i].atributo) &&
                   ((struct_transactions[j].id != struct_transactions[i].id))) {
                    newTuple.ti = struct_transactions[i].id;
                    newTuple.tj = struct_transactions[j].id;
                    struct_tuples[*sizeTuple] = newTuple;
                    *sizeTuple += 1;
                    adj[struct_transactions[i].id-1][struct_transactions[j].id-1] = 1;
                }
            }
        }
    }
}

extern int countWrites(int chao, int teto, Processo *struct_transactions) {
    int counter = 0;
    int ids[teto-chao];
    int posicoesOcupadas = 0;
    
    for (int i = chao; i < teto; ++i) {
        if (compare_strings(struct_transactions[i].operacao, "W")) {
            if (!isRepeated(struct_transactions[i].id, ids, posicoesOcupadas)) {
                ids[posicoesOcupadas] = struct_transactions[i].id;
                posicoesOcupadas +=1;
                counter += 1;
            }
        }
    }
    
    return counter;
}

extern void printVisao (bool controle, int count, int numTransacoes) {
    if (controle) {
        printf("NV\n");
    } else {
        if (count < numTransacoes) {
            printf("SV\n");
        } else {
            printf("NV\n");
        }
    }
}

extern void testeVisao(int chao, int teto, Processo *struct_transactions, int numTransacoes) {
    
    bool rxAfterWx = false;
    
    if (countWrites(chao, teto, struct_transactions) < numTransacoes) {
        for (int i = chao; i < teto; ++i) {
            if (compare_strings(struct_transactions[i].operacao, "W")) {
                for (int j = i+1; j < teto; ++j) {
                    if (compare_strings(struct_transactions[j].operacao, "R") &&
                        (struct_transactions[i].id != struct_transactions[j].id)) {
                        rxAfterWx = true;
                    }
                }
            }
        }
    }
    
    printVisao(rxAfterWx, countWrites(chao, teto, struct_transactions), numTransacoes);
    
}

extern void printTransactions(int n, Processo *struct_transactions)
{
    printf("Tempo\t T\t Op.\t At.\n");
    int i;
    for (i = 0; i < n; i++){
        printf("%d\t %d\t %s\t %s\n", struct_transactions[i].tempo, struct_transactions[i].id,
               struct_transactions[i].operacao, struct_transactions[i].atributo);
    }
    printf("\n");
}

