#include <stdio.h>

main()
{
    float saldo, totalSaldos=0, saldoMedio, percentagemDev, saldoDev=0, numClientes=0;
    int saldoCred=0;

    while(numClientes<10)
    {
        printf("Digite o saldo do Cliente: ");
        scanf("%f", &saldo);

        if(saldo < 0)
        {
            saldoDev++;
        }
        else if(saldo > 0)
        {
            saldoCred++;
        }

        totalSaldos += saldo;

        numClientes++;
    }

    percentagemDev = ((100*saldoDev)/numClientes);

    saldoMedio = totalSaldos/10;

    printf("\nO saldo medio dos clientes e: R$ %.2f", saldoMedio);
    printf("\n%.f%% dos clientes esta com saldo devedor", percentagemDev);
    printf("\nNumero de clientes com saldo credor: %d", saldoCred);
}
