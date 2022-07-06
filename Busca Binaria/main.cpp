/*
Teste Busca binária
*/
#include "BB.cpp"
#include <iostream>
#include <string>

using namespace std;

typedef int Elemento;

//funcao printa se o valor foi encontrado
void encontrado(bool sim){
	if(sim)
		cout << "Encontrado!" << endl;
	else
		cout << "Nao encontrado..." << endl;
}

//programa principal
int main() {

    //variaveis locais
	int tamanho = 16;
    BB *a1 = new BB(tamanho);

	//adiciona os elementos ao vetor
	for(int i=0; i<tamanho; i++)
		a1->setVetor(i, ((i+1)*11)-1);

	//exibe o vetor
	a1->Imprime();
	cout << endl;

	//valores que existem na lista
	cout << "Elemento procurado = 120" << "\n" << endl;

	cout << "Busca sequencial... ";
	encontrado(a1->Sequencial(120));
	cout << "'Tempo de execucao':" << a1->vezesSequencial(120) << endl;

	cout << "Busca binaria... ";
	encontrado(a1->Binaria(120));
	cout << "'Tempo de execucao':" << a1->vezesBinaria(120) << "\n" << endl;

	//valores que nao existem na lista
	cout << "Elemento procurado = 15" << "\n" << endl;

	cout << "Busca sequencial... ";
	encontrado(a1->Sequencial(15));
	cout << "'Tempo de execucao':" << a1->vezesSequencial(15) << endl;

	cout << "Busca binaria... ";
	encontrado(a1->Binaria(15));
	cout << "'Tempo de execucao':" << a1->vezesBinaria(15) << "\n" << endl;

	//fim do programa
    delete(a1);
    return 0;
}