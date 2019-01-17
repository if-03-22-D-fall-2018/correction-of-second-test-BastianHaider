/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.h
 * Author:			P. Bauer
 * Due Date:		November 25, 2012
 * ----------------------------------------------------------
 * Description:
 * dictionary.h defines functions to maintain a simple
 * dictionary.
 * ----------------------------------------------------------
 */
#ifndef ___DICTIONARY_H
#define ___DICTIONARY_H

#include "general.h"

typedef struct DictionaryImplementation* Dictionary;

void add(Dictionary dict, const char* word);
void delete_dictionary(Dictionary dictionary);
const char* get_next_entry(Dictionary dict);
int get_size(Dictionary dict);
bool has_next(Dictionary dict);
void insert_sorted(Dictionary dict, const char* word);
bool is_in_dict(Dictionary dictionary, const char* word);
Dictionary new_dictionary();
void start_iterating(Dictionary dict);


#endif
