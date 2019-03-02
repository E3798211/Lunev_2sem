
#ifndef   DL_LIST_H_INCLUDED
#define   DL_LIST_H_INCLUDED

#ifdef    DEBUG
    #pragma message( "Using DEBUG" )
    #define DBG_MSG(...) fprintf(stderr, __VA_ARGS__)
#else
    #define DBG_MSG(...)
#endif // DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// =================================

typedef int data_t;

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

#endif // DL_LIST_H_INCLUDED

