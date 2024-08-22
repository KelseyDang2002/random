#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL; // init list

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node)); // allocate memory for pointer n
        if (n == NULL)
        {
            return 1;
        }
        n->number = number; // n point to new node number
        n->next = NULL; // n point to new node next

        n->next = list; // link new node to list
        list = n; // set n to start of list
    }

    // node *ptr = list; // point to first node of list
    // while (ptr != NULL) // while not at the end of the list
    // {
    //     printf("%i\n", ptr->number);
    //     ptr = ptr->next; // iterate to next node number
    // }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next; // new pointer temporarily poiting at next node
        free(ptr);
        ptr = next;
    }

    return 0;
}
