
void reverse_string(char str[]);
void toggle(char str[]);
void unreverse(char str[]);
void untoggle(char str[]);

#define max_length 100

#include <stdio.h>
#include <string.h>

int main(){

 int choice;
 char message[max_length];

 do{

    printf("=======Welcome to the TCS ENCRYPTION and DECRYPTION software======= \n");
    printf("PRESS: 1 To Encrypt a text \n");
    printf("PRESS: 2 To Decrypt a text \n");
    printf("PRESS: 3 To Exit The Program \n");
    scanf("%d",&choice);

    switch(choice){

    case 1:
    printf("\nEnter the Text that You want to Encrypt \n");
    scanf(" %[^\n]", message);
    getchar();
    
    reverse_string(message);
    toggle(message);
    printf("\nEncrypted Text: %s\n", message);

    break;

    case 2:
    printf("\nEnter the Text that You want to Decrypt \n");
    scanf(" %[^\n]", message);
    getchar();

    toggle(message);
    reverse_string(message);
    printf("\nDecrypted Text: %s \n", message);
    break;

    case 3:
    printf("\nExiting the Program....\n");
    break;

    default:
    printf("Invalid Input Provided \n");
    }
 }while(choice!=3);

 return 0;
}


void reverse_string(char str[]){
    
    int length = strlen(str);
    int middle = length / 2;
    char temp;

    for( int i=0; i<middle; i++)
 {
    temp = str[i];
    str[i]= str[length - i - 1];
    str[length - i - 1] = temp;
 }

}


void toggle(char str[]){
    int length = strlen(str);

    for(int i=0; i<length; i++)
 {
    str[i] = str[i]^(1<<2);
    str[i] = str[i]^(1<<5);
 }
}


// keepin these functions for clarity;
void unreverse(char str[])
{
    reverse_string(str);
}

void untoggle(char str[]){
    int length = strlen(str);

    for(int i=0; i<length; i++)
 {
    str[i] = str[i]^(1<<2);
    str[i] = str[i]^(1<<5);
 }

}