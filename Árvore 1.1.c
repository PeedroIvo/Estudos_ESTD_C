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
    int opcao=0;
    Arv *raiz, *subRaiz;

    printf("NOVA ARVORE CRIADA!\n\nDigite a letra que quer inserir na RAIZ: ");

    raiz = insere();
    subRaiz = raiz;

    while(opcao == 0)
    {
        printf("\nO QUE DESEJA FAZER?\n\n");
        printf("1 - Inserir um no a ESQUERDA\n");
        printf("2 - Inserir um no a DIREITA\n");
        printf("3 - Imprimir todos os nos da arvore\n");
        printf("4 - SAIR\n\n");
        scanf("%d", &opcao);

        printf("\nOpcao selecionada: %d\n\n", opcao);

        if(opcao == 1)
        {
            printf("Digite a letra que quer inserir na ESQUERDA: ");

            subRaiz->esq = insere();
            subRaiz = subRaiz->esq;

            opcao = 0;
        }
        else if(opcao == 2)
        {
            printf("Digite a letra que quer inserir na DIREITA: ");

            subRaiz->dir = insere();
            subRaiz = subRaiz->dir;

            opcao = 0;
        }
        else if(opcao == 3)
        {
            imprime(raiz);
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
