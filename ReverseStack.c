#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE        100

typedef struct stack
{
    int Arr[MAX_SIZE];
    int Top;
}Stack;

void Stack_voidInitStack(Stack* ps);
void Stack_voidPush(int Copy_intValue, Stack* ps);
int Stack_INTPop(Stack* ps);

int  Stack_intIsEmpty(Stack* ps);
int  Stack_intIsFull(Stack* ps);
void Stack_voidPrint(Stack* ps);

///////////////////////////////////////////////////////////
int main()
{
    Stack s;
    Stack_voidInitStack(&s);
    Stack* ps= &s;
    
    Stack_voidInitStack(ps);
    Stack_voidPush(1,ps);
    Stack_voidPush(2,ps);
    Stack_voidPush(3,ps);
    
    return 0;
}


//////////////////////////////////////////////////////////
void Stack_voidInitStack(Stack* ps)
{
 ps->Top =-1;
}
///////////////////////////////////////////////////////////
void Stack_voidPush(int Copy_intValue, Stack* ps)
{
   if(!Stack_intIsFull(ps))
    {           
        ps->Top++;
        ps->Arr[ps->Top] =  Copy_intValue;
    }
    else
    {
        printf("Stack is Full \n");
    }

}
////////////////////////////////////////////////////////////
int Stack_INTPop(Stack* ps)
{
    if(!Stack_intIsEmpty(ps))
       { ps ->Top--;
        return ps->Arr[ps->Top];
       }
    else
        {
           
        return 0;
        }
}
/////////////////////////////////////////////////////////////

int  Stack_IntIsEmpty(Stack* ps)
{
    if(ps->Top == -1)
        return 1;
    else
        return 0;
    
}
////////////////////////////////////////////////////////////
int  Stack_IntIsFull(Stack* ps)
{
    return (ps->Top==(MAX_SIZE-1));
     
}
////////////////////////////////////////////////////////////
void Stack_voidPrint(Stack* ps)
{
    int Iter = ps->Top;
    while(Iter!=-1)
    {
        printf("%d", ps->Arr[Iter]);
        Iter--;
    }
}

