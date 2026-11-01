#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    //Dados da aplicacao.Ex: PRODUTO
    int cod;

    //mecanismo para unir um nó em outro!
    struct NO * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void adicionar(int cod){

        // 1- construir o no!

        NO * novo = malloc(sizeof(NO));
        novo->cod = cod;

        novo->prox = NULL;

        //2 - como encaixar o no na lista!

        if(inicio == NULL){ //fila esta vazia
            inicio = novo;
            fim = novo;
        }else{ //fila nao esta vazia
            fim->prox = novo;
            fim = novo;
        }
        tam++;

}

void reorganizarEntregas(){
    if (tam < 1){
        return;
    }

    NO *ini_impar = NULL;
    NO *ini_par = NULL;
    NO *fim_impar = NULL;
    NO *fim_par = NULL;

    NO *atual = inicio;

    while(atual != NULL){
        NO *prox_no = atual->prox;
        atual->prox = NULL;

        if(atual->cod % 2 != 0){
            if(ini_impar == NULL) {
                ini_impar = atual;
            } else {
                fim_impar->prox = atual;
            }
            fim_impar = atual;
        } else {
            if(ini_par == NULL) {
                ini_par = atual;
            } else {
                fim_par->prox = atual;
            }
            fim_par = atual;
        }
        atual = prox_no;
    }

    if(ini_impar != NULL){
        inicio = ini_impar;
        fim_impar->prox = ini_par;
        fim = (ini_par != NULL) ? fim_par : fim_impar;
    } else {
        inicio = ini_par;
        fim = fim_par;
    }
}


void imprimir(){
    NO *aux = inicio;
    for(int i = 0; i< tam; i++){
        printf("------ DADOS DO PRODUTO ----- \n");
        printf("Codigo: %d\n", aux->cod);
        printf("--------------------------- \n");
        aux = aux->prox;
    }

}

int remover(){
    int cod = 0;
    if(tam > 0){
        NO *lixo = inicio;
        inicio = inicio->prox;
        cod = lixo->cod;
        free(lixo);
        tam--;
    }
    return cod;
}

int main(){
    adicionar(12);
    adicionar(7);
    adicionar(4);
    adicionar(9);
    adicionar(16);
    adicionar(3);
    adicionar(8);


    printf("Antes de organizar\n");
    imprimir();
    reorganizarEntregas();
    printf("Depois de organizar\n");
    imprimir();
    //int pos = 3;
   // printf("\nA posicao %d foi removida e continha o produto: %s.\n", pos, remover(pos));

    return 0;
 }




