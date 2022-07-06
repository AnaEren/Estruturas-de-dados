/*
TAD - Fila
Comandos: cheia,vazia, insere, retira
*/
#include <stdio.h>
#include "filas.h"
#define tamanho 20
//cria uma fila
void cria(Fila *p){
    p->primeiro = 0;
    p->ultimo = 0;
    p->Nroelementos = 0;
}
//verifica se a fila esta cheia
bool cheia(Fila *p){
    if (p->Nroelementos == tamanho){
        return true;
    }
    else
        return false;
}
//verifica se a fila esta vazia
bool vazia(Fila *p){
    if (p->Nroelementos == 0){
        return true;
    }
    else{
        return false;
    }
}
//insere elementos na fila
void insere(Fila *p, int x, bool *deuCerto){
    if(p->Nroelementos == tamanho){
        *deuCerto = false;
    }
    else{
        *deuCerto = true;
        p->Nroelementos++;
        p->elementos[p->ultimo] = x;
        //vetor circular
        if(p->ultimo == 19)
            p->ultimo = 0;
        else
            p->ultimo++;
    }
}
//retira elementos da fila
void retira(Fila *p, int *x, bool *deuCerto){
    if(p->Nroelementos == 0){
        *deuCerto = false;
    }
    else{
        *deuCerto = true;
        p->Nroelementos--;
        *x = p->elementos[p->primeiro];
        p->elementos[p->primeiro] = 0;
        //vetor circular
        if(p->primeiro == 19)
            p->primeiro = 0;
        else
            p->primeiro++;
    }
}
