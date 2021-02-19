#include "api.h"

int main()
{
    int N;
    Arv *a = arv_criavazia();

    // printf("Digite o numero de numeros aleatorios a serem gerados: ");
    // scanf("%d", &N);

    srand(time(NULL));

    for (int i = 0; i < 1000000; i++)
        a = insere(a, i);

    //arv_imprime(a);
    printf("%d", altura(a));
    arv_libera(a);
    return 0;
}