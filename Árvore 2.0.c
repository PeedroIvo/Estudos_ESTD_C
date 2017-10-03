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

Arv* insere(void)
{
    Arv *a, *sae, *sad;

    a = inicializa();
    sae = inicializa();
    sad = inicializa();

    char c;

    printf("Digite a letra que quer inserir na arvore: ");

    do
    {
        c = getchar();
    }
    while(c == ' ' || c == '\n');

    a = cria(c, sae, sad);

    return a;
}

main()
{
    int opcao=0, lado=0, numNo=0, i=0, qntdNos;

    printf("Digite o numero MAXIMO de nos na nova arvore: ");
    scanf("%d", &qntdNos);

    Arv *raiz, *no[qntdNos];

    raiz = inicializa();
    printf("\n-------------------\nNOVA ARVORE CRIADA!\nMAXIMO DE NOS = %d\n-------------------\n", qntdNos);

    while(opcao == 0)
    {
        printf("\nO QUE DESEJA FAZER?\n\n");
        printf("1 - Inserir um no na arvore\n");
        printf("2 - Imprimir todos os nos da arvore\n");
        printf("3 - SAIR\n\n");
        scanf("%d", &opcao);

        printf("\nOpcao selecionada: %d\n\n", opcao);

        if(opcao == 1)
        {
            if(numNo < qntdNos)
            {
                if(numNo == 0)
                {
                    raiz = insere();
                    no[numNo] = raiz;
                }
                else if(lado == 0)
                {
                    no[i]->esq = insere();
                    no[numNo] = no[i]->esq;
                    lado = 1;
                }
                else if(lado == 1)
                {
                    no[i]->dir = insere();
                    no[numNo] = no[i]->dir;
                    lado = 0;
                    i++;
                }
                numNo++;
            }
            else
            {
                printf("-----------------------------\nVOCE ATINGIU O LIMITE DE NOS!\n-----------------------------\n");
            }

            opcao = 0;
        }
        else if(opcao == 2)
        {
            if(vazia(raiz))
            {
                printf("--------------------\nA ARVORE ESTA VAZIA!\n--------------------\n");
            }
            else
            {
                imprime(raiz);
                printf("\n");
            }

            opcao = 0;
        }
        else if(opcao < 1 || opcao > 3)
        {
            printf("-----------------------\nOPCAO NAO IDENTIFICADA!\n-----------------------\n");

            opcao = 0;
        }
    }
}
