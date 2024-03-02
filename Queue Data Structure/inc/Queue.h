
#ifndef QUEUE_H_
#define QUEUE_H_

#include<stddef.h>
/*Symbolic constants */
#define FALSE  0
#define TRUE 1 
/*Type Declarations */
typedef int BOOL;


typedef struct tagDotInfo {
    char Dotname[32];
    int dot_x;
    int dot_y;

}DotInfo;

typedef DotInfo DATATYPE;

typedef struct tagQUEUE {
    DATATYPE* pQueue;
    size_t head;
    size_t tail;
    size_t qsize;
    size_t count;

}QUEUE, * HQUEUE;

/*Function Prototypes*/
HQUEUE CreateQueue(size_t qsize);
BOOL PutItem(HQUEUE, const DATATYPE* pVal);
BOOL GetItem(HQUEUE, DATATYPE* pVal);
void ClearQueue(HQUEUE hQueue);
void CloseQueue(HQUEUE hQueue);

/*Macros*/

#define GetCount(hQueue)        ((hQueue)->count)
#define GetSize(hQueue)         ((hQueue)->qsize)
#define IsEmpty(hQueue)         ( !(hQueue)->count)


#endif
