/****************************************************/
/*   AUTHOR      : Yassmina Abdo Ali                */
/*   Description : StackArray                       */
/*   DATE        : 16 Dec 2021                      */
/*   VERSION     : V01                              */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE    100

typedef struct stack
{
    char Arr[MAX_SIZE];
    int Top;
}Stack;

/************************************************/
/***************Functions Prototypes*************/
/************************************************/
void Stack_voidInitStack(Stack* ps);
void Stack_voidPush(int Copy_CharValue, Stack* ps);
char Stack_CharPop(Stack* ps);
int  Stack_IntIsEmpty(Stack* ps);
int  Stack_intIsFull(Stack* ps);
void Stack_voidPrint(Stack* ps);
void reverse(char* str ,Stack* ps,int size) ;
int IsClosingMatch(char value ,Stack* ps );
void BanlncedChecker(char* str , Stack* ps , int size);


int main()
{
    Stack s;
    Stack* ps= &s;
    char str[]="[()]{}{[()()]()}"; 
    int size =strlen(str);
   
    Stack_voidInitStack(ps);
    
    BanlncedChecker(str,ps,size);


    return 0;
}

/************************************************/
/***************Functions Declaration************/
/************************************************/
void Stack_voidInitStack(Stack* ps)
{
 ps->Top =-1;
}

void Stack_voidPush(int Copy_CharValue, Stack* ps)
{
   if(!Stack_intIsFull(ps))
    {           
        ps->Top++;
        ps->Arr[ps->Top] =  Copy_CharValue;
    }
    else
    {
        printf("Stack is Full \n");
    }

}

char Stack_CharPop(Stack* ps)
{
    if(!Stack_IntIsEmpty(ps))
      
        return ps->Arr[ps->Top--];   
    else
     
        return ' ';   
}

int  Stack_IntIsEmpty(Stack* ps)
{
    if(ps->Top == -1)
        return 1;
    else
        return 0;
    
}

int  Stack_intIsFull(Stack* ps)
{
    return (ps->Top==(MAX_SIZE-1));
     
}

void Stack_voidPrint(Stack* ps)
{
    int Iter = ps->Top;
    while(Iter!=-1)
    {
        printf("%c\n", ps->Arr[Iter]);
        Iter--;
    }
}

 void reverse(char *str ,Stack* ps,int size) 
 {         
        int i;
        for(i = 0; i < size; i++) 
		{
            Stack_voidPush(str[i],ps);
        }

        for(i = 0; i < size; i++) 
		{
            str[i] = Stack_CharPop(ps);
        }       
        
 }
 
 void BanlncedChecker(char* str , Stack* ps , int size)
 {
    int i; 
    for(i=0 ; i<size ; i++)
    {
        if( str[i] == '('||    str[i] =='{'||   str[i] =='[' )       
            Stack_voidPush(str[i],ps);

        

        if( str[i] == ')'||    str[i] =='}'||   str[i] ==']' )
        {
            
            if(!IsClosingMatch(str[i],ps))             
                break;  
            
            else 
                 Stack_CharPop(ps);   
        }
    }

    if(! Stack_IntIsEmpty(ps))
    printf(" Brackets are not balanced \n"); 
    else
    printf(" Brackets are balanced \n"); 


 }
 
 int IsClosingMatch(char value ,Stack* ps )
 {

     if(ps->Arr[ps->Top]== '(' && value ==')')
     return 1;

     if(ps->Arr[ps->Top]== '{' && value =='}')
     return 1;

     if(ps->Arr[ps->Top]== '[' && value ==']')
     return 1;

     return 0;
 }

