#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct dataNode{


    float id;


}DataNode;



typedef struct node{

    DataNode data;
    struct node* next;


}Node;



typedef struct pilha{

    int size;
    Node* head;

}Pilha;

bool isEmpty(Pilha *pilha){ //verifica se a pilhaa e vazia

    return(pilha->size ==0);

}

void printpilha(Pilha* pilha){ //imprime a pilhaa


    Node *pointer = pilha->head;
    if(pilha->size == 0){
        printf("*");
    }else{
    
        while(pointer != NULL){
            printf("%.2f\n", pointer->data.id);
            pointer = pointer->next;
        }


    }
    printf("\n");
}
void push(Pilha *pilha, DataNode data){ // cria o elementoda pilhaa

    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = pilha->head;
    pilha->head = node;
    pilha->size++;
}



Pilha* createpilha(){ //cria a pilhaa

    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));

    pilha -> size = 0;
    pilha -> head = NULL;

    return pilha;

}

void pop(Pilha *pilha){ //retira um item da pilhaa

    if(!isEmpty(pilha)){
        Node * pointer = pilha -> head;
        pilha -> head = pointer -> next;
        free(pointer);
        pilha->size--;
        }
}
Node *atPos(Pilha *pilha, int index){ //devolve o que tem na posicao que eu peço

    if(index >= 0 && index < pilha->size){
        Node *node = pilha -> head;
        int i;
        for(i = 0; i < index; i++)
            node = node->next;


        return node;
    }
    printf(" [  indice invalido  ]\n");
    return NULL;
}

int comprimento(Pilha *pilha){

    Node* pointer = atPos(pilha, 0);
    if(pointer != NULL){
        Node* maxNode = pointer;
        int cont = 0;

        while(pointer != NULL){
            cont = cont + 1;
            pointer = pointer -> next;

        }
        return cont;
    }

}

void exclui_adiciona(Pilha *pilha){

    int choice;
    int operations;
    int element;
    scanf("%d", &operations);
    DataNode data_aux;

    for(int i = 0; i < operations; i++){
        scanf("%d", &choice);
        switch(choice){
        case 1:
            scanf("%f", &data_aux.id);
            push(pilha, data_aux);
        break;
        case 0:
            pop(pilha);

        }

    }
    printpilha(pilha);
}

int main(){
    Pilha *pilha = createpilha(); //criando a pilhaa encadeada
    DataNode data; //iniciando elemento da pilhaa;

    exclui_adiciona(pilha);
}