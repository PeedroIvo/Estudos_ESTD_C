/*
Pedro Ivo Mariano de Oliveira Barros
ESTD - Curso de F�rias
Sistemas de Informa��o - IFAL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct PontoFuncional
{
    char nome[30];
    int  matricula;
    char dataEntrada[11];
    char horaEntrada[6];
    char horaSaida[6];
    struct PontoFuncional *prox;
} ponto;

int qntElementos= 0;

void IniciaLista(ponto *lista)
{
    lista->prox = NULL;
}

int ListaVazia(ponto *lista)
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

void InsereElemento(ponto *lista)
{
    int contEntrada=0, contSaida=0;
    ponto *tmp, *novo;
    novo = (ponto *) malloc(sizeof(ponto));

    if(novo == NULL)
    {
        printf("\nErro de alocacao de memoria!");
        exit(1);
    }
    novo->prox = NULL;

    printf("Nome do Funcionario: ");
    getchar();
    gets(novo->nome);

    printf("Matricula: ");
    scanf("%d", &novo->matricula);

    printf("Data de Entrada (dd/mm/aaaa): ");
    getchar();
    gets(novo->dataEntrada);

    do
    {
        if(contEntrada == 0)
        {
            printf("Hora de Entrada (hh:mm): ");
        }
        else
        {
            printf("Este campo nao pode ficar vazio! Insira a hora de entrada (hh:mm): ");
        }
        gets(novo->horaEntrada);
        contEntrada++;
    }
    while(novo->horaEntrada[0] == '\0');

    do
    {
        if(contSaida == 0)
        {
            printf("Hora de Saida (hh:mm): ");
        }
        else
        {
            printf("Este campo nao pode ficar vazio! Insira a hora de saida (hh:mm): ");
        }
        gets(novo->horaSaida);
        contSaida++;
    }
    while(novo->horaSaida[0] == '\0');

    if(ListaVazia(lista))
    {
        lista->prox = novo;
    }
    else
    {
        tmp = lista->prox;
        while(tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }

    qntElementos++;
}

void DeletaElemento(ponto *lista,int chave)
{
    ponto *tmp, *anterior;
    anterior = lista;
    tmp = lista->prox;
    while(tmp->prox != NULL)
    {
        if(tmp->matricula==chave)
        {
            anterior->prox=tmp->prox;
            free(tmp);
            break;
        }
        else
        {
            anterior = tmp;
            tmp=tmp->prox;
        }
    }
    if(tmp->prox==NULL)
    {
        if(tmp->matricula==chave)
        {
            anterior->prox=tmp->prox;
            free(tmp);
        }
    }

    qntElementos--;
}

void ImprimeLista(ponto *lista)
{
    ponto *tmp;
    tmp = lista->prox;
    int i=1;
    if(ListaVazia(lista))
        printf("\nLista Vazia!\n");
    else
    {
        while(tmp != NULL)
        {
            printf("\nRegistro %d\nNome do Funcionario: %s\nMatricula: %d\nData de Entrada: %s\nHora de Entrada: %s\nHora de Saida: %s\n", i, tmp->nome, tmp->matricula, tmp->dataEntrada, tmp->horaEntrada, tmp->horaSaida);
            i++;
            tmp = tmp->prox;
        }

        printf("\nQuantidade de registros da lista: %d\n", qntElementos);
    }
}

void libera (ponto* lista)
{
    ponto* tmp;
    tmp = lista;
    while (tmp != NULL)
    {
        ponto* t = tmp->prox;
        free(tmp);
        tmp = t;
    }
}

int main(void)
{
    int chave=0, desejo=0, cont=0;
    ponto  *lista;
    lista = (ponto *) malloc(sizeof(ponto));

    if(lista == NULL )
    {
        printf("\nErro de alocacao de memoria!");
        exit(1);
    }

    IniciaLista(lista);

    while(desejo==0)
    {
        if(cont>0)
        {
            printf("\n");
        }

        printf("O que deseja fazer?\n");
        printf("1 - Inserir Registro de Ponto\n");
        printf("2 - Deletar Registro de Ponto\n");
        printf("3 - Imprimir Lista dos Registros\n");
        printf("4 - Sair\n\n");
        scanf("%d", &desejo);

        if(desejo==1)
        {
            InsereElemento(lista);
            desejo=0;
        }
        else if(desejo==2)
        {
            printf("Informe a matricula do funcionario que deseja deletar dos registros: ");
            scanf("%d", &chave);
            DeletaElemento(lista,chave);
            desejo=0;
        }
        else if(desejo==3)
        {
            ImprimeLista(lista);
            desejo=0;
        }

        cont++;
    }

    return 0;
}
