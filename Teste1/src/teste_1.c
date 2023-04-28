/****************************************************************************
 * Data Versao: Abril 2023
 Responsavel: Daniel Abratte
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
     
//declaro a função validanumero()
int validanumero(int num);   
        
int main() 
{    
    int i, numero = 0;
    int resultado;

    printf("Digite o numero a validar: ");
    i = scanf("%d", &numero);

    //Valida se o valor que é um valor valido
    if ( i == 0) 
    {
        printf("Ingrese un numero valido");
        return 1;
    } 

    resultado = numero;

    while(resultado != 1 && resultado != 4){
        resultado = validanumero(resultado);    
    }    
        
    //Caso resultado = 1, é Happy Number   
    if(resultado == 1)    
        printf("%d E um Happy Number \n", numero);    
    //Caso não seja happy number, o ciclo da função validanumero vai conter o numero 4
    else if(resultado == 4)    
        printf("%d Nao e um Happy Number \n", numero);     
     
    return 0;    
}

//Função validanumero() Esta função verifica se é um Happy Number
int validanumero(int num){    
    int resto = 0, acum = 0;    
        
    while(num > 0){  
        resto = num%10;                //Resto da divisão, para obter o ultimo digito de num
        acum = acum + pow(resto,2);    //acumula o quadrado de resto
        num = num/10;                  //Para remover 1 digito da variable num 
    }    

    return acum;    
}    