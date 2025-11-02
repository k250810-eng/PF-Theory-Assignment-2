#include <stdio.h>
#include <string.h>

void customerinfo(long long *cnic, char name[]);
void displayinventory(int code[], int quantity[], int price[], int size);
void additem(int code[], int quantity[], int price[], int *count,int *cart_count, int cart_code[], int cart_quantity[], float cart_price[], int size);
float calculatetotal(float cart_price[],int cart_count);
float displaytotal(long long cnic, char name[], float totalbill);
void invoice(long long cnic, char name[], float totalbill, float totalwithoutdiscount);



int main(){

    int price[] = {100, 200, 300, 15};
    
    int quantity[] = {50, 10, 20, 8};
    int code[] = {1, 2, 3, 4};
    long long cnic;

    char name[50];
    int size = 4;
    int choice;
    int count = 0;
    float totalbill = 0.0;
    float totalwithoutdiscount= 0.0;

    float cart_price[50] = {0};
    int cart_quantity[50] = {0};
    int cart_code[50] = {0};
    int cart_count = 0;

    customerinfo(&cnic, name);

do{

    
printf("================================================= \n");
printf("Welcome to the interactive menu \n");
printf("---> Press 1 to display inventory \n");
printf("---> Press 2 to add an item to cart \n");
printf("---> Press 3 to carry out a purchase\n");
printf("---> Press 4 to get the invoice \n");
printf("---> Press 5 to exit the program\n");
printf("================================================= \n");

scanf("%d", &choice);

switch(choice){
    case 1:
    displayinventory(code, quantity, price, size);
    break;

    case 2:
    additem(code, quantity, price, &count,&cart_count, cart_code, cart_quantity, cart_price, size);
    break;

    case 3:
    totalbill = calculatetotal(cart_price,cart_count);
    totalwithoutdiscount = totalbill;
    displaytotal(cnic, name, totalbill);
    
    break;

    case 4:
    invoice(cnic, name, totalbill, totalwithoutdiscount);
    break;

    case 5:
    printf("Exiting program... Come back again!! \n");
    break;

    default:
    printf("Invalid choice \n");

}
} while(choice != 5);

    return 0;
}


void customerinfo(long long *cnic, char name[])
{
    printf("Please Enter your name \n");
    scanf(" %[^\n]", name);
    
    printf("Please Enter your 13 digit CNIC number \n");
    scanf("%lld", cnic);

    while(*cnic < 1000000000000 || *cnic > 9999999999999 ){
        printf("Invalid CNIC number, Try Again \n");
        scanf("%lld", cnic);
    }
}
void displayinventory(int code[], int quantity[], int price[], int size){

    printf("============== Inventory List ============== \n");
    printf("======The following items are available======\n");

for (int i =0; i< size; i++)
  {
    printf("Product code: %d | Quantity in stock: %d | Price per product: %d \n", code[i], quantity[i], price[i]);
    printf("\n");   
  }
}

void additem(int code[], int quantity[], int price[], int *count,int *cart_count, int cart_code[], int cart_quantity[], float cart_price[], int size){

    int new_code;
    int new_quantity;

    printf("Enter the product code of the item you want to add to cart \n");
    scanf("%d", &new_code);

    printf("Enter the quantity of the item you want to add to cart \n");
    scanf("%d", &new_quantity);
    
    for(int i =0; i<size; i++){
        if(code[i] == new_code){
            if(quantity[i] >= new_quantity){
                cart_code[*cart_count] = new_code;
                cart_quantity[*cart_count] = new_quantity;
                cart_price[*cart_count] = price[i] *  new_quantity;
                (*cart_count)++;
                quantity[i] -= new_quantity;
                printf("Item added to cart successfully \n");
            } else {
                printf("Insufficient quantity in stock \n");
            }
            return;
        }
    }
    printf("Invalid product code \n");
}

float calculatetotal(float cart_price[],int cart_count){

    float total = 0.0;
    for(int i =0; i< cart_count; i++){
        total += cart_price[i];
    }
    return total;

}



float displaytotal(long long cnic, char name[], float totalbill){

printf("Would you like to check out>? (1 for yes, 0 for no) \n");
int checkout_choice;
float totalwithoutdiscount = totalbill;


scanf("%d", &checkout_choice);
if(checkout_choice == 0){
    printf("Returning to main menu. \n");
    return totalwithoutdiscount;
}

char promocode[20];
int promo_choice;

printf("Enter a promocode if you have one \n");
scanf("%s", promocode);

if(strcmp(promocode, "Eid2025") == 0){
    promo_choice = 1;
} else {
    printf("Invalid promocode \n");
    promo_choice = 0;
}


if(promo_choice == 1){
    totalbill *= 0.75;  
    printf("Total after discount: %.2f \n", totalbill);
} else {
    printf("Total: %.2f \n", totalbill);
}

printf("==============Total Bill ============== \n");
printf("Customer Name: %s \n", name);
printf("CNIC: %lld \n", cnic);        
printf("Total Bill: %.2f \n", totalbill);

return totalwithoutdiscount;
}

void invoice(long long cnic, char name[], float totalbill, float totalwithoutdiscount)
{
    printf("============== Invoice ============== \n");
    printf("Customer Name: %s \n", name);
    printf("CNIC: %lld \n", cnic);
    printf("Total Bill: %.2f \n", totalbill);
    printf("====================================== \n");

    printf("Total Bill (without discount): %.2f \n", totalwithoutdiscount);
}