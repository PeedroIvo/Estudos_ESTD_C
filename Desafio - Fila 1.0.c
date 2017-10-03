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

typedef struct TipoFila
{
    no* ini;
    no* fim;
} tipoFila;

void IniciaLista(no *lista)
{
    lista->prox = NULL;
}

int ListaVazia(no *lista)
{
    if(lista->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void NovaSenha(no *lista, tipoFila *fila, int opcao)
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

        printf("------------------------\n- SUA SENHA COMUM E: %c%d\n------------------------\n", novo->tipo, senhaComum);

        qntSenhaC++;
    }
    else if (opcao == 2)
    {
        novo->tipo = 'P';
        senhaPref++;
        novo->senha = senhaPref;

        printf("-------------------------------\n- SUA SENHA PREFERENCIAL E: %c%d\n-------------------------------\n", novo->tipo, senhaPref);

        qntSenhaP++;
    }

    if(ListaVazia(lista))
    {
        lista->prox = novo;
        fila->ini = novo;
    }
    else
    {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
}

void ChamaSenha(no *lista, tipoFila *fila)
{
    if(ListaVazia(lista))
    {
        printf("--------------------\n- A FILA ESTA VAZIA!\n--------------------\n");
    }
    else
    {
        printf("--------------------\n- ATENCAO! SENHA %c%d\n--------------------\n", fila->ini->tipo, fila->ini->senha);

        lista->prox = fila->ini->prox;
        fila->ini = lista->prox;
    }
}

void ImprimeFila(no *lista, int opcao)
{
    no *tmp;
    tmp = lista->prox;

    if(ListaVazia(lista))
    {
        printf("A Fila esta vazia!\n");
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
    no  *filaComum, *filaPref;
    tipoFila *inicioFimComum, *inicioFimPref;

    filaComum = (no *) malloc(sizeof(no));
    filaPref = (no *) malloc(sizeof(no));

    inicioFimComum = (tipoFila *) malloc(sizeof(tipoFila));
    inicioFimPref = (tipoFila *) malloc(sizeof(tipoFila));

    if(filaComum == NULL || filaPref == NULL)
    {
        printf("\nErro de alocacao de memoria!");
        exit(1);
    }

    IniciaLista(filaComum);
    IniciaLista(filaPref);

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
            NovaSenha(filaComum, inicioFimComum, opcao);
            opcao = 0;
        }
        else if(opcao == 2)
        {
            NovaSenha(filaPref, inicioFimPref, opcao);
            opcao = 0;
        }
        else if(opcao == 3)
        {
            if(chamaPreferencial == 1)
            {
                if(ListaVazia(filaPref))
                {
                    ChamaSenha(filaComum, inicioFimComum);
                    chamaPreferencial == 1;
                }
                else
                {
                    ChamaSenha(filaPref, inicioFimPref);
                    chamaPreferencial = 0;
                }
            }
            else
            {
                if(ListaVazia(filaComum))
                {
                    ChamaSenha(filaPref, inicioFimPref);
                    chamaPreferencial = 0;
                }
                else
                {
                    ChamaSenha(filaComum, inicioFimComum);
                    chamaPreferencial = 1;
                }
            }

            if(ListaVazia(filaComum) && ListaVazia(filaPref))
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
            printf("Opcao nao identificada!\n");
            opcao = 0;
        }

        cont++;
    }
}
