#include <stdio.h>

typedef struct {
    char letter;
    int number;
    int mults;
} values;

void calculate(values *val, int N, int I, int F) {
    for (int i = 0; i < N; i++) {
        for (int j = I; j <= F; j++) {
            if (j % val[i].number == 0)
                val[i].mults++;
        }
    }
}

void sort(values *val, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (val[j].letter > val[j + 1].letter) {
                values temp = val[j];
                val[j] = val[j + 1];
                val[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int N, I, F;
    if (scanf("%d", &N) != 1)
        return 1;
    if (N < 1 || N > 26)
        return 1;
    values val[N];
    for (int i = 0; i < N; i++) {
        if (scanf(" %c %d", &val[i].letter, &val[i].number) != 2)
            return 1;
        if (val[i].number <= 0 || val[i].number > 1000000000 || val[i].letter < 'A' || val[i].letter > 'Z') {
            return 1;
        }
        val[i].mults = 0;}
    if (scanf("%d %d", &I, &F) != 2)
        return 1;
    if (I < 1 || I > 1000000000 || F < 1 || F > 1000000000)
        return 1;
    calculate(val, N, I, F);
    sort(val, N);
    for (int i = 0; i < N; i++) {
        printf("%c %d\n", val[i].letter, val[i].mults);
    }
    return 0;
}
