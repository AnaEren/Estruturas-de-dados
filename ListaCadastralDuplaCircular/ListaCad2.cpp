/*
TAD - Lista Cadastral Dupla Circular com header ordenada
Lista
~Lista
Vazia
Cheia
EstaNaLista
Insere
Retira
PegaoPrimeiro
PegaoProximo
*/
#include <iostream>
#include <string>

using namespace std;

struct Node{
    public:
        string Info;
        Node *Before;
        Node *Next;
    Node(string x, Node *bef, Node *prox){
        Info = x;
        Before = bef;
        Next = prox;
    };
};
class Lista{
    private:
        Node *atual;
        Node *Header;
    public:
    //cria a lista
        Lista(){
            cout<<"Construindo a fila..."<<endl;
            Header = new Node("0", NULL, NULL);
            Header->Before = Header;
            Header->Next = Header;
            atual = new Node("0", NULL, NULL);
        }
    //destroi a lista
        virtual ~Lista(){
            string x; bool ok; Node *aux, *aux2;
            aux = Header->Next;
            while(aux != Header){
                aux2 = aux->Next;
                delete(aux);
                aux = aux2;
            }
            cout<<"\nDestruindo a fila...";
        }
    //verifica se a lista está vazia
        bool Vazia(){
            return Header->Before == Header || Header->Next == Header;
        }
    //verifica se a lista está cheia (sempre retorna falso)
        bool Cheia(){
            return false;
        }
    //verifica se dado elemento está na lista
        bool EstaNaLista(string x){
            Node *lAux;

            Header->Info = x;
            lAux = Header->Next;
            while(lAux->Info != x)
                lAux = lAux->Next;
            if(lAux == Header)
                return false;
            else
                return true;
        }
    //insere um elemento na lista
        void Insere(string x, bool *deuCerto){
            Node *novo = new Node (x, NULL, NULL);
            Node *lAux = new Node ("0", NULL, NULL);

            *deuCerto = false;
            Header->Info = "M";// para números, pegar a media
            if(!this->EstaNaLista(x)){
                if(this->Vazia()){
                    novo->Next = Header;
                    novo->Before = Header;
                    Header->Next = novo;
                    Header->Before = novo;
                    *deuCerto = true;
                }
            //para metade menor do alfabeto
                else if(x <= "M"){
                    lAux = Header->Next;
                    if(lAux->Info > x){
                        novo->Next = lAux;
                        novo->Before = Header;
                        Header->Next = novo;
                        lAux->Before = novo;
                        *deuCerto = true;
                    }
                    else{
                        Header->Info = "M";
                        while(!*deuCerto && lAux->Info < Header->Info){
                            if (lAux->Info < x && x < lAux->Next->Info){
                                novo->Next = lAux->Next;
                                novo->Before = lAux;
                                lAux->Next->Before = novo;
                                lAux->Next = novo;
                                *deuCerto = true;
                            }
                            lAux = lAux->Next;
                        }
                    }
                }
            //para metade maior do alfabeto
                else{
                    lAux = Header->Before;
                    if(lAux->Info < x){
                        novo->Next = Header;
                        novo->Before = lAux;
                        Header->Before = novo;
                        lAux->Next = novo;
                        *deuCerto = true;
                    }
                    else{
                        Header->Info = "M";
                        while(!*deuCerto && lAux->Info > Header->Info){
                            if (lAux->Info > x && x > lAux->Before->Info){
                                novo->Before = lAux->Before;
                                novo->Next = lAux;
                                lAux->Before->Next = novo;
                                lAux->Before = novo;
                                *deuCerto = true;
                            }
                            lAux = lAux->Before;
                        }
                    }
                }
            //if
            }
        }  
    //retira um elemento da lista 
        void Retira(string x, bool *deuCerto){
            Node *lAux = new Node("0", NULL, NULL);
            Node *lAux2 = new Node("0", NULL, NULL);
            Node *destruidor = new Node("0", NULL, NULL);
            bool retirado = false;

            //se a lista estiver vazia ou o elemento nao está na lista
            if(this->Vazia() || !this->EstaNaLista(x)){
                *deuCerto = false;
            }
            else{
                //se não, retira a informacao
                lAux = Header;
                    while(!retirado){
                        if(lAux->Next->Info == x){
                            lAux2 = lAux->Next->Next;
                            lAux2->Before = lAux;
                            destruidor = lAux->Next;
                            delete(destruidor);
                            lAux->Next = lAux2;
                            retirado = true;
                        }
                        lAux = lAux->Next;
                    }
           }
            
        }
    //pega o primeiro elemento da lista (se este existir)
        void PegaPrimeiro(string *x, bool *certo){
            if(!this->Vazia()){
                atual = Header->Next;
                *x = atual->Info;
                *certo = true;
            }
            else{
                *certo = false;
            }
            if(atual->Next == Header){
                *certo = false;
            }
        }
    //cria a lista
        void PegaProximo(string *x, bool *certo){
            if(atual->Next != Header){
                atual = atual->Next;
                *x = atual->Info;
                *certo = true;
            }
            else{
                *certo = false;
            }
            if(atual->Next == Header){
                *certo = false;
            }
        }
};
