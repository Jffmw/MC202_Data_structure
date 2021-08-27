#include <stdio.h>

int main() {
    
    int V[5] = {100,200,300,400,500};
    
    printf("V[0]: %d\n", V[0]);
    printf("*V: %d\n", *V);
    printf("*(V+1): %d\n", *(V+1) );
    
    return 0;
}