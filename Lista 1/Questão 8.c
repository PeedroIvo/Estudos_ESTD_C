#include <stdio.h>

main()
{
    int vetor[20], i, j, aux;

    printf("Digite os 20 elementos a seguir:\n");

    for(i=0; i<20; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("\n");

    for(i=0; i<20; i++)
    {
        printf("%d ", vetor[i]);
    }

    i=0;
    j=20;

    while(i<10)
    {
        aux = vetor[i];
        vetor[i] = vetor[j-1];
        vetor[j-1] = aux;

        i++;
        j--;
    }

    printf("\n");

    for(i=0; i<20; i++)
    {
        printf("%d ", vetor[i]);
    }
}
