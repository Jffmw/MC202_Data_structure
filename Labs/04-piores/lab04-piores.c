#include <stdio.h>
#include <string.h>


double main() {
    
    int N_palavras, N_desculpas;
    char palavras[N_palavras][101], desculpas[N_desculpas][101];

    int i;
    

    while (scanf("%d %d",&N_palavras,&N_desculpas) != EOF)
    {
        printf("os numeros são %d %d\n", N_palavras, N_desculpas);
        
        // recebendo palavras chave
        printf("recebendo as palavras chave\n");
        for (i = 0; i < N_palavras; i++)
        {   
            printf("%d\n", i);
            scanf(" %s", palavras[i]);
        }

        for (i = 0; i < N_palavras; i++)
        {   
            printf(">%s<\n", palavras[i]);
        }

        printf("recebendo as desculpas\n");
        for (i = 0; i < N_desculpas; i++)
        {   
            printf("%d\n", i);
            scanf(" %[^\n]", desculpas[i]);

        }

        for (i = 0; i < N_desculpas; i++)
        {   
            printf(">%s<\n", desculpas[i]);
        }

        printf("\n acabou um while\n");
    }

    printf("saiu do while\n");
    for (i = 0; i < N_desculpas; i++)
        {   
            printf(">%s<\n", desculpas[i]);
        }

    return 0;
}
