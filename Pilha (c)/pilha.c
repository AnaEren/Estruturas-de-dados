/*
TAD - Pilha c/ Alocação encadeada e Dinâmica
Desenvolvedor: Ana Ellen D P Silva
Operações: Cria, Vazia, Cheia, Empilha, Desempilha
Data: 04/02/22
*/
#include "pilha.h"

//cria: cria uma pilha vazia
void cria (Pilha *p){
    p->Topo==NULL;
}
//vazia: verifica se uma pilha está vazia
bool vazia (Pilha *p){
        return p->Topo==NULL;
}
//cheia: verifica se uma pilha esta cheia
bool cheia(Pilha *p){
    return false;
}
//empilha: insere um elemento dado no topo de uma pilha
void empilha (int v, Pilha *p, bool *certo){
    NodePtr aux;
    aux = (Node*) malloc (sizeof(Node));
    if(aux==NULL)
        *certo = false;
    else{
        *certo = true;
        aux->Info = v;
        aux->Next = p->Topo;
        p->Topo = aux;
    }
}
//desempilha: retira um elemento do topo de uma pilha
void desempilha (int *v, Pilha *p, bool *certo){
    if(vazia(p)==true)
        *certo = false;
    else{
        *certo = true;
        *v = p->Topo->Info;
        p->Topo = p->Topo->Next;
    }
}
void destroi (Pilha* p){
    int v; bool ok;
    while(!vazia(p))
        desempilha(&v, p, &ok);
}
