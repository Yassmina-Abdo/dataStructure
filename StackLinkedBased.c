#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE    100

typedef struct stacknode
{
    int data;
    struct stacknode* Next;
}StackNode;

typedef struct stack
{
    StackNode* Top;
    int size;
}Stack;




////////////////////////////////////////////////////////////
void Stack_voidInitStack(Stack* ps);
void Stack_voidPush(int Value, Stack* ps);
void Stack_voidPop(Stack* ps);
int  Stack_IntIsEmpty(Stack* ps);
int  Stack_intIsFull(Stack* ps);
void Stack_voidPrint(Stack* ps);
void Stack_voidClearStack(Stack* ps);
int Stack_IntGetMinStack(Stack* ps);

///////////////////////////////////////////////////////////
int main()
{
    Stack s;
    Stack* ps= &s;
    Stack_voidInitStack(ps);
    int *pd;
    
    Stack_voidPush(1, ps);
    Stack_voidPush(2, ps);
    Stack_voidPush(3, ps);
    Stack_voidPrint(ps);
    int minimum = Stack_IntGetMinStack(ps);
    printf("%d\n", minimum);
     printf("----------------\n");

    Stack_voidPop(ps);
    Stack_voidPrint(ps);

    return 0;
}


//////////////////////////////////////////////////////////
void Stack_voidInitStack(Stack* ps)
{
 ps->Top =NULL;
 ps->size =0;
}
///////////////////////////////////////////////////////////
void Stack_voidPush(int Value, Stack* ps)
{
   
        StackNode* pn= (StackNode*) malloc(sizeof(StackNode));
        pn->data = Value;
        pn->Next = ps->Top;
        ps->Top =pn;
        ps->size++;   
}
////////////////////////////////////////////////////////////
void Stack_voidPop(Stack* ps)
{
    if(!Stack_IntIsEmpty(ps))
    {
      
      StackNode *pn = ps->Top;
      ps->Top = ps->Top->Next;
      free(pn);
      ps->size--;    

    }           
    else
     
        printf("Stack is Empty");
}
/////////////////////////////////////////////////////////////

int  Stack_IntIsEmpty(Stack* ps)
{
    if(ps->Top == NULL)
        return 1;
    else
        return 0;
    
}
////////////////////////////////////////////////////////////

void Stack_voidClearStack(Stack* ps)
{
    
    StackNode* pn = ps->Top;
    while(pn != NULL)
    {
        pn = pn->Next;
        free(ps->Top);
        ps->Top=pn;
    }
    ps->size=0;

}

int Stack_IntGetMinStack(Stack* ps)
{
    
    StackNode* pn = ps->Top;
    int min = pn->data;
    while(pn != NULL)
    {
        if(min >pn->data)
        {
            min =pn->data;
        }
        pn = pn->Next;
          
    }
    return min;   

}
////////////////////////////////////////////////////////////

void Stack_voidPrint(Stack* ps)
{
    StackNode* pn = ps->Top;
    
    while(pn !=NULL)
    {
        printf("%d\n", pn->data);
        pn = pn->Next;      
    }
}

