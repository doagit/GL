#include <stdio.h>
#include <math.h>

float calculatroco(
    float deuda,
    float pago);

void calculodineiro(
    float troc,
    int* tr);

void mostradineiro(
    int* tr);

int main(int argc, char const *argv[])
{
    //Inicio Variaveis
    float due;
    float pago = 0, troco = 0, decimal = 0;
    int i, inteiro = 0;
    int atr[10];
    
    //Fim Variaveis

    printf("Valor a ser pago: R$");
    scanf("%f",&due);

    printf("Valor efetivamente pago: R$");
    scanf("%f",&pago);

    //Função que calcula e retorna o troco
    troco = calculatroco( due, pago);

    if ( troco < 0) 
    { 
		printf("O Valor total nao foi pago, resta pagar R$%.2f\n", -troco);
        return 0;
	}

    if ( troco == 0 )
    { 
		printf("Valor de pagamento justo, sem troco!!\n");
        return 0;
	}

    printf("Troco R$%.2f\n", troco);
    
    calculodineiro(troco, atr);

    mostradineiro(atr);

    return 0;
}


//Função que calcula o valor do troco
float calculatroco( float deuda, float pago)
{ 
    
    return (roundf((pago - deuda)* 100) / 100); 

}


void calculodineiro(float troc, int* tr) 
{
    int i;

    for (i=0 ; i <= 10; i++)
    {
        tr[i]=0;    
    }

    //cédulas de R$ 100,00, R$ 50,00, R$ 20,00, R$ 10,00, R$ 5,00 e R$ 2,00
    while ( troc >= 100 )
    {
        troc = troc - 100;
        tr[0]++;
    }
    
    if ( troc >= 50 )
    {
        troc = troc - 50;
        tr[1]++;
    }

    while ( troc >= 20 )
    {
        troc = troc - 20;
        tr[2]++;
    } 

    if ( troc >= 10 )
    {
        troc = troc - 10;
        tr[3]++;
    }
    
    if ( troc >= 5 )
    {
        troc = troc - 5;
        tr[4]++;
    }

    while ( troc >= 2 )
    {
        troc = troc - 2;
        tr[5]++;
    } 

    //moedas de R$ 1,00, R$ 0,50, R$ 0,25, R$ 0,10, R$ 0,05

    if ( troc >= 1 )
    {
        troc = troc - 1;
        tr[6]++;
    }

    if ( troc >= 0.50 )
    {
        troc = troc - 0.5;
        tr[7]++;
    }

    if ( troc >= 0.25 )
    {
        troc = troc - 0.25;
        tr[8]++;
    }

    while ( troc >= 0.099 )
    {
        troc = troc - 0.10;
        tr[9]++;
    }

    if ( troc < 0.099 && troc > 0.03)
    {
        troc = troc - 0.05;
        tr[10]++;
    }

}

void mostradineiro(int* tr)
{
    int i;
    
       for (i=0 ; i <= 10; i++)
    {
        if (tr[i] != 0)
        {
            switch(i)
            {
            case 0:
                printf("%d X R$ 100,00\n", tr[i]);
                break;
            case 1:
                printf("%d X R$ 50,00\n", tr[i]);
                break;
            case 2:
                printf("%d X R$ 20,00\n", tr[i]);
                break;
            case 3:
                printf("%d X R$ 10,00\n", tr[i]);
                break;
            case 4:
                printf("%d X R$ 5,00\n", tr[i]);
                break;
            case 5:
                printf("%d X R$ 2,00\n", tr[i]);
                break;
            case 6:
                printf("%d X R$ 1,00\n", tr[i]);
                break;
            case 7:
                printf("%d X R$ 0,50\n", tr[i]);
                break;
            case 8:
                printf("%d X R$ 0,25\n", tr[i]);
                break;
            case 9:
                printf("%d X R$ 0,10\n", tr[i]);
                break;
            case 10:
                printf("%d X R$ 0,05\n", tr[i]);
                break;
            default:
                printf("Error! Tipo de moeda desconhecida");
            }
        }
    }
}