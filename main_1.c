#include <stdio.h>
#include <stdlib.h>

struct Aluno{
  char nome[30];
  int  matricula;//elemento chave
  char disciplina[10];
  float nota;
  struct Aluno *prox;
};

typedef struct Aluno aluno;


void IniciaLista( aluno *lista){
   lista->prox=NULL;
}

int ListaVazia( aluno *lista){
if(lista->prox == NULL)
		return 1;
	else
		return 0;
}

void InsereLista( aluno *lista){
	aluno *tmp,*novo;
	novo=(aluno *) malloc(sizeof( aluno));
	if( novo == NULL )
    {
    printf("\nErro de alocacao de memoria!");
    exit(1);
    }
	novo->prox = NULL;

            printf("Nome aluno: ");
            scanf("%s", novo->nome);
            printf(" matricula: ");
            scanf("%i", &novo->matricula);
            printf(" disciplina: ");
            scanf("%s", novo->disciplina);
            printf(" nota: ");
            scanf("%f", &novo->nota);

	if(ListaVazia(lista)){
		lista->prox=novo;
	}
	else{
		tmp = lista->prox;
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		tmp->prox = novo;
    }
}

void DeletaLista(aluno *lista,int chave){
		aluno *tmp,*anterior;
		anterior = lista;
		tmp=lista->prox;
		while(tmp->prox != NULL){

            if(tmp->matricula==chave){
                anterior->prox=tmp->prox;
                tmp->prox=NULL;
                free(tmp);
                break;
            }
            else{
              anterior = tmp;
              tmp=tmp->prox;
            }
        }
        //Para testar o ultimo elemento
        if(tmp->prox==NULL){
            if(tmp->matricula==chave){
                anterior->prox=tmp->prox;
                tmp->prox=NULL;
                free(tmp);
            }
        }
}

void ImprimeLista( aluno *lista){
    aluno *tmp;
	tmp=lista->prox;
	int i=1;
    if(ListaVazia(lista))
		printf("Lista Vazia");
	else{
            while(tmp != NULL){
               printf("Elemento %i \n Nome:%s Matricula: %i Disciplina %s Nota: %f \n\n",i,tmp->nome,tmp->matricula,tmp->disciplina,tmp->nota);
               i=i+1;
               tmp = tmp->prox;
            }
	}
}
void libera (aluno* lista)
{
 aluno* tmp;
 tmp=lista;
 while (tmp != NULL) {
    aluno* t = tmp->prox; /* guarda referência para o próximo elemento*/
    free(tmp); /* libera a memória apontada por p */
    tmp = t; /* faz p apontar para o próximo */
 }
}
int main(void)
{
//   int i=0;
    aluno  *lista =(aluno *) malloc(sizeof(aluno));
    if( lista == NULL )
    {
    printf("\nErro de alocacao de memoria!");
    exit(1);
    }
    int chave=0;
    IniciaLista(lista);
    int desejo=0;
    while(desejo==0){
        printf("O que deseja fazer?\n");
        printf("1 - Inserir Elemento \n");
        printf("2 - Deletar Elemento \n");
        printf("3 - Imprimir Lista \n");
        printf("4 - Sair \n");
        scanf("%i",&desejo);
        if(desejo==1){
            InsereLista(lista);
            desejo=0;
        }
        else if(desejo==2){
            printf("Informe a matricula que deseja apagar: ");
            scanf("%i", &chave);
            DeletaLista(lista,chave);
            desejo=0;
        }
        else if(desejo==3){
            ImprimeLista(lista);
            desejo=0;
        }
    }

    return 0;
}
