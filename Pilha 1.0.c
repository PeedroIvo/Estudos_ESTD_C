#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct Pilha
{
    int n;
    float vet[MAX];
} pilha;

pilha* Cria (void) //Função Cria - Retorna um ponteiro
{
    pilha* p = (pilha*) malloc(sizeof(pilha));
    p->n = 0;  // inicializa com zero elementos
    return p;
}

void Push (pilha* p, float v) //Função Insere na Pilha
{
    if (p->n == MAX)   // capacidade esgotada
    {
        printf("Capacidade da pilha estourou.\n");
        exit(1); // aborta programa
    }
    // insere elemento na próxima posição livre
    p->vet[p->n] = v;//printf("SSSSSSSSSSS");
    p->n++;
}

float Pop (pilha* p) //Função remove da Pilha
{
    float v;
    if (Vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1); // aborta programa
    }
    // retira elemento do topo
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

int Vazia (pilha* p)
{
    return (p->n == 0);
}

void Libera (pilha* p)
{
    free(p);
}

pilha* Copia (pilha *p)
{
    int i, n;
    float valor;
    pilha *copia_p, *copia_aux;

    copia_p = Cria();
    copia_aux = Cria();

    n = p->n;

    for(i=0; i<n; i++)
    {
        valor = Pop(p);
        Push(copia_aux, valor);
    }
    for(i=0; i<n; i++)
    {
        valor = Pop(copia_aux);
        Push(p, valor);
        Push(copia_p, valor);
    }

    Libera(copia_aux);

    return copia_p;
}

void Imprime (pilha *p)
{
    pilha *p_aux;
    float v;
    int i;

    p_aux = Cria();

    p_aux = Copia(p);

    for(i=0; i<p->n; i++)
    {
        v = Pop(p_aux);
        printf("%.2f\n", v);
    }

    Libera(p_aux);
}

main()
{
    pilha *p;
    int opcao = 0, i = 0;
    float valor;

    p = Cria();

    while(opcao == 0)
    {
        if(i>0)
        {
            printf("\n");
        }

        printf("O QUE DESEJA FAZER?\n\n");
        printf("1 - Inserir um elemento na pilha - EMPILHAR\n");
        printf("2 - Remover um elemento da pilha - DESEMPILHAR\n");
        printf("3 - Imprimir a pilha\n");
        printf("4 - SAIR\n\n");
        scanf("%d", &opcao);

        printf("\nOpcao selecionada: %d\n\n", opcao);

        if(opcao == 1)
        {
            printf("Insira o valor que deseja inserir: ");
            scanf("%f", &valor);
            Push(p, valor);
            opcao = 0;
        }
        else if(opcao == 2)
        {
            Pop(p);
            printf("Deletado com sucesso!\n");
            opcao = 0;
        }
        else if(opcao == 3)
        {
            Imprime(p);
            opcao = 0;
        }
        else if(opcao < 1 || opcao > 4)
        {
            printf("Opcao nao identificada!\n");
            opcao = 0;
        }

        i++;
    }
}
