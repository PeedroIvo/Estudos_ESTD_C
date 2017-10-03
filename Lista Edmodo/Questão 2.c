#include <stdio.h>

int contagem(char *str, char letra1, char letra2)
{
    int total=0, frequencia=0;
    char *pLetra1, *pLetra2;

    pLetra1 = &letra1;
    pLetra2 = &letra2;

    while(str[total] != '\0')
    {
        if(str[total] == *pLetra1 || str[total] == *pLetra2)
        {
            frequencia++;
        }
        total++;
    }

    return frequencia;
}

main()
{
    char nome[80], *pNome;
    int qtLetra, *pQtLetra;

    pNome = &nome;
    pQtLetra = &qtLetra;

    printf("Digite o nome abaixo:\n");
    gets(pNome);

    *pQtLetra = contagem(nome, 'a', 'A');
    printf("\nLetra A: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'b', 'B');
    printf("\nLetra B: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'c', 'C');
    printf("\nLetra C: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'd', 'D');
    printf("\nLetra D: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'e', 'E');
    printf("\nLetra E: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'f', 'F');
    printf("\nLetra F: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'g', 'G');
    printf("\nLetra G: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'h', 'H');
    printf("\nLetra H: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'i', 'I');
    printf("\nLetra I: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'j', 'J');
    printf("\nLetra J: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'k', 'K');
    printf("\nLetra K: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'l', 'L');
    printf("\nLetra L: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'm', 'M');
    printf("\nLetra M: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'n', 'N');
    printf("\nLetra N: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'o', 'O');
    printf("\nLetra O: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'p', 'P');
    printf("\nLetra P: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'q', 'Q');
    printf("\nLetra Q: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'r', 'R');
    printf("\nLetra R: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 's', 'S');
    printf("\nLetra S: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 't', 'T');
    printf("\nLetra T: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'u', 'U');
    printf("\nLetra U: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'v', 'V');
    printf("\nLetra V: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'w', 'W');
    printf("\nLetra W: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'x', 'X');
    printf("\nLetra X: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'y', 'Y');
    printf("\nLetra Y: %d vezes na frase", qtLetra);

    *pQtLetra = contagem(nome, 'z', 'Z');
    printf("\nLetra Z: %d vezes na frase\n", qtLetra);
}
