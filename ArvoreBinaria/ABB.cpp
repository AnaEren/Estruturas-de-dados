//Árvore binária 
/* OPERAÇÕES:
- Cria          - Destroi
- Vazia         - Está na árvore
- Insere        - Remove 
*/
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef string Elemento;

class ABB{
    public:
    Elemento Info;
    bool vazia;//(bool que indica se está vazio ou nao)
    ABB* Dir;
    ABB* Esq;
    ABB* Raiz;//ponteiro auxiliar

    //cria
        ABB(){
            this->vazia = true;
            this->Raiz = NULL;
            this->Dir = NULL;
            this->Esq = NULL;
            cout<<"Criando arvore binaria..."<<endl;
        }
    //cria para o insere
        ABB(Elemento x, ABB* Raiz){
            this->vazia = false;
            this->Info = x;
            this->Raiz = Raiz;
            this->Dir = NULL;
            this->Esq = NULL;
            cout<<"Criando arvore binaria..."<<endl;
        }
    //desroi
        ~ABB(){
            while(!Vazia()){
                ABB* P = Raiz; bool *Ok;
            //procura qual no vai remover
                while(P->Dir != NULL && P->Esq != NULL){
                    if(P->Dir == NULL)
                        P = P->Esq;
                    else
                        P = P->Dir;
                }
            //remove o nó
                this->Remove(P->Info, Ok);
            }
            cout<<"Destruindo arvore binaria..."<<endl;
        }

    //vazia
        bool Vazia(){
            return this->vazia;
        }
    //verifica se um elemento esta na arvore
        bool EstaNaArvore(Elemento x){
            //elemento nao encontrado ou arvore vazia
            if(this->vazia)
                return false;

            else{
                if(this->Info == x)
                    return true;//encontrado!

                else{//ainda nao encontrado
                    if(this->Info < x)
                        this->Esq->EstaNaArvore(x);
                        
                    else
                        this->Dir->EstaNaArvore(x);
                }
            }
        }
    //insere
        void Insere(string x, bool *Ok){
        //elemento ja existe na arvore
            if(this->Info == x)
                *Ok = false;

        //este é o lugar para inserir
			else if(this->Vazia()){
				this->Info = x;
				this->vazia = false;
                cout<<" Adicionando..."<<endl;
			}

        //ainda nao encontrou um lugar pra inserir
            else{
                if(this->Info > x){
                //encontrou um lugar para inserir
                    if(this->Esq==NULL)
                        this->Esq = new ABB(x, this);

                //continua procurando
                    else this->Esq->Insere(x, Ok);
                }

                else{
                //encontrou um lugar para inserir
                    if(this->Dir==NULL)
                        this->Dir = new ABB(x, this);

                //continua procurando
                    else this->Dir->Insere(x, Ok);
                }
            }
        }

    //remove
        void Remove(string x, bool *Ok){
        //não encontrado ou vazia
            cout<<" Excluindo 1..."<<endl;
            if(this->Vazia())
                *Ok = false;

        //encontrou o elemento
            if(this->Info == x){

            //0 filhos
                if(this->Dir == NULL && this->Esq == NULL){
                    (this->Raiz->Dir->Info == x ? this->Raiz->Dir : this->Raiz->Esq) = NULL;
                    delete(this);
                    *Ok = true;
                }

            //1 filho
                //só tem o filho da esquerda
                else if(this->Dir == NULL){
                    this->Raiz->Esq = this->Esq;
                    delete(this);
                    *Ok = true;
                }

                //só tem o filho da direita
                else if(this->Esq == NULL){
                    this->Raiz->Dir = this->Dir;
                    delete(this);
                    *Ok = true;
                }

            //2 filhos
                else{
                    ABB* P = this->Esq;
                    while(P->Dir != NULL)
                        P = P->Dir;
                    this->Info = P->Info;
                    P->Info = x;
                    this->Esq->Remove(x, Ok);
                }
            }

        //contunua procurando
            else{
                if(this->Info > x)
                    this->Esq->Remove(x, Ok);
                else
                    this->Dir->Remove(x, Ok);
            }
        }
};