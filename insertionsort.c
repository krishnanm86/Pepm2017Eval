#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gmp.h"

void insertion_sort(mpz_t *arr, int len) {
    /* sorts arr in place using insertion sort */

    int i, j;
    mpz_t key;
    mpz_init(key);

    for (i = 1; i < len; ++i) {
        mpz_set(key, arr[i]);
        j = i-1;

        while (j >= 0 && mpz_cmp(arr[j], key) > 0) {
            mpz_set(arr[j+1], arr[j]);
            --j;
        }

        mpz_set(arr[j+1], key);
    }
}

int main(int argc, char **argv) {
    
    mpz_t *arr;
    arr = malloc(8* sizeof(mpz_t));

    mpz_init_set_ui(arr[0], 4);
    
    mpz_init_set_ui(arr[1], 5);
    
    mpz_init_set_ui(arr[2], 20);
    
    mpz_init_set_ui(arr[3], 6);
    
    mpz_init_set_ui(arr[4], 2);
    
    mpz_init_set_ui(arr[5], 3);
    
    mpz_init_set_ui(arr[6], 12);
    
    mpz_init_set_ui(arr[7], 1);
    

    insertion_sort(arr, 8);

    int i;
    for (i = 0; i < 8; ++i) {
        gmp_printf(" %Zd ", arr[i]);
    }

    printf("\n");

    return 0;
}