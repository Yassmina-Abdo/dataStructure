/****************************************************/
/*   AUTHOR      : Yassmina Abdo Ali                */
/*   Description : ListLinkedBased                  */
/*   DATE        : 16 Dec 2021                      */
/*   VERSION     : V01                              */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct listnode
{
    struct listnode* Next;  
    int data;    
}ListNode;

typedef struct list
{
    
    ListNode* head;
    int size;
}List;

/************************************************/
/***************Functions Prototypes*************/
/************************************************/
void List_voidInitList(List* pl);
void List_voidInsertList(int Pos, List* pl, int Copy_intValue);
void List_voidReplaceList(int Pos, List* pl, int Copy_intValue);
void List_voidDeleteList(int Pos, List* pl, int* pd);
void List_voidRetriveList(int Pos, List* pl, int* pd);
int  List_intIsEmpty(List* pl);
int  List_intIsFull(List* pl);
int  List_intSize(List* pl);
void List_voidPrint(List* pl);
void List_voidDestroyList(List* pl);



int main()
{
    int size, RetrivedValue;
    List L;

    List_voidInitList(&L);

    List_voidInsertList(0,&L,1);
    List_voidInsertList(1,&L,2);
    List_voidInsertList(2,&L,3);
    
    size= List_intSize(&L);

    printf("The size of the list is = %d\n", size);
    printf("The elements of the list are\n");
    List_voidPrint(&L);

    List_voidRetriveList(2, &L, &RetrivedValue);
    printf("\nThe RetrivedValue is = %d\n", RetrivedValue);

    List_voidDeleteList(1,&L, &RetrivedValue);
    printf("The RetrivedValue is= %d\n", RetrivedValue);
    
    size= List_intSize(&L);
    printf("The size of the list is= %d\n", size);

    List_voidReplaceList(1, &L, 4);
    printf("The elements of the list are\n");
    List_voidPrint(&L);


    


    return 0;
}

/************************************************/
/***************Functions Declaration************/
/************************************************/
void List_voidInitList(List* pl)
{
    pl->head =NULL;
    pl->size=0;
}

void List_voidInsertList(int pos, List* pl,int Copy_IntValue)
{
    ListNode* q;
    int i;

    ListNode* pn= (ListNode*) malloc(sizeof(ListNode));
    pn->data = Copy_IntValue;
    pn->Next = NULL;

    if(pos ==0)
    {
        pn->Next = pl->head;
        pl->head =pn;
    }
    else
    {
       for(q= pl->head ,i=0 ; i< pos-1 ; i++)
       {
          q= q->Next;
       }
       pn->Next = q->Next;
       q->Next = pn;
    }
   
    pl->size++;
}

void List_voidReplaceList(int Pos, List* pl, int Copy_intValue)
{
    int i;
    ListNode* q;
    for(q= pl->head, i=0; i<Pos; i++)
    {
        q = q->Next;
    }
    q->data= Copy_intValue;
}

void List_voidDeleteList(int Pos, List* pl, int* pd)
{
    int i;
    ListNode *q, *tmp;
    if(Pos==0)
    {
        *pd = pl->head->data;
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }
    else
    {
        for(q= pl->head, i=0; i<Pos-1; i++)
        {
            q = q->Next;
        }
       *pd = q->Next->data;
        tmp= q->Next->Next;
        free(q->Next);
        q->Next = tmp;
    }
    pl->size--;
}
void List_voidRetriveList(int Pos, List* pl, int* pd)
{
    int i;
    ListNode* q;

    for(q= pl->head, i=0; i< Pos; i++)
    {
        q = q->Next;
    }
    *pd= q->data;
}

void List_voidPrint(List* pl)
{
    ListNode* q= pl->head;
    while(q != NULL)
    {
        printf("%d\t", q->data);
        q= q->Next;
    }
}

void List_voidDestroyList(List* pl)
{
    ListNode* tmp;

    while(pl->head != NULL)         
    {
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }

    pl->size=0;
}

int  List_intSize(List* pl)
{
    return (pl->size);
}

int  List_intIsEmpty(List* pl)
{
    return (pl->head == NULL);
}

int  List_intIsFull(List* pl)
{
    return 0;
}





