/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.cpp
 * Author:			P. Bauer
 * Due Date:		November 25, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of dictionary.h.
 * ----------------------------------------------------------
 */

 #include "general.h"
 #include "dictionary.h"
 #include <stdlib.h>
 #include <string.h>


 typedef struct NodeImplementation* Node;

 struct NodeImplementation
 {
   const char* word;
   struct NodeImplementation* next;
 };
 struct DictionaryImplementation
 {
   int length;
   Node head;
   Node current;
 };

Dictionary new_dictionary()
{
    Dictionary dictionary = (Dictionary)malloc(sizeof(struct DictionaryImplementation));
    dictionary->length=0;
    dictionary->head=0;
    return dictionary;

}
 void add(Dictionary dict, const char* word)
 {
  Node newNode=(Node)malloc(sizeof(struct NodeImplementation));
  newNode->word=word;
  newNode->next=0;
  Node currentNode = dict->head;
  if (dict->head ==0)
  {
    dict->head=newNode;
  }
  else
  {
    if (is_in_dict(dict,word))
    {
      return;
    }
    while (currentNode->next!=0)
    {
      currentNode=currentNode->next;
    }

    currentNode->next=newNode;
  }
  dict->length++;
 }
 void delete_dictionary(Dictionary dictionary)
 {
   Node currentNode = dictionary->head;
   while (currentNode != 0)
   {
     Node to_be_deleted=currentNode;
     currentNode=currentNode->next;
     sfree(to_be_deleted);
   }
   sfree(dictionary);
 }
 const char* get_next_entry(Dictionary dict)
 {
   if (has_next(dict))
   {
     const char* word=dict->current->word;
    dict->current=dict->current->next;
    return word;
   }
   return 0;
 }
 int get_size(Dictionary dict)
 {
   Node current = dict->head;
   int counter = 0;
   while (current != 0)
   {
    counter++;
    current=current->next;
   }
   return counter;
 }
 bool has_next(Dictionary dict)
 {
   if (dict->current != 0)
   {
     return true;
   }
   return false;
 }
 void insert_sorted(Dictionary dict, const char* word)
 {
   if (dict->head==0) add(dict,word);
  else
  {
    if (is_in_dict(dict,word)) return;
    Node newNode=(Node)malloc(sizeof(NodeImplementation));
    newNode->word=word;
    newNode->next=0;
    if (strcasecmp(dict->head->word,word)>0)
    {
      newNode->next=dict->head;
      dict->head=newNode;
      dict->length++;
    }
    else
    {
      Node current=dict->head;
      while (current->next!=0 && strcasecmp(current->next->word,word)<0)
      {
        current=current->next;
      }
      if (current->next==0) add(dict,word);
      if (strcasecmp(current->next->word,word)>0)
      {
        newNode->next=current->next;
        current->next=newNode;
        dict->length++;
      }

    }
  }
 }
 bool is_in_dict(Dictionary dictionary, const char* word)
 {
   Node current=dictionary->head;
   while(current != 0)
  {
    if(strcasecmp(current->word, word) == 0){
      return true;
    }
    current = current->next;
  }
  return false;
 }
 void start_iterating(Dictionary dict)
 {
   dict->current=dict->head;
 }
