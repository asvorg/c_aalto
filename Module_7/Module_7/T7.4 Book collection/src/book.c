#include "book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * \brief Initializes a book for the collection.
 *
 * \param p_book The book to be initialized.
 * \param p_id The book identifier string
 * \param p_title The book title string
 * \param p_author The book author string
 * \param release The release date of the book
 * \returns 0 if the book identifier is not valid. The identifier is invalid
 * 			  if the stated book identifier has more than 9 characters.
 * \returns 1 if the book can be initialized.
 */
int init_book(struct book *p_book,
			  const char *p_id,
			  const char *p_title,
			  const char *p_author,
			  struct date release)
{
	
		p_book->title = malloc(sizeof(char) * (strlen(p_title) + 1));
		p_book->author = malloc(sizeof(char) * (strlen(p_author) + 1));
		if (p_book->title == NULL || p_book->author == NULL) {
			return 0;
		}
		//copy strings to book
		if (strlen(p_id) > 9) {
			return 0;
		}
		else{
			strcpy(p_book->id, p_id);
			strcpy(p_book->title, p_title);
			strcpy(p_book->author, p_author);
			p_book->release_date = release;
		return 1; // Book initialized successfully
	}
}
/**
 * \brief Deletes the collection. The function frees all allocated memory for
 * the books in the collection and the collection itself.
 *
 * \param collection The array of books representing the collection
 * \param size The number of books in the collection
 */
void delete_collection(struct book *collection, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++) {
		free(collection[i].title);
		free(collection[i].author);
	}
}
/**
 * \brief Finds a book from the collection based on the book identifier.
 *
 * \param collection The array of books representing the collection
 * \param size The number of books in the collection
 * \param p_id The book identifier string
 * \return A pointer to the found book or NULL if the book was not found.
 */
struct book *find_book(struct book *collection,
					   unsigned int size,
					   const char *p_id)
{
	for (unsigned int i = 0; i < size; i++) {
		if (strcmp(collection[i].id, p_id) == 0) {
			return &collection[i];
		}
	}
	return NULL;
}

/**
 * \brief Adds a book to the collection. The collection is an array, and the
 * array should be reallocated to store the new book.
 *
 * \param collection The array of books representing the collection
 * \param size The number of books in the current collection
 * \param new_book The new book to be copied to the collection
 * \return A pointer to enlarged collection
 */
struct book *add_to_collection(struct book *collection,
							   unsigned int size,
							   struct book new_book)
{
	//dynamic memory allocation
	struct book *new_collection = malloc(sizeof(struct book) * (size + 1));
	
	if (new_collection == NULL) {
		return NULL;
	}
	for (unsigned int i = 0; i < size; i++) {
		new_collection[i] = collection[i];
		}
	new_collection[size] = new_book;
	free(collection);
	collection = new_collection;
	return collection;
	}
