// bit array char 

/* vetores de bits são vetores para valores binários 
utilizamos essas técnicas para economizar memória 
armazenando números onde os 1 da sua forma binaria representam nossas 
variáveis binárias */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int main(void)
{
    unsigned char c;

    c = 1;       // 0000 0001
    c = c << 3;  // 0000 1000

    printf("%i %0.2x\n",c,c);


    // fun Set -> adicona valores 1 ao "vetor"
    unsigned char r = 2 | c; // 0000 0010 | 0000 1000 = 0000 1010

    printf("%i %0.2x\n",r,r);

    // fun Reset -> remove valores 1 do vetor 
    c = 1;       // 0000 0001
    c <<= 3;     // 0000 1000
    c = ~c;      // 1111 0111

    unsigned char d = r & c; // 0000 0010

    printf("%i %0.2x\n",d,d);

    // fun Test -> testa se uma determinada posição tem valor 0 ou 1
    /* fazemos um teste & com o "vetor" e uma máscara com 1 na posição que 
    queremos verificar. Se o resultado for 0 a posição tem valor 0,
    se o retorno for igual da máscara o valor é 1.*/

    return 0;
}


