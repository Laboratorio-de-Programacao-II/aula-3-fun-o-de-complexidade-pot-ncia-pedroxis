#include <stdio.h>

long long pot(long long base, int exp) {
    long long resultado = 1;
    for (int i = 0; i < exp; i++)
        resultado *= base;
    return resultado;
}

long long pot_eficiente(long long base, int exp) {
    long long resultado = 1;
    for(int i=0; i < exp/2; i++) {    // executa a potencia (N/2) vezes 
        resultado *=  base;            // primeira iteração o resultado vira o proprio numero, após isso é multiplicado por ele mesmo
    } 
    if(exp % 2 == 0){     //expoente par
        resultado *= resultado;                // sabemos quanto é a metade da exponenciação então a multiplicamos por 2
    } else if (exp % 2 == 1) {   // expoente impar
        resultado *= resultado;
        resultado *= base;             // se expoente é ímpar, faz uma ultima multiplicação. 
    }
    
    return resultado; 

    //considerando apenas o bloco de repetiçao o algoritmo possui uma grandeza Log(N)
}



int main() {
    long long base;
    int exp;
    scanf("%lld %d", &base, &exp);

    long long r1 = pot(base, exp);
    long long r2 = pot_eficiente(base, exp);

    printf("%lld\n%lld\n", r1, r2);
    return 0;
}
