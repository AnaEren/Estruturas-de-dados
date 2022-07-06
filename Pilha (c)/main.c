/*
Teste para o TAD - Pilha
Desenvolvedor: Ana Ellen D P Silva
Operações: 
1. Coloca uma quantidade aleatória de números aleatórios em uma pilha
2. Imprime os valores da pilha
3. Imprime o valor do topo da pilha
Data: 22/01/22
*/
#include "pilha.h"
//preencheAleatorio: coloca em uma pilha uma quantidade aleatoria de valores aleatorios
void preencheAleatorio(Pilha *p){
    //variaveis locais
    bool certo = true, cheiaP;
    int i = 0, valor;
    int aleat = rand()%11;//sorteio da quantia de elementos
    //verifica se a pilha ja esta cheia
    
    cheiaP = cheia(p);
    if(cheiaP){
        printf("A pilha já se encontra cheia.\n");
    }
    //adicionando valores sorteados à pilha
    while(i<5 && certo && cheiaP == false){
        valor = rand()%100;
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
    printf("%d valores adicionados.", i);
    
}
//imprime: imprime a pilha
void imprime(Pilha *p){
    //variaveis locais
    int i, v, topo;
    Pilha p2;
    bool certoD, certoE, certoD1, certoE2, vaziaP, vaziaP2;
    cria(&p2);
    //verifica se a pilha esta vazia
    if(vazia(p)){
        printf("A pilha se encontra vazia.\n");
    }
    else{
        printf("\nExibindo pilha:");
        certoD = true; certoE = true;
        //exibindo a pilha
        while(!vazia(p) && certoD && certoE){
            desempilha(&v, p, &certoD);
            printf(" %d", v);
            empilha(v, &p2, &certoE);
        }
        certoD = true; certoE = true;
        //reorganizando a ordem da pilha
        while(!vazia(&p2) && certoD && certoE){
            desempilha(&v, &p2, &certoD);
            empilha(v, p, &certoE);
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
    numeroTopo(&p1);
    //3
    imprime(&p1);
    return 0;
}

