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
    Arv* p = (Arv*)malloc(sizeof(Arv));

    p->info = c;
    p->esq = sae;
    p->dir = sad;

    return p;
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

main()
{
    int opcao=0;
    char letra;
    Arv *subArvore, *sae, *sad, *raiz;

    sae = inicializa();
    sad = inicializa();
    raiz = inicializa();

    printf("NOVA ARVORE CRIADA!\n\nDigite a letra que quer inserir na RAIZ: ");
    do
    {
        letra = getchar();
    }
    while(letra == ' ' || letra == '\n');

    raiz = cria(letra, sae, sad);

    subArvore = raiz;

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
            do
            {
                letra = getchar();
            }
            while(letra == ' ' || letra == '\n');

            subArvore->esq = cria(letra, sae, sad);

            subArvore = subArvore->esq;

            opcao = 0;
        }
        else if(opcao == 2)
        {
            printf("Digite a letra que quer inserir na DIREITA: ");
            do
            {
                letra = getchar();
            }
            while(letra == ' ' || letra == '\n');

            subArvore->dir = cria(letra, sae, sad);

            subArvore = subArvore->dir;

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
