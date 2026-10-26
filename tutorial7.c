#include <stdio.h>
#include <ctype.h>


#define MAX 5


int top = -1;


void push(int *arr, int value)
{


   top++;
   arr[top] = value;
}


int pop(int *arr)
{
   int value = arr[top];
   top--;
   return value;
}


void evaluateExpression(char *exp)
{
   int stack[MAX];


   for (int i = 0; exp[i] != '\0'; i++)
   {
       char ch = exp[i];


       if (isdigit(ch))
       {
           push(stack, ch - '0');
       }
       else
       {
           int v2 = pop(stack);
           int v1 = pop(stack);
           int result;


           switch (ch)
           {
               case '+':
                   result = v1 + v2;
                   break;


               case '-':
                   result = v1 - v2;
                   break;


               case '*':
                   result = v1 * v2;
                   break;


               case '/':
                   result = v1 / v2;
                   break;


               default:
                   printf("Invalid operator: %c\n", ch);
                   return;
           }


           push(stack, result);
       }
   }


   printf("Result = %d\n", pop(stack));
}


int main()
{
   char exp[] = "123*+";


   evaluateExpression(exp);


   return 0;
}
