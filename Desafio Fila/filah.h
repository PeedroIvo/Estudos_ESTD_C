#ifndef FILAH_H_INCLUDED
#define FILAH_H_INCLUDED

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

        no *tmp;
        tmp = fila->ini;
        fila->ini = fila->ini->prox;
        free(tmp);
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

void Libera (topoFila *fila)
{
    no *tmp1, *tmp2;
    tmp1 = fila->ini;

    while (tmp1 != NULL)
    {
        tmp2 = tmp1->prox;
        free(tmp1);
        tmp1 = tmp2;
    }

    free(fila);
}

#endif // FILAH_H_INCLUDED
