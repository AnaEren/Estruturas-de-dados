/*
Teste TAD - fila alocada dinamicamente
1. Insere uam quantia aleatória de elementos aleatorios
2. Exibe os elementos da fila
3. Exibe o ultimo elemento da fila
*/
#include "fila.cpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int i=0, j=0, random = rand()%20;
    bool ok;
    Fila *f1 = new Fila;
    Fila *f2 = new Fila;
    cout<<"Inserindo "<<random<<" elementos... ";
    while(i<random){
        j = rand()%10;
        f1->Insere(j, &ok);
        i++;
    }
    i=0;
    cout<<"\nExibe: ";
    while(!f1->Vazia()){
        f1->Retira(&j, &ok);
        cout<<j<<" ";
        f2->Insere(j, &ok);
        i++;
    }
    i=0;
    while(!f2->Vazia()){
        f2->Retira(&j, &ok);
        f1->Insere(j, &ok);
        i++;
    }
    cout<<"\nUltimo elemento: "<<j;
    cout << endl;
    
    return 0;
}