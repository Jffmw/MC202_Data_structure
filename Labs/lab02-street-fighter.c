#include <stdio.h>

int main(){ 
    int i,flag, hpryu, hpken, golpe; 
    int gryu, gken, hpryu1, hpken1;
    int golpes[15];

    scanf("%d", &hpryu);
    scanf("%d", &hpken);
    hpryu1 = hpryu;
    hpken1 = hpken;
    gryu = 0;
    gken = 0;

    for (i = 0; hpken1 != 0 && hpryu1 != 0; i++)  {
        
        scanf("%d", &golpe);
        
        golpes[i] = golpe;
       


        if (golpe > 0){
            hpken1 = hpken1 - golpe;


            if (hpken1 < 0) {
                hpken1 = 0;
            }
            
        }
        else {
            golpe = -golpe;
            hpryu1 = hpryu1 - golpe;
            
            if(hpryu1 < 0) {
                hpryu1 = 0;
            }
            

        }

    }

    for (i = 0; hpken != 0 && hpryu != 0; i++)  {

        if (golpes[i] > 0){
            gryu++;
            hpken = hpken - golpes[i];



            if (hpken <= 0) {
                hpken = 0;
                flag = 1;
            }
            printf("RYU APLICOU UM GOLPE: %d\n", golpes[i]);
            printf("HP RYU = %d\n", hpryu);
            printf("HP KEN = %d\n", hpken);

        }
        else {

            gken++;
            golpes[i] = - golpes[i];
            hpryu = hpryu - golpes[i];
            
            if(hpryu <= 0) {
                hpryu = 0;
            }
            printf("KEN APLICOU UM GOLPE: %d\n", golpes[i]);
            printf("HP RYU = %d\n", hpryu);
            printf("HP KEN = %d\n", hpken);

        }

    }
    
     
    if (flag) {
        printf("LUTADOR VENCEDOR: RYU\n");
        printf("GOLPES RYU = %d\n", gryu);
        printf("GOLPES KEN = %d\n", gken);
    }
    else {
        printf("LUTADOR VENCEDOR: KEN\n");
        printf("GOLPES RYU = %d\n", gryu);
        printf("GOLPES KEN = %d\n", gken);
    }
    

return 0;

}