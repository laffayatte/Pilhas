#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct pilha{

    float item[MAXTAM];
    int topo;

}Tpilha;

void pilha_cria(Tpilha *p){

    p->topo = 0;
    p->item[0] = -10;
}
int pilha_vazia(Tpilha *p){

    if(p->topo == -1){
        return 1;

    }else{
        return 0;
    }

}

int pilha_cheia(Tpilha *p){

    if(p->topo == MAXTAM -1){
        return 1;
    }else{
        return 0;
    }

}

void pilha_pop(Tpilha *p, float x){

    if(pilha_cheia(p)==1){
        printf("a pilha ja esta cheia\n");

    }else if(p->item[0] ==  (-10)){

        p->item[p->topo] = x;
        p->topo++;

    }else{
        p->topo++;
        p->item[p->topo - 1] = x;

    }

}

Tpilha *pilha_libera(Tpilha *v){

Tpilha* v2 = (Tpilha*)malloc(sizeof(Tpilha));

    for(int i = 0; i < v->topo + 1; i++){

        v2->item[i] = v->item[i];

    }
    for(int i = 0; i < v->topo + 1; i++){

        v->item[i] = -10;

    }
    for(int i = 0; i < v->topo; i++){

        v->item[i] = v2->item[i];

    }
    v->topo = v->topo - 1;
    printf("\n");
}

void print_pilha(Tpilha *p){

   if(p->topo == 0){
		printf("*");
	}

    
	for(int i = p->topo -1; i >=0; i--){

        printf("%.2f ",p->item[i] );
        printf("\n");

    }

    printf("\n");

}


int main(){


    Tpilha* v = (Tpilha*)malloc(sizeof(Tpilha));
    pilha_cria(v);

    int operacoes;
    float elemento;
    int alternativa;
    scanf("%d", &operacoes);


    for(int i = 0; i< operacoes; i++){
    scanf("%d", &alternativa);
    switch(alternativa){

        case 1:
            scanf("%f", &elemento);
            pilha_pop(v, elemento);
        break;

        case 0:
            pilha_libera(v);
			 break;
    }
}




    print_pilha(v);


}