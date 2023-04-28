/****************************************************************************
 * Data Versao: Abril 2023
 Responsavel: Daniel Abratte
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void cargalista(
    int arr[],
    int quantidade);

void printarray(
    int arr[],
    int q);

void swapElements(
    int* x,
    int* y);

int partition (
    int arr[],
    int lowIndex,
    int highIndex);

void quickSort(
    int arr[],
    int lowIndex,
    int highIndex);

int agrupa(
    int arr[],
    int quantidade);

int main()
{
    
    int n, i, q = 0;
    int *lista;

    // Solicita a quantidade de elementos da lista
    printf("Insira a quantidade de numeros da lista \n", i);
    i = scanf("%d", &q);

    //Valida se o valor que é um valor valido
    if ( i == 0) 
    {
        printf("Ingrese un numero valido");
        return 1;
    } 
    
    //Aloca memoria para o array lista
    lista = (int*)malloc(q * sizeof(int));

    //Chamada a função cargalista para completar o array lista
    cargalista(lista, q);

    printf("Lista inserida : ");
    printarray(lista, q);

    quickSort(lista, 0, q-1); 

    printf("\nSaida Agrupada : ");
    agrupa(lista, q);

    //libera memoria do array lista
    free(lista);
    lista = NULL;
    
    return 0;
}

//Função cargalista para completar o array lista
void cargalista(int arr[], int quantidade) 
{ 
    int i; 
    for(i = 0; i < quantidade; i++)
        {
            printf("Insira o valor para a posicao: %d ", i);
            scanf("%d", &arr[i]);
        }
}

//Função que imprime o array
void printarray(int arr[], int quantidade) 
{ 
    int i; 
    for(i = 0; i < quantidade; i++)
    {
        printf(" %d", arr[i]);
    }
}

//Função que faz swap dos elementos, usada pela função partition
void swapElements(int *x, int *y)
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}   

// Função Partition usada pela função quickSort
int partition (int arr[], int lowIndex, int highIndex) 
{ 
    int pivotElement = arr[highIndex];
	int i = (lowIndex - 1); 
	int j;

    for ( j = lowIndex; j <= highIndex- 1; j++) 
	{ 
		if (arr[j] <= pivotElement) 
		{ 
			i++; 
			swapElements(&arr[i], &arr[j]); 
		} 
	} 
	swapElements(&arr[i + 1], &arr[highIndex]); 

	return (i + 1); 
}   

// Função quickSort, para ordenar o array
void quickSort(int arr[], int lowIndex, int highIndex) 
{ 
	int pivot;

    if (lowIndex < highIndex) 
	{ 
		pivot = partition(arr, lowIndex, highIndex); 
		// Separately sort elements before & after partition 
		quickSort(arr, lowIndex, pivot - 1); 
		quickSort(arr, pivot + 1, highIndex); 
	} 
} 

//Função que agrupa os numeros da lista
int agrupa(int arr[], int quantidade)
{
    int i = 0, valor_ini, valor_fim;

    while (i < quantidade) {
        valor_ini = arr[i];
        i++;

        while (( arr[i] == (arr[i-1] + 1) ) && i < quantidade ) 
            i++;
       
        valor_fim = arr[i-1];

        if (valor_ini < valor_fim) {
            printf(" [%d-%d]", valor_ini, valor_fim);
        }
        else {
            printf(" [%d]", valor_ini);  
        }

    }

    return 0;
}