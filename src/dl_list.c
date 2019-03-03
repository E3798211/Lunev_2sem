
#include "dl_list.h"

#ifdef    INVALID_CALLOC     
    #pragma message ( "Using INVALID_CALLOC" )
    #include <time.h>
    static void* invalid_calloc(size_t nmemb, size_t size)
    {
        return ((rand() % 2)? calloc(nmemb, size) : NULL);
    }
    #define calloc(nmemb, size) invalid_calloc(nmemb, size);
#endif // INVALID_CALLOC

// =================================

list_t* create_node()
{
    return (list_t*)calloc(1, sizeof(list_t));
}

list_t* set_value(list_t* const node, data_t new_value)
{
    node->value = new_value;
    return node;
}

list_t* insert_after(list_t* const prev, list_t* const to_insert)
{
    if (!to_insert || !prev)    return NULL;

    list_t* next = prev->next;
    prev->next   = to_insert;
    to_insert->prev = prev;
    to_insert->next = next;

    if (next)   next->prev = to_insert;

    return to_insert;
}

void print_list(list_t* const head)
{
    size_t i = 0;
    for(list_t* cur = head; cur; cur = cur->next)
        printf("[%4lu] "DATA_T_FORMAT"\n", i++, cur->value);
}


