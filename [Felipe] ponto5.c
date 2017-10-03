/// Programa de ponto de funcionarios
/// Participantes: Felipe Cavalcanti de Carvalho, Nélio Carneval e João Fernando.
/// Questão:Implemente um registro de Ponto Funcional, armazenando na lista nome,matricula, data,hora de entrada e hora de saida
///o programa deve dar as seguintes opções ao usuario:
///     Imprimir a Lista de Ponto;
///     Inserir um Ponto;
///     Deletar um ponto;
///     Deve ainda bloquear a entrada de uma hora de entrada e saída vazia.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ponto{
char nome[40];
int matricula;
char hrEntrada[6],hrSaida[6];
char data [11];
struct Ponto *ant;
struct Ponto *prox;
}ponto;


int qnt=0;

void iniciaponto( ponto *lista)
{
   lista->ant=NULL;
   lista->prox=NULL;
}
int verificaponto( ponto *lista)
{
if(lista->prox == NULL && lista->ant == NULL)
		return 1;
	else
		return 0;

}
  void copia(ponto *lista,ponto *lista2)
  {
      lista2=lista;
  }




    int buscaponto(ponto *lista,int key)
{
	ponto *tmp;
		if(lista->matricula==key)
        {
            return 1;

        }

		tmp=lista->prox;
		while(tmp->prox != NULL)
        {

            if(tmp->matricula==key){
               return 1;
                break;
            }
            else{
              tmp=tmp->prox;
            }
        }
        if(tmp->prox==NULL)
        {
            if(tmp->matricula==key){
                return 1;

            }
        }

	else
		return 0;

}
void ordenaCres(ponto *lista)
{
    ponto *tmp;
    tmp=lista->prox;
    while(tmp->prox!=NULL)
        {
            if(tmp->prox->matricula<tmp->matricula)
                {
                    trocaposicao(lista);
                }
            tmp=tmp->prox;
        }
}

void ordenaDecres(ponto *lista)
{
    ponto *tmp;
    tmp=lista->prox;
    while(tmp->prox!=NULL)
        {
            if(tmp->prox->matricula>tmp->matricula)
                {
                    trocaposicao(lista);
                }
            tmp=tmp->prox;
        }
}

void inserircomeco(ponto *lista)
{
ponto *novo;
novo=(ponto *) malloc(sizeof( ponto));

    if(verificaponto(lista)==1)
    {
        novo->ant=lista;
        novo->prox=NULL;
        lista->prox=novo;
    }
    novo->ant=lista;
    lista->prox->ant=novo;
    novo->prox=lista->prox;
    lista->prox=novo;
}


void inserirponto( ponto *lista)
{
	ponto *novo,*tmp;
	novo=(ponto *) malloc(sizeof( ponto));
    char vazio[6]="";
	if( novo == NULL )
    {
    printf("\nNao ha espaco disponivel na memoria!");
    exit(1);
    }

    novo->prox=NULL;

    printf("\nInsira o nome do funcionario: ");
    fflush(stdin);
    fgets(novo->nome,9,stdin);
    fflush(stdin);
    printf("\nInsira matricula/Numero de cadastro do funcionario : ");
    scanf("%d", &novo->matricula);
    fflush(stdin);
    printf("\n Insira a data(dd/mm/aaaa): ");
    gets(novo->data);
    fflush(stdin);
    entrada:
    printf("\n Insira o horario de entrada (Formato hh:mm) : ");
    gets(novo->hrEntrada);
    fflush(stdin);
        if(strcmp(novo->hrEntrada,vazio)==0)
            {
            printf("Informe uma entrada valida!");
           // exit(1);
            goto entrada;
            }
    saida:
    printf("\n Insira o horario de saida(Formato hh:mm) : ");
    gets(novo->hrSaida);
       if(strcmp(novo->hrSaida,vazio)==0)
            {
            printf("Informe uma entrada valida!");
            //exit(1);
            goto saida;
            }
if(verificaponto(lista))
    {
		lista->prox=novo;
		novo->ant=lista;

	}
	else{
        tmp = lista->prox;
		while(tmp->prox != NULL)
		{
        tmp = tmp->prox;
		}
		tmp->prox = novo;
		novo->ant=tmp;
    }
}
void trocaposicao(ponto *tmp)
{

ponto *aux;
tmp=tmp->ant->prox;
    while(tmp->prox!=NULL)
    {
        tmp->ant->prox=tmp->prox;
        tmp->prox->ant=tmp->prox;
        aux=tmp->prox->prox;
        tmp->prox->prox=tmp;
        tmp->prox=aux;
    }


}

