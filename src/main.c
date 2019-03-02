
#include <stdio.h>
#include "dl_list.h"

#define N_LISTS 100

int main()
{
    srand(time(NULL));
    
    list_t* lists[N_LISTS] = {};

    for(size_t i = 0; i < N_LISTS; i++)
    {
        lists[i] = create_node();
        if (!lists[i])
            DBG_MSG("%2lu create_node() failed\n", i);
    }
    
    for(size_t i = 0; i < N_LISTS; i++)
        free(lists[i]);

    return 0;
}

