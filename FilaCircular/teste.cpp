/*
Teste TAD - fila alocada dinamicamente
1. Insere uam quantia aleatória de elementos aleatorios
2. Exibe os elementos da fila
3. Exibe o ultimo elemento da fila
*/
#include "FilaCircular.cpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int i=0, j, random = rand()%20;
    bool ok;
    Fila *f1 = new Fila;

    cout<<"Inserindo "<<7<<" elementos... ";
    while(i<5){
        cout<<endl;
        j = rand()%100;
        f1->Insere(j);
        cout<<"\nExibe: ";
        f1->Exibe();
        i++;
    }
    f1->Retira(&j, &ok);
    f1->Exibe();
    f1->Retira(&j, &ok);
    f1->Exibe();
    
    return 0;
}