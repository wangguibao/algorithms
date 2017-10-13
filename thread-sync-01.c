/**
 * thread-sync-01.c
 * Two threads work together to print a increasing sequence
 */
#include <pthread.h>
#include <stdio.h>
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

volatile int x = 1;

void *print_odd(void *arg)
{
    int run = 1;
    while (run) {
        pthread_mutex_lock(&lock);
        if (x % 2 == 0) {
            pthread_cond_wait(&cond, &lock);
        }
        fprintf(stdout, "%u\n", x);
        fflush(stdout);
        ++x;
        if (x >= 10) {
            run = 0;
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

void *print_even(void *arg)
{
    int run = 1;
    while (run) {
        pthread_mutex_lock(&lock);
        if (x % 2 == 1) {
            pthread_cond_wait(&cond, &lock);
        }
        fprintf(stdout, "%u\n", x);
        fflush(stdout);
        ++x;
        if (x >= 10) {
            run = 0;
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t th1;
    pthread_t th2;
    int ret = 0;

    ret = pthread_create(&th1, NULL, print_odd, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create error\n");
        return -1;
    }

    ret = pthread_create(&th2, NULL, print_even, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create error\n");
        return -1;
    }

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
