#include "relayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>



#define MAXJOB  100
#define BUF_SIZE 1024

enum STAT
{
    STAT_R=0,
    STAT_W,
    STAT_E,
};
struct  job_stat
{   
    enum STAT stat_now;
    int fd1;
    int fd2;
    char buffer[BUF_SIZE];
    int len;
    int pos;
};

struct job_str
{
    int job_id;
    int fd1;
    int fd2;
    struct  job_stat job_stat_driver;
};


static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static struct job_str** job_arr=NULL;



void relayer_drive(struct job_str *job)
{
    int ret;
        switch (job->job_stat_driver.stat_now)
        {
        case  STAT_R:
               ret = read(job->fd1,job->job_stat_driver.buffer,BUF_SIZE);
                if(ret < 0)
                {
                    if(errno == EAGAIN)
                    {
                        job->job_stat_driver.stat_now=STAT_R;
                    }
                    else
                    {
                          job->job_stat_driver.stat_now=STAT_E;
                    }
                }     
                else
                {
                    job->job_stat_driver.len=ret;
                    job->job_stat_driver.pos=0;
                    job->job_stat_driver.stat_now=STAT_W;
                }
            break;

        case  STAT_W:
               ret =  write(job->fd2,job->job_stat_driver.buffer+job->job_stat_driver.pos,job->job_stat_driver.len);
                if(ret < 0)
                {
                    if(errno == EINTR)
                    {
                        job->job_stat_driver.stat_now=STAT_W;
                    }
                    else
                    {
                        job->job_stat_driver.stat_now=STAT_E;
                    }
                }
                else 
                {
                    if((job->job_stat_driver.len-ret)>0)
                    {
                        job->job_stat_driver.pos=ret;
                        job->job_stat_driver.len=job->job_stat_driver.len-ret;
                        job->job_stat_driver.stat_now=STAT_W;
                    }
                    else
                    {
                        job->job_stat_driver.stat_now=STAT_R;
                    }

                }
            break;

        case  STAT_E:
            /* code */
            break;           

        default:
            break;
        }
    }


void * thread_fun(void * p)
{
    int i;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        for ( i=0;i<MAXJOB;i++)
        {
            if(job_arr[i]!=NULL&&job_arr[i]->job_stat_driver.stat_now!=STAT_E)
            {
                relayer_drive(job_arr[i]);
            }
        }
        pthread_mutex_unlock(&mutex);  
    }
    
}


int mod_init(void)
{
    pthread_t tid;
    int ret;
    job_arr=(struct job_str**)malloc(sizeof(struct job_str *)*MAXJOB);
    if(job_arr==NULL)
    {
        return -2;
    }
    ret = pthread_create(&tid,NULL,thread_fun,NULL);
    if(ret < 0)
    {
        return -1;
    }
};


int mod_rmove(void)
{
    free(job_arr);
};

int get_freepos_unlock(struct job_str** arr,int max)
{
        int pos;
        for(pos=0;pos<max;pos++)
        {
            if(arr[pos]==NULL)
            return pos;
        }
        return -1;
};



int job_add(int fd1,int fd2,int *job_id)
{
   struct job_str* me=NULL;
   me=malloc(sizeof(*me));
   if(me==NULL)
        return -3;

    me->fd1=fd1;
    me->fd2=fd2;
    me->job_stat_driver.fd1=fd1;
    me->job_stat_driver.fd2=fd2;
    me->job_stat_driver.stat_now=STAT_R;
    me->job_stat_driver.pos=0;
    me->job_stat_driver.len=0;

    pthread_mutex_lock(&mutex);
    me->job_id=get_freepos_unlock(job_arr,MAXJOB);
    pthread_mutex_unlock(&mutex);

    if(me->job_id>=0)
    {
        job_arr[me->job_id]=me;
        *job_id=me->job_id;
        return 0;
    }
    else
        return -2;
};


int job_cancel(int *job_id)
{

};


