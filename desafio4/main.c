#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    char *senha;

    //mecanismo para unir um nó em outro!
    struct NO * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void adicionar(char *senha){

        // 1- construir o no!

        NO * novo = malloc(sizeof(NO));
        novo->senha = senha;

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
        printf("------ SENHA ----- \n");
        printf("Direcao: %s\n", aux->senha);
        printf("--------------------------- \n");
        aux = aux->prox;
    }

}

char remover(){
    char *senha = "";
    if(tam > 0){
        NO *lixo = inicio;
        inicio = inicio->prox;
        senha = lixo->senha;
        free(lixo);
        tam--;
    }
    return *senha;
}
int simplificarTrajeto(){
    int trajetosEliminados = 0;
    int houveRemocao = 1;

    while(houveRemocao){
        houveRemocao = 0;
        NO *atual = inicio;
        NO *anterior = NULL;

        while(atual != NULL && atual->prox != NULL){
            char *m1 = atual->senha;
            char *m2 = atual->prox->senha;

            if((m1=="A" && m2=="B") || (m1=="B" && m2=="A") || (m1=="C" && m2=="D") || (m1=="D" && m2=="C")){
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
                tam -=2;
                break;
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
        }
    }

    if(tam == 0){
        printf("COFRE DESBLOQUEADO\n");
    }
    return trajetosEliminados;
}

int main(){
    adicionar("A");
    adicionar("B");
    adicionar("C");
    adicionar("D");
    //adicionar("C");
    //adicionar("A");

    int trajetosEliminados = simplificarTrajeto();
    printf("\nForam eliminados %d caracteres\n", trajetosEliminados);
    imprimir();

    return 0;
 }




