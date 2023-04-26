/****************************************************************************
 * Data Versao: Abril 2023
 Responsavel: Daniel Abratte
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
     
//declaro a função validateNumber()
int validateNumber(int num);   
        
int main(int argc, char *argv[ ]) 
{    
    int numero = 0;
    int resultado;

    numero = atoi(argv[1]); // Converte o argumento recevedo para inteiro
    resultado = numero;

    while(resultado != 1 && resultado != 4){
        resultado = validateNumber(resultado);    
    }    
        
    //Caso resultado = 1, é Happy Number   
    if(resultado == 1)    
        printf("%d E um numero feliz", numero);    
    //Caso não seja happy number, o ciclo da função validateNumber vai conter o numero 4
    else if(resultado == 4)    
        printf("%d Nao e um numero feliz \n", numero);     
     
    return 0;    
}

//Função validateNumber() Esta função verifica se é um Happy Number
int validateNumber(int num){    
    int resto = 0, acum = 0;    
        
    while(num > 0){  
        resto = num%10;                //Resto da divisão, para obter o ultimo digito de num
        acum = acum + pow(resto,2);    //acumula o quadrado de resto
        num = num/10;                  //Para remover 1 digito da variable num 
    }    
    return acum;    
}    