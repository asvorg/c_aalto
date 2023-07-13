#include "shop.h"

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
	}
