#include <stdio.h>
#include <stdlib.h>
#include"gmp.h"

int binary_search(mpz_t A[], int p, int r, mpz_t v) {
    int m = (p+r) / 2;

    if (p == r) {
        return -1;
    }

    if (mpz_cmp(A[m], v) == 0)
        return m;

    if (mpz_cmp(v, A[m]) > 0) {
        /* search right */
        return binary_search(A, m+1, r, v);
    }
    return binary_search(A, p, m, v);
}

int main(int argc, char **argv) {
    mpz_t *arr;
    arr = malloc(8* sizeof(mpz_t));

    mpz_init_set_ui(arr[0], 1);
    
    mpz_init_set_ui(arr[1], 2);
    
    mpz_init_set_ui(arr[2], 3);
    
    mpz_init_set_ui(arr[3], 4);
    
    mpz_init_set_ui(arr[4], 5);
    
    mpz_init_set_ui(arr[5], 6);
    
    mpz_init_set_ui(arr[6], 7);
    
    mpz_init_set_ui(arr[7], 8);

    mpz_t tosearch;
    mpz_init_set_ui(tosearch, 8);
    int res = binary_search(arr, 0, 8, tosearch);

    if (res >= 0) {
        gmp_printf("A[%d] = %Zd\n", res, arr[res]);
    } else {
        gmp_printf("not found\n");
    }
    return 0;
}