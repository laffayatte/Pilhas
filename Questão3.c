#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Thiago Rodrigo Monteiro Salgado#


//structs
typedef struct dataNode{


    float id;


}DataNode;



typedef struct node{

    DataNode data;
    struct node* next;


}Node;



typedef struct fila{

    int size;
    Node* head;

}Fila;

//funcoes

bool isEmpty(Fila *fila){ //verifica se a filaa e vazia

    return(fila->size ==0);

}

void printfila(Fila* fila){ //imprime a filaa


    Node *pointer = fila->head;
    if(fila->size == 0){
        printf("*");
    }else{
        //printf(" \nsua fila de elementos: \n\n");
        while(pointer != NULL){
            printf(" %.1f ", pointer->data.id);
            pointer = pointer->next;
        }


    }




    printf("\n");


}
void push(Fila *fila, DataNode data){ // cria o elementoda filaa

    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = fila->head;
    fila->head = node;
    fila->size++;

}



Fila* createfila(){ //cria a filaa

    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila -> size = 0;
    fila -> head = NULL;

    return fila;

}

void pop(Fila *fila){ //retira um item da fila

    if(!isEmpty(fila)){
        Node * pointer = fila -> head;
        fila -> head = pointer -> next;
        free(pointer);
        fila->size--;
        }
}
Node *atPos(Fila *fila, int index){ //devolve o que tem na posicao que eu peço

    if(index >= 0 && index < fila->size){
        Node *node = fila -> head;
        int i;
        for(i = 0; i < index; i++)
            node = node->next;


        return node;
    }
    printf(" [  indice invalido  ]\n");
    return NULL;
}






int comprimento(Fila *fila){

    Node* pointer = atPos(fila, 0);
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

void insert_fim(Fila *fila, DataNode data){

     Node* novo = (Node*)malloc(sizeof(Node));
     novo->next = NULL;

     if(fila->size == 0){
        fila->head = novo;
        novo->data = data;
     }else{
      Node *tmp = fila->head;
      novo->data = data;


      while(tmp->next != NULL)
       tmp = tmp->next;

      tmp->next = novo;
     }
     fila->size++;
}

Fila* merge(Fila* fila1, Fila* fila2){

    Node* t1 = fila1->head;
    Node* a1 = fila2->head;

    Node* t2 = fila1->head->next;
    Node* a2 = fila2->head->next;

    while((t2!=NULL) && (a2!= NULL)){

        t1->next = a1;
        a1->next = t2;
        t1 = t2;
        t2 = t2->next;
        a1 = a2;
        a2 = a2->next;


    }

    t1->next = a1;
    if(a2 == NULL){
        a1->next = t2;

    }

    fila2->head = NULL;

    printfila(fila1);


}
