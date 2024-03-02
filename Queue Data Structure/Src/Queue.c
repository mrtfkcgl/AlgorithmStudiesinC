#include<stdio.h>
#include<stdlib.h>

#include"Queue.h"

HQUEUE CreateQueue(size_t qsize)
{
    HQUEUE hQueue;
    if ((hQueue = (HQUEUE)malloc(sizeof(QUEUE))) == NULL)
        return NULL;
    if ((hQueue->pQueue = (DATATYPE*)malloc(qsize * sizeof(DATATYPE))) == NULL)
    {
        free(hQueue);
        return NULL;
    }

    hQueue->head = hQueue->tail = hQueue->count = 0; 
    hQueue->qsize = qsize;
    return hQueue;
}


BOOL PutItem(HQUEUE hQueue, const DATATYPE* pVal)
{
    if (hQueue->count == hQueue->qsize)
        return FALSE;
    
    hQueue->pQueue[hQueue->tail++] = *pVal;
   
    /*if (hQueue->tail == hQueue->qsize)
        hQueue->tail = 0;
     */
    hQueue->tail = hQueue->tail % hQueue->qsize;
    ++hQueue->count;
    return TRUE;
}
BOOL GetItem(HQUEUE hQueue, DATATYPE* pVal)
{
    if (hQueue->count =0)
        return FALSE;

    *pVal = hQueue->pQueue[hQueue->head++];
    hQueue->head = hQueue->head % hQueue->qsize;
    --hQueue->count;
    return TRUE;
}

void ClearQueue(HQUEUE hQueue)
{
    hQueue->head = hQueue->tail = hQueue->count = 0;
}

void CloseQueue(HQUEUE hQueue)
{
    free(hQueue->pQueue);
    free(hQueue);
}
