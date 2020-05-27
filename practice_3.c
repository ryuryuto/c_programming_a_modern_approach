//
// Created by ryu on 5/22/20.
//
#include <stdio.h>


void practice3_1(void)
{
    int month,day,year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("You entered the date: %d%.2d%.2d", year, month, day);
}

void practice3_2(void)
{
    int month,day,year;

    printf("Item\t\t\tUnit\t\t\tPurchase\n");
    printf("    \t\t\tPrice\t\t\tDate\n");
    printf("%-4d\t\t\t$%7.2f\t\t%-.2d/%-.2d/%-d",583, 13.5,5,4,2010);
//    printf("Item\tUnit\tPurchase\n");

}

void practice3_4(void)
{
    int a,b,c;
    scanf("(%d)%d-%d",&a,&b,&c);
    printf("You entered %d.%d.%d", a, b, c);
}

//int main(void)
//{
//    practice3_4();
//    return 0;
//}
