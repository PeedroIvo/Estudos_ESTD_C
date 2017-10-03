/*
Pedro Ivo Mariano de Oliveira Barros
ESTD - Curso de Férias
Sistemas de Informação - IFAL
Árvore binária, com inserção de modo que a arvore sempre fique completa, porem com metodos que nao sei se são corretos
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

Arv* insere(void) /* Criei essa função pra ser mais geral que a função cria, o char info é gerado nela, depois a função cria é chamada */
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

main() ///Depois de muitas pesquisas sem sucesso, eu bolei esse metodo de percorrer todos os nós da arvore, não sei se é correto, mas ele de fato preenche a arvore e todos sao imprimidos na função imprime corretamente
{
    int opcao=0;
    int lado=0; //Representa o lado que sera criado o nó, 0 se for esquerda, 1 se for direita
    int numNo=0; //Vai ser usado para atribuir aos nós um indice no vetor de nós
    int i=0; //Vai ser usado para fazer o programa percorrer o vetor de nós
    int qntdNos; //Representa a quantidade maxima de nós na arvore

    printf("Digite o numero MAXIMO de nos na nova arvore: ");
    scanf("%d", &qntdNos);

    Arv *raiz; //É a raiz da arvore

    Arv *no[qntdNos]; //Este é o vetor de nos, ele é a razao para ter um numero maximo de nós, os endereços dos nos sao armazenados neste vetor

    raiz = inicializa();
    printf("\n-------------------\nNOVA ARVORE CRIADA!\nMAXIMO DE NOS = %d\n-------------------\n", qntdNos);

    while(opcao == 0)
    {
        printf("\nO QUE DESEJA FAZER?\n\n");
        printf("1 - Inserir um no na arvore\n"); //Simplesmente insere um no, ele sera inserido na proxima posicao livre
        printf("2 - Imprimir todos os nos da arvore\n");
        printf("3 - SAIR\n\n");
        scanf("%d", &opcao);

        printf("\nOpcao selecionada: %d\n\n", opcao);

        if(opcao == 1)
        {
            if(numNo < qntdNos) //Indica que o programa só vai inserir um nó se a quantidade maxima de nos não for atingida
            {
                if(numNo == 0) //Sendo o primeiro no do vetor a raiz, se numNo = 0, adiciona-se conteudo a raiz
                {
                    raiz = insere();
                    no[numNo] = raiz;
                }
                else if(lado == 0) //Como indicado em sua declaração se lado = 0, inserimos um nó no filho esquerdo
                {
                    no[i]->esq = insere();
                    no[numNo] = no[i]->esq; //Após adiciona-se conteudo ao filho esquerdo, adicion-se ele ao vetor de nos
                    lado = 1; //Muda-se lado para 1 (direito), e na proxima vez que inserirmos um no ele vai ser inserido no filho direito
                }
                else if(lado == 1) //Analogamente tem-se aqui o lado direito, que fará basicamente a msm coisa, porém no filho direito
                {
                    no[i]->dir = insere();
                    no[numNo] = no[i]->dir;
                    lado = 0; //Desta vez mudamos lado para 0 (esquerdo)
                    i++; //Só incrementa-se essa variavel, depois de inserir no filho direito do nó, assim na proxima inserção vamos ao proximo nó no vetor de nós
                }
                numNo++; //Incrementa-se essa variavel para atribuir ao proximo no um indice posterior ao que acabou de ser criado
            }
            else //Se a quantidade maxima de nos for atiginda, este aviso aparece na tela
            {
                printf("-----------------------------\nVOCE ATINGIU O LIMITE DE NOS!\n-----------------------------\n");
            }

            opcao = 0;
        }
        else if(opcao == 2)
        {
            if(vazia(raiz))//Verifica se a arvore está vazia
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
