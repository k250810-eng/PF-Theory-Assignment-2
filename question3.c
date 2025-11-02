#include <stdio.h>

void update(int grid[10][10]);
void query(int grid[10][10]);
void diagnostic(int grid[10][10]);

int main(){

    int grid[10][10] = {0};
    int choice;

    do{
    
    printf("========Welcome to the IESCO Grid Management System======== \n");
    printf("---> Press 1 to update the Sector Status \n");
    printf("---> Press 2 for a Query Status of a Sector \n");
    printf("---> Press 3 for a complete Sector Diagnostics \n");
    printf("---> Press 4 to exit the program \n");

    scanf("%d", &choice);


    switch (choice) 
    { 

        case 1: update(grid);
        break;

        case 2: query(grid);
        break;

        case 3: diagnostic(grid);
        break;

        case 4: printf("Exiting The IESCO Program... \n");
        break;

        default: printf("Invalid Input given, Try Again!\n");

    }

}while(choice!=4);


return 0;
}

void update(int grid[10][10]){

int choice;
int row, col;

printf("Which row do you want to change? \n NOTE:Rows range from 0 to 9 \n --->");
scanf("%d", &row);

printf("Which column do you want to change? \n NOTE:Columns range from 0 to 9 \n --->");
scanf("%d", &col);

printf("Enter the status to update (flip ON (1) or OFF (0)):\n");
printf("1 - Power | 2 - Overload | 3 - Maintenance | 4 - Exit the Update Menu\n");

scanf("%d", &choice);

switch(choice)
{
 case 1:
 grid[row][col] ^= (1<<0);
 printf("Power status at sector (%d,%d) updated successfully \n\n", row, col);
 break;

 case 2:
 grid[row][col] ^= (1<<1);
 printf("Overload status at sector (%d,%d) updated successfully \n\n", row, col);
 break;

 case 3:
 grid[row][col] ^= (1<<2);
 printf("Maintenance status at sector (%d,%d) updated successfully \n\n", row, col);
 break;

 case 4:
    printf("Exiting Update Menu... \n\n");
 break;

 default: printf("Invalid Value entered \n\n");

 }
  
}


void query(int grid[10][10]){

int row, col;    

printf("Enter the row of the sector to query: \n");
scanf("%d", &row);

printf("Enter the column of the sector to query: \n");
scanf("%d", &col);

printf("=====Status Report for sector at (%d,%d)===== \n", row, col);

if(grid[row][col]&(1<<0))
{
    printf("Power at sector with COORDS (%d,%d) is ON\n",row,col);
}
else
{
    printf("Power at sector with COORDS (%d,%d) is OFF\n",row,col);
}

if(grid[row][col]&(1<<1))
{
    printf("EMERGENCY!! Grid at (%d,%d) is overloaded \n",row,col);
}
else
{
    printf("Grid at (%d,%d) is normal \n",row,col);
}    
if(grid[row][col]&(1<<2))
{
    printf("Maintenance Required at (%d,%d) \n\n\n", row, col);
}
else
{
    printf("Maintenance not Required at (%d,%d) \n\n\n", row,col);
}

}


void diagnostic(int grid[10][10])
{
int overload_count =0;
int maintenance_count =0;

for(int i=0; i<10; i++)
{
    for(int j=0; j<10; j++)
    {
        if(grid[i][j] & (1<<1))
        {
            printf("Sector at (%d,%d) is overloaded \n", i, j);
            overload_count++;
        }
        if(grid[i][j] & (1<<2))
        {
            maintenance_count++;
            printf("Sector at (%d,%d) requires maintenance \n", i, j);
        }
    }
 }

 printf("Summary of DIAGNOSTIC REPORT: \n");
printf("Total overloaded sectors: %d\n", overload_count);
printf("Total sectors requiring maintenance: %d\n", maintenance_count);

}