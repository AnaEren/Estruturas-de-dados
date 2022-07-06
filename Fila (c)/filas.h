/*
TAD - Fila
Desenvolvedor: Ana Ellen D P Silva
Operações: Cria, Vazia, Cheia, Insere, Retira
Obs: Tamanho da Fila definido como 20
Data: 20/01/22
*/
#ifndef FILAS_H
#define FILAS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//elementos e seu topo
typedef struct Fila{
    int elementos[20];
    int tamanho;
    int primeiro;
    int ultimo;
    int Nroelementos;
}Fila;
void cria(Fila *p);
//verifica se a fila esta cheia
bool cheia(Fila *p);
//verifica se a fila esta vazia
bool vazia(Fila *p);
//insere elementos na fila
void insere(Fila *p, int x, bool *deuCerto);
//retira elementos da fila
void retira(Fila *p, int *x, bool *deuCerto);
#endif