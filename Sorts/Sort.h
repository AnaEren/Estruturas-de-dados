#pragma once

#include <iostream>
#include <string>
#include <stdlib.h> 

#define pai(i) ((i-1)/2)
#define filho(i) (2*i + 1)

using namespace std;

typedef int Elemento;

class Sorts{
public:
	// Construtor
	Sorts(int tamanho){
			this->tamanho = tamanho;
			this->v = new Elemento[tamanho];
	}
	// Destrutor
	virtual ~Sorts(){
		delete[] v;
	}
	// MÉTODOS DE ORDENACAO

	// SelectionSort - Selecao 
	void SelectionSort(){ // O(n²)
		// variaveis auxiliares
		int i, j, menor, index;
		// percorre o vetor
		for(i = 0; i < tamanho - 1; i++){ // O(n)
			// inicia o menor valor como o de posicao i (para fins de comparacao)
			menor = v[i]; index = i;
			// procura o menor tamanho ainda nao posicionado corretamente
			for(j = i; j < tamanho - 1; j++){ //maior varredura será O(n)
				// muda o menor
				if(menor > v[j]){
					menor = v[j];
					index = j;
				}
			}
			// apos a varredura completa atras do menor, troca 
			// o valor, posicinado apos os ja corretamente inseridos
			this->troca(i, index);
		}

	}

	// BubbleSort - Troca
	bool BubbleSort(){// O(n²)
		// vaiaveis auxiliares de varredura e quantia de trocas
		int i, j, trocas = - 1, ultimo, total = tamanho;

		while(trocas != 0){// O(n) no pior caso
			trocas = 0;
			ultimo = 0;
			
			for(j = 1; j < total; j ++){// O(n-1)
				if(v[j - 1] > v[j]){
					trocas++;
					this->troca(j, j-1);
					ultimo = j;
				}
			}
			total = ultimo;
		}
	}

	// InsertionSort - Insercao
	void InsertionSort(){ // O(n²)
		// variaveis auxiliares de varredura e armazenamento
		int i, j, aux;

		//considera v[0] como ja posicionado e varre o resto do vetor
		for(i = 1; i < tamanho; i++){// O(n)

			// insere cada numero do vetor no local correto, um por vez
			aux = v[i]; j = i;

			// muda o vetor de acordo com a posicao que v[i] deve ficar

			while((j > 0) && (aux < v[j-1])){// O(n) no pior caso (percorrer vetor inteiro)
				// (funcao troca desnecessaria)
				v[j] = v[j-1];
				j--;
			}
			v[j] = aux;
		}
	}

	// HeapSort - Selecao + Heap
	void HeapSort(){

		int n = this->tamanho, i, j;

		// constroi o heap
		for(i = 0; i < n; i++)
			this->sobeHeap(i);
		
		for(j = n; j > 0; j--){

			// faz a troca do primero com o ultimo valor
			this->troca(0, j-1);

			// restaura o heap
			this->desceHeap(j-1);
		}
	}
	//faz o valor da posicao passada subir enquanto seus filhos forem maiores que si
	void sobeHeap(int posicao){
		int i = posicao;

		//enquanto houver posicoes e o pai for menor que o filho
		while(i > 0 && v[pai(i)] < v[i]){
			//troca o valor do pai com o de filho maior que si
			this->troca(pai(i), i);

			//coloca o valor do pai do atual como o novo filho
			i = pai(i);
		}
	}
	// reorganiza o heap, descendo os maiores
	void desceHeap(int posicao){
		int i = 0, j = 1;

		//enquanto houver filhos e pelo menos um dos filhos for maior que o pai
		while(filho(i) < posicao && (v[filho(i)] > v[i] 
				||(filho(i) + 1 < posicao && v[filho(i)+1] > v[i]))){

			//coloca um filho para o pai atual
			j = filho(i);

			//se o filho tiver e for menor que seu irmao, estes trocam
			if(j + 1 < posicao && v[j + 1] > v[j])
				j++;

			//a posicao do pai e do maior filho sao trocadas
			this->troca(i, j);

			// o filho trocado se torna o novo pai
			i = j;
		}
	}

	// QuickSort - Troca (feito recursivamente)
	void QuickSort(int esq = 0, int dir = -1){ // O(n²)
	// se o pivo escolhido fos sempre o menor / maior numero do vetor, este seria
	// o pior caso de quickSort, que passaria pela recursividade n vezes, ou O(n)
		//se o tamanho nao estiver pre definido
		if(dir < 0 )
			dir = tamanho - 1;

		// se o direito (final) for maior que o esquerdo (inicial)
		if(esq < dir){

			// escolhe o pivo e faz a divisao
			int pivo = this->particao(esq, dir);

			// faz a recursividade
			// para a segunda parte (direita)
			this->QuickSort(pivo + 1, dir);

			// para a primeira parte (esquerda)
			this->QuickSort(esq, pivo - 1);
		}
	}


