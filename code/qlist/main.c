#include <stdio.h>
#include "qlist.h"
int main(int argc, char** argv) {
    qlist_s  *qlist = NULL;

    qlist = qlist_create();
    if(qlist == NULL)
    {
        printf("create err\n");
    }

    qlist_backadd(qlist,1);
    qlist_backadd(qlist,2);
    qlist_backadd(qlist,5);
    qlist_backadd(qlist,5);
    qlist_del(qlist,0);
    qlist_backdel(qlist);

     qlist_show(qlist);

    if(qlist_destroy(qlist))
    {
        printf("destroy ok \n");
    };
    

    return 0;
}
