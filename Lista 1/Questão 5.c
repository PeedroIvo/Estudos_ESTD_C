#include <stdio.h>

main()
{
    float altura, menorAltura, maiorAltura, somaAlturaF = 0, mediaAlturaF, quantidadeF = 0, percentagemF;
    char sexo[10];
    int quantidadeM = 0, i;

    for(i=0; i<10; i++)
    {
        if(i>0)
        {
            getchar();
        }

        printf("Digite o sexo (masculino ou feminino): ");
        gets(sexo);

        printf("Digite a altura: ");
        scanf("%f", &altura);

        if(strcmp(sexo, "masculino") == 0)
        {
            quantidadeM++;
        }
        else if(strcmp(sexo, "feminino") == 0)
        {
            quantidadeF++;
            somaAlturaF += altura;
        }

        if(i == 0)
        {
            menorAltura = altura;
            maiorAltura = altura;
        }
        else if(altura < menorAltura)
        {
            menorAltura = altura;
        }
        else if(altura > maiorAltura)
        {
            maiorAltura = altura;
        }
    }

    mediaAlturaF = somaAlturaF/quantidadeF;

    percentagemF = ((100*quantidadeF)/10);

    printf("\nMaior Altura: %.2f", maiorAltura);
    printf("\nMenor Altura: %.2f", menorAltura);
    printf("\nMedia de altura de Mulheres: %.2f", mediaAlturaF);
    printf("\nA quantidade de homens: %d", quantidadeM);
    printf("\n%.2f%% das pessoas sao mulheres\n", percentagemF);
}
