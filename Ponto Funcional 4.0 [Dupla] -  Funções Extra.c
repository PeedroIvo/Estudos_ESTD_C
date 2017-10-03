/*
Pedro Ivo Mariano de Oliveira Barros
ESTD - Curso de Férias
Sistemas de Informação - IFAL
Lista Duplamente Encadeada com funções de Busca, Inserção no Início, Inserção no Meio, Deletar no Início e Deletar no Fim
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
    struct PontoFuncional *ant;
    struct PontoFuncional *prox;
} ponto;

int qntPontos = 0;

void IniciaLista(ponto *lista)
{
    lista->ant = NULL;
    lista->prox = NULL;
}

int ListaVazia(ponto *lista)
{
    if(lista->prox == NULL && lista->ant == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PontoNoFIM(ponto *lista, ponto *novo)
{
    ponto *tmp;

    if(ListaVazia(lista))
    {
        lista->prox = novo;
        novo->ant = lista;
    }
    else
    {
        tmp = lista->prox;
        while(tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
        novo->ant = tmp;
    }
}

void PontoNoINICIO(ponto *lista, ponto *novo)
{
    if(ListaVazia(lista))
    {
        lista->prox = novo;
        novo->ant = lista;
    }
    else
    {
        novo->prox = lista->prox;
        novo->ant = lista;
        lista->prox->ant = novo;
        lista->prox = novo;
    }
}

void PontoNoMEIO(ponto *lista, ponto *novo)
{
    int posicao;

    printf("\nInforme a posicao da lista que deseja inserir o ponto (Maximo = %d): ", qntPontos+1);
    scanf("%d", &posicao);

    if (posicao < 1 || posicao > qntPontos+1)
    {
        printf("\nNao e possivel inserir nesta posicao!\n");
    }
    else if(posicao == 1)
    {
        PontoNoINICIO(lista, novo);
    }
    else if (posicao == qntPontos+1)
    {
        PontoNoFIM(lista, novo);
    }
    else
    {
        ponto *tmp;
        tmp = lista->prox;
        int i = 1;

        while(tmp->prox != NULL)
        {
            if(i == posicao)
            {
                novo->prox = tmp;
                novo->ant = tmp->ant;
                tmp->ant->prox = novo;
                tmp->ant = novo;
                break;
            }
            else
            {
                tmp = tmp->prox;
                i++;
            }
        }
        if(tmp->prox == NULL)
        {
            if(i == posicao)
            {
                novo->prox = tmp;
                novo->ant = tmp->ant;
                tmp->ant->prox = novo;
                tmp->ant = novo;
            }
        }
    }
}

void InserePonto(ponto *lista, int opcao)
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

    if(opcao == 1) //Inserir no FIM
    {
        PontoNoFIM(lista, novo);
    }
    else if(opcao == 2) //Inserir no INICIO
    {
        PontoNoINICIO(lista, novo);
    }
    else if(opcao == 3) //Inserir no MEIO
    {
        PontoNoMEIO(lista, novo);
    }

    qntPontos++;
}

void DeletaPonto(ponto *lista, int chave)
{
    ponto *tmp;
    tmp = lista->prox;
    if(ListaVazia(lista))
    {
        printf("\nA lista esta vazia!\n");
    }
    else
    {
        while(tmp->prox != NULL)
        {
            if(tmp->matricula == chave)
            {
                tmp->ant->prox = tmp->prox;
                tmp->prox->ant = tmp->ant;
                free(tmp);
                printf("\nDeletado com sucesso!\n");
                break;
            }
            else
            {
                tmp = tmp->prox;
            }
        }
        if(tmp->prox == NULL)
        {
            if(tmp->matricula==chave)
            {
                tmp->ant->prox = NULL;
                free(tmp);
                printf("\nDeletado com sucesso!\n");
            }
            else
            {
                printf("\nPonto nao encotrado!\n");
            }
        }

        qntPontos--;
    }
}

void DeletaFIM(ponto *lista)
{
    ponto *tmp;
    tmp = lista->prox;
    if(ListaVazia(lista))
    {
        printf("A lista esta vazia!\n");
    }
    else
    {
        while(tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        if(tmp->prox == NULL)
        {
            tmp->ant->prox = NULL;
            free(tmp);
            printf("Deletado com sucesso!\n");
        }

        qntPontos--;
    }
}

void DeletaINICIO(ponto *lista)
{
    if(ListaVazia(lista))
    {
        printf("A lista esta vazia!\n");
    }
    else
    {
        lista->prox = lista->prox->prox;
        lista->prox->ant = lista;
        printf("Deletado com sucesso!\n");

        qntPontos--;
    }
}

void ImprimeLista(ponto *lista)
{
    ponto *tmp;
    tmp = lista->prox;
    int i=1;
    if(ListaVazia(lista))
    {
        printf("A lista esta vazia!\n");
    }
    else
    {
        while(tmp != NULL)
        {
            printf("Ponto %d\nNome do Funcionario: %s\nMatricula: %d\nData de Entrada: %s\nHora de Entrada: %s\nHora de Saida: %s\n\n", i, tmp->nome, tmp->matricula, tmp->dataEntrada, tmp->horaEntrada, tmp->horaSaida);
            i++;
            tmp = tmp->prox;
        }

        printf("Quantidade de pontos da lista: %d\n", qntPontos);
    }
}

void BuscaPonto(ponto *lista, int chave)
{
    ponto *tmp;
    tmp = lista->prox;
    if(ListaVazia(lista))
    {
        printf("\nA lista esta vazia!\n");
    }
    else
    {
        while(tmp->prox != NULL)
        {
            if(tmp->matricula == chave)
            {
                printf("Ponto Encontrado!\n\nNome do Funcionario: %s\nMatricula: %d\nData de Entrada: %s\nHora de Entrada: %s\nHora de Saida: %s\n", tmp->nome, tmp->matricula, tmp->dataEntrada, tmp->horaEntrada, tmp->horaSaida);
                break;
            }
            else
            {
                tmp = tmp->prox;
            }
        }
        if(tmp->prox == NULL)
        {
            if(tmp->matricula==chave)
            {
                printf("\nPonto Encontrado!\n\nNome do Funcionario: %s\nMatricula: %d\nData de Entrada: %s\nHora de Entrada: %s\nHora de Saida: %s\n", tmp->nome, tmp->matricula, tmp->dataEntrada, tmp->horaEntrada, tmp->horaSaida);
            }
            else
            {
                printf("\nPonto nao encotrado!\n");
            }
        }
    }
}

main()
{
    int chave=0, opcao=0, cont=0;
    ponto  *lista;
    lista = (ponto *) malloc(sizeof(ponto));

    if(lista == NULL)
    {
        printf("\nErro de alocacao de memoria!");
        exit(1);
    }

    IniciaLista(lista);

    while(opcao == 0)
    {
        if(cont>0)
        {
            printf("\n");
        }

        printf("O QUE DESEJA FAZER?\n\n");
        printf("1 - Inserir um ponto no FIM da lista\n");
        printf("2 - Inserir um ponto no INICIO da lista\n");
        printf("3 - Inserir um ponto no MEIO da lista\n");
        printf("4 - Deletar um ponto da lista\n");
        printf("5 - Deletar o ULTIMO ponto da lista\n");
        printf("6 - Deletar o PRIMEIRO ponto da lista\n");
        printf("7 - Buscar um ponto na lista\n");
        printf("8 - Imprimir a lista de ponto\n");
        printf("9 - SAIR\n\n");
        scanf("%d", &opcao);

        printf("\nOpcao selecionada: %d\n\n", opcao);

        if(opcao == 1)
        {
            InserePonto(lista, opcao);
            opcao = 0;
        }
        else if(opcao == 2)
        {
            InserePonto(lista, opcao);
            opcao = 0;
        }
        else if(opcao == 3)
        {
            InserePonto(lista, opcao);
            opcao = 0;
        }
        else if(opcao == 4)
        {
            printf("Informe a matricula do funcionario que deseja deletar: ");
            scanf("%d", &chave);
            DeletaPonto(lista, chave);
            opcao = 0;
        }
        else if(opcao == 5)
        {
            DeletaFIM(lista);
            opcao = 0;
        }
        else if(opcao == 6)
        {
            DeletaINICIO(lista);
            opcao = 0;
        }
        else if(opcao == 7)
        {
            printf("Informe a matricula do funcionario que deseja buscar: ");
            scanf("%d", &chave);
            BuscaPonto(lista, chave);
            opcao = 0;
        }
        else if(opcao == 8)
        {
            ImprimeLista(lista);
            opcao = 0;
        }
        else if(opcao < 1 || opcao > 9)
        {
            printf("Opcao nao identificada!\n");
            opcao = 0;
        }

        cont++;
    }
}
