#include "list.h"

int main ()
{
    List **l = create_list ();
    insert_end (l);
    check_list (l);

}