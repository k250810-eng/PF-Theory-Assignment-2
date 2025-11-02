
#define max_size 10
int stack[max_size];
int top = -1;

void push(int data);
int pop(void);
int peek(void);
void display();

#include <stdio.h>

int main(){

    int choice;
    int data;

do{

   printf("\n======Stack Manager======\n");
   printf("Enter: 1 for pushing a new value\n");
   printf("Enter: 2 for popping a previous value\n");
   printf("Enter: 3 to  peek into the stack top \n");
   printf("Enter: 4 to  display the stack values \n");
   printf("Enter: 5 to  Exit from the manager\n");
   scanf("%d", &choice);

   switch(choice){
  
case 1: printf("Enter the value to be pushed onto the stack \n");
        scanf("%d",&data);
        push(data);
        break;

case 2: data = pop();
        if (data!=-999)
            {
              printf("\n Popped value is %d \n", data);
            }
        break;

case 3: data = peak();
         if(data !=-999)
        {
          printf("\n Top value is %d \n", peek());
        }
        break;

case 4: display();
        break;

case 5: printf("\n Exiting the manager.... \n");
        break;

default: printf("\n Invalid Input provided \n");

}

}while(choice != 5);

return 0;
}

// returning -999 represents as an error in all Overflows and Underflows cases

void push(int data){

if(top == max_size - 1)
    {
        printf("Stack Overflow! Cannot push %d onto stack \n", data);
        return;
    }
else
    {  
        top++;
        stack[top] = data;
    }
}

int pop(void){
int value;
if(top == -1)
    {
        printf("Stack Underflow! Cannot Pop last value\n");
        return -999;
    }

else
    {
        value = stack[top];
        top --;
        return value;
    }
}

int peek()
{
if(top == -1)
    {
       printf("Stack Underflow! Cannot Peek \n");
       return -999;
    }
    return stack[top];
}

void display(){

int i = 0;

if(top == -1)
      {
        printf("Stack Underflow! \n");
      }      
else
      {
        for(i = top; i >= 0; i--)
        {
          printf("\n %d", stack[i]);
        }
      }
}
