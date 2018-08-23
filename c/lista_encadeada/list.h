#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int Number;
    struct Lista *Next;
} List;

List *create_list ();
void insert_end (List **);
void check_list (List **);


#endif