/*
Teste para o TAD - Lista
Desenvolvedor: Ana Ellen D P Silva
Operações: 
Adiciona: insere elementos aleatorios na fila
Quantia: calcula a quantia de elementos da fila
Exibe: exibe os elementos da fila
Data: 26/01/22
*/
#include "filas.h"
#include <stdbool.h>
//insere elementos aleatorios na fila
void adiciona (Fila * f){
    //variaveis locais
    int i=0, x;
    bool deuCerto = 1;
    //adiciona elementos para a fila
    while(i<(15) && deuCerto){
        x = rand()%1000;
        insere(f, x, &deuCerto);
        i++;
    }
}
//quantos termos tem na fila
int quantia(Fila *f){
    //variaveis locais
    Fila aux;
    int x, qnt=0;
    bool deuCertor=1, deuCertoi=1, vazia1;
    //cria a fila auxiliar
    cria(&aux);
    //se a fila principal estiver cheia ou vazia, retorna imediatamente
    if(vazia(f)){ return 0;}
    else if(cheia(f)){ return 20;}
    //se nao, calcula o tamanho da fila
    else{
        //retira da fila principal e coloca em uma secundária
        while(vazia(f) == false && deuCertor && deuCertoi){
            retira(f, &x, &deuCertor);
            qnt++;//conta quantas vezes isso ocorreu ate a primeira estar vazia
            insere(&aux, x, &deuCertoi);
            vazia1 = vazia(f);
        }
        //reicere os elementos da fila principal
        while(vazia(&aux) == false && deuCertor && deuCertoi){
            retira(&aux, &x, &deuCertor);
            insere(f, x, &deuCertoi);
        }
    //retorna a quantia de elementos da fila
    return qnt;
    }
}
//exibe a lista
void exibe(Fila *f, int i){
    //variaveis locais
    int x, j = 0;
    bool deuCertor=1, deuCertoi=1;

    printf("\n Fila:");
    //retira e reincere os elementos da fila, exibindo-os no processo
    while(j<i && deuCertoi && deuCertor){
        retira(f, &x, &deuCertor);
        printf(" %d", x);
        insere(f, x, &deuCertoi);
        j++;
    }
    printf("\n");
}
int main(){
    //variaveis
    Fila f1;
    int i=0, x, qnt;
    //cria a fila
    cria(&f1);
    //adiciona elementos para a fila
    adiciona(&f1);
    //funçao calcula o tamanho da fila
    qnt = quantia(&f1);
    //exibe a quantia
    printf("\n Quantia: %d", qnt);
    //exibe os elementos da fila
    exibe(&f1, qnt);

    return 0;
}