#include <stdio.h>
#include <assert.h>

float multInt1 (int n, float m) {
    float r = 0;
    for (int i = 0; i < n; i++) {
        r += m;
    }
    return r;
}

float multInt2 (int n, float m, int *it) {
    float r = 0;
    *it = 0;
    while (n > 0) {
        if (n % 2 == 1)
            r += m;
        n = n/2;
        m = m*2;
        (*it)++;
    }
    return r;
}

int mdc1 (int a, int b){
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    for (int i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int mdc2 (int a, int b, int *it) {
    *it = 0;
    while (a > 0 && b > 0) {
        if (a >= b)
            a = a - b;
        else 
            b = b - a;
        (*it)++;
    }
    return b;
}

int mdc3 (int a, int b, int *it) {
    *it = 0;
    while (a > 0 && b > 0) {
        if (a >= b)
            a = a % b;
        else 
            b = b % a;
        (*it)++;
    }
    return (a > b) ? a : b;
}

int fib1 (int n){
    if (n <= 1)
        return n;
    else
        return fib1(n-1) + fib1(n-2);
}

int fib2 (int n, int *it) {
    if (n <= 1)
        return n;
    int fn1 = 0, fn2 = 1, fin = 1;
    for (int i = 2; i <= n; i++) {
        fin = fn1 + fn2;
        fn1 = fn2;
        fn2 = fin;
        (*it)++;
    }
    return fin;
}

int main()
{
    int it;

    assert(multInt1(3, 2) == 6);
    assert(multInt1(3, 0) == 0);
    assert(multInt1(0, 2) == 0);
    assert(multInt1(0, 0) == 0);

    assert(multInt2(3, 1, &it) == 3);
    printf ("Iter multInt2 3x1 %d\n", it);
    assert(multInt2(3, 0, &it) == 0);
    printf ("Iter multInt2 3x0 %d\n", it);
    assert(multInt2(0, 1, &it) == 0);
    printf ("Iter multInt2 0x1 %d\n", it);
    assert(multInt2(0, 0, &it) == 0);
    printf ("Iter multInt2 0x0 %d\n", it);
    assert(multInt2(3203, 2301, &it) == 7370103);
    printf ("Iter multInt2 3203x2301 %d\n", it);

    assert(mdc1(3, 2) == 1);
    assert(mdc1(3, 3) == 3);
    assert(mdc1(36, 6) == 6);
    assert(mdc1(6, 12) == 6);
    assert(mdc1(12, 5) == 1);

    assert(mdc2(3, 2, &it) == 1);
    printf ("Iter mdc2 3x2 %d\n", it);
    assert(mdc3(3, 2, &it) == 1);
    printf ("Iter mdc3 3x2 %d\n", it);
    assert(mdc2(3, 3, &it) == 3);
    printf ("Iter mdc2 3x3 %d\n", it);
    assert(mdc3(3, 3, &it) == 3);
    printf ("Iter mdc3 3x3 %d\n", it);
    assert(mdc2(36, 6, &it) == 6);
    printf ("Iter mdc2 36x6 %d\n", it);
    assert(mdc3(36, 6, &it) == 6);
    printf ("Iter mdc3 36x6 %d\n", it);
    assert(mdc2(6, 12, &it) == 6);
    printf ("Iter mdc2 6x12 %d\n", it);
    assert(mdc3(6, 12, &it) == 6);
    printf ("Iter mdc3 6x12 %d\n", it);
    assert(mdc2(12, 5, &it) == 1);
    printf ("Iter mdc2 12x5 %d\n", it);
    assert(mdc3(12, 5, &it) == 1);
    printf ("Iter mdc3 12x5 %d\n", it);
    assert(mdc2(3203, 2301, &it) == 1);
    printf ("Iter mdc2 3203x2301 %d\n", it);
    assert(mdc3(3203, 2301, &it) == 1);
    printf ("Iter mdc3 3203x2301 %d\n", it);

    assert(fib1(0) == 0);
    assert(fib1(1) == 1);
    assert(fib1(2) == 1);
    assert(fib1(8) == 21);

    assert(fib2(0, &it) == 0);
    printf("Iter fib2 0 %d\n", it);
    assert(fib2(1, &it) == 1);
    printf("Iter fib2 1 %d\n", it);
    assert(fib2(2, &it) == 1);
    printf("Iter fib2 2 %d\n", it);
    assert(fib2(8, &it) == 21);
    printf("Iter fib2 8 %d\n", it);
}