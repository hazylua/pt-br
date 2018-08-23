#include "list.h"

List *create_list ()
{
    List *l = malloc (sizeof (List));
    l->Next = NULL;
    return l;
}

void insert_end (List **l)
{
    int n = 1;
    List *new = malloc (sizeof (List));
    new->Number = n;
    new->Next = NULL;

    if ((*l)->Next != NULL)
        l = (*l)->Next;
    (*l)->Next = new;
}

void check_list (List **l)
{
    List **h = l;
    do
    {
        printf ("%d\n", (*h)->Number);
    }
    while ((*h)->Next != NULL);
}