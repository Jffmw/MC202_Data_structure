#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d %d %d\n", n, m, k);
    
    typedef struct {
        int l;
        int c;
        int v;
    } Coordenadas;
    Coordenadas coor[n+m];

    /*
    for (int i = 0; i < n+m; i++)
    {
        coor[i].l = 0;
        coor[i].c = 0;
        coor[i].v = 0;   
    }
    */

    for (int i = 0; i < k; i++)
    {
        scanf(" [%d,%d] %d", &coor[i].l, &coor[i].c, &coor[i].v);  
    }

    for (int i = 0; i < k; i++)
    {
        printf("(%d,%d,%d)\n", coor[i].l, coor[i].c, coor[i].v);
    }

    char e;
    int j = 0;
    int nl, nc, nv;
    
    while (scanf(" %c", &e) != EOF)
    {
        if(e == 't')
        {
            break;
        }

        if (e == 'a') 
        {
            printf(">A<\n");

        } else if (e == 'p')
        {
            printf("VC: ");
            for (int i = 0; i < k+j; i++)
            {
                printf("(%d,%d,%d) ", coor[i].l, coor[i].c, coor[i].v);
            }
            printf("\n");
            
         
        } else if (e == 'r') 
        {
            printf(">R<\n");
            int f = 1;
            scanf(" [%d,%d]", &nl, &nc);
            for (int i = 0; i < k+j; i++)
            {
                if(nl == coor[i].l && nc == coor[i].c)
                {
                    f = 0;
                    printf("M[%d][%d] == %d\n", nl, nc, coor[i].v);
                }
            }
            if(f)
                printf("M[%d][%d] == %d\n", nl, nc, 0);
        }   
    }

    
    
    return 0;
}