#include <stdio.h>
#include <string.h>

int main () {
    char s[100];
    char chr;
    int i = 0;
    
    while (scanf("%c",&chr) != EOF) 
    {
    s[i] = chr;
    i++;
    }
    
    s[i] = "\0";
    printf("\n>%s<\n",s);
    
    
    return 0;
}
