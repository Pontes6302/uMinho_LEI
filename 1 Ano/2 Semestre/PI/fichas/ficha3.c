#include <stdio.h>

void swapM (int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void swap (int v[], int i, int j)
{
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int soma (int v[], int N)
{
    int s = 0;
    for (int i = 0; i < N; i++)
        s += v[i];
    return s;
}

void inverteArray2 (int v[], int N)
{
    for (int i = 0; i < N/2; i++)
        swap (v,i,N-i-1);
}

void inverteArray (int v[], int N)
{
    for (int i = 0; i < N/2; i++)
        swapM (&v[i],&v[N-i-1]);
}

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
    putchar ('\n');
}

int maximum (int v[], int N, int *m)
{
    if (N <= 0)
        return 1;
    *m = v[0];
    for (int i = 0; i < N; i++)
        if (v[i] > *m)
            *m = v[i];
    return 0;
}

void quadrados (int q[], int N)
{
    for (int i = 0; i < N; i++)
        q[i] = i*i;
}

//void pascal (int v[], int N)
//{
//}

int main()
{  
    printf ("Testes\n");
    // teste das funções de swap e inverteArray
    int a, b, v[10] = {10, 6, 2, 3, 5, 1, 5, 9, 8, 7};
    int x = 3, y = 5;
    printf ("x = %d y = %d\n", x, y);
    swapM (&x, &y);
    printf ("x = %d y = %d\n", x, y);
    printf ("%d %d\n", v[0], v[9]);
    swap (v,0,9);
    printf ("%d %d\n", v[0], v[9]);
    printf ("ao invertemos o array "); dumpV (v,10);
    inverteArray (v,10);
    printf ("obtemos               "); dumpV (v,10);

    // teste das funções maximum, soma e quadrados
    x = maximum (v,10, &y);
    printf ("O maior elemento de "); dumpV (v,10);
    printf ("é %d\n", y);
    printf ("Os 10 primeiros quadrados: "); 
    quadrados (v,10); 
    dumpV (v,10);
    x = soma (v,10);
    printf ("A soma dos elementos de "); dumpV (v,10);
    printf ("é %d\n", x);

    // teste da função de cálculo do triangulo de Pascal
    /*
    printf ("A linha 5 do triângulo de Pascal é ");
    pascal (v,5); dumpV (v,6);
    */
    /*
    printf ("As linhas 0 a 10 do triângulo de Pascal\n\n");
    desenhaTriangulpP (10);
    */
    printf ("\nFim dos testes\n");

    return 0;
}
