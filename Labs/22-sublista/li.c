#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "li.h"


list* l_alloc() {
    list* L = malloc(sizeof(list));
    
    if (!L) 
    {
        printf("sem memória para list\n");
        return NULL;
    }

    L->head = NULL;
    L->size = 0;

    return L;
}



void l_free(list* L) {
    node* p = L->head;

    while (p != NULL)
    {
        node* q = p->next; // guarda referencia para o próximo elemento 
        free(p);           // libera memória do node apontado por p
        p = q;             // faz p apontar para o próximo node 
    }
    
}



int l_insert_head(list* L, int data) {

    node* p = malloc(sizeof(node));
    if (!p) {
        printf("sem memória para node adicional\n");
        return 0;
    }
    
    p->data = data;
    p->next = L->head;
    
    L->head = p;
    L->size++;

    return 0;
}



int l_insert_tail(list* L, int data) {

    node* p = malloc(sizeof(node));
    if (!p) {
        printf("sem memória para node adicional\n");
        return 0;
    }
    
    p->data = data;
    p->next = NULL;
    
    node* q = L->head;

    if (L->size == 0)
    {
        l_insert_head(L, data);
        return 0;
    }
    

    while (q->next != NULL)
    {
        q = q->next;
    }

    q->next = p;

    L->size++;
    
    return 0;
}



list* l_sublist(list* L, int inicio, int fim) {
 
    list* B = l_alloc();
    node* p = L->head;
    
    for (int i = 0; p != NULL; i++) {

        if (inicio <= fim)
        {
            if (i >= inicio && i <= fim)
            {
                l_insert_tail(B, p-> data);
            }
            
        } else {
            if (i >= fim && i <= inicio)
            {
                l_insert_head(B, p->data);
            }
                
        }
    
        p = p->next;
    }

    return B;
}



int l_insert_sub(list* L,list* B, int posicao) {
    
    node* q = L->head;

    node* p = B->head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    if (posicao != 0)
    {
        for (int i = 0; i < posicao-1; i++)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = B->head;
    }
    else
    {
        p->next = L->head;
        L->head = B->head;
        
    }

    return 0;
}



void l_print(list* L) {

    node* p = L->head;

    printf("A: { ");
    while (p != NULL)
    {   
        if (p->next == NULL)
        {
            printf("%d ",p->data);
        }
        else
        {
            printf("%d, ",p->data);
        }
    
        p = p->next;
    }
    printf("}");
    printf("\n");

}