#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int res;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned int seed = tv.tv_sec * 1000000 + tv.tv_usec;
    srandom(seed);
    res = random() % 3;
//    printf("%s: %d\n", argv[0], res);
    return res;
}