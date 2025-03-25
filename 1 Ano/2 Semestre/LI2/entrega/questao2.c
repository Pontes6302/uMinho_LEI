#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXIN ((unsigned long long) pow (10, 1000))

int compare_num(char *a, char *b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int i = 0;
    if (lena > lenb)
        return 1;
    else if (lena < lenb)
        return 0;
    while(a[i] != '\0') {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return 0;
        i++;
    }
    return 0;
}

char *multiply(char *a, char b){
    int lena = strlen(a);
    char *result = (char *) malloc((lena + 1) * sizeof(char));
    int carry = 0;
    for (int i = lena - 1; i >= 0; i--) {
        int temp = (a[i] - '0') * (b - '0') + carry;
        result[i+1] = temp % 10 + '0';
        carry = temp / 10;
    }
    if (carry != 0)
        result[0] = carry + '0';
    else
        result++;
    return result;
}

char *calculate(char *N, int S, int length) {
    char *ret = (char *) malloc((S + 1) * sizeof(char));
    strcpy(ret, "0");
    char *temp = (char *) malloc((S +1) * sizeof(char));
    for (int i = 0; i <= length-S; i++) {
        temp[0] = N[i];
        temp[1] = '\0';
        for (int j = 1 ; j < S; j++) {
            temp = multiply(temp, N[j+i]);
        }
        if (compare_num(temp, ret) != 0)
            snprintf(ret, S + 1, "%s", temp);
        temp[0] = '\0';
    }
    return ret;
}

int main (void){
    int C;
    if (scanf("%d", &C) != 1 || C < 1 || C > 100)
        return 1;
    char **final = (char **) malloc(C * sizeof(char *));
    for (int i = 0; i < C; i++) {
        char N[1001];
        int S;
        if (scanf("%s %d", N, &S) != 2)
            return 1;
        int length = strlen(N);
        if (length < 1 || length > 1000 || S < 0 || S > length)
            return 1;
        final[i] = calculate( N, S, length);
    }
    for (int p = 0; p < C; p++) {
        printf("%s\n", final[p]);
    }
}
