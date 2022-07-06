/*
Teste TAD - Lista Cadastral Dupla Circular com header
- Uniao
- Intercessão
- Imprime
*/
#include "Q1.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
//exibe os elementos das filas
void exibe(Lista *l1, Lista *l2){
    bool ok; string a = "Lista vazia", x = a, y = a, z = a, w = a;

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
}
//programa principal
int main() {
    Lista *l1 = new Lista;
    Lista *l2 = new Lista;
    bool ok, igualb, test=true;
    string x, y;
    int i = 0, z, w;

    while(i != 5){
        cout<<"\nMENU - Digite: \n 1- Inserir\n 2- Retirar\n 3- Sao Iguais?\n 4- Exibir\n 5- Sair"<<endl;
        cin>>i;
        switch(i){
            case 1:
                cout<<"Lista 1 ou 2?";
                cin>>w;
                if(w == 1){
                    l1->Insere("Martha", &ok);
                    l1->Insere("Ana", &ok);
                    l1->Insere("Rejane", &ok);
                    l1->Insere("Carlos", &ok);
                    l1->Insere("Rejane", &ok);
                    l1->Insere("Rejane", &ok);
                    l1->Insere("Carlos", &ok);
                    l1->Insere("Rejane", &ok);
                    l1->Insere("Carlos", &ok);
                }
                else if(w == 2){
                    l1->Insere("B", &ok);
                    l1->Insere("C", &ok);
                    l1->Insere("B", &ok);
                    l1->Insere("A", &ok);
                }
                else{
                    cout<<" Inválido!";
                }
            break;
            case 2:
                cout<<"Lista 1 ou Todos?";
                cin>>z;
                if(z == 1){
                    cin>>y;
                    l1->Remove_1(y, &ok);
                }
                else if(z == 2){
                    cin>>y;
                    l1->Remove_Todos(y, &ok);
                }
                else{
                    cout<<" Inválido!";
                }
            break;
            case 3:
                //igualb = igual(l1, l2);
                if(igualb)
                    cout<<"Iguais."<<endl;
                else
                    cout<<"Diferentes."<<endl;
            break;
            case 4:
                exibe(l1, l2);
            break;
            case 5:
                cout<<"Programa terminado.";
            break;
            default:
                cout<<" Numero invalido!"<<endl;
            break;
        }
    }
    delete(l1);
    delete(l2);
    return 0;
}