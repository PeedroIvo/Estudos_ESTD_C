/*
Pedro Ivo Mariano de Oliveira Barros
ESTD - Curso de F�rias
*/

#include <stdio.h>
#include <time.h>

typedef struct aposta
{
    char nomeJogador[100];
    int numero1;
    int numero2;
    int numero3;
} dadosAposta;

void sorteio(int *numero)
{
    *numero = 1+(rand() % 99);

    return;
}

main()
{
    dadosAposta aposta[5], *pAposta;
    int i, numSorteado1, numSorteado2, numSorteado3, numGanhadores=0, erroNaAposta, *pNumSorteado1, *pNumSorteado2, *pNumSorteado3;

    pAposta = &aposta;

    pNumSorteado1 = &numSorteado1;
    pNumSorteado2 = &numSorteado2;
    pNumSorteado3 = &numSorteado3;

    for(i=0; i<5; i++)
    {
        if(i>0)
        {
            getchar();
            printf("\n");
        }

        printf("Digite o nome do apostador %d:\n", i+1);
        gets(pAposta[i].nomeJogador);

        do{
        erroNaAposta = 0;

        printf("Digite os 3 numeros que o apostador %d deseja apostar, entre 1 e 99:\n", i+1);
        scanf("%d%d%d", &aposta[i].numero1, &aposta[i].numero2, &aposta[i].numero3);

        if((pAposta[i].numero1 == pAposta[i].numero2 || pAposta[i].numero1 == pAposta[i].numero3 || pAposta[i].numero2 == pAposta[i].numero3)&&(pAposta[i].numero1 > 99 || pAposta[i].numero2 > 99 || pAposta[i].numero3 > 99 || pAposta[i].numero1 < 1 || pAposta[i].numero2 < 1 || pAposta[i].numero3 < 1))
        {
            printf("\n- OS 3 NUMEROS DEVEM SER DIFERENTES E ESTAR ENTRE 1 E 99!\n- REPITA A OPERACAO!\n\n");
            erroNaAposta++;
        }
        else if(pAposta[i].numero1 == pAposta[i].numero2 || pAposta[i].numero1 == pAposta[i].numero3 || pAposta[i].numero2 == pAposta[i].numero3)
        {
            printf("\n- OS 3 NUMEROS DEVEM SER DIFERENTES!\n- REPITA A OPERACAO!\n\n");
            erroNaAposta++;
        }
        else if(pAposta[i].numero1 > 99 || pAposta[i].numero2 > 99 || pAposta[i].numero3 > 99 || pAposta[i].numero1 < 1 || pAposta[i].numero2 < 1 || pAposta[i].numero3 < 1)
        {
            printf("\n- OS 3 NUMEROS DEVEM ESTAR ENTRE 1 E 99!\n- REPITA A OPERACAO!\n\n");
            erroNaAposta++;
        }

        } while(erroNaAposta > 0);
    }

    srand((unsigned)time(NULL));

    sorteio(pNumSorteado1);

    do{
    sorteio(pNumSorteado2);
    }while(numSorteado2 == numSorteado1);

    do{
    sorteio(pNumSorteado3);
    }while(numSorteado3 == numSorteado1 || numSorteado3 == numSorteado2);

    printf("\nOs 3 numeros sorteados sao: %d %d %d\n", numSorteado1, numSorteado2, numSorteado3);

    for(i=0; i<5; i++)
    {
        if(numSorteado1 == pAposta[i].numero1 || numSorteado1 == pAposta[i].numero2 || numSorteado1 == pAposta[i].numero3)
        {
            if(numSorteado2 == pAposta[i].numero1 || numSorteado2 == pAposta[i].numero2 || numSorteado2 == pAposta[i].numero3)
            {
                if(numSorteado3 == pAposta[i].numero1 || numSorteado3 == pAposta[i].numero2 || numSorteado3 == pAposta[i].numero3)
                {
                    numGanhadores++;
                }
            }
        }
    }

    if(numGanhadores == 1)
    {
        printf("\nHOUVE UM VENCEDOR!!\n");
    }
    else if(numGanhadores > 1)
    {
        printf("\nHOUVE MAIS DE UM VENCEDOR!!\n");
    }
    else
    {
        printf("\nNAO HOUVE VENCEDOR E O PREMIO ACUMULOU!!\n");
    }
}
