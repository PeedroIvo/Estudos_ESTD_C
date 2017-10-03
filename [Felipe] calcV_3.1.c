#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct pilha
{
    int n;
    float vet[MAX];
} Pilha;
Pilha * cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; /* inicializa com zero elementos */
    return p;
}

void push (Pilha* p, float v)
{
    if (p->n == MAX)   /* capacidade esgotada */
    {
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre*/

    p->vet[p->n] = v;
    p->n++;


}
float pop (Pilha* p)
    {
        float v;
        if (vazia(p))
        {
            printf("Pilha vazia.\n");
            exit(1); /* aborta programa */
        }
        /* retira elemento do topo */
        v = p->vet[p->n-1];
        p->n--;
        return v;
    }
    int vazia (Pilha* p)
    {
        return (p->n == 0);
    }
    void libera (Pilha* p)
    {
        free(p);
    }
Pilha * copia(Pilha * p)
{
    int i=0, n;
    float v;
    Pilha *copiaux;
    Pilha *copia;
    copia=cria();
    copiaux=cria();
    n=p->n;

    for(i=0;i<n;i++)
    {
        v=pop(p);
        push(copia,v);

    }
    for(i=0;i<n;i++)
    {
        v=pop(copia);
        push(copiaux,v);
        push(p,v);
    }
    free(copia);
    return copiaux;
}
float imprimir(Pilha * p)
{
    int i;
    Pilha *p_aux;
    float v;
    p_aux=cria();
    p_aux=copia(p);

    for(i=0;i<p->n;i++)
    {
        v=pop(p_aux);
        printf("\n%.2f\n",v);
    }
    libera(p_aux);
}
float main()
{
Pilha *p=cria();
int opcao=0;
float v1,v2,result,v;
char operacao,escolher;

   menu:
   printf("      Calculadora        ");
   printf("\nDigite o primeiro valor da operacao:");
   scanf("%f",&v);
   push(p,v);
    proximo:
    printf("\nDigite o proximo valor da operacao:");
   scanf("%f",&v);
   push(p,v);
   inicio:
   printf("\nDigite uma das operacoes disponiveis: ( + , - , * , / )\n");
   getchar();
   scanf("%c",&operacao);
    if(operacao == '+')
    {
        v1=pop(p);
        v2=pop(p);
        result=v1+v2;
        printf("\nO resultado da sua soma: %.2f",result);
        printf("\n deseja continuar sua operacao? (Escolha s/S para ir, outro caractere qualquer para sair:    )");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
            {
                push(p,result);
                goto proximo;
            }
            else{

        printf("\ndeseja fazer uma nova operacao? (Escolha s/S para ir, outro caractere qualquer para sair:      )");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
                goto menu;
            else
                exit(1);
            }
    }
    else if(operacao == '-')
    {
        v1=pop(p);
        v2=pop(p);
        result=v2-v1;
        push(p,result);
        printf("\nO resultado da sua subtracao: %.2f",result);
        printf("\ndeseja continuar sua operacao? (Escolha s/S para ir, outro caractere qualquer para sair:        )");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
            {
                push(p,result);
                goto proximo;
            }
            else{

        printf("\ndeseja fazer uma nova operacao? (Escolha s/S para ir, outro caractere qualquer para sair:       )");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
                goto menu;
            else
                exit(1);
            }
    }
    else if(operacao == '*')
    {
        v1=pop(p);
        v2=pop(p);
        result=v1*v2;
        push(p,result);
        printf("\nO resultado da sua multiplicacao: %.2f",result);
        printf("\ndeseja continuar sua operacao? (Escolha s/S para ir, outro caractere qualquer para sair:          )");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
            {
                push(p,result);
                goto proximo;
            }
            else{

        printf("\ndeseja fazer uma nova operacao? (Escolha s/S para ir, outro caractere qualquer para sair):           ");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
                goto menu;
            else
                exit(1);
            }
    }
    else if(operacao == '/')
    {
        v1=pop(p);
        v2=pop(p);
        result=v2/v1;
        push(p,result);
        printf("\nO resultado da sua divisao: %.2f",result);
        printf("\ndeseja continuar sua operacao? (Escolha s/S para ir, outro caractere qualquer para sair;             )");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
            {
                push(p,result);
                goto proximo;
            }
            else{

        printf("\ndeseja fazer uma nova operacao? (Escolha s/S para ir, outro caractere qualquer para sair;              )");
        getchar();
        scanf("%c",&escolher);
            if(escolher == 's' || escolher == 'S')
                goto menu;
            else
                exit(1);
            }
    }
    else
        printf("\n  operacao invalida! \n");
        goto inicio;


}
