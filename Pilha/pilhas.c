/*
TAD - Pilha
Desenvolvedor: Ana Ellen D P Silva
Operações: Cria, Vazia, Cheia, Empilha, Desempilha
Obs: Tamanho da Pilha definido como 20
Data: 20/01/22
*/
#include "pilhas.h"

//cria: cria uma pilha vazia
void cria (Pilha *p){
    p->topo = 0;
}
//vazia: verifica se uma pilha está vazia
bool vazia (Pilha *p){
    if(p->topo == 0)
        return true;
    else
        return false;
}
//cheia: verifica se uma pilha esta cheia
bool cheia(Pilha *p){
    if(p->topo == tamanho)
        return true;
    else
        return false;
}
//empilha: insere um elemento dado no topo de uma pilha
void empilha (int v, Pilha *p, bool *certo){
    bool ok = cheia(p);
    if(ok==true)
        *certo = false;
    else{
        p->elementos[p->topo] = v;
        p->topo ++;
        *certo = true;
    }
}
//desempilha: retira um elemento do topo de uma pilha
void desempilha (int *v, Pilha *p, bool *certo){
    if(vazia(p)==true)
        *certo = false;
    else{
        p->topo --;
        *v = p->elementos[p->topo];
        *certo = true;
    }
}
