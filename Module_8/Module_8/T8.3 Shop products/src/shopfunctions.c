#include "shopfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Returns a comparison value obtained by comparing the names of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details The name field of a Product is a string.
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns 0 if a == b
 * \returns a positive number if b should be placed before a
 */
int compareAlpha(const void* a, const void* b) {
	(void)a;
	(void)b;
	char *name_a = ((Product*)a)->name;
	char *name_b = ((Product*)b)->name;
	return strcmp(name_a, name_b);
}

/**
 * \brief Returns a comparison value obtained by comparing in_stock of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details in_stock is an integer, and the products with higher stock should be
 *          placed before the products with lower stock. 
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns result of compareAlpha(a, b) if a == b
 * \returns a positive number if b should be placed before a
 */
int compareNum(const void* a, const void* b) {
	(void)a;
	(void)b;
	int in_stock_a = ((Product*)a)->in_stock;
	int in_stock_b = ((Product*)b)->in_stock;
	if (in_stock_a > in_stock_b) {
		return -1;
	} else if (in_stock_a < in_stock_b) {
		return 1;
	} else {
		return compareAlpha(a, b);
	}
}

const Product* findProduct(const Product* p_array,
						   const char* search_key,
						   int (*cmp)(const void*, const void*)) {
	(void)p_array;
	(void)search_key;
	(void)cmp;
	int i = 0;
	while (p_array[i].name[0] != 0) {
		if (strcmp(p_array[i].name, search_key) == 0) {
			return &p_array[i];
		}
		i++;
	}
	return NULL;
}
