#include <stdio.h>

void addbook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void process(int isbns[], float prices[], int quantities[], int count);
void stock(int isbns[], char titles[][50], float prices[], int quantities[], int count);

int main(){
int isbns[100];
char titles[100][50];
float prices[100];
int quantities[100];
int count = 0;

int choice;

printf("Enter the number of books that you want to enter the value of \n ");
scanf("%d",&count);

for(int i = 0; i < count ; i++){

    printf("Enter the ISBN number of book %d: ",i+1);
    scanf("%d",&isbns[i]);

    while(isbns[i]<0){
        printf("Invalid ISBN number (cannot be negative try again)");
        scanf("%d",&isbns[i]);
    }

    printf("Enter the title name for book %d: ",i+1);
    scanf(" %[^\n]",titles[i]);

    printf("Enter the price for book %d: ",i+1);
    scanf("%f",&prices[i]);

    while(prices[i]<0){
        printf("Invalid price");
        scanf("%f",&prices[i]);
    }

    printf("Enter the quantity for book %d: ", i+1);
    scanf("%d", &quantities[i]);


    while(quantities[i]<0){
        printf("Invalid amount");
        scanf("%f",&quantities[i]);
    }
}

do{
printf("================================================= \n");
printf("Welcome to the interactive menu \n");
printf("--> Enter 1 to add a book \n");
printf("--> Enter 2 to process a sale for a book \n");
printf("--> Enter 3 to generate out of stock update \n");
printf("--> Enter 4 to exit the program \n");
printf("=================================================\n");

scanf("%d",&choice);

switch (choice)
{
    case 1:
    addbook(isbns, titles, prices, quantities, &count);
    break;

    case 2:
    process(isbns, prices, quantities, count);
    break;

    case 3:
    stock(isbns, titles, prices, quantities, count);
    break;

    case 4:
    printf("Exiting program... \n");
    break;

    default: printf("Invalid choice \n");
    
}

}while(choice!=4);

return 0;
}

void addbook(int isbns[], char titles[][50], float prices[], int quantities[], int *count){

    if(*count >= 100){
        printf("Cannot add more books. Inventory is full.\n");
        return;
    }

    int new_isbn;
    int new_books;

    printf("How Many Books do you want to add? \n");
    scanf("%d", &new_books);

if( *count + new_books > 100){
    printf("Book limit exceeded");
    return;
}

for( int i = 0; i< new_books; i++)
 {      
    printf("Enter the ISBN of the new book: \n");
    scanf("%d", &new_isbn);
    
     while(new_isbn<0)
   {
        printf("ISBN number cannot be less than zero \n");
        printf("Try again \n");
        scanf("%d", &new_isbn);
   }
   
   for( int j = 0; j< *count; j++){
     
   if( isbns[j]== new_isbn)
   {
        printf("Book with ISBN %d already exists.\n", new_isbn);
        continue;   
   }   
}
 
 isbns[*count] = new_isbn;

    printf("Enter the quantity of the new book: ");
    scanf("%d", &quantities[*count]);

    while(quantities[*count]< 0){
        printf("invalid amount, Try Again \n");
        scanf("%d", &quantities[*count]);
    }
    
    printf("Enter the title of the new book: ");
    scanf(" %[^\n]", titles[*count]);

    printf("Enter the price of the new book: ");
    scanf("%f", &prices[*count]);

    while(prices[*count]< 0){
        printf("Invalid price entered, Try again \n");
        scanf("%f",&prices[*count]);
    }


     (*count)++;
  }
}   
    
void process(int isbns[], float prices[], int quantities[], int count){

    int new_isbn;
    int copies_sold;

    printf("Enter the ISBN of the book \n");
    scanf("%d", &new_isbn);
    
    printf("Enter the number of copies sold \n");
    scanf("%d",&copies_sold);

    for ( int i = 0; i< count; i++){

           
     if(new_isbn == isbns[i] && quantities[i] >= copies_sold ){
        quantities[i] = quantities[i] - copies_sold;
        printf("Transaction successful \n");
        printf("remaining quantity is %d \n",quantities[i]);
        return;
     }
    else if (new_isbn == isbns[i] && quantities[i] < copies_sold){
        printf("Not enough copies in stock \n");
        return;
     } 
    }
    printf("Book with ISBN %d not found in inventory.\n", new_isbn);
} 


void stock(int isbns[], char titles[][50], float prices[], int quantities[], int count){

    printf("=============================================================== \n");
    printf("====================Books in low quantity====================== \n");

    for ( int i=0; i<count ; i++ )
    {
        
         if (quantities[i] <= 5)
         {
          printf("Book no %d, Isbn: %d, Book Name: %s, Price: %.2f , quanitity left: %d \n", i+1, isbns[i], titles[i], prices[i], quantities[i]);
         }
    }
}