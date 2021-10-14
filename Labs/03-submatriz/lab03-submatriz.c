#include <stdio.h>

int main() {
    // declaracao das variáveis para criação da matriz e da soma desejada
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
    
    // inicio dos testes com as submatrizes
    int icont, jcont, contagem;
    int tamanho_submatriz, tamanho_matriz;
    int soma, inicio_submatriz_linha, inicio_submatriz_coluna;

    if (n >= m)
        tamanho_matriz = m;
    else
        tamanho_matriz = n;
    
    for(tamanho_submatriz = 1; tamanho_submatriz <  tamanho_matriz ; tamanho_submatriz++) 
    {
        contagem = tamanho_matriz - tamanho_submatriz + 1;
        for (icont = 0; icont < contagem; icont++) 
        {
            for (jcont = 0; jcont < contagem; jcont++) 
            {
                soma = 0;
                inicio_submatriz_linha = 1 + icont;
                inicio_submatriz_coluna = 1 + jcont; 
 
                for (i = 0; i < tamanho_submatriz; i++) 
                {

                    for (j = 0; j < tamanho_submatriz; j++) 
                    {
                        soma +=  M[i+icont][j+jcont];
                    }
                    
                }

                if (soma == s) 
                {
                    printf("submatriz %d x %d em [%d,%d]\n", i, i, inicio_submatriz_linha, inicio_submatriz_coluna); 
                    return 0;
                }
            }
        }
    }
    printf("nao ha'\n");
    return 0;
}