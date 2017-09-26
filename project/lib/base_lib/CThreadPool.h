
#ifndef CThreadPool
#define CThreadPool

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define THREAD_NUM 8

struct task_node {
	void (*func)(void *);
	void * arg;
	struct task_node *next;
};

typedef struct {
	pthread_mutex_t lock;
	pthread_cond_t cond;
	pthread_t * threads;
	struct task_node *head;
	int threadCount;
	int queueSize;
	int shutDown;
	int started;
}threadPool_t;

typedef enum{
	threadPool_invaild = -1,
	threadPool_lock_fail = -2,
	threadPool_already_shutdown = -3,
	threadPool_cond_broadcast = -4,
	threadPool_thread_fail = -5,
} threadPool_error_t;

threadPool_t* threadPoolInit(int thread_num);
int threadPoolAdd(threadPool_t *pool, void(*func)(void *),void * arg);
int threadPoolDestroy(threadPool_t *poll,int g);

#endif