#include "shop.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * \brief Writes the products in the shop into the specified binary file. 
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_binary(const char* filename, const Product* shop) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return 1; 
    }
    
    
    long unsigned int num_products = 0;
    while (shop[num_products].name[0] != '\0') {
        num_products++;
    }
    
    
    size_t items_written = fwrite(shop, sizeof(Product), num_products, file);
    
    
    fclose(file);
    
    if (items_written == num_products) {
        return 0;}
		else {
        return 1;
    }
}

/**
 * \brief Reads the shop products from the specified binary file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 */
Product* read_binary(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    long unsigned int num_products = file_size / sizeof(Product);
    Product* products = malloc(num_products * sizeof(Product) + 1);

    if (products == NULL) {
        fclose(file);
        return NULL;
    }

    size_t items_read = fread(products, sizeof(Product), num_products, file);

    fclose(file);

    if (items_read == num_products) {
        return products;
    } else {
        free(products); // Clean up the allocated memory
        return NULL;
    }
}


/**
 * \brief  Writes the shop products into a text file.
 * 
 * \details The file writes each product as follows.
 * 
 *          <product-name> <price> <in-stock>
 * 
 *       In other words, the structure fields are separated with a space, and the array 
 *       elements are separated by a newline. Because the data items are separated by a 
 *       space, the product name should not have spaces in it.
 * 
 *       The last array element (with the name of null character) should not be 
 *       written into the file.
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_plaintext(const char* filename, const Product* shop) {
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		return 1;
	}
	
	
	int num_products = 0;
	while (shop[num_products].name[0] != '\0') {
		num_products++;
	}
	
	
	for (int i = 0; i < num_products; i++) {
		fprintf(file, "%s %f %d\n", shop[i].name, shop[i].price, shop[i].in_stock);
	}
	
	
	fclose(file);
	
	return 0;
	}

/**
 * \brief Reads the shop products from the specified text file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 *
 * \note You can parse each line using sscanf function.
 */
Product* read_plaintext(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		return NULL;
	}
	
	
	int num_products = 0;
	while (!feof(file)) {
		char c = fgetc(file);
		if (c == '\n') {
			num_products++;
		}
	}
	
	
	Product* products = malloc(num_products * sizeof(Product) + 1);
	if (products == NULL) {
        fclose(file);
        return NULL;
    }
	rewind(file);
	
	
	for (int i = 0; i < num_products; i++) {
		fscanf(file, "%s %f %d\n", products[i].name, &products[i].price, &products[i].in_stock);
	}
	
	
	fclose(file);
	
	return products;
}