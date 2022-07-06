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
        Node *primeiro;
        Node *ultimo;
    public:
        Fila(){
            cout<<"Construindo a fila..."<<endl;
            primeiro = NULL;
            ultimo = NULL;
        }   
        virtual ~Fila(){
            cout<<"Destruindo a fila..."<<endl;
        }
        void Cria(){
            cout<<"Construindo a fila..."<<endl;
            primeiro = NULL;
            ultimo = NULL;
        }   
        bool Vazia(){
            return this->primeiro == NULL;
        }
        bool Cheia(){
            return false;
        }
        void Insere(int x, bool* deuCerto){

            Node *fAux = new Node (x, NULL);
            *deuCerto = true;
            
            if(this->Vazia())
                this->primeiro = fAux;
            else
                this->ultimo->Next = fAux;
            this->ultimo = fAux;
        }   
        void Retira(int* x, bool* deuCerto){

            Node *fAux = new Node(primeiro->Info, primeiro->Next);


            if(this->Vazia()){
                this->primeiro = NULL;
                this->ultimo = NULL;
                *deuCerto = false;
            }
            else{
                *deuCerto = true;
                *x = fAux->Info;
                this->primeiro = this->primeiro->Next;
            }
            delete(fAux);
            
        }
};
