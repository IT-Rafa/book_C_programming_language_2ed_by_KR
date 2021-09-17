/* 
    calcula el tamaño del tipo
    cacula el valor maximo del tipo
*/

/*
    Cuando hay overflow de un dígito, el valor es 0
*/
#include <limits.h>
#include <stdio.h>

long power(long base, long n);

int main(void)
{
    printf("max int: %ld\n", LONG_MAX);

    printf("Calculando max short\n");
    long maxtype = 0;
    long maxtadd;

    int maxpower;
    for (maxpower = 0; maxtype >= 0; ++maxpower) {
        maxtype = power(2, maxpower);
        if (maxtype < 0) {
            maxtype = power(2, maxpower - 1);
            break;
        }
    }

    char s[100];
    int len = sprintf(s, "%ld", maxtype);
    printf("limite actual: %d digits: %s\n", len, s);

    maxtype = 0;
    // power of ten
    for (int p = len - 1; p >= 0; --p) {
        for (int d = 9; d >= 0; --d) {
            maxtadd = d * power(10, p);
            printf("pos %2d: %ld\n", p, maxtype);
            if (maxtype + maxtadd > 0){
                maxtype = maxtype + maxtadd;
                break;
            }
        }
    }
    printf("FINAL %ld\n", maxtype);
}

long power(long base, long n)
{
    long p;

    if (n == 0)
        return 1;

    for (p = 1; n > 0; --n) {
        p = p * base;
    }
    return p;
}
