/*
Teste para o TAD - Pilha
Desenvolvedor: Ana Ellen D P Silva
Operações:
1. Coloca uma quantidade aleatória de números aleatórios em uma pilha
2. Imprime os valores da pilha
3. Imprime o valor do topo da pilha
Data: 22/01/22
*/
#include "pilhas.h"
//preencheAleatorio: coloca em uma pilha uma quantidade aleatoria de valores aleatorios
void preencheAleatorio(Pilha *p){
    //variaveis locais
    bool certo = true, cheiaP;
    int i=0, valor;
    int aleat = rand()%100;//sorteio da quantia de elementos
    //verifica se a pilha ja esta cheia
    cheiaP = cheia(p);
    if(cheiaP){
        printf("A pilha já se encontra cheia.\n");
    }
    //adicionando valores sorteados à pilha
    while(i<aleat && certo && cheiaP == false){
        valor = rand()%10;
        empilha(valor, p, &certo);
        if(certo==false){
            printf("Operação falhou, %d valores adicionados.\n", i);
        }
        i++;
        cheiaP = cheia(p);
        if(cheiaP){
            printf("Pilha cheia. %d valores adicionados.\n", i);
        }
    }
}
//imprime: imprime a pilha
void imprime(Pilha *p){
    //variaveis locais
    int i, v, topo;
    Pilha p2;
    bool certoD = true, certoE = true, vaziaP, vaziaP2 = false;
    cria(&p2);
    i=0;
    //verifica se a pilha esta vazia
    vaziaP = vazia(p);
    if(vaziaP){
        printf("A pilha se encontra vazia.\n");
    }
    else{
        //reorganizando a ordem da pilha
        while(vaziaP2==false && certoD && certoE){
            desempilha(&v, p, &certoD);
            empilha(v, &p2, &certoE);
            vaziaP2 = vazia(p);
            i++;
        }
        i=0; vaziaP2 = false;
        //exibindo a pilha
        while(vaziaP2==false && certoD && certoE){
            desempilha(&v, &p2, &certoD);
            printf("%d ", v);
            empilha(v, p, &certoE);
            vaziaP2 = vazia(p);
            i++;
        }
    }
}
//numeroTopo: exibe o numero que está no topo da pilha
void numeroTopo(Pilha *p){
    //variaveis locais
    bool certoD, certoE;
    int v;
    desempilha(&v, p, &certoD);
    printf("\nElemento do topo: %d ", v);
    empilha(v, p, &certoE);
}
int main(){
    //variaveis locais
    bool ok, certo = true;
    int i, valor, t;
    Pilha p1;
    //cria a pilha a ser usada
    cria(&p1);
    //funcoes com a pilha:
    //1
    preencheAleatorio(&p1);
    //2
    imprime(&p1);
    //3
    numeroTopo(&p1);
    return 0;
}
