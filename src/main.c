
#include <stdio.h>
#include "dl_list.h"

#define N_LISTS 30

int inner(list_t* node, void* arg)
{
    printf("%d\n", node->value);
    if (node->value == 5)
        return 1;
    else
        return 0;
}

int main()
{
    srand(time(NULL));
    
    list_t* lists[N_LISTS] = {};
    for(size_t i = 0; i < N_LISTS; i++)
        while(!(lists[i] = create_node()))
            DBG_MSG("Failed to create node\n");
    
    data_t x = 0;
    for(size_t i = 0; i < N_LISTS; i++)
        set_value(lists[i], i);
    for(size_t i = 0; i < N_LISTS; i++)
        get_value(lists[i], &x);
     
    for(size_t i = 0; i < N_LISTS - 1; i++)
        if (!insert_after(lists[i], lists[i+1]))
            DBG_MSG("Failed to insert_after\n");

    list_t *node1, *node2;
    while(!(node1 = create_node())) DBG_MSG("Node1 failed\n");
    while(!(node2 = create_node())) DBG_MSG("Node2 failed\n");

    if (!(insert_after (lists[10], node1))) DBG_MSG("Node1 append failed\n");;
    if (!(insert_before(lists[20], node2))) DBG_MSG("Node2 insert failed\n");

    printf("Elem with 5 is %p\n", find(lists[0], 5));
    printf("Elem with 123 is %p\n", find(lists[0], 123));

    delete_node(lists[N_LISTS - 1]);
    delete_node(lists[25]);

    for_each(lists[0], NULL, inner, NULL);
    print_list(lists[0]);
    delete_list(lists[0]);

    
    set_value(NULL, 0);
    get_value(NULL, 0);
    insert_after (NULL, NULL);
    insert_before(NULL, NULL);
    delete_node(NULL);
    for_each(NULL, NULL, NULL, NULL);
    return 0;
}

