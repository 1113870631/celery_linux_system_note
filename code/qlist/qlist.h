#ifndef   Q_LIST_H__
#define Q_LIST_H__

#define MAX_DATA_NUM 4
typedef  int datatype;

typedef struct tagqlist_s
{
    int pos;
    datatype data[MAX_DATA_NUM];
}qlist_s;

qlist_s *  qlist_create(void);

int qlist_destroy(qlist_s * qlist);

int qlist_backadd(qlist_s *qlist,datatype  data);

int qlist_del(qlist_s *qlist,int pos);

int qlist_backdel(qlist_s *qlist);

int qlist_insert(qlist_s *qlist,datatype * data, int pos);

int qlist_search(qlist_s *qlist,datatype * data);

int qlist_is_empty(qlist_s *qlist);

int qlist_show(qlist_s *qlist);


#endif // !  Q_LIST_H__