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

///Nunca sai, programa sempre rodando
///Não consegui implementar a questao de entrar com dois valores, a partir do segundo ciclo do while
///Se entrar com apenas um valor e um operador no primeiro ciclo o programa buga

main()
{
    pilha *p;
    int i = 1;
    float v, valor1, valor2, resultado;
    char operador;

    p = Cria();

    while(i > 0)
    {
        printf("Digite a expressao a ser calculada: ");

        if(i == 1)
        {
            scanf("%f", &v);
            Push(p, v);

            i++;
        }

        scanf("%f", &v);
        Push(p, v);

        do
        {
            operador = getchar();
        }
        while(operador == ' ' || operador == '\n');

        if(operador != '+' && operador != '-' && operador != '*' && operador != '/')
        {
            printf("\nOperador nao identificado! Use [+] [-] [*] ou [/]\n\n");

            if(i == 1)
            {
                Pop(p);
            }

            Pop(p);
        }
        else
        {
            valor2 = Pop(p);
            valor1 = Pop(p);

            if(operador == '+')
            {
                resultado = valor1+valor2;
            }
            else if(operador == '-')
            {
                resultado = valor1-valor2;
            }
            else if(operador == '*')
            {
                resultado = valor1*valor2;
            }
            else if(operador == '/')
            {
                resultado = valor1/valor2;
            }

            printf("Resultado = %.2f\n\n", resultado);
            Push(p, resultado);
        }
    }
}

