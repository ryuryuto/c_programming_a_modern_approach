#include <stdio.h>

void practice_2_7(void) {
    int amount, num_20, num_10, num_5, num_1;
    printf("Enter a dollar amount: ");
    scanf("%d",&amount);

    num_20 = amount / 20;
    amount = amount % 20;
    num_10 = amount / 10;
    amount = amount % 10;
    num_5 = amount / 5;
    amount = amount % 5;
    num_1 = amount;

    printf("$20 bills: %d\n",num_20);
    printf("$10 bills: %d\n",num_10);
    printf(" $5 bills: %d\n",num_5);
    printf(" $1 bills: %d\n",num_1);

}

int practice_2_8(void)
{
    float loan,interest_rate,monthly_payment;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    loan=loan - monthly_payment + loan * interest_rate / 100 / 12;
    printf("Balance remaining after first payment: $%.2f\n", loan);
    loan=loan - monthly_payment + loan * interest_rate / 100 / 12;
    printf("Balance remaining after second payment: $%.2f\n", loan);
    loan=loan - monthly_payment + loan * interest_rate / 100 / 12;
    printf("Balance remaining after third payment: $%.2f\n", loan);

    return 0;
}


