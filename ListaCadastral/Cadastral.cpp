/*
Teste TAD - Lista Cadastral
- Uniao
- Intercessão
- Imprime
*/
#include "listaCad.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
//faz a união entre as filas 1 e 2
Lista *uniao (Lista *l1, Lista *l2){
    Lista *l3 = new Lista;
    string x, y; bool ok, okI;

    l1->PegaPrimeiro(&x, &ok);
    l3->Insere(x, &ok);
    while(ok){
        l1->PegaProximo(&x, &ok);
        l3->Insere(x, &okI);
    }
    l2->PegaPrimeiro(&x, &ok);
    l3->Insere(x, &okI);
    while(ok){
        l2->PegaProximo(&x, &ok);
        l3->Insere(x, &okI);
    }

    return l3;

}
//faz a intercecao entre as filas 1 e 2
Lista *interceccao (Lista *l1, Lista *l2){
    Lista *l3 = new Lista;
    string x, y; bool ok;

    l1->PegaPrimeiro(&x, &ok);
    if(l2->EstaNaLista(x))
        l3->Insere(x, &ok);
    while(ok){
        l1->PegaProximo(&x, &ok);
        if(l2->EstaNaLista(x))
            l3->Insere(x, &ok);
    }
    return l3;

}
//exibe os elementos das filas
void exibe(Lista *l1, Lista *l2, Lista *l3, Lista *l4){
    bool ok; string a = "Fila vazia", x = a, y = a, z = a, w = a;

    cout<<"\nLista 1:\n";
    l1->PegaPrimeiro(&x, &ok);
        cout<<x;
    while(ok){
        l1->PegaProximo(&x, &ok);
            cout<<" "<<x;
    }
    cout<<"\nLista 2:\n";
    l2->PegaPrimeiro(&y, &ok);
        cout<<y;
    while(ok){
        l2->PegaProximo(&y, &ok);
            cout<<" "<<y;
    }
    cout<<"\nLista 3:\n";
    l3->PegaPrimeiro(&z, &ok);
        cout<<z;
    while(ok){
        l3->PegaProximo(&z, &ok);
            cout<<" "<<z;
    }
    cout<<"\nLista 4:\n";
    l4->PegaPrimeiro(&w, &ok);
        cout<<w;
    while(ok){
        l4->PegaProximo(&w, &ok);
            cout<<" "<<w;
    }
}
//programa principal
int main() {
    Lista *l1 = new Lista;
    Lista *l2 = new Lista;
    Lista *l3 = new Lista;
    Lista *l4 = new Lista;
    bool ok, test=true;
    string e("Elias"), x, y;
    int i = 0, z, w;

    l1->Insere("Martha", &ok);
    l1->Insere("Ana", &ok);
    l1->Insere(e, &ok);
    l1->Insere("Rejane", &ok);
    l1->Insere("Carlos", &ok);

    while(i != 6){
        cout<<"\nMENU - Digite: \n 1- Inserir\n 2- Retirar\n 3- Interseccao\n 4- Uniao\n 5- Exibir\n 6- Sair"<<endl;
        cin>>i;
        switch(i){
            case 1:
                cout<<"Lista 1 ou 2?";
                cin>>w;
                if(w == 1){
                    cin>>x;
                    l1->Insere(x, &ok);
                }
                else if(w == 2){
                    cin>>x;
                    l2->Insere(x, &ok);
                }
                else{
                    cout<<" Inválido!";
                }
            break;
            case 2:
                cout<<"Lista 1 ou 2?";
                cin>>z;
                if(z == 1){
                    cin>>y;
                    l1->Retira(y, &ok);
                }
                else if(z == 2){
                    cin>>y;
                    l2->Retira(y, &ok);
                }
                else{
                    cout<<" Inválido!";
                }
            break;
            case 3:
                l3 = interceccao(l1, l2);
            break;
            case 4:
                l4 = uniao(l1, l2);
            break;
            case 5:
                exibe(l1, l2, l3, l4);
            break;
            case 6:
                cout<<"Programa terminado.";
            break;
            default:
                cout<<" Numero invalido!"<<endl;
            break;
        }
    }
    delete(l1);
    delete(l2);
    delete(l3);
    return 0;
}