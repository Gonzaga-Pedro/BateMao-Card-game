#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projetoFinal.c"

int main()
{
    srand(time(NULL));

    int vez =1;
    int contador = 1;
    int i, j;
    int pos = 0;
    int aux;

    //laço que cria pilha do baralho ordenadamente
    for(j=0; j<4; j++){
        for(i=1; i<14; i++){
            criaBaralho(i, vetorNaipes[j]);
        }
    }
    embaralhaBaralho(pos, listaAux1, listaAux2);
    distribuirBaralho();

    //laço que define o andamento do jogo
    while((J1!=NULL)&&(J2!=NULL)&&(J3!=NULL)&&(J4!=NULL)){
        if(vez==1){
            aux = 1;
            printf("Jogador 1 = ");
            imprimirBaralho(J1);
            colocaMesa(J1);
            removeJ1();
            printf("\nmesa(%d) = ", contador);
            imprimirBaralho(mesa);

            if(mesa->numero == contador){
                while(mesa!=NULL){
                    movePilha(aux);
                }

                printf("\nJogador 1 = ");
                imprimirBaralho(J1);
                printf("\nmesa(%d) = ", contador);
                imprimirBaralho(mesa);
                contador = 0;
            }
            vez = 2;

        }else if(vez == 2){
            aux = 2;
            printf("jogador 2 = ");
            imprimirBaralho(J2);
            colocaMesa(J2);
            removeJ2();
            printf("\nmesa(%d) = ", contador);
            imprimirBaralho(mesa);

            if(mesa->numero == contador){
                while(mesa!=NULL){
                    movePilha(aux);
                }

                printf("\njogador 2 = ");
                imprimirBaralho(J2);
                printf("\nmesa(%d) = ", contador);
                imprimirBaralho(mesa);
                contador = 0;
            }
            vez = 3;

        }else if(vez == 3){
            aux = 3;
            printf("jogador 3 = ");
            imprimirBaralho(J3);
            colocaMesa(J3);
            removeJ3();
            printf("\nmesa(%d) = ", contador);
            imprimirBaralho(mesa);

            if(mesa->numero == contador){
                while(mesa!=NULL){
                    movePilha(aux);
                }

                printf("\njogador 3 = ");
                imprimirBaralho(J3);
                printf("\nmesa(%d) = ", contador);
                imprimirBaralho(mesa);
                contador = 0;
            }
            vez = 4;

        }else{
            aux = 4;
            printf("jogador 4 = ");
            imprimirBaralho(J4);
            colocaMesa(J4);
            removeJ4();
            printf("\nmesa(%d) = ", contador);
            imprimirBaralho(mesa);

            if(mesa->numero == contador){
                while(mesa!=NULL){
                    movePilha(aux);
                }

                printf("\njogador 4 = ");
                imprimirBaralho(J4);
                printf("\nmesa(%d) = ", contador);
                imprimirBaralho(mesa);
                contador = 0;
            }
            vez = 1;

        }
        contador++;
        if(contador > 13){
            contador=1;
        }
        printf("\npressione enter!\n");
        getchar();
    }

    if(J1==NULL){
        printf("Jogador1 venceu");
    }else if(J2==NULL){
        printf("Jogador2 venceu");
    }else if(J3==NULL){
        printf("Jogador3 venceu");
    }else if(J4==NULL){
        printf("Jogador4 venceu");
    }

    return 0;
}
