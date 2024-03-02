#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>
#include"Queue.h"



void GetRandomName(char *name,size_t size)
{
    size_t i;

    for (i = 0; i < size - 1;++i)
        name[i] = 'A' + rand() % 26;
    name[i] = '\0';

}
void GetRandomNumber(int* x, int* y)
{
    *x = rand()%99;
    *y = rand()%99;
}



int main(void)
{
    HQUEUE hQueue;
    int i;
    DotInfo Dot;
    srand(time(NULL));
    if ((hQueue = CreateQueue(10)) == NULL)
    {
        fprintf(stderr, "Cannot create queue! ... \n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 10; ++i) {
        GetRandomName(Dot.Dotname, 32);
        GetRandomNumber(&(Dot.dot_x), &(Dot.dot_y));
        PutItem(hQueue, &Dot);
        printf("%d, %s  x=%d    y=%d \n",i,Dot.Dotname, Dot.dot_x,Dot.dot_y);
    }
  
    float Clc = .0;
    printf("--------\n");
    for (i = 0; i < 10; ++i) {
        GetItem(hQueue, &Dot);

        printf("%d, %s  x=%d    y=%d\n", i, Dot.Dotname, Dot.dot_x, Dot.dot_y);
            
    }

    ClearQueue(hQueue);
    CloseQueue(hQueue);

    return 0;
}

