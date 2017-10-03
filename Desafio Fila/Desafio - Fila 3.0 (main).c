/*
Pedro Ivo Mariano de Oliveira Barros
ESTD - Curso de Férias
Sistemas de Informação - IFAL
DESAFIO - FILA
*/

#include <stdio.h>
#include <stdlib.h>
#include "filah.h"

main()
{
    int opcao=0, cont=0, chamaPreferencial = 1;
    topoFila *filaComum, *filaPref;

    filaComum = (topoFila *) malloc(sizeof(topoFila));
    filaPref = (topoFila *) malloc(sizeof(topoFila));

    if(filaComum == NULL || filaPref == NULL)
    {
        printf("\nErro de alocacao de memoria!");
        exit(1);
    }

    IniciaFila(filaComum);
    IniciaFila(filaPref);

    while(opcao == 0)
    {
        if(cont>0)
        {
            printf("\n");
        }

        printf("O QUE DESEJA FAZER?\n\n");
        printf("1 - Pegar Senha Comum\n");
        printf("2 - Pegar Senha Preferencial\n");
        printf("3 - Chamar Senha da Fila\n");
        printf("4 - Imprimir Fila Comum\n");
        printf("5 - Imprimir Fila Preferencial\n");
        printf("6 - SAIR\n\n");
        scanf("%d", &opcao);

        printf("\nOpcao selecionada: %d\n\n", opcao);

        if(opcao == 1)
        {
            NovaSenha(filaComum, opcao);
            opcao = 0;
        }
        else if(opcao == 2)
        {
            NovaSenha(filaPref, opcao);
            opcao = 0;
        }
        else if(opcao == 3)
        {
            if(chamaPreferencial == 1)
            {
                if(FilaVazia(filaPref))
                {
                    ChamaSenha(filaComum);
                    chamaPreferencial == 1;
                }
                else
                {
                    ChamaSenha(filaPref);
                    chamaPreferencial = 0;
                }
            }
            else
            {
                if(FilaVazia(filaComum))
                {
                    ChamaSenha(filaPref);
                    chamaPreferencial = 0;
                }
                else
                {
                    ChamaSenha(filaComum);
                    chamaPreferencial = 1;
                }
            }

            if(FilaVazia(filaComum) && FilaVazia(filaPref))
            {
                chamaPreferencial = 1;
            }

            opcao = 0;
        }
        else if(opcao == 4)
        {
            ImprimeFila(filaComum, opcao);
            opcao = 0;
        }
        else if(opcao == 5)
        {
            ImprimeFila(filaPref, opcao);
            opcao = 0;
        }
        else if(opcao == 6)
        {
            Libera(filaComum);
            Libera(filaPref);
        }
        else if(opcao < 1 || opcao > 6)
        {
            printf("-------------------------\n- OPCAO NAO IDENTIFICADA!\n-------------------------\n");
            opcao = 0;
        }

        cont++;
    }
}
