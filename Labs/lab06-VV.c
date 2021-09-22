#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* era preciso criar um programa que armazena um vetor de vetores com vetores.
chamando o vetor mais a fora de v0 temos que cada elemento de v0 é (linha l de uma matriz, quantidade de elementos em v1 = t, apontador para v1)
sendo v1 outro vetor com t vetores v2 no formato (coluna c de uma matriz, valor da posição l,c da matriz) */

int main()
{
    int n, m , k;
    scanf("%d %d %d", &n, &m, &k);

    /* para isso foi criado um vetor de structs sendo esse v0 e para cada elemento v0[i] foram colocados 
    linha; t = quantidade de v2 em v1 e um apontador que aponta para o inicio de v1 (v1 é um vetor de apontadores 
    sendo que cada v1[i] é um apontador para o incio de  cada v2) */
    typedef struct { 
        int linha;
        int t;
        int **v1;
    } Vetor_de_vetores;
    Vetor_de_vetores v0[k];
    

    // recebendo as entradas no formato "linha" "quantidade de v2 em v1" : "v1[0][0] = v2[0] = coluna","v1[0][1] = v2[1] = valor da posição linha coluna" e assim por diante
    for (int i = 0; i < k; i++) 
    {

        scanf("%d %d :", &v0[i].linha, &v0[i].t); // aqui são recebidos para cada v0[i] o valor da linha e de quantos v2's serão inseridos em v1
        
        /* quando entra a quantidade de v2 que serão entrados então é alocado dinamicamente memória para n apontadores, sendo n a quantidade de v2 que serão inseridos em v1 */
        v0[i].v1 = (int **) calloc( v0[i].t, sizeof(int *)); // assim temos que v1 será um vetor de t apontadores, cada apontador para um v2

        for (int l = 0; l < v0[i].t; l++)
        {
            v0[i].v1[l] = (int *)calloc(2,sizeof(int)); // para cada apontador alocado em v1 é alocado o espaço para um v2 sendo esse espaço de dois inteiros
        }        

        for (int j = 0; j < v0[i].t; j++)
        { 
            scanf("%d,%d", &v0[i].v1[j][0], &v0[i].v1[j][1]);
        }

    } 
    /* Depois de todo esse processo firemos com um vetor de structs chamado v0 sendo que cada v0[i] armazena um valor de linha, um valor de quantos vetores teremos em v1 e 
    um vetor de apontadores v1. Para cada v0[i] foi alocado os espaço de t apontadores em v1 e em cada v1[i] foi alocado o espaço para dois inteiros
    
    estrutura exemplo 
    v0[0] = linha = x; t = 2 ; v1 -> |v1[0]| |v1[1]|           v1 aponta para um vetor de apontadores onde cada v1[i] aponta para um vetor de tamanho 2  
                                       ↓       ↓
                                      |_|     |_|
                                      |_|     |_|
     */


    /*//printando o vetor v1 separado por linha, quantidade e vetor com coluna e valor para testar que tudo esta entrando corretamente
    for (int i = 0; i < k; i++)
    {
        printf("linha %d quantidade %d valores ", es[i].linha, es[i].t);
        for (int j = 0; j < es[i].t; j++)
        {
            printf("(%d %d)", es[i].v1[j][0], es[i].v1[j][1]);
        }
        printf("\n");
        
    }
    */
    
    int e, quant_saidas = 0;
    int **saidas;
    saidas = (int **) calloc( 0, sizeof(int *));

    while (scanf(" %lc", &e) != EOF)
    {
        if(e == 't') { break;

        } else if (e == 'p')
        {
            saidas = (int **) realloc(saidas, (quant_saidas + 1) * sizeof(int *));
            saidas[quant_saidas] = (int *)calloc(1,sizeof(int));
            saidas[quant_saidas][0] = 'p';
            quant_saidas++;

        } else if (e == 'r') 
        {    
            saidas = (int **) realloc(saidas, (quant_saidas + 1) * sizeof(int *));
            saidas[quant_saidas] = (int *)calloc(3,sizeof(int));
            saidas[quant_saidas][0] = 'r';
            scanf(" [%d,%d]", &saidas[quant_saidas][1], &saidas[quant_saidas][2]);
            quant_saidas++;

        }   
    }
    

    /* printando os valores do vetor saidas para checar se as saídas foram armazenadas corretamente
    for (int i = 0; i < quant_saidas; i++)
    {
        printf("vetor de saida %d ", i);
        if (saidas[i][0] == 'p')
            printf("saida[%d] = p\n",i);
        else if (saidas[i][0] == 'r')
            printf("saida[%d] = (%d %d %d)\n", i, saidas[i][0], saidas[i][1], saidas[i][2]);
    }
    */



    for (int i = 0; i < quant_saidas; i++)
    {
        if (saidas[i][0] == 'p')
        {
            printf("VV: ");
            for (int j = 0; j < k; j++)
            {
                for (int l = 0; l < v0[j].t; l++)
                {
                    printf("(%d,%d,%d) ", v0[j].linha, v0[j].v1[l][0], v0[j].v1[l][1]);
                }
                
            }
            printf("\n");
            
            
        }
        else if (saidas[i][0] == 'r')
        {
            int flag = 1;

            for (int j = 0; j < k; j++)
            {
                for (int l = 0; l < v0[j].t; l++)
                {
                    if (saidas[i][1] == v0[j].linha && saidas[i][2] == v0[j].v1[l][0])
                    {
                        printf("M[%d][%d] == %d\n", saidas[i][1], saidas[i][2], v0[j].v1[l][1]);
                        flag = 0;
                    }
                    
                }
            }

            if (flag)
            {
                printf("M[%d][%d] == %d\n", saidas[i][1], saidas[i][2], 0);
            }
            
        }
    }



    // Limpando a memória dos vetores que foram alocados dinamicamente
    for (int i = 0; i < k; i++)
    {
        free(v0[i].v1);
    }
    free(saidas);
    

    return 0;
}
