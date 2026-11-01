#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    char *direcao;

    //mecanismo para unir um nó em outro!
    struct NO * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void adicionar(char *direcao){

        // 1- construir o no!

        NO * novo = malloc(sizeof(NO));
        novo->direcao = direcao;

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

void imprimir(){
    NO *aux = inicio;
    for(int i = 0; i< tam; i++){
        printf("------ DIRECAO ----- \n");
        printf("Direcao: %s\n", aux->direcao);
        printf("--------------------------- \n");
        aux = aux->prox;
    }

}

char remover(){
    char *direcao = "";
    if(tam > 0){
        NO *lixo = inicio;
        inicio = inicio->prox;
        direcao = lixo->direcao;
        free(lixo);
        tam--;
    }
    return *direcao;
}
int simplificarTrajeto(){
    int trajetosEliminados = 0;
    int houveRemocao = 1;

    while(houveRemocao){
        houveRemocao = 0;
        NO *atual = inicio;
        NO *anterior = NULL;

        while(atual != NULL && atual->prox != NULL){
            char *m1 = atual->direcao;
            char *m2 = atual->prox->direcao;

            if((m1=="N" && m2=="S") || (m1=="S" && m2=="N") || (m1=="O" && m2=="L") || (m1=="L" && m2=="O")){
                NO *lixo1 = atual;
                NO *lixo2 = atual->prox;
                if(anterior == NULL){
                    inicio = lixo2->prox;
                }
                else{
                    anterior->prox = lixo2->prox;
                }
                free(lixo1);
                free(lixo2);
                trajetosEliminados+=2;
                houveRemocao=1;
                break;
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
        }
    }
    return trajetosEliminados;
}

int main(){
    adicionar("N");
    adicionar("L");
    adicionar("O");
    adicionar("S");
    adicionar("N");
    adicionar("L");

    int trajetosEliminados = simplificarTrajeto();
    printf("%d", trajetosEliminados);
    imprimir();

    return 0;
 }




