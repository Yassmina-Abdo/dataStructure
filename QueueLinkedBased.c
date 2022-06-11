/****************************************************/
/*   AUTHOR      : Yassmina Abdo Ali                */
/*   Description : QueueLinkedBased                  */
/*   DATE        : 16 Dec 2021                      */
/*   VERSION     : V01                              */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct queuenode
{
    int data;
    int* Next;
    
}QueueNode;

typedef struct queue
{
    
    QueueNode* Front;
    QueueNode* Rear;
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
void Queue_voidClearQueue(Queue* pq);
int  Queue_intSize(Queue* pq);




int main()
{
    int FrontValue,size;
    Queue Q;
    Queue* qs= &Q;
    Queue_voidInitQueue(qs);
    
    
    Queue_voidEnqueue(1,qs);
    Queue_voidEnqueue(2,qs);
    Queue_voidEnqueue(3,qs);

    printf("After Enqueue\n");
    Queue_voidPrint(qs);
    printf("============================ \n");

    size = Queue_intSize(qs);
    printf("Size is %d\n",size);
    printf("============================ \n");

    Queue_voidDequeue(qs, &FrontValue);
    printf("After Dequeue\n");
    Queue_voidPrint(qs);
    printf("============================ \n");

    Queue_voidReturnFrontValue(qs, &FrontValue);
    printf(" Front Value Now is: %d",FrontValue); 

    //Queue_voidClearQueue(qs);


    return 0;
}

/************************************************/
/***************Functions Declaration************/
/************************************************/
void Queue_voidInitQueue(Queue* pq)
{
    pq->Front =NULL;
    pq->Rear = NULL;
    pq->size=0;
}

void Queue_voidEnqueue(int Copy_IntValue, Queue* pq)
{
    QueueNode* pn= (QueueNode*) malloc(sizeof(QueueNode));
    pn->data = Copy_IntValue;
    pn->Next = NULL;

    if(pq->Front == NULL)
    {
        pq->Front =pn;
    }
    else
    {
       pq->Rear->Next =pn;
    }
    pq->Rear= pn;
    pq->size++;
          

}

void Queue_voidDequeue(Queue* pq, int* pd)
{

    
    QueueNode* pn= pn= pq->Front;  
    *pd = pn->data;  
    pq->Front= pq->Front->Next;   
    free(pn);
    
    if(Queue_IntIsEmpty(pq))    
    {
        pq->Rear= NULL;
    }
    
    pq->size--; 
}

int  Queue_IntIsEmpty(Queue* pq)
{
    if(pq->Front == NULL)
        return 1;
    else
        return 0;
    
}

int  Queue_IntIsFull(Queue* pq)
{
    return 0;
     
}

void Queue_voidPrint(Queue* pq)
{
     QueueNode* pn = pq->Front;
    
    while(pn !=NULL)
    {
        printf("%d\n", pn->data);
        pn = pn->Next;      
    }
}

void Queue_voidReturnFrontValue(Queue* pq ,int* pd)
{
    if(!Queue_IntIsEmpty(pq))
    {    
        *pd= pq->Front->data;
    }
    else
    {
        printf("Queue is Empty\n");
    }          
}
int  Queue_intSize(Queue* pq)
{
    return pq->size;
}
 
 void Queue_voidClearQueue(Queue* pq)
{
    
    while(pq->Front != NULL)
    {     
        pq->Rear = pq->Front->Next;       
        free(pq->Front);      
        pq->Front = pq->Rear;
    }  
    pq->size=0;
}