void deletarponto(ponto *lista,int key)
{
		ponto *tmp;
		tmp=lista->prox;
		while(tmp->prox != NULL)
        {

            if(tmp->matricula==key){
                tmp->prox->ant=tmp->ant;
                tmp->ant->prox=tmp->prox;
                free(tmp);
                break;
            }
            else{
              tmp=tmp->prox;
            }
        }
        if(tmp->prox==NULL)
        {
            if(tmp->matricula==key){
                tmp->ant->prox=NULL;
                free(tmp);
            }
        }
}
void imprimeponto( ponto *lista)
{
    ponto *tmp;
	tmp=lista->prox;
    if(verificaponto(lista))
		printf("\n\nLista de pontos de funcionarios esta vazia!\n\n");
	else{
            while(tmp!=NULL){
               printf("\n\nFuncionario:%s \nMatricula: %d \nData do ponto: %s \nHorario  de entrada: %shr \nHorario de saida: %shr\n\n",tmp->nome,tmp->matricula,tmp->data,tmp->hrEntrada,tmp->hrSaida);
               tmp = tmp->prox;
            }
	}
}
void imprimeordenada( ponto *lista)
{

    int i = 0;
    char ordem;

    do{
    printf("\nDigite C se for Crescente e D se for Decrescente: ");
    getchar();
    scanf("%c",&ordem);

            if(ordem == 'c'  || ordem=='C')
            {
                ordenaCres(lista);
                imprimeponto(lista);
                i=0;
            }
            else if(ordem == 'd' || ordem =='D')
            {
                ordenaDecres(lista);
                imprimeponto(lista);
                i=0;
            }

        else
        {
            printf("Ordem nao identificada!");
            i++;
        }
    }while (i>0);
}

void main(void)
{

    int key=0;

     ponto *lista =(ponto *) malloc(sizeof(ponto));
     ponto *lista2 =(ponto *) malloc(sizeof(ponto));
    if( lista==NULL )
    {
    printf("\nProblema com a alocacao de memoria!");
    exit(1);
    }
    iniciaponto(lista);
    int opcao=0;


    while(opcao==0)
    {
    menu:
    printf("\nInsira uma opcao de alteracao/exibicao:\n");
     printf("\n\n[1] Inserir ponto de funcionario \n");
     printf("[2] Deletar registro de ponto de funcionario \n");
     printf("[3] Imprimir Lista de funcionarios \n");
     printf("[4] Buscar ponto de funcionario\n");
     printf("[5] Imprimir funcao ordenada\n");
     printf("[6] Ordenar funcao em ordem crescente \n");
     printf("[7] Ordenar funcao em ordem decrescente\n");
     printf("[8] Sair\n");

        scanf("%d",&opcao);
        printf("\nOpcao selecionada: %d\n\n",opcao);

        while(opcao!=8)
    {
        if(opcao==1){
            inserirponto(lista);
            copia(lista,lista2);
            opcao=0;
            break;
        }
        else if(opcao==2){
            if(verificaponto(lista))
            {
                printf("Lista de pontos vazia!");
                opcao=0;
            }
            else
            {
            printf("\nInforme a matricula de funcionario que deseja apagar: ");
            scanf("%d", &key);
            deletarponto(lista,key);
            copia(lista,lista2);
            opcao=0;
            break;
            }
        }
        else if(opcao==3){
            imprimeponto(lista);
            opcao=0;
            break;
        }
        else if(opcao==4){
            printf("\nInforme a matricula de funcionario que deseja visualizar: ");
            scanf("%d", &key);
            if(verificaponto(lista))
            {
                printf("Lista de pontos vazia!");
                opcao=0;
            }
            if(buscaponto(lista,key)==1)
                printf("Achou!");
            else
                printf("Não achou!");
            opcao=0;
            break;
        }
           else if(opcao==5){
            imprimeordenada(lista2);
        }
        else if(opcao==6){
            ordenaCres(lista);
        }
        else if(opcao==7){
            ordenaDecres(lista);
        }
        else
            printf("\nOpcao Invalida!\n");
            goto menu;
    }
}

///Outra opçao de menu(em switch):
///        switch(opcao)
///       {
///        case 0:
///        break;
///        case 1:
///            inserirponto(lista);
///            opcao=0;
///           break;
///       case 2:
///            deletarponto(lista,key);
///            opcao=0;
///            break;
///        case 3:
///            imprimeponto(lista);
///            opcao=0;
///            break;
///        default:
///            printf("opcao invalida!");
}
