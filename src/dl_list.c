
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

list_t* create_node()
{
    return (list_t*)calloc(1, sizeof(list_t));
}

list_t* set_value(list_t* const node, data_t new_value)
{
    node->value = new_value;
    return node;
}

