#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float totalBill = 0.0; //global variable

//function prototypes
void coffeeOrder(float *coffeeBill);
void tableReservation(float *tableReservationBill);

int main(void)
{

        int option , payment;

        printf("Welcome to Coffee Shop!\n");
        printf("01. Order Coffee\n02. Table Reservation\n03. Exit\n");
        scanf("%d" , &option);

        switch(option)
        {
            case 1:
            coffeeOrder(&totalBill); //call by reference
            break;

            case 2:
            tableReservation(&totalBill); //call by reference
            break;

            case 3:
            printf("Good bye!");
            exit(0);

            default:
            printf("Wrong choice!");
        }
        char time[10];
        printf("At what time? ");
        scanf("%s" , time);
        printf("\nYour order was successfull!\n");
        printf("Your total bill is %.2f\n" , totalBill);
        printf("See you at %s!\n\n" , time);
}

//coffee order function
void coffeeOrder(float *coffeeBill)
{
    int quantity;
    char coffee[5][20] = {"01.Espresso" , "02.Cappuccino" , "03.Latte" , "04.Americano" , "05.Mocha"};
    float coffeePrice[5] = {350 , 400 , 300 , 500 , 250};

    printf("Menu\n======\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s - Rs. %.2f\n" , coffee[i] , coffeePrice[i]);
    }

    char option = 'y';
    while(option == 'y')
    {
        int coffeeNumber;
        printf("Enter the code of the coffee : ");
        scanf("%d" , &coffeeNumber);

        if(coffeeNumber <= 0 || coffeeNumber > 5)
        {
            printf("Error! Invalid number. Please enter a valid coffee number like(1,2,3,4,5)\n\n");
            continue;
        }

        printf("Enter quantity : ");
        scanf("%d" , &quantity);


        //calculating bill
        *coffeeBill += coffeePrice[coffeeNumber-1] * quantity;

        printf("Do you want to make another order? y/n : \n");
        scanf("%s" , &option);
    }
    char tableReserve;
    printf("Do you want to reserve a table ? (y/n)");
    scanf("%s" , &tableReserve);
    switch(tableReserve)
    {
        case 'y':
        tableReservation(&totalBill);
        break;

        case 'n':
        break;

        default:
        printf("Invalid choice\n");
    }


}

//table reservation function
void tableReservation(float *tableReservationBill)
{
    int tableNumber;
    float tablePrice;

    printf("+------- COUNTER -------+\n");
    printf("|      Order Here       |\n");
    printf("+-----------------------+\n");
    printf("| T1(2) | T2(4) | T3(2) |\n");
    printf("| T4(4) | T5(2) | T6(4) |\n");
    printf("| T7(2) | T8(4) | T9(2) |\n");
    printf("+------- WINDOWS -------+\n\n\n");

    loop:printf("Which table would you like to reserve : ");
    scanf("%d" , &tableNumber);

    if(tableNumber < 1 || tableNumber > 9)
    {
        printf("Invalid choice! Please enter a valid table number\n\n");
        goto loop;
    }

    if(tableNumber % 2 == 1)
    {
        tablePrice = 500.00;
    }
    else
    {
        tablePrice = 800.00;
    }



    *tableReservationBill += tablePrice;


}
