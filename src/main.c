
#include <stdio.h>
#include "dl_list.h"

#define N_LISTS 30

void inner(list_t* node, va_list arg)
{
    int x = va_arg(arg, int);
    printf("%d\n", x + node->value);
}

int main()
{
    srand(time(NULL));
    
    list_t* lists[N_LISTS] = {};
    for(size_t i = 0; i < N_LISTS; i++)
        while(!(lists[i] = create_node()))
            DBG_MSG("Failed to create node\n");
   
    for(size_t i = 0; i < N_LISTS; i++)
        set_value(lists[i], i);
    for(size_t i = 0; i < N_LISTS; i++)
        get_value(lists[i]);
     
    for(size_t i = 0; i < N_LISTS - 1; i++)
        if (!append(lists[i], lists[i+1]))
            DBG_MSG("Failed to append\n");

    list_t *node1, *node2;
    if (!(node1 = create_node())) DBG_MSG("Node1 failed\n");
    if (!(node2 = create_node())) DBG_MSG("Node2 failed\n");

    if (!(append(lists[10], node1))) DBG_MSG("Node1 append failed\n");
    if (!(insert(lists[20], node2))) DBG_MSG("Node2 insert failed\n");

    printf("Elem with 5 is %p\n", find(lists[0], 5));
    printf("Elem with 123 is %p\n", find(lists[0], 123));

    delete_node(lists[N_LISTS - 1]);
    delete_node(lists[25]);

    for_each(lists[0], NULL, inner, 5);
    print_list(lists[0]);
    delete_list(lists[0]);

    return 0;
}

