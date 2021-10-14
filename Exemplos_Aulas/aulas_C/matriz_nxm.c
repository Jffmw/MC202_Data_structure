//criando e printando uma matriz nxm

#include <stdio.h>

int main() 
{
    int n, m, i, j;

    scanf("%d", &n);
    scanf("%d", &m);
    
    printf("valor n %d\n", n);
    printf("valor m %d\n", m);

    int M[n][m];
    
    /* Criando a matriz nxm introduzindo cada linha i 
     * com os elementos de cada coluna separados por " "
    */
    for ( i = 0; i < n; i++ ) 
    {
        printf ("\nLinha[%d] = ", i);
        
        for ( j = 0; j < m; j++ ) 
        {
            scanf("%d", &M[i][j]);
        }    
    }

    /*  printando os elementos da matriz nxm indicando a linha e printando
     *  todos os elementos de cada linha sem pulo de linha
    */ 
    for (i=0; i < n; i++) 
    {
        printf ("\nLinha[%d] = ", i);
        for (j=0; j < m; j++) 
        {
            printf("%d ", M[i][j]);
        }
        printf("\n"); // para pular linha quando terminar a coluna
    }

    return 0;
}