#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "li.h"


int main() {

    list* A = l_alloc();

    int data;
    char entrada;

    // recebendo a lista A e seus valores iciais 
    scanf("%c = {", &entrada);
    while (scanf("%d,", &data) == 1)
    {
        l_insert_tail(A,data);
    }

    while (scanf("%c", &entrada) != EOF)
    {

        if (entrada == 'f')
        {
            exit(1);


        } else if (entrada == 's') 
        {
            int inicio, fim;
            scanf(" A[%d..%d]", &inicio, &fim);

            list* F = A;

            A = l_sublist(A, inicio, fim);
            
            l_free(F); 


            l_print(A);

        } else if (entrada == '+')
        {
            list* B = l_alloc();
            
            int inicio, fim, posicao;
            scanf(" A[%d..%d]", &inicio, &fim);
            B = l_sublist(A,inicio,fim);

            scanf(" %d", &posicao);
            l_insert_sub(A, B, posicao);

            l_print(A);
        }
        
        
    }
    
        
            
    return 0;
}