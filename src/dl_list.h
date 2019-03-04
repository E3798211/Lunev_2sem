
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
#include <stdarg.h>

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
    Returns pointer to the next element or NULL in case of error
 */
list_t* delete_node(list_t* to_delete);

/*
    Returns EXIT_FAILURE in case of error.
 */
void delete_list(list_t* head);

/*
    Returns pointer to the inserted element.
    Return NULL in case of error.
 */
list_t* insert_after(list_t* const prev, list_t* const to_insert);

/*
    Returns EXIT_FAILURE in case of error.
 */
void print_list(list_t* const head);

/*
    Applies function to_apply() to each node including "from"
    and excluding "to". To iterate to the end, set "to" to NULL.
 */
void for_each(list_t* const from, const list_t* const to,
              void (*to_apply)(list_t* node, va_list args), ...);

#endif // DL_LIST_H_INCLUDED

