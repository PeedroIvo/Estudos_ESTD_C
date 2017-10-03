/*
Pedro Ivo Mariano de Oliveira Barros
ESTD - Curso de F�rias
Sistemas de Informa��o - IFAL
�rvore bin�ria, por�m com inser��o em apenas um caminho na arvore
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    char info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* inicializa(void)
{
    return NULL;
}

Arv* cria(char c, Arv* sae, Arv* sad)
{
    Arv* a = (Arv*)malloc(sizeof(Arv));

    a->info = c;
    a->esq = sae;
    a->dir = sad;

    return a;
}

int vazia(Arv* a)
{
    return a==NULL;
}

void imprime(Arv* a)
{
    if (!vazia(a))
    {
        printf("%c ", a->info); /* mostra raiz */
        imprime(a->esq); /* mostra sae */
        imprime(a->dir); /* mostra sad */
    }
}

Arv* insere(void) /* Criei a fun��o insere para evitar repeti��o no main, ela pega o char info, e depois chama a fun��o cria */
{
    Arv *a, *sae, *sad;

    a = inicializa();
    sae = inicializa();
    sad = inicializa();

    char c;

    do
    {
        c = getchar();
    }
    while(c == ' ' || c == '\n');

    a = cria(c, sae, sad);

    return a;
}

main() ///Como mostrado em sala, este algoritmo apenas cria um caminho na arvore, deixando todos os outros n�s NULL
{
    int opcao=0;
    Arv *raiz, *tmpRaiz;

    printf("NOVA ARVORE CRIADA!\n\nDigite a letra que quer inserir na RAIZ: "); //Antes de entrar no menos � necess�rio inserir um conteudo para a raiz

    raiz = insere();
    tmpRaiz = raiz; //Uma variavel temporaria recebe a raiz, afim de deixar a raiz intacta

    while(opcao == 0)
    {
        printf("\nO QUE DESEJA FAZER?\n\n");
        printf("1 - Inserir um no a ESQUERDA\n");
        printf("2 - Inserir um no a DIREITA\n");
        printf("3 - Imprimir todos os nos da arvore\n");
        printf("4 - SAIR\n\n");
        scanf("%d", &opcao);

        printf("\nOpcao selecionada: %d\n\n", opcao);

        if(opcao == 1) //Nesta op��o sera driado um n� no filho esquerdo do n� anterior
        {
            printf("Digite a letra que quer inserir na ESQUERDA: ");

            tmpRaiz->esq = insere();
            tmpRaiz = tmpRaiz->esq; //Apos criado, este no passa a ser a raiz temporaria para a proxima inser��o

            opcao = 0;
        }
        else if(opcao == 2) //Nesta op��o sera driado um n� no filho direito do n� anterior
        {
            printf("Digite a letra que quer inserir na DIREITA: ");

            tmpRaiz->dir = insere();
            tmpRaiz = tmpRaiz->dir; //Apos criado, este no passa a ser a raiz temporaria para a proxima inser��o

            opcao = 0;
        }
        else if(opcao == 3)
        {
            imprime(raiz); //Imprime-se a arvore sem verificar se est� vazia, porque a arvore nunca estar� vazia
            printf("\n");

            opcao = 0;
        }
        else if(opcao < 1 || opcao > 4)
        {
            printf("-------------------------\n- OPCAO NAO IDENTIFICADA!\n-------------------------\n");

            opcao = 0;
        }
    }
}
