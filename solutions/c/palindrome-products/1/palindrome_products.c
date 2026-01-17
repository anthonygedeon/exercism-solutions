#include "palindrome_products.h"
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool is_palindrome(int number) {
    int num = number;

    int sum = 0;
    while (number != 0) {
        int digit = number % 10;
        sum += digit * pow(10, floor(log10(abs(number))));
        number /= 10;
    }

    return sum == num;
}

static void free_factors(factor_t *node) {
    if (node == NULL)
        return;
    free_factors(node->next);
    free(node);
    node = NULL;
}

static void append(factor_t *node, int a, int b) {
    factor_t *n = node;
    for (; n != NULL; n = n->next)
        ;
    n = (factor_t *)malloc(sizeof(factor_t));

    n->factor_a = a;
    n->factor_b = b;
    n->next = NULL;
}

product_t *get_palindrome_product(int from, int to) {
    product_t *result = (product_t *)malloc(sizeof(product_t));
    if (result == NULL) {
        return NULL;
    }

    result->smallest = INT_MAX;
    result->largest = -INT_MAX;
    result->factors_sm = NULL;
    result->factors_lg = NULL;
    /* result->error = NULL; */

    for (int i = from; i <= to; i++) {
        for (int j = from; j <= to; j++) {
            int product = i * j;

            if (is_palindrome(product)) {
                if (result->smallest >= product) {
                    if (result->smallest != product) {
                        result->smallest = product;
                        free_factors(result->factors_sm);
                    }
                    append(result->factors_sm, i, j);
                }

                if (result->largest <= product) {
                    if (result->largest != product) {
                        result->largest = product;
                        free_factors(result->factors_lg);
                    }
                    append(result->factors_lg, i, j);
                }
            }
        }
    }

    printf("%d\n", result->smallest);
    printf("(%p %p)\n", (void *)result->factors_sm, (void *)result->factors_sm);

    return result;
}

void free_product(product_t *p) {
    free_factors(p->factors_sm);
    free_factors(p->factors_lg);
    free(p);
}
