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
        int N;
        if (scanf("%d", &N) != 1)
            return 1;
        grupo_tamanho[i] = N;
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &valores[total_valores].valor) != 1)
                return 1;
            valores[total_valores].grupo = i + 1;
            valores[total_valores].posicao_original = total_valores;
            total_valores++;
        }
    }

    qsort(valores, total_valores, sizeof(Valor), comparar);

    double ord_rel[MAXIN];
    int pos_ord[MAXIN];
    int pos = 0;
    while (pos < total_valores) {
        int start = pos;
        int end = pos;
        while (end < total_valores && valores[end].valor == valores[start].valor) {
            end++;
        }
        double sum_ord = 0;
        for (int i = start; i < end; i++) {
            sum_ord += i + 1;
        }
        double avg_ord = sum_ord / (end - start);
        for (int i = start; i < end; i++) {
            ord_rel[valores[i].posicao_original] = avg_ord;
            pos_ord[valores[i].posicao_original] = start;
        }
        pos = end;
    }

    printf(" Pos  Ord  Grp     OrdRel  Val  Prm\n");
    for (int i = 0; i < total_valores; i++) {
        printf("%4d %4d %4d %10.1f %4d %4d\n", i, i + 1, valores[i].grupo, ord_rel[i], valores[i].valor, pos_ord[i]);
    }

    double total_ordem = 0;
    for (int i = 0; i < total_valores; i++) {
        grupo_ordem_media[valores[i].grupo - 1] += ord_rel[i];
        total_ordem += ord_rel[i];
    }

    printf("\n  Grp MediaOrdem\n");
    for (int i = 0; i < G; i++) {
        grupo_ordem_media[i] /= grupo_tamanho[i];
        printf("%4d %10.1f\n", i + 1, grupo_ordem_media[i]);
    }
    printf("Todos %10.1f\n", total_ordem / total_valores);

    double H = 0;
    for (int i = 0; i < G; i++) {
        H += grupo_tamanho[i] * pow(grupo_ordem_media[i] - (total_ordem / total_valores), 2);
    }
    H = (12.0 / (total_valores * (total_valores + 1))) * H;

    double ref = valor_referencia(G);

    printf("\nCalc: %.2f\n", H);
    printf(" Ref: %.2f\n", ref);
    printf(H >= ref ? "Sim\n" : "Nao\n");

    return 0;
}
