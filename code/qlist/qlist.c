#include <stdio.h>
#include <stdlib.h>
#include "qlist.h"

qlist_s *  qlist_create(void)
{
    qlist_s * qlist_tmp = NULL;

    qlist_tmp = (qlist_s * )malloc(sizeof(qlist_s));
    if(qlist_tmp == NULL)
    {
        return -1;
    }

    qlist_tmp->pos = -1;
    return qlist_tmp;
};

int qlist_destroy(qlist_s * qlist)
{
    if(qlist != NULL)
    {
        free(qlist);
        return 1;
    }
    return -2;
};

int qlist_backadd(qlist_s *qlist,datatype  data)
{
    if(qlist->pos >=(MAX_DATA_NUM-1)|| qlist->pos <-1)
    {
        return -3;
    }
    qlist->pos++;
    qlist->data[qlist->pos] = data;
    return qlist->pos;
};

int qlist_insert(qlist_s *qlist,datatype * data, int pos)
{
    return 0;
};

int qlist_search(qlist_s *qlist,datatype * data)
{
    return 0;
};

int qlist_is_empty(qlist_s *qlist)
{
    if(qlist->pos < 0)
    {
        return 1;
    }
    return 0;
};

int qlist_show(qlist_s *qlist)
{
    if(qlist_is_empty(qlist))
    {
        return -1;
    }

    for(int i=0;i <=qlist->pos;i++)
    {
        printf("%d\n",qlist->data[i]);
    }
    return 1;
};


int qlist_del(qlist_s *qlist,int pos)
{
    if(qlist_is_empty(qlist))
    {
        return -1;
    }
    if(pos > qlist->pos)
    {
        return -1;
    }

    int  tmp_pos = pos;
    
    if(tmp_pos == qlist->pos)
    {
       
    }
    else
    {
            for(int i = tmp_pos; i<qlist->pos; i++)
        {
            qlist->data[i] = qlist->data[i+1];
        }
    }
     qlist->pos--;
    return 0;
};


int qlist_backdel(qlist_s *qlist)
{
    if(qlist_is_empty(qlist))
    {
        return -1;
    }
    qlist->pos--;
    return qlist->pos;
};