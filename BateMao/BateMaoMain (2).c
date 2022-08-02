#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 52

//Struct Carta
typedef struct stCarta{ //Struct Carta
    int naipe;
    int numero;
    struct stCarta * proximo;
}tCarta;

//declaração de variaveis de tamanho
int vetorNaipes[] = {3, 4, 5, 6};
int totalBaralho = 0;
int total = 0;
//variaveis de listas auxiliares para embaralhamento
int listaAux1[MAX];
int listaAux2[MAX];
//declaração das Pilhas
tCarta * baralho = NULL;
tCarta * mesa = NULL;
tCarta * J1 = NULL;
tCarta * J2 = NULL;
tCarta * J3 = NULL;
tCarta * J4 = NULL;

//cria pilha do baralho inicial
void criaBaralho(int num, int NP){
    tCarta* novo=(tCarta*)malloc(sizeof(tCarta));
    //pilha-struct recebendo valores passados como parametro
    novo->numero=num;
    novo->naipe=NP;
    novo->proximo=baralho;
    baralho=novo;
    totalBaralho++;
}

//Impressao de pilha recebida como parametro
void imprimirBaralho(tCarta* pilha){
  tCarta* atual = pilha;

  while(atual!=NULL){
    if(atual->numero == 11){
        if(atual->naipe == 3){
            printf("[J/Copas]");
        }
        if(atual->naipe == 4){
            printf("[J/Ouro] ");
        }
        if(atual->naipe == 5){
            printf("[J/Paus]");
        }
        if(atual->naipe == 6){
            printf("[J/Espadas] ");
        }
    }else if(atual->numero == 12){
        if(atual->naipe == 3){
            printf("[Q/Copas]");
        }
        if(atual->naipe == 4){
            printf("[Q/Ouro] ");
        }
        if(atual->naipe == 5){
            printf("[Q/Paus]");
        }
        if(atual->naipe == 6){
            printf("[Q/Espadas] ");
        }
    }else if(atual->numero == 13){
        if(atual->naipe == 3){
            printf("[K/Copas]");
        }
        if(atual->naipe == 4){
            printf("[K/Ouro] ");
        }
        if(atual->naipe == 5){
            printf("[K/Paus]");
        }
        if(atual->naipe == 6){
            printf("[K/Espadas] ");
        }
    }else if(atual->numero == 1){
        if(atual->naipe == 3){
            printf("[A/Copas]");
        }
        if(atual->naipe == 4){
            printf("[A/Ouro] ");
        }
        if(atual->naipe == 5){
            printf("[A/Paus]");
        }
        if(atual->naipe == 6){
            printf("[A/Espadas] ");
        }
    }else{
        if(atual->naipe == 3){
            printf("[%d/Copas]", atual->numero);
        }
        if(atual->naipe == 4){
            printf("[%d/Ouro] ", atual->numero);
        }
        if(atual->naipe == 5){
            printf("[%d/Paus]", atual->numero);
        }
        if(atual->naipe == 6){
            printf("[%d/Espadas]", atual->numero);

        }
    }
    atual=atual->proximo;
  }
}

//Divide pilha do baralho inicial em duas listas auxiliares. Uma recebe os numeros e a outra os naipes
//posicao na lista passada como parametro
//Motivo: Embaralhamento
void transfereLista(int indice){
    tCarta* atual=baralho;

    if(baralho!=NULL){
        baralho=atual->proximo;
        listaAux1[indice] = atual->numero;
        listaAux2[indice] = atual->naipe;
        free(atual);
        totalBaralho--;
    }
}

