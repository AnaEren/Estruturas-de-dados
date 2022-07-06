/*
(TAD) Algoritimo de busca sequencial e busca binária, em um vetor ordenado
Nome: Ana Ellen Deodato Pereira da Silva
*/
#include <iostream>

using namespace std;
typedef int Elemento;

class BB{
	public:
	//cria a classe
		BB(int tamanho){
			this->tamanho = tamanho;
			this->v = new Elemento[tamanho];
		}
		~BB(){
			delete[] v;
		}
	//realizam a busca binaria
		bool Binaria(Elemento procurado){
			return this->BusBin(procurado, 0, this->tamanho);
		}
		bool BusBin(Elemento procurado, int esq, int dir){
			//se a posicao direita é maior que a esquerda
			if(dir < esq)
				return false;
			
			//calcula o valor do meio
			int meio = (esq + dir)/2;

			//se o valor for encontrado
			if(this->v[meio] == procurado)
				return true;

			//se nao, continua procurando
			else{
				if(procurado < this->v[meio])
					return this->BusBin(procurado, esq, meio-1);
				else
					return this->BusBin(procurado, meio+1, dir);
			}
		}
	//verifica quantas vezes foi passado na busca Binaria
		int vezesBinaria(Elemento procurado){
			return this->vBusBin(procurado, 0, this->tamanho);
		}
		int vBusBin(Elemento procurado, int esq, int dir){
			//se a posicao direita é maior que a esquerda
			if(dir < esq)
				return 1;
			
			//calcula o valor do meio
			int meio = (esq + dir)/2;

			//se o valor for encontrado
			if(this->v[meio] == procurado)
				return 1;

			//se nao, continua procurando
			else{
				if(procurado < this->v[meio])
					return 1 + this->vBusBin(procurado, esq, meio-1);
				else
					return 1 + this->vBusBin(procurado, meio+1, dir);
			}
		}
	//realizam a busca sequencial
		bool Sequencial(Elemento procurado){
			//procura no vetor inteiro, até encontrar
			for(int i=0; i<this->tamanho; i++){
				if(this->v[i] == procurado)
					return true;//encontrado!
			}
			return false;
		}
	//realizam a busca sequencial
		int vezesSequencial(Elemento procurado){
			//procura no vetor inteiro, até encontrar
			for(int i=0; i<this->tamanho; i++){
				if(this->v[i] == procurado)
					return i+1;//encontrado!
			}
			return this->tamanho;
		}
	//insere os elementos do vetor
		bool setVetor(int posicao, Elemento valor){
			if(this->tamanho > posicao){
				this->v[posicao] = valor;
				return true;
			}
			else
				return false;
		}
	//imprime os dados
		void Imprime(){
			cout << "Vetor: ";
			for(int i=0; i<tamanho; i++)
				cout<< this->v[i] << " ";
			cout << endl;
		}

	private:
		Elemento* v;
		int tamanho;
};
