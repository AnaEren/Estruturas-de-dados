/*
TAD - Lista Cadastral
*/
#include <iostream>
#include <string>

using namespace std;

struct Node{
    public:
        string Info;
        Node *Next;
    Node(string x, Node *prox){
        Info = x;
        Next = prox;
    };
};
class ListaCadastral{
    //private:
    public:
        Node *primeiro;
        Node *atual;
    //cria a lista
        ListaCadastral(){
            cout<<"Construindo a fila..."<<endl;
            primeiro = NULL;
            atual = NULL;
        }
    //destroi a lista
        virtual ~ListaCadastral(){
            string x; bool ok; Node *aux;
            cout<<"\nDestruindo a fila...";
            while(primeiro != NULL){
                aux = primeiro;
                primeiro = primeiro->Next;
                delete(aux);
            }
        }
    //verifica se a lista está vazia
        bool Vazia(){
            return this->primeiro == NULL;
        }
    //verifica se a lista está cheia (sempre retorna falso)
        bool Cheia(){
            return false;
        }
    //verifica se dado elemento está na lista
        bool EstaNaLista(string x){
            Node *lAux = new Node (this->primeiro->Info, this->primeiro->Next);
            bool ok = false;

            while(!ok && lAux != NULL){
                if(lAux->Info == x){
                    ok = true;
                }
                lAux = lAux->Next;
            }
            return ok;
        }
    //insere um elemnto na lista
        void Insere(string x, bool *deuCerto){
            Node *novo = new Node (x, NULL);
            Node *lAux = new Node ("0", NULL);
            bool colocado = false;

            if(this->Vazia() || !this->EstaNaLista(x)){
                *deuCerto = true;
                if(this->Vazia()){
                    this->primeiro = novo;
                    colocado = true;
                }
                else{
                    if (primeiro->Info > x){
                        novo->Next = primeiro;
                        primeiro = novo;
                        colocado = true;
                    }
                    else{
                        lAux = primeiro;
                        while(!colocado && lAux->Next != NULL){
                            if (lAux->Info < x && x < lAux->Next->Info){
                                novo->Next = lAux->Next;
                                lAux->Next = novo;
                                colocado = true;
                            }
                            lAux = lAux->Next;
                        }
                        if(!colocado && lAux->Next == NULL){
                            lAux->Next = novo;
                        }
                    }
                }
            }
            else{
                *deuCerto = false;
            }
        }  
    //retira um elemento da lista 
        void Retira(string x, bool *deuCerto){
            Node *lAux = new Node("0", NULL);
            Node *lAux2 = new Node("0", NULL);
            Node *destruidor = new Node("0", NULL);
            bool retirado = false;
            //se a lista estiver vazia ou o elemento nao está na lista
            if(this->Vazia() || !this->EstaNaLista(x)){
                *deuCerto = false;
            }
            else{
                //se não, retira a informacao
                *deuCerto = true;
                //se a primeira informaçao for a procurada
                if(primeiro->Info == x){
                    lAux = this->primeiro->Next;
                    destruidor = this->primeiro;
                    delete(destruidor);
                    this->primeiro = lAux;
                    retirado = true;
                }
                //se nao
                else{
                    lAux = primeiro;
                    while(!retirado){
                        if(lAux->Next->Info == x){
                            lAux2 = lAux->Next->Next;
                            destruidor = lAux->Next;
                            delete(destruidor);
                            lAux->Next = lAux2;
                            retirado = true;
                        }
                        lAux = lAux->Next;
                    }
                }
            }
            
        }
    //pega o primeiro elemento da lista (se este existir)
        void PegaPrimeiro(string *x, bool *certo){
            if(!this->Vazia()){
                *x = primeiro->Info;
                atual = primeiro->Next;
                *certo = true;
            }
            else{
                *certo = false;
            }
            if(atual == NULL){
                *certo = false;
            }
        }
    //cria a lista
        void PegaProximo(string *x, bool *certo){
            if(atual != NULL){
                *x = atual->Info;
                atual = atual->Next;
                *certo = true;
            }
            else{
                *certo = false;
            }
            if(atual == NULL){
                *certo = false;
            }
        }
};
