
#include "CThreadPool.h"

typedef enum{
	immediateShutdown = 1,
	gracefulShutdown = 2,
}threadPool_sd_t;

static int threadPoolFree(threadPool_t *pool);
static void *threadPoolWorker(void *arg);

threadPool_t * threadPoolInit(int threadNum)
{
	if(threadNum <= 0)
	{
		return NULL;
	}
	
	threadPool_t *pool;
	if((pool = (threadPool_t *) malloc(sizeof(threadPool_t))) < 0)
	{
		printf("threadPool malloc error");
		goto err;
	}
	
	pool -> threadCount = 0;
	pool -> queueSize = 0;
	pool -> shutDown = 0;
	pool -> started = 0;
	pool -> threads = (pthread_t *) malloc(sizeof(pthread_t)* threadNum);
	pool -> head = (task_node *) malloc(sizeof(task_node));
	
	if((pool -> threads == NULL) || (pool -> head == NULL))
	{
		printf("pthread malloc error");
		goto err;
	}
	
	pool -> head -> func = NULL;
	pool -> head -> arg = NULL;
	pool -> head -> next = NULL;
	
	if(pthread_mutex_init(&(pool -> lock),NULL) != 0)
	{
		printf("mutex malloc error");
		goto err;
	}
	
	if(pthread_cond_init(&(pool -> cond), NULL) != 0)
	{
		pthread_mutex_destroy((&pool -> lock));
		goto err;
	}
	
	for(int i = 0;i < THREAD_NUM;++i)
	{
		if(pthread_create(&(pool -> threads[i]), NULL, threadPoolWorker, (void *)pool) != 0)
		{
			threadPoolDestroy(pool,0);
			return NULL;
		}
		
		pool -> threadCount++;
		pool -> started++;
	}
	
	printf("pthread_create success");
	return pool;
	
err:
	if(pool)
	{
		threadPoolFree(pool);
	}
	return NULL;
}

static void *threadPoolWorker(void *arg)
{
	if(arg == NULL)
	{
		return NULL;
	}
	
	threadPool_t *pool = (threadPool_t *)arg;
	task_node * task;
	
	while(1)
	{
		pthread_mutex_lock(&(pool -> lock));
		
		printf("I am working \n");
		while((pool -> queueSize == 0) && !(pool -> shutDown))
		{
			pthread_cond_wait(&(pool -> cond), &(pool -> lock));
		}
		
		if(pool -> shutDown == immediateShutdown)
			break;
		else if((pool -> shutDown == gracefulShutdown) && pool -> queueSize == 0)
			break;
		 task = pool -> head -> next;
		if(task == NULL)
		{
			pthread_mutex_unlock(&(pool -> lock));
			continue;
		}
		pool -> head -> next = task -> next;
		pool -> queueSize --;
		
		pthread_mutex_unlock(&(pool -> lock));
		

		(*(task->func))(task -> arg);
		free(task);
	}
	
	pool -> started --;
	pthread_mutex_unlock(&(pool -> lock));
	pthread_exit(NULL);
	
	return NULL;
}


int threadPoolAdd(threadPool_t *pool ,void (*func)(void *),void *arg)
{
	int rc,err = 0;
	if(pool == NULL || func == NULL)
	{
		return -1;
	}
	
	if(pthread_mutex_lock(&(pool -> lock)) != 0)
	{
		return -1;
	}
	
	if(pool -> shutDown == 1)
	{
		err = threadPool_already_shutdown;
		//goto out;
	}
	
	task_node* task = (task_node *) malloc(sizeof(task_node));
	
	if(task == NULL)
	{
		goto out;
	}
	
	task -> func = func;
	task -> arg = arg;
	// 插入在队列的头部
	task -> next = pool -> head -> next;
	pool -> head -> next = task;
	pool -> queueSize ++;
	
	rc = pthread_cond_signal(&(pool -> cond));
	
out:
	if(pthread_mutex_unlock(&(pool -> lock)) != 0)
	{
		return -1;
	}
	return err;
}

int threadPoolDestroy(threadPool_t *pool,int graceful)
{
	int err = 0;
	if(pool == NULL)
	{
		return threadPool_invaild;
	}
	
	if(pthread_mutex_lock(&(pool -> lock)) != 0)
	{
		return threadPool_lock_fail;
	}
	
	do{
		if(pool -> shutDown)
		{
			err = threadPool_already_shutdown;
			break;
		}
		
		pool -> shutDown = (graceful) ? gracefulShutdown : immediateShutdown;
		
		if(pthread_cond_broadcast(&(pool -> cond)) != 0)
		{
			err = threadPool_cond_broadcast;
			break;
		}
		
		for(int i = 0;i < pool -> threadCount;i++)
		{
			if(pthread_join(pool -> threads[i],NULL) != 0)
			{
				err = threadPool_thread_fail;
			}
		}
		
	}while (0);
	
	 if (!err) {
			pthread_mutex_destroy(&(pool->lock));
			pthread_cond_destroy(&(pool->cond));
			threadPoolFree(pool);
		}

	return err;
	
}

int threadPoolFree(threadPool_t * pool)
{
	if(pool == NULL || pool -> started > 0)
	{
		return -1;
	}
	
	if(pool -> threads)
	{
		free(pool -> threads);
	}
	
	task_node * oldTask;
	while(pool -> head -> next)
	{
		oldTask = pool -> head -> next;
		pool -> head -> next = pool -> head -> next -> next;
		free(oldTask);
	}
	return 0;
}