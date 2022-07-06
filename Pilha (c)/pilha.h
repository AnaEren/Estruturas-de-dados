/*
TAD - Pilha c/ Alocação encadeada e Dinâmica
Desenvolvedor: Ana Ellen D P Silva
Operações: Cria, Vazia, Cheia, Empilha, Desempilha
Data: 04/02/22
*/
#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//elementos e seu topotypedef 
typedef struct Node{
    int Info;
    struct Node *Next;
} Node;

typedef Node *NodePtr;

typedef struct pilha{
    NodePtr Topo;
}Pilha;
//Operações:
void cria (Pilha*);
bool vazia (Pilha*);
bool cheia (Pilha*);
void empilha (int, Pilha*, bool*);
void desempilha (int*, Pilha*, bool*);
void destroi (Pilha*);

#endif
