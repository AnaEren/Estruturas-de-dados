/*
TAD - Pilha
Desenvolvedor: Ana Ellen D P Silva
Operações: Cria, Vazia, Cheia, Empilha, Desempilha
Obs: Tamanho da Pilha definido como 20
Data: 20/01/22
*/
#ifndef PILHAS_H
#define PILHAS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define tamanho 20
//elementos e seu topo
typedef struct pilha{
    int elementos[tamanho];
    int topo;
}Pilha;
//Operações:
void cria (Pilha*);
bool vazia (Pilha*);
bool cheia (Pilha*);
void empilha (int, Pilha*, bool*);
void desempilha (int*, Pilha*, bool*);
#endif
