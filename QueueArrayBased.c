/****************************************************/
/*   AUTHOR      : Yassmina Abdo Ali                */
/*   Description : QueueArrayBased                  */
/*   DATE        : 16 Dec 2021                      */
/*   VERSION     : V01                              */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE    100

typedef struct queue
{
    int Arr[MAX_SIZE];
    int Front;
    int Rear;
    int size;
}Queue;

/************************************************/
/***************Functions Prototypes*************/
/************************************************/
void Queue_voidInitQueue(Queue* pq);
void Queue_voidEnqueue(int Copy_IntValue, Queue* pq);
void Queue_voidDequeue(Queue* pq, int* pd);
int  Queue_IntIsEmpty(Queue* pq);
int  Queue_IntIsFull(Queue* pq);
void Queue_voidPrint(Queue* pq);
void Queue_voidReturnFrontValue(Queue* pq ,int* pd);




int main()
{
    int FrontValue;
    Queue Q;
    Queue* qs= &Q;
    Queue_voidInitQueue(qs);
    
    
    Queue_voidEnqueue(1,qs);
    Queue_voidEnqueue(2,qs);
    Queue_voidEnqueue(3,qs);

    printf("After Enqueue\n");
    Queue_voidPrint(qs);
    printf("============================ \n");


    Queue_voidDequeue(qs, &FrontValue);
    printf("After Dequeue\n");
    Queue_voidPrint(qs);
    printf("============================ \n");

    Queue_voidReturnFrontValue(qs, &FrontValue);
    printf(" Front Value Now is: %d",FrontValue); 


    return 0;
}

/************************************************/
/***************Functions Declaration************/
/************************************************/
void Queue_voidInitQueue(Queue* pq)
{
    pq->Front =-1;
    pq->Rear = -1;
    pq->size=0;
}

void Queue_voidEnqueue(int Copy_IntValue, Queue* pq)
{
    if(!Queue_IntIsFull(pq))
    {       
        if(pq->Front== -1)    
            pq->Front= 0;

        pq->Rear++;    
        pq->Arr[pq->Rear] =  Copy_IntValue;
        pq->size++;
    }
    else
    {
        printf("Queue is Full \n");
    }

}

void Queue_voidDequeue(Queue* pq, int* pd)
{

    if(!Queue_IntIsEmpty(pq))
    {
       *pd = pq->Arr[pq->Front];
       pq->Front++;
       pq->size--;

       if(pq->Front>pq->Rear)
       {
          pq->Front =pq->Rear = -1;
          pq->size--;
       }
    }
               
    else
     
       printf("Queue is Empty\n");
}

int  Queue_IntIsEmpty(Queue* pq)
{
    if(pq->Front == -1)
        return 1;
    else
        return 0;
    
}

int  Queue_IntIsFull(Queue* pq)
{
    return (pq->Rear ==(MAX_SIZE-1));
     
}

void Queue_voidPrint(Queue* pq)
{
    int i;
    for(i=pq->Front ; i<= pq->Rear ; i++)
    {
        printf("%d\n", pq->Arr[i]);       
    }
}

void Queue_voidReturnFrontValue(Queue* pq ,int* pd)
{
   *pd = pq->Arr[pq->Front];
}

 
 