//Transfere os valores das duas listas de volta para pilha, porem agora com valores embaralhados
//No caso as duas listas feitas previamente sao passadas como parametro
void transferePilha(int lista1[MAX], int lista2[MAX]){
    tCarta* novo=(tCarta*)malloc(sizeof(tCarta));

    int sorteio;
    sorteio = rand()%MAX; //sorteia uma posicao entre 0 e 51

    //para nao repetir valores foi usado progressao linear nas listas
    //se os valores da lista forem iguais a -1 percorre linearmente ate um encontrar um valor
    while((lista1[sorteio] == -1) && (lista2[sorteio] == -1)){
        sorteio++;
        if(sorteio == MAX){
            sorteio = 0;
        }
    }

    novo->numero=lista1[sorteio];
    novo->naipe=lista2[sorteio];
    novo->proximo=baralho;
    baralho=novo;
    //"remove" valor da lista, o qual foi passado para a pilha
    lista1[sorteio] = -1;
    lista2[sorteio] = -1;
    totalBaralho++;
}

//funcao que agrega duas funcoes necessarias para embaralhar
void embaralhaBaralho(int indice, int list[MAX], int list2[MAX]){
    for(indice = 0; indice<MAX; indice++){
        transfereLista(indice);
    }
    for(indice = 0; indice<MAX; indice++){
        transferePilha(list, list2);
    }
}

//distribui as cartas da pilha(Baralho) para as novas pilhas(uma de cada jogador)
//distribui as cartas alternadamente entre os jogadores 1-4 com uma variavel auxiliar de controle
void distribuirBaralho(){
    int aux = 1;
    for(int i = 0; i < MAX; i++){
        tCarta* novo=(tCarta*)malloc(sizeof(tCarta));
        tCarta* atual=baralho;

        if(aux == 1){
            novo->numero= atual->numero;
            novo->naipe= atual->naipe;
            novo->proximo=J1;
            J1=novo;
        }else if(aux == 2) {
            novo->numero= atual->numero;
            novo->naipe= atual->naipe;
            novo->proximo=J2;
            J2=novo;
        }else if(aux == 3){
            novo->numero= atual->numero;
            novo->naipe= atual->naipe;
            novo->proximo=J3;
            J3=novo;
        }else{
            novo->numero= atual->numero;
            novo->naipe= atual->naipe;
            novo->proximo=J4;
            J4=novo;
            aux = 0;
        }
        baralho=atual->proximo;
        free(atual);
        totalBaralho--;
        aux++;
    }
}

//funcao que coloca na pilha da mesa a carta no topo da pilha de um jogador passado como parametro
void colocaMesa(tCarta* jogador){
    tCarta* novo=(tCarta*)malloc(sizeof(tCarta));
    tCarta* atual=jogador;

    novo->numero= atual->numero;
    novo->naipe= atual->naipe;
    novo->proximo=mesa;
    mesa=novo;
}

//funcoes que removem carta do topo de cada jogador
void removeJ1(){
    tCarta* atual=J1;

    if(J1!=NULL){
        J1=atual->proximo;
        free(atual);
    }
}

void removeJ2(){
    tCarta* atual=J2;

    if(J2!=NULL){
        J2=atual->proximo;
        free(atual);
    }
}

void removeJ3(){
    tCarta* atual=J3;

    if(J3!=NULL){
        J3=atual->proximo;
        free(atual);
    }
}

void removeJ4(){
    tCarta* atual=J4;

    if(J4!=NULL){
        J4=atual->proximo;
        free(atual);
    }
}

//Funcao que move a pilha da mesa para um jogador qualquer
//recebe como parametro uma variavel auxiliar para definir qual jogador recebe a pilha da mesa
void movePilha(int auxiliar){
    tCarta* novo=(tCarta*)malloc(sizeof(tCarta));
    tCarta* atual=mesa;

    if(auxiliar == 1){
        novo->numero= atual->numero;
        novo->naipe= atual->naipe;
        novo->proximo=J1;
        J1=novo;
    }else if(auxiliar == 2){
        novo->numero= atual->numero;
        novo->naipe= atual->naipe;
        novo->proximo=J2;
        J2=novo;
    }else if(auxiliar == 3){
        novo->numero= atual->numero;
        novo->naipe= atual->naipe;
        novo->proximo=J3;
        J3=novo;
    }else{
        novo->numero= atual->numero;
        novo->naipe= atual->naipe;
        novo->proximo=J4;
        J4=novo;
    }

    mesa=atual->proximo;
    free(atual);
}
