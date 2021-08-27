#include <stdio.h>

int main() {
    // declaração das variáveis para criação da matriz e da soma desejada
    int n, m, i, j, s;
  
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &s);
    
    int M[n][m];
    
    /* Criando a matriz nxm introduzindo cada linha i 
     * com os elementos de cada coluna separados por " "
    */
    for ( i = 0; i < n; i++ ) 
    {
        for ( j = 0; j < m; j++ ) 
        { 
            scanf("%d", &M[i][j]);
        }    
    }
    
    // início dos testes com as submatrizes


    for (i=0; i < n; i++) 
    {
        for (j=0; j < m; j++) 
        {
            if(M[i][j] == s)
            {
                printf("submatriz 1 x 1 em [%d,%d]", i+1, j+1);
                return 0;
            }
        }
    }
    

    return 0;
}
