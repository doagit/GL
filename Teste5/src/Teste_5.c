/****************************************************************************
 * Data Versao: Maio 2023
 Responsavel: Daniel Abratte
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2 * (2) = 4 => nro primo proximo = 5 
#define TAM_HT 5

//INI structs

// struct para os dados de cada item de fatura
typedef struct itens_fatura{
    int idFatura;
    int idItem;
    float valorItem;
    char desc_item[30];
    struct itens_fatura* prox;
} ItensFatura;

// struct para os dados de cada imposto de item de fatura
typedef struct ItensFaturaImp {
    int idFatura;
    int idItem;
    float valorImposto;
    char imposto[10];
    struct ItensFaturaImp* prox;
} ItensFaturaImp;

//struct no de lista de saida
typedef struct no {
    int id_fatura;
    int id_item;
    float valor_item;
    char desc_item[30];
    char imposto[10];
    float valor_imposto;
    struct no* prox;
} no;

//struct para tabela 
typedef struct tabhash{
    no *pno;
    int tam;
}tabhash;

//FIM structs

//Ini Declaracao funçoes
int funcaoHash(
    int idf, 
    int idi);

void inicializarTabela(
    tabhash t[]);

void inserir(
    tabhash t[],
    ItensFatura itf,
    ItensFaturaImp ifi);

void buscanatabela(
    tabhash t[],
    ItensFaturaImp itfi);

void imprime_tabela(
    tabhash t[]);

void inicializaLista(
    tabhash *t);

void inserir_na_lista(
    tabhash *l, 
    ItensFatura itf,
    ItensFaturaImp ifi,
    int valor);

void updatelista(
    tabhash *l,
    ItensFaturaImp ifi);

void imprime_lista(
    tabhash *l,
    int pos);

void lerarquivo(
    tabhash* tabela,
    char* nomeArquivo);
//Fim Declaracao de funçoes

//main
int main(){
    char* arquivo;
    tabhash tabela[TAM_HT];
    
    inicializarTabela(tabela);
    imprime_tabela(tabela);
    arquivo = "itensFatura.csv";
    lerarquivo(tabela, arquivo);

    arquivo = "ItensFaturaImpostos.csv";
    lerarquivo(tabela, arquivo);
    
    imprime_tabela(tabela);
}

//Funcao Hash com chave composta
int funcaoHash(int idf, int idi) {
    return ((idf + idi) % TAM_HT);
}

//Ini Funcoes para tabela
//Funcao que por cada item da tabela inicializa a lista
void inicializarTabela(tabhash t[]){
    int i;
    for(i = 0; i < TAM_HT; i++)
        inicializaLista(&t[i]);
}

//Funcao para inserir elemento na tabela hash
void inserir(tabhash t[], ItensFatura itf, ItensFaturaImp ifi){
    int indice = funcaoHash(itf.idFatura, itf.idItem);
    inserir_na_lista(&t[indice], itf, ifi, indice);
}


//Funcao para realizar uma busca na tabela.
void buscanatabela(tabhash t[], ItensFaturaImp itfi){
    int indice = funcaoHash(itfi.idFatura, itfi.idItem);
    updatelista(&t[indice], itfi);
}

//Funcao para imprimir  a tabela
void imprime_tabela(tabhash t[]){
    int i;
    for(i = 0; i < TAM_HT; i++){
        imprime_lista(&t[i], i);
    }
}

//Fim Funcoes para tabela

//Ini Funcoes para lista
//Funcao para inicializar cada lista da tabela
void inicializaLista(tabhash *t){
    t->pno = NULL;
    t->tam = 0;
}

// Funcao para inserir um elemento no início na lista recebida como parâmetro
void inserir_na_lista(tabhash *l, ItensFatura item, ItensFaturaImp ifi, int valor){
    no *novo = malloc(sizeof(no));

    if(novo){
        novo->id_fatura = item.idFatura;
        novo->id_item = item.idItem;
        novo->valor_item = item.valorItem;
        strcpy(novo->desc_item, item.desc_item);
        novo->prox = l->pno;
        l->pno = novo;
        l->tam++;
    }
    else 
        printf("\n\tErro ao alocar memoria!\n");

}

// Função para buscar elemento de itensFatura na lista
void updatelista(tabhash *l, ItensFaturaImp ifi){
    int idfac;
    int iditem;
    float vitem;
    char ditem[30];
    
    no *aux = l->pno;
    while(aux && aux->id_fatura != ifi.idFatura && aux->id_item != ifi.idItem)
        aux = aux->prox;
    if(aux) {
        if (( strcmp(aux->imposto, "ISS") != 0 ) || ( strcmp(aux->imposto,"PIS") != 0 ))
        {
            if ((strcmp(ifi.imposto, "ISS") == 0 ) && (strcmp(aux->imposto,"PIS") == 0 )) {

                if ( aux->prox == NULL ) { // Elemento no final da lista
                    no* novo = (no*)malloc(sizeof(no));
                    novo->id_fatura = aux->id_fatura;
                    novo->id_item = aux->id_item;
                    novo->valor_item = aux->valor_item;
                    strcpy(novo->desc_item, aux->desc_item);
                    strcpy(novo->imposto, ifi.imposto);
                    novo->valor_imposto = ifi.valorImposto;
                    aux->prox = novo;
                } else {
                    no* novo = (no*)malloc(sizeof(no));
                    novo->id_fatura = aux->id_fatura;
                    novo->id_item = aux->id_item;
                    novo->valor_item = aux->valor_item;
                    strcpy(novo->desc_item, aux->desc_item);
                    strcpy(novo->imposto, ifi.imposto);
                    novo->valor_imposto = ifi.valorImposto;
                    novo->prox = aux->prox;
                    aux->prox = novo;
                }
            }
            else if ((strcmp(ifi.imposto, "PIS") == 0 ) && (strcmp(aux->imposto,"ISS") == 0 )) {

                if ( aux->prox == NULL ) { // Nodo no final da lista
                    no* novo = (no*)malloc(sizeof(no));
                    novo->id_fatura = aux->id_fatura;
                    novo->id_item = aux->id_item;
                    novo->valor_item = aux->valor_item;
                    strcpy(novo->desc_item, aux->desc_item);
                    strcpy(novo->imposto, ifi.imposto);
                    novo->valor_imposto = ifi.valorImposto;
                    aux->prox = novo;
                }
                else {
                    no* novo = (no*)malloc(sizeof(no));
                    novo->id_fatura = aux->id_fatura;
                    novo->id_item = aux->id_item;
                    novo->valor_item = aux->valor_item;
                    strcpy(novo->desc_item, aux->desc_item);
                    strcpy(novo->imposto, ifi.imposto);
                    novo->valor_imposto = ifi.valorImposto;
                    novo->prox = aux->prox;
                    aux->prox = novo;                       
                }

            } 
            else if (strcmp(aux->imposto, ifi.imposto) == 0 ) {
                
                if (aux->valor_imposto != ifi.valorImposto) {
                    
                    no* novo = (no*)malloc(sizeof(no));
                    novo->id_fatura = aux->id_fatura;
                    novo->id_item = aux->id_item;
                    novo->valor_item = aux->valor_item;
                    strcpy(novo->desc_item, aux->desc_item);
                    strcpy(novo->imposto, ifi.imposto);
                    novo->valor_imposto = ifi.valorImposto;
                    novo->prox = aux->prox;
                    aux->prox = novo;     
                } 
                else 
                    printf("Imposto registrado!");

            }
            else {
                strcpy(aux->imposto, ifi.imposto);
                aux->valor_imposto = ifi.valorImposto;
            }
            
        } 
    } 
    else
        printf("\n\tElemento nao encontrado na lista!\n");
}

// Funcao para imprimir a lista
void imprime_lista(tabhash *l, int pos){
    no *aux = l->pno;
    if ( aux ) {
        printf("\nHASH OF KEYS -POS: %i\n", pos);
        while(aux){
            printf("\t\tid_fatura %d ;\n", aux->id_fatura);
            printf("\t\tid_item %d ;\n", aux->id_item);
            printf("\t\tvalor_item %.2f ;\n", aux->valor_item);
            printf("\t\tdesc_item %s ;\n", aux->desc_item);
            printf("\t\timposto %s ;\n", aux->imposto);
            printf("\t\tvalor_imposto %.2f\n", aux->valor_imposto);
            printf("\n");
            aux = aux->prox;
        }
    }
}

//Fim Funcoes para lista

//Ini funcao ler arquivos
//Funcao para ler arquivo de itensfatura
void lerarquivo(tabhash* tabela, char* nomeArquivo) {
    char* campo;
    ItensFatura* item;
    char* arqitensf = "itensFatura.csv";

    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo %s\n", nomeArquivo);
        return;
    }
    char linha[1024];
     // descarta as primeiras duas linhas (cabeçalho)
    fgets(linha, 1024, arquivo);
    fgets(linha, 1024, arquivo);

    if (strcmp(arqitensf, nomeArquivo) == 0){
        ItensFaturaImp ifi;
        while (fgets(linha, 1024, arquivo)) {
            item = (ItensFatura*)malloc(sizeof(ItensFatura));
            campo = strtok(linha, ";");
            item->idFatura = atoi(campo);
            campo = strtok(NULL, ";");
            item->idItem = atoi(campo);
            campo = strtok(NULL, ";");
            item->valorItem = atof(campo);
            campo = strtok(NULL, ";");
            strtok(campo, "\n");
            strcpy(item->desc_item, campo);
            inserir(tabela, *item, ifi);
        }
    } else {
        while (fgets(linha, 1024, arquivo)) {
            ItensFaturaImp * itfi = (ItensFaturaImp*)malloc(sizeof(ItensFaturaImp));
            campo = strtok(linha, ";");
            itfi->idFatura = atoi(campo);
            campo = strtok(NULL, ";");
            itfi->idItem = atoi(campo);
            campo = strtok(NULL, ";");
            strcpy(itfi->imposto, campo);
            campo = strtok(NULL, ";");
            itfi->valorImposto = atof(campo);
            buscanatabela(tabela, *itfi);
        }
    }
    
    fclose(arquivo);
}   

//Fim funcao ler arquivos


