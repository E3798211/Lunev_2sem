
#include "dl_list.h"

#ifdef    INVALID_CALLOC     
    #pragma message ( "Using INVALID_CALLOC" )
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

int set_value(list_t* const node, data_t new_value)
{
    if (!node)
        return EXIT_FAILURE;
    node->value = new_value;
    return EXIT_SUCCESS;
}

int get_value(const list_t* const node, data_t* const value)
{
    if (!node)
        return EXIT_FAILURE;
    *value = node->value;
    return EXIT_SUCCESS;
}

list_t* insert_after (list_t* const prev, list_t* const to_insert)
{
    if (!to_insert || !prev)
        return NULL;

    list_t* next = prev->next;
    prev->next   = to_insert;
    to_insert->prev = prev;
    to_insert->next = next;

    if (next)   
        next->prev = to_insert;

    return to_insert;
}

list_t* insert_before(list_t* const next, list_t* const to_insert)
{ 
    if (!to_insert || !next)
        return NULL;
    
    list_t* prev = next->prev;
    next->prev   = to_insert;
    to_insert->prev = prev;
    to_insert->next = next;

    if (prev)
        prev->next = to_insert;

    return to_insert;
}

list_t* delete_node(list_t* to_delete)
{
    if (!to_delete)
        return NULL;

    if (to_delete->prev)
        to_delete->prev->next = to_delete->next;
    if (to_delete->next)
        to_delete->next->prev = to_delete->prev;

    list_t* next = to_delete->next;
    free(to_delete);

    return next;
}

void delete_list(list_t* head)
{
    if (head->prev) 
        head->prev->next = NULL;

    while(head)
    {
        list_t* next = head->next;
        free(head);
        head = next;
    }
}

void print_list(list_t* const head)
{
    size_t i = 0;
    for(list_t* cur = head; cur; cur = cur->next)
        printf("[%4lu] "DATA_T_FORMAT"\n", i++, cur->value);
}

int for_each(list_t* const from, const list_t* const to,
              int (*to_apply)(list_t* node, void* args), void* args)
{
    if (!from)
        return EXIT_FAILURE;

    for(list_t* node = from; node != to; node = node->next) 
        if (to_apply(node, args))
            break;

    return EXIT_SUCCESS;
}

list_t* find(list_t* head, data_t value)
{
    while(head)
    {
        if (head->value == value)   return head;
        head = head->next;
    }
    return NULL;
}

int divide(list_t** first, list_t** second, data_t stop_value)
{
    list_t* cur = *first;
    while(cur)
    {
        if (cur->value == stop_value)
        {
            *second = cur->next;
            cur->next = NULL;

            if (*second)
                (*second)->prev = NULL;

            return EXIT_SUCCESS;
        }
        cur = cur->next;
    }
    return EXIT_FAILURE;
}







