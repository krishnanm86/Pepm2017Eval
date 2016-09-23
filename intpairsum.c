#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gmp.h"

/* You can make it faster by ensuring a sorted array + binary search */

void find_int_pair_sum(mpz_t *arr, int len, mpz_t N, mpz_t *pair) {
    int i, j;
    mpz_t first, second;
    mpz_init(first);
    mpz_init(second);
    int found = 0;

    for (i = 0; i < len-1; ++i) {
        mpz_set(first, arr[i]);
        for (j = i+1; j < len; ++j) {
            mpz_set(second, arr[j]);
            mpz_t temp;
            mpz_init(temp);
            mpz_add(temp, first, second);
            if (mpz_cmp(temp, N) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    if (found) {
        mpz_set(pair[0], first);
        mpz_set(pair[1], second);
    } else {
        mpz_set_si(pair[0], -1);
        mpz_set_si(pair[1], -1);
    }
}

int main(int argc, char **argv) {
    mpz_t *arr;
    arr = malloc(8* sizeof(mpz_t));

    mpz_init_set_ui(arr[0], 1);
    
    mpz_init_set_ui(arr[1], 2);
    
    mpz_init_set_ui(arr[2], 3);
    
    mpz_init_set_ui(arr[3], 4);
    
    mpz_init_set_ui(arr[4], 5);
    
    mpz_init_set_ui(arr[5], 10);
    
    mpz_init_set_ui(arr[6], 20);
    
    mpz_init_set_ui(arr[7], 50);
    mpz_t N;
    mpz_init_set_ui(N, 70);
    mpz_t *out;
    out = malloc(2* sizeof(mpz_t));

    find_int_pair_sum(arr, 8, N, out);

    gmp_printf("%Zd, %Zd\n", out[0], out[1]);

    return 0;
}