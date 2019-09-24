#include <stdio.h>
#include <stdlib.h>
#include "myhook.h"

int main() {
    enable_hook();
    printf("hello\n");
    void *p = malloc(sizeof(int));

    int count1 = get_count();
    int count2 = get_count();
    int count3 = get_count();

    printf("p = %d\n", count1);
    //free(p);

    printf("p = %d\n", count2);

    //p = malloc(4);
    printf("p = %d\n", count3);

    int count4 = get_count();
    printf("p = %d\n", count4);

    int count5 = get_count();
    printf("p = %d\n", count5);

    free(p);
    return 0;
}
