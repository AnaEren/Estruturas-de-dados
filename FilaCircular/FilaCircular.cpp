//fila de vacinacao, ordem por idade 
//insere
/*
TAD - Fila Alocada Dinamicamente
*/
#include <iostream>

using namespace std;

class Node{
    public:
        int Info;
        Node *Next;
    Node(int x, Node *prox){
        Info = x;
        Next = prox;
    };
};

class Fila{
    private:
        Node *FV;
        int Tamanho;
    public:
        Fila(){
            cout<<"Construindo a fila..."<<endl;
            FV = NULL;
        }   
        virtual ~Fila(){
            cout<<"Destruindo a fila..."<<endl;
        }
        void Cria(){
            cout<<"Construindo a fila..."<<endl;
            FV = NULL;
            Tamanho = 0;
        }   
        bool Vazia(){
            return this->FV == NULL;
        }
        bool Cheia(){
            return false;
        }
        void Insere(int Idade){
            Node *P = new Node (Idade, NULL);
            Node *P3 = new Node (0, NULL);
            bool inserido = false; int i;
            P3 = FV;
            
            if(this->Vazia()){
                P->Next = P;
                FV = P;
            }
            else{
                Node *P2 = FV;
                if(FV->Info < Idade){
                    P->Next = FV;
                    while(P2->Next != FV)
                        P2 = P2->Next;
                    P2->Next = P;
                    FV = P;
                }
                else{
                    while(!inserido){
                        if (P2->Next->Info < Idade){
                            P->Next = P2->Next;
                            P2->Next = P;
                            inserido = true;
                        }
                        P2 = P2->Next;
                        if(P2->Next == FV){
                            P->Next = FV;
                            P2->Next = P;
                            inserido = true;
                        }
                    }
                }
            }
            Tamanho++;
        }   
        void Retira(int* x, bool* deuCerto){
            Node *P = new Node(FV->Info, FV->Next);
            Node *P2 = new Node(FV->Info, FV->Next);
            int i=1;

            if(this->Vazia()){
                FV = NULL;
                *deuCerto = false;
            }
            else{
                *deuCerto = true;
                *x = P->Info;
                P = FV;
                FV = FV->Next;
            }
            
            while(P2->Next != FV)
                P2 = P2->Next;
            P2->Next = FV;

            Tamanho --;
            delete(P);
            
        }
        void Exibe(){
            Node *fAux = new Node (0, FV);
            int i;
            fAux = FV;
            cout<<FV->Info<<endl;
            for(i=0;i<Tamanho;i++){
                cout<<fAux->Info<<" ";
            fAux = fAux->Next;
            }
            cout<<"\n"<<Tamanho<<endl;
        }
};
