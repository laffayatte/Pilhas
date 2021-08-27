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

    Fila fila = (Fila)malloc(sizeof(Fila));

    fila -> size = 0;
    fila -> head = NULL;

    return fila;

}

void pop(Fila *fila){ //retira um item da filaa

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

     Node novo = (Node)malloc(sizeof(Node));
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

    //printf("lista 1: ");
    //printList(list1);

    //printf("lista 2: ");
    //printList(list2);

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


    //printf("lista merge: ");
    printfila(fila1);


}


int main(){






    Fila *fila1 = createfila(); //criando a filaa encadeada
    DataNode data1; //iniciando elemento da filaa;
    Fila *fila2 = createfila(); //criando a filaa encadeada
    DataNode data2; //iniciando elemento da filaa;

    int tam;
    //printf("digite o tamanho da sua pilha: ");
    /*scanf("%d", &tam);


	//printf("\n\tdigite os elementos da sua primeira pilha \n\n");

    for(int i =0; i < tam; i++){
        //printf("elemento: [%d] \e ", i);
        scanf("%f", &data1.id);
        insert_fim(fila1, data1);
    }



	//printf("digite o tamanho da sua segunda pilha: ");
    scanf("%d", &tam);


	//printf("\n\tdigite os elementos da sua segunda pilha \n\n");

    for(int i =0; i < tam; i++){
        //printf("elemento: [%d] \e ", i);
        scanf("%f", &data2.id);
        insert_fim(fila2, data2);
    }*/

    char valid[20];
    int ok = 0;


    while((scanf("%f", &data1.id))!= 0){

        insert_fim(fila1, data1);

    }

    while((scanf("%f", &data2.id))!= 0){

        insert_fim(fila2, data2);

    }


    while (1) {
        //printf ("Entre com o elemento: ");
        scanf("%s",&valid);
        if (sscanf (valid, "%f", &data1.id) != 1)
        {
            break;
        }
        else
        {
            insert_fim(fila1,data1);
        }
    };


    while (1) {
        //printf ("Entre com o elemento: ");
        scanf("%s",&valid);
        if (sscanf (valid, "%f", &data2.id) != 1)
        {
            break;
        }
        else
        {
            insert_fim(fila2,data2);
        }
    };


    //printfila(fila1);
    //printfila(fila2);

	merge(fila1, fila2);











}