	// Insere os elementos do vetor
	bool setVetor(int posicao, Elemento valor){
		if(this->tamanho > posicao){
			this->v[posicao] = valor;
			return true;
		}
		else
			return false;
	}

	// Imprime os dados
	void Imprime(){
		for(int i=0; i<tamanho; i++)
			cout<< this->v[i] << " ";
		cout << endl;
	}

private:

	int* v;
	int tamanho;

	// faz a particao e a mudanca no vetor, para o quicksort
    int particao(int esq, int dir){
        // coloca o pivo como o final do vetor
        int pivo = v[esq];
        // variavel auxiliar para a particao
        int j = dir;

        // faz a particao (menores a esquerda, maiores a direita)
		// começando do fim e terminando no inicio (comecando pelos maiores)
        for(int i = dir; i > esq; i--){ // maior busca será O(n)
			// se o vetor passado e maior que o pivo
            if(v[i] >= pivo){
				// este ficara no "final" do vetor
                this->troca(i, j);
				// a posicao "final" para os maiores numeros dimunui
                j--;
            }
        }
        // trocando o pivo atual pelo ultimo numero trocado de lugar
        // dividindo, assim, numeros maiores que o pivo dos menores e 
        // associando um novo pivo a posicao
        this->troca(j, esq);

        // retorna o novo pivo (posicao para a reparticao)
        return j;
    }

	// Troca duas posicoes de um vetor de lugar
	void troca(int i, int j){
		int aux = v[i];
		v[i] = v[j];
		v[j] = aux;
	}
};
/*
class ABB{
public:
	ABB(Elemento x, ABB* mae){
		this->mae = mae;
		this->Info = x;
		this->esq = NULL;
		this->dir = NULL;
	}

	ABB(Elemento x){
		this->mae = NULL;
		this->Info = x;
		this->esq = NULL;
		this->dir = NULL;
	}

	virtual~ABB(){
		delete(this);
	}
	// insere elementos, como a arvore é um auxilio, esta nao é complexa
	bool Insere(Elemento x){
		bool inserido = false;

		if(this->Info > x){
			if(this->esq == NULL){
				this->esq = new ABB(x, this);
				inserido = true;
			}
			else
				this->esq->Insere(x);
		}
		else{
			if(this->dir == NULL){
				this->dir = new ABB(x, this);
				inserido = true;
			}
			else
				this->dir->Insere(x);
		}	
		if(inserido){
			this->Rebalanceia();
			return true;
		}
		return false;
	}
	// faz o balanceio recursivamente
	bool Rebalanceia(){
		if(!this) return false;
		this->Balanceia();
		if(this->mae){
			this->mae->Rebalanceia();
		}return true;
	}
	// calcula a altura de uma arvore binaria
	int Altura(){
		int hDir, hEsq;
		if(this){
			hDir = this->dir->Altura();
			hEsq = this->esq->Altura();
			return hDir>hEsq ? (1 + hDir) : (1 + hEsq);
		}
		else
			return 0;	
	}
	void Balanceia(){
		if(this){
			// desbalanceado para o lado direito
			if(this->Balanco() >= 2){
				if(this->esq->Balanco() <= 1)
					this->Rotacao(true);
				this->Rotacao(false);
			}
			// desbalanceado para o lado esquerdo
			else if(this->Balanco() <= -2){
				if(this->esq->Balanco() >= 1)	
					this->Rotacao(false);
				this->Rotacao(true);
			}
		}
	}
	//calcula o balanco dos lados
	int Balanco(){
		return this?this->dir->Altura()-this->esq->Altura():0;
	}
	//faz a rotacao da arvore
	bool Rotacao(bool lado){
		if(this){
			// false = esquerda; true = direita;
			if(lado){
			ABB* P = this->esq;
			cout << "Aqui 2";
			P->dir->mae = this;
			P->dir = this;
			P->esq->mae = P;
			cout << "Aqui 2";
			}
			else{
			ABB* P = this->dir;
			cout << "Aqui 2";
			P->esq->mae = this;
			P->esq = this;
			P->dir->mae = P;
			cout << "Aqui 2";
			}
		}
	}
	bool Troca(){

	}
	void Imprime(){
		if(this){
			this->esq->Imprime();
			cout<<this->Info<<" ";
			this->dir->Imprime();
		}
	}

	ABB* esq, *dir, *mae, *R;
	Elemento Info;
};
*/