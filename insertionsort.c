/*
 Petar 'PetarV' Velickovic
 Algorithm: Insertion Sort
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define MAX_N 5001
using namespace std;
typedef long long lld;

int n;
mpz_t *niz;

//Insertion sort algoritam za sortiranje niza
//Slozenost: O(n^2)

inline void insertionSort()
{
    for (int i=1;i<n;i++)
    {
        int j = i - 1;
        mpz_t tmp;
        mpz_init_set(tmp, niz[i]);
        while (j >= 0 && mpz_cmp(niz[j], tmp) > 0) 
        {
          mpz_set(niz[j+1], niz[j]);
          j--;
        }
        mpz_set(niz[j+1], tmp);
    }
}

int main()
{
    n = 5;
    niz =  malloc(MAX_N* sizeof(mpz_t));
    mpz_init_set_ui(niz[0], 4);
    mpz_init_set_ui(niz[1], 2);
    mpz_init_set_ui(niz[2], 5);
    mpz_init_set_ui(niz[3], 1);
    mpz_init_set_ui(niz[4], 3);
    insertionSort();
    for (int i=0;i<n;i++) gmp_printf("%Zd ",niz[i]);
    printf("\n");
    return 0;
}
