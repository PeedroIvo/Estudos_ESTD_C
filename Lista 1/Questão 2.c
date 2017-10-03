#include <stdio.h>

main()
{
    int menorIdade, maiorIdade, quantidadePessoas=0, quantidadeH=0, idade;
    float somaSalario=0, salario, mediaSalario, percentagemMT, quantidadeM=0, quantMTrezentos;
    char sexo;

    printf("Digite a Idade: ");
    scanf ("%d", &idade);
    menorIdade = idade;
    maiorIdade = idade;

    while (idade > 0)
    {
        if(idade < menorIdade)
        {
            menorIdade = idade;
        }
        else if(idade > maiorIdade)
        {
            maiorIdade = idade;
        }

        printf("Digite o Sexo: ");
        getchar();
        scanf ("%c", &sexo);

        if(sexo == 'm' || sexo == 'M')
        {
            quantidadeH++;
        }
        else if(sexo == 'f' || sexo == 'F')
        {
            quantidadeM++;
        }

        printf("Digite o Salario: ");
        scanf ("%f", &salario);

        somaSalario += salario;

        if(sexo == 'f' || sexo == 'F')
        {
            if(salario <= 300)
            {
                quantMTrezentos++;
            }
        }

        quantidadePessoas++;

        printf("\nDigite a Idade: ");
        scanf ("%d", &idade);
    }

    mediaSalario = (somaSalario/quantidadePessoas);

    percentagemMT = ((100*quantMTrezentos)/quantidadeM);

    printf("\nMedia dos Salarios: R$ %.2f", mediaSalario);
    printf("\nMenor Idade: %d", menorIdade);
    printf("\nMaior Idade: %d", maiorIdade);
    printf("\n%.2f%% das mulheres tem salario de ate R$ 300,00", percentagemMT);
    printf("\nA quantidade de homens: %d\n", quantidadeH);
}
