#include <stdio.h>
int main() {
    int i, *pi, **ppi;
    i = 10;
    pi = &i;
    ppi = &pi;
    printf("Valor de i: %d\n", i);
    printf("Endereco de i: %p\n", &i);
    printf("\n");
    printf("Valor de i via pi: %d\n", *pi);
    printf("Valor de pi: %p\n", pi);
    printf("Endereco de pi: %p\n", &pi);
    printf("\n");
    printf("Valor de i via ppi: %d\n", **ppi);
    printf("Valor de ppi: %p\n", ppi);
    printf("Endereco de ppi: %p\n", &ppi);
    return 0;
}