#include <stdio.h>

main()
{
    int numero, i, numDivisores=0;

    printf("Digite o numero: ");
    scanf("%d", &numero);

    for(i=1; i<=numero; i++)
    {
        if(numero%i == 0){
            numDivisores++;
        }
    }

    if(numDivisores == 2)
    {
        printf("O numero e primo!\n");
    }
    else
    {
        printf("O numero nao e primo!\n");
    }
}
