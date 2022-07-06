/*
Teste Busca binária
*/
#include "Sort.h"
#include <iostream>
#include <string>
#include <stdlib.h> 

using namespace std;

typedef int Elemento;

//programa principal
int main() {

    //variaveis locais
	int tamanho = 10, selecao = 0, num;
    Sorts *s = new Sorts(tamanho);
	/*
	for(int i = 0; i< tamanho; i++){
		a->Insere(i);
	}
	cout << endl;

	a->Imprime();
	
	cout << endl;
	cout << "Altura da àrvore = " << a->Altura() << endl;
	*/
	while(selecao != 5){
		cout << "Tipo de ordenacao: "; cin >> selecao;
	
		//adiciona os elementos ao vetor
		for(int i = 0; i< tamanho; i++)
			s->setVetor(i, rand()%10);

		//exibe o vetor ainda nao ordenado
		cout << "Vetor nao ordenado: "; s->Imprime();
		cout << endl;

		switch(selecao){
			case 0:
				s->QuickSort();
				cout << "Vetor pos QuickSort: "; s->Imprime();
				cout << endl;
			break;
			case 1:
				s->SelectionSort();
				cout << "Vetor pos SelectionSort: "; s->Imprime();
				cout << endl;
			break;
			case 2:
				s->HeapSort();
				cout << "Vetor pos HeapSort: "; s->Imprime();
				cout << endl;
			break;
			case 3:
				s->BubbleSort();
				cout << "Vetor pos BubbleSort: "; s->Imprime();
				cout << endl;
			break;
			case 4:
				s->InsertionSort();
				cout << "Vetor pos InsertionSort: "; s->Imprime();
				cout << endl;
			break;
			case 5:
				cout << "Programa terminado!";
			break;
			default:
				cout << "Entrada invalida!" << endl;
			break;
		}
	}
	//fim do programa
    return 0;
}