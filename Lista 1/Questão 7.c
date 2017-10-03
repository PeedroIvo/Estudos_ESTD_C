#include <stdio.h>

main()
{
    int vetor[10], posicaoVetor, menorElemento, i;

    for(i=0; i<10; i++)
    {
        scanf("%d", &vetor[i]);

        if(i == 0)
        {
            menorElemento = vetor[i];
            posicaoVetor = i;
        }
        else if(vetor[i] < menorElemento)
        {
            menorElemento = vetor[i];
            posicaoVetor = i;
        }
    }

    printf("O menor elemento do vetor e: %d\nEle esta na posicao %d do vetor\n", menorElemento, posicaoVetor);
}
