#include <stdio.h>

void quadrado (int a){
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf ("#");
        }
        printf ("\n");
    }
}

void xadrez (int a){
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if ((i+j) % 2 == 0)
                printf ("#");
            else
                printf ("_");
        }
        printf ("\n");
    }
}

void horizontal (int a){
    for (int i = 0; i < a; i++){
        for (int j = 0; j <= i; j++){
            printf ("#");
        }
        printf ("\n");
    }
    for (int i = a - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            printf ("#");
        }
        printf ("\n");
    }
}

void vertical(int a) {
    for (int i = 1; i <= a; i++) {
        int j = 0;
        while (j < a - i) {
            printf(" ");
            j++;
        }
        while (j < a + i - 1) {
            printf("#");
            j++;
        }
        printf("\n");
    }
}

void circulo(int raio) {
    int diametro = 2 * raio + 1;
    int centro = raio;

    for (int y = 0; y < diametro; y++) {
        for (int x = 0; x < diametro; x++) {
            int dx = x - centro;
            int dy = y - centro;
            if (dx * dx + dy * dy <= raio * raio)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
   circulo(4);
}