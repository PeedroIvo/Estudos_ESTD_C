/*
Pedro Ivo Mariano de Oliveira Barros
ESTD - Curso de Férias
Sistemas de Informação - IFAL
DESAFIO - FILA
*/

#include <stdio.h>
#include <stdlib.h>

int senhaComum = 0, senhaPref = 0;
int qntSenhaC = 0, qntSenhaP = 0;

typedef struct No
{
    char tipo;
    int senha;
    struct no* prox;
} no;

typedef struct TopoFila
{
    no* ini;
    no* fim;
} topoFila;

void IniciaFila(topoFila *fila)
{
    fila->ini = NULL;
    fila->fim = NULL;
}

int FilaVazia(topoFila *fila)
{
    if(fila->ini == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void NovaSenha(topoFila *fila, int opcao)
{
    no *novo;
    novo = (no *) malloc(sizeof(no));

    if(novo == NULL)
    {
        printf("\nErro de alocacao de memoria!");
        exit(1);
    }
    novo->prox = NULL;

    if(opcao == 1)
    {
        novo->tipo = 'C';
        senhaComum++;
        novo->senha = senhaComum;

        printf("------------------------------\n- NOVA SENHA COMUM GERADA: %c%d\n------------------------------\n", novo->tipo, novo->senha);

        qntSenhaC++;
    }
    else if (opcao == 2)
    {
        novo->tipo = 'P';
        senhaPref++;
        novo->senha = senhaPref;

        printf("-------------------------------------\n- NOVA SENHA PREFERENCIAL GERADA: %c%d\n-------------------------------------\n", novo->tipo, novo->senha);

        qntSenhaP++;
    }

    if(FilaVazia(fila))
    {
        fila->ini = novo;
    }
    else
    {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
}

void ChamaSenha(topoFila *fila)
{
    if(FilaVazia(fila))
    {
        printf("--------------------\n- A FILA ESTA VAZIA!\n--------------------\n");
    }
    else
    {
        printf("--------------------\n- ATENCAO! SENHA %c%d\n--------------------\n", fila->ini->tipo, fila->ini->senha);

        if(fila->ini->tipo == 'C')
        {
            qntSenhaC--;
        }
        else if(fila->ini->tipo == 'P')
        {
            qntSenhaP--;
        }

        fila->ini = fila->ini->prox;
    }
}

void ImprimeFila(topoFila *fila, int opcao)
{
    no *tmp;
    tmp = fila->ini;

    if(FilaVazia(fila))
    {
        printf("--------------------\n- A FILA ESTA VAZIA!\n--------------------\n");
    }
    else
    {
        if(opcao == 4)
            {
                printf("------------------\n");
            }
        else if(opcao == 5)
            {
                printf("-------------------------\n", tmp->senha);
            }
        while(tmp != NULL)
        {
            if(opcao == 4)
            {
                printf("- Senha Comum: %c%d\n", tmp->tipo, tmp->senha);
            }
            else if(opcao == 5)
            {
                printf("- Senha Preferencial: %c%d\n", tmp->tipo, tmp->senha);
            }
            tmp = tmp->prox;
        }

        if(opcao == 4)
        {
            printf("------------------\n\nQuantidade de senhas na fila comum: %d\n", qntSenhaC);
        }
        else if(opcao == 5)
        {
            printf("-------------------------\n\nQuantidade de senhas na fila preferencial: %d\n", qntSenhaP);
        }
    }
}

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
        else if(opcao < 1 || opcao > 6)
        {
            printf("-------------------------\n- OPCAO NAO IDENTIFICADA!\n-------------------------\n");
            opcao = 0;
        }

        cont++;
    }
}
