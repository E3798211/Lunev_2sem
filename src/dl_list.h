
#ifndef   DL_LIST_H_INCLUDED
#define   DL_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <time.h>

#ifdef    DEBUG
    #pragma message( "Using DEBUG" )
    #define DBG_MSG(...)                \
    do {                                \
        fprintf(stderr, __VA_ARGS__);   \
    } while(0)                          
#else
    #define DBG_MSG(...)                \
    do {                                \
                                        \
    }while(0)                           
#endif // DEBUG

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

/*
    Returns EXIT_FAILURE in case node==NULL
 */
int set_value(list_t* const node, data_t new_value);

/*
    Returns EXIT_FAILURE in case node==NULL
    Stores node's content in <value> parameter, so it must be
    a valid pointer to pre-allocated memory.
 */
int get_value(const list_t* const node, data_t* const value);

/*
    Returns pointer to the next element or NULL in case of error
 */
list_t* delete_node(list_t* to_delete);

/*
    Returns EXIT_FAILURE in case of error.
 */
void delete_list(list_t* head);

/*
    Return pointer to the inserted element.
    Return NULL in case of error.
 */
list_t* insert_after (list_t* const prev, list_t* const to_insert);
list_t* insert_before(list_t* const next, list_t* const to_insert);

/*
    Returns EXIT_FAILURE in case of error.
 */
void print_list(list_t* const head);

/*
    Applies function to_apply() to each node including "from"
    and excluding "to". To iterate to the end, set "to" to NULL.

    Returns error code.

    Function to_apply() must return 0 if no further iteration needed,
    1 otherwise.
 */
int for_each(list_t* const from, const list_t* const to,
              int (*to_apply)(list_t* node, void* args), void* args);

/*
    Return NULL if no element found
 */
list_t* find(list_t* head, data_t value);

#endif // DL_LIST_H_INCLUDED

