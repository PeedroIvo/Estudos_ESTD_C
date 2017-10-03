#include <stdio.h>

int strlen(char *str)
{
    int total=0;

    while(str[total] != '\0')
        total++;

    return total;
}

main()
{
    char nome[100], *pNome;
    int i=0, numLetras, *pNumLetras;

    pNumLetras = &numLetras;
    pNome = &nome;

    while(i==0)
    {
        printf("Digite o nome abaixo:\n");
        gets(pNome);

        printf("\n%s", nome);

        *pNumLetras = strlen(nome);

        printf("\nO nome tem %d caracteres\n\n------------------------\n", numLetras);
    }
}
