
#ifndef   DL_LIST_H_INCLUDED
#define   DL_LIST_H_INCLUDED

#ifdef    DEBUG
    #pragma message( "Using DEBUG" )
    #define DBG_MSG(...) fprintf(stderr, __VA_ARGS__)
#else
    #define DBG_MSG(...) ;
#endif // DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// =================================

typedef int data_t;
#define DATA_T_FORMAT "%d"

typedef struct list
{
    struct list* next;
    struct list* prev;
    data_t value;
} list_t;

// =================================

/*
    Uses calloc() inside so free() must be called outside.
    Returns NULL in case of error. 
 */
list_t* create_node();

list_t* set_value(list_t* const node, data_t new_value);

/*
    Returns pointer to the inserted element.
    Return NULL in case of error.
 */
list_t* insert_after(list_t* const prev, list_t* const to_insert);

/*
    Returns pointer to the next element or NULL in case of error
 */
list_t* delete_node(list_t* to_delete);

/*
    Returns EXIT_FAILURE in case of error.
 */
void print_list(list_t* const head);

#endif // DL_LIST_H_INCLUDED

