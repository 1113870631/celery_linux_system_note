#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define LEFT  3000
#define RIGHT 400000
#define THREAD_NUM 1

static int pool=0;
static pthread_t thread_arr[THREAD_NUM];
static pthread_mutex_t  mutex= PTHREAD_MUTEX_INITIALIZER;


void * fun  (void *p ){
    int tmp=(int)p;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(pool>0)
        {
        printf("%d: %d\n",tmp,pool);
        pool=0;
        }
        pthread_mutex_unlock(&mutex);

             if(pool==-1)
            pthread_exit(NULL);
    }
};

int main(int argc , char** argv ) {

    int err,j;

    for(j=0;j<THREAD_NUM;j++){
            if(pthread_create(thread_arr+j, NULL, fun, (void*)j)<0){
                perror("pthread_create:");
                exit(1);
            };
    }

int i=LEFT;
            while(1)
            {
                pthread_mutex_lock(&mutex);
                while(pool==0)
                {
                    pool=i;
                    i++;
               }
               if(i>RIGHT){
                    pool=-1;
                    pthread_mutex_unlock(&mutex);
                    break;
               }
               pthread_mutex_unlock(&mutex);
               sched_yield();
        }
      
    

    for(int j=0;j<THREAD_NUM;j++){
        pthread_join(thread_arr[j],NULL);
    }
    pthread_mutex_destroy(&mutex);

}
