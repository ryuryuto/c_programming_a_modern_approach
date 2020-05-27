//
// Created by ryu on 5/22/20.
//
#include <stdio.h>
#include <math.h>

void practice4_2(void)
{
    int num;


    printf("Enter a three-digit number: ");
    scanf("%d", &num);
    printf("Reversed number is ");
    if(num==0) printf("%d",num);
    while (num!=0)
    {
        printf("%d",num%10);
        num=num/10;
    }

}

void practice4_4(void)
{
    int num,result=0,base=1;


    printf("Enter a number: ");
    scanf("%d", &num);

    while (num!=0)
    {
        result+=base*(num%8);
        num=num/8;
        base*=10;
    }

    printf("In octal, your number is 0%d",result);

}
//
//void practice3_4(void)
//{
//    int a,b,c;
//    scanf("(%d)%d-%d",&a,&b,&c);
//    printf("You entered %d.%d.%d", a, b, c);
//}

int main(void)
{
    practice4_4();
    return 0;
}
