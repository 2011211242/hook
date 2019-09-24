#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
#include "myhook.h"

static int count = 0;

void *malloc(size_t size) {
    count++;
    void *(*myMalloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
    //printf("call my malloc\n");
    void * ptr = myMalloc(size);
    * (int *) ptr = count;
}

int get_count()
{
    return count;
}

int enable_hook() {
    return 1;
}
