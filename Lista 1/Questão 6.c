#include <stdio.h>

main()
{
    int sim = 0, nao = 0;
    char resposta[5];

    printf("Responda as perguntas a seguir com SIM ou NAO:\n\n");

    printf("Telefonou para a vitima? ");
    gets(resposta);
    if(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0)
    {
        sim++;
    }

    printf("Esteve no local do crime? ");
    gets(resposta);
    if(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0)
    {
        sim++;
    }

    printf("Mora perto da vitima? ");
    gets(resposta);
    if(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0)
    {
        sim++;
    }

    printf("Devia a vitima? ");
    gets(resposta);
    if(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0)
    {
        sim++;
    }

    printf("Ja trabalhou com a vitima? ");
    gets(resposta);
    if(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0)
    {
        sim++;
    }

    if(sim == 2)
    {
        printf("\nSuspeito!\n");
    }
    else if(sim == 3 || sim == 4)
    {
        printf("\nCumplice!\n");
    }
    else if(sim == 5)
    {
        printf("\nAssassino!\n");
    }
    else
    {
        printf("\nInocente!\n");
    }
}
