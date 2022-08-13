#ifndef RELAYER_H__
#define RELAYER_H__





int mod_init(void);


int mod_rmove(void);


/**
 * @brief 
 * 添加一个工作
 * @param fd1  目标文件
 * @param fd2  源文件
 * @param job_id  成功生成job的job ID 失败为NULL
 * @return int  
 *        0   成功
 *      -1   输入数据有误
 *      -2    内存空间不足
 *      -3     malloc 失败
 */
int job_add(int fd1,int fd2,int * job_id);


/**
 * @brief 
 * 取消一个job
 * @param job_id  要取消job的job ID
 * @return int 
 *      0   取消成功
 */
int job_cancel(int *job_id);






#endif // !RELAYER_H__