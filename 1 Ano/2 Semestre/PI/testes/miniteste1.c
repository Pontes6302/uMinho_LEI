
#include <stdio.h>

int v = 10;
int x = 15;
int y = 13;
char d = 's';

void mov(int t){
    if (t % 3 == 0 && t % 5 == 0) {
        if (d == 'n')
            d = 'e';
    else if (d == 'e')
        d = 's';
    else if (d == 's')
         d = 'w';
    else
         d = 'n';
    } 
    else if (t % 3 == 0)
        v += 2;
    else if (t % 5 == 0)
        v -= 1;
    else {
        if (d == 'n')
            y += v;
        else if (d == 'e')
            x += v;
        else if (d == 's')
            y -= v;
        else
            x -= v;
    }
}


int main() {
    int max_distance = 0;
    int current_distance = 0;
    char last_direction = d;

    for (int i = 1; i <= 10000; i++) {
        mov(i);
        if (d == last_direction) {
            current_distance += v;
        } else {
            if (current_distance > max_distance) {
                max_distance = current_distance;
            }
            current_distance = v;
            last_direction = d;
        }
    }

//    if (current_distance > max_distance) {
//        max_distance = current_distance;
//    }

    printf("x = %d y = %d\n", x, y);
    printf("dir = %c\n", d);
    printf("v = %d\n", v);
    printf("Maior distância percorrida continuamente numa só direção: %d\n", max_distance);

    return 0;
}
