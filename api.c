#include "api.h"

struct arv
{
    int chave;
    Arv *esq;
    Arv *dir;
};

Arv *arv_criavazia(void)
{
    return NULL;
}

Arv *insere(Arv *a, int chave)
{

    if (busca(a, chave) != NULL)
        return a;

    if (a == NULL)
    {
        a = (Arv *)malloc(sizeof(Arv));
        a->chave = chave;
        a->esq = a->dir = NULL;
    }
    else if (chave < a->chave)
        a->esq = insere(a->esq, chave);
    else
        a->dir = insere(a->dir, chave);

    return a;
}

Arv *busca(Arv *a, int chave)
{
    if (a == NULL)
        return NULL;
    else if (a->chave > chave)
        return busca(a->esq, chave);
    else if (a->chave < chave)
        return busca(a->dir, chave);
    else
        return a;
}

static int max2(int a, int b)
{
    return (a > b) ? a : b;
}

int altura(Arv *a)
{
    if (a == NULL)
        return -1;
    else
        return 1 + max2((altura(a->esq)), (altura(a->dir)));
}

void arv_imprime(Arv *a)
{
    printf("<");
    if (a != NULL)
    {
        printf("%d", a->chave);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");
}

Arv *arv_libera(Arv *a)
{
    if (a != NULL)
    {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}