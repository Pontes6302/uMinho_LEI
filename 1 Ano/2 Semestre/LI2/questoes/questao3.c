#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXIN ((int) 100*100)

typedef struct {
    int valor;
    int grupo;
    int posicao_original;
} Valor;

int comparar(const void *a, const void *b) {
    return ((Valor *)a)->valor - ((Valor *)b)->valor;
}

double valor_referencia(int num_grupos) {
    double p = 0.95;
    double df = num_grupos - 1;
    double a = (p < 0.5) ?  sqrt(-2.0 * log(p)) : sqrt(-2.0 * log(1.0 - p));
    double poly = 2.515517 + 0.802853 * a + 0.010328 * a * a;
    double q = 1.0 + 1.432788 * a + 0.189269 * a * a + 0.001308 * a * a * a;
    double z = (p < 0.5) ? -(a - poly / q) : (a - poly / q);
    double x = df * pow(1.0 - 2.0 / (9.0 * df) + z * sqrt(2.0 / (9.0 * df)), 3.0);
    return x;
}

int main(void) {
    Valor valores[MAXIN];
    int total_valores = 0;
    int grupo_tamanho[100];
    double grupo_ordem_media[100] = {0};

    int G;
    if (scanf("%d", &G) != 1)
        return 1;
    for (int i = 0; i < G; i++) {
        int temp;
        scanf("%d", &temp);
        grupo_tamanho[i] = temp;
        for (int j = 0; j < temp; j++) {
            int valor;
            scanf("%d", &valor);
            valores[total_valores].valor = valor;
            valores[total_valores].grupo = i;
            valores[total_valores].posicao_original = total_valores;
            total_valores++;
        }
    }

    qsort(valores, total_valores, sizeof(Valor), comparar);
    printf(" Pos  Ord  Grp     OrdRel  Val  Prm\n");

    int ordem = 1;
    for (int i = 0; i < total_valores; i++) {
        int valor = valores[i].valor;
        int grupo = valores[i].grupo;
        int posicao_original = valores[i].posicao_original;
        int primeira_posicao = posicao_original;
        double ordem_relativa = ordem;

        for (int j = i + 1; j < total_valores && valores[j].valor == valor; j++) {
            ordem_relativa += ordem + (j - i);
        }
        ordem_relativa /= (total_valores - i);

        printf("%4d %4d %4d %10.1f %4d %4d\n", i, ordem, grupo, ordem_relativa, valor, primeira_posicao);
        grupo_ordem_media[grupo - 1] += ordem_relativa;
        ordem++;
    }

    printf("\n  Grp MediaOrdem\n");
    double media_total = 0;
    for (int i = 0; i < G; i++) {
        grupo_ordem_media[i] /= grupo_tamanho[i];
        printf("%4d %10.1f\n", i + 1, grupo_ordem_media[i]);
        media_total += grupo_ordem_media[i];
    }
    media_total /= G;
    printf("Todos %10.1f\n", media_total);

    double S = 0;
    for (int i = 0; i < G; i++) {
        S += grupo_tamanho[i] * pow(grupo_ordem_media[i] - media_total, 2);
    }

    double X = ((double)(G - 1) / G) * (12 * S / (G * G - 1));
    printf(" S: %.2f\n", S);
    printf(" X: %.2f\n", X);

    return 0;
}
