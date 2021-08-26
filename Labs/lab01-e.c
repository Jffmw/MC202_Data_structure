#include <stdio.h>

int main() {
    
    int  k, i, j;
    double e, fat;
    scanf("%d", &k);
    

    for (i = 0; i < k; i++) {        

        j = i; 
        
        for(fat = 1; j > 1; j = j - 1) {
            fat = fat * j;
        }
        
        e = e + 1/fat;
        
    }
    
    printf("e=%.12f\n", e);

    return 0;
}