/*
Teste TAD - Lista Cadastral
- Uniao
- Intercessão
- Imprime
*/
#include "ABB.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef string Elemento;

void exibe(ABB*);
Elemento soma(ABB*);
int niveis(ABB*);

//exibe os elementos da arvore
void exibe(ABB* abb){
    if(abb){
        exibe(abb->Esq);
        cout<< abb->Info <<endl;
        exibe(abb->Dir);
    }
}

//soma os elementos da arvore
Elemento soma(ABB* abb){
    if(abb){
        return soma(abb->Dir) + abb->Info + soma(abb->Esq);
    }
    else{
        return " ";
    }
}
//calcula a altura de uma arvore binaria
int niveis(ABB* abb){
    int hDir, hEsq;
    if(abb){
        hDir = niveis(abb->Dir);
        hEsq = niveis(abb->Esq);
        return hDir>hEsq ? (1 + hDir) : (1 + hEsq);
    }
    else
        return 0;
}

//programa principal
int main() {
    //variaveis locais
    int i = 0, z, w, niveis1 = 0, niveis2 = 0;
    ABB *a1 = new ABB;
    Elemento x, y;
    bool ok;

    a1->Insere("Martha", &ok);
    a1->Insere("Elias", &ok);
    a1->Insere("Ana", &ok);
    a1->Insere("Lara", &ok);
    a1->Insere("Reja", &ok);
    a1->Insere("Rosa", &ok);

    while(i != 6){
        cout<<"\nMENU - Digite: \n 1- Inserir\n 2- Retirar\n 3- Exibir\n 4- Soma\n 5- Niveis\n 6- Sair"<<endl;
        cin>>i;
        switch(i){
        //insere
            case 1:
                cin>>x;
                a1->Insere(x, &ok);
                exibe(a1);
            break;
        //remove
            case 2:
                cin>>y;
                a1->Remove(y, &ok);
                exibe(a1);
            break;
        //exibe
            case 3:
                exibe(a1);
            break;
        //soma
            case 4:
                cout<<"Soma: "<<soma(a1)<<endl;
            break;
        //niveis
            case 5:
                cout<<"Niveis: "<<niveis(a1)<<endl;
            break;
        //encerra
            case 6:
                cout<<"Programa terminado.";
            break;
        //numero incorreto:
            default:
                cout<<" Numero invalido!"<<endl;
            break;
        }
    }
    delete(a1);
    return 0;
}