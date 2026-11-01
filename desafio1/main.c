#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    int cod_cliente;
    int cod_produto;
    int qtd;

    struct NO * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void adicionar(int cod_cliente, int cod_produto, int qtd){

        NO * novo = malloc(sizeof(NO));
        novo->cod_cliente = cod_cliente;
        novo->cod_produto = cod_produto;
        novo->qtd = qtd;

        novo->prox = NULL;

        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else{
            fim->prox = novo;
            fim = novo;
        }
        tam++;

}

void imprimir(){
    NO *aux = inicio;
    for(int i = 0; i< tam; i++){
        printf("------ DADOS DO PRODUTO ----- \n");
        printf("Codigo cliente: %d\n", aux->cod_cliente);
        printf("Codigo produto : %d\n", aux->cod_produto);
        printf("Quantidade : %d\n", aux->qtd);
        printf("--------------------------- \n");
        aux = aux->prox;
    }

}

int remover(){
    int cod_produto = 0;
    if(tam > 0){
        NO *lixo = inicio;
        inicio = inicio->prox;
        cod_produto = lixo->cod_produto;
        free(lixo);
        tam--;
    }
    return cod_produto;
}

void consolidarPedidos(){
    NO *atual = inicio;
    while(atual != NULL){
        NO *aux = atual;

        while(aux->prox != NULL){
            if(atual->cod_cliente == aux->prox->cod_cliente && atual->cod_produto == aux->prox->cod_produto){
                atual->qtd += aux->prox->qtd;
                NO * lixo = aux->prox;
                aux->prox = aux->prox->prox;
                free(lixo);
                tam--;
            }else{
                aux = aux->prox;
            }

        }
        atual = atual->prox;
    }


}


int main(){
    adicionar(10, 101, 2);
    adicionar(20, 202,3);
    adicionar(10,101, 4);
    adicionar(30,303,1);
    adicionar(20,202,2);
    adicionar(10, 101, 2);
    adicionar(20, 202,3);
    adicionar(10,101, 4);
    adicionar(30,303,1);
    adicionar(20,202,2);

    consolidarPedidos();

    imprimir();

    return 0;
 }




