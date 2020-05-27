//
// Created by ryu on 5/22/20.
//
#include <stdio.h>

void practice5_2(void)
{
    int hour,minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d",&hour,&minute);
    printf("Equivalent 12-hour time: ");

    if(hour == 0 || hour == 24) printf("%d:%d AM",12,minute);
    else if(hour < 12){
        printf("%d:%d AM",hour,minute);
    }
    else if(hour < 13){
        printf("%d:%d PM",hour,minute);
    }
    else{
        printf("%d:%d PM",hour-12,minute);
    }

}

void practice5_4(void)
{
    int speed;

    printf("Enter a wind speed(in knots): ");
    scanf("%d", &speed);
    printf("The description is: ");

    if (speed<1)    printf("Calm");
    else if (speed < 3)   printf("Light air");
    else if (speed < 27)    printf("Breeze");
    else if (speed < 47)    printf("Gale");
    else if (speed < 63)    printf("Storm");
    else    printf("Hurrican");

}

void practice5_6(void)
{
    int a,b,c,d,max,min,max1,min1,max2,min2;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a,&b,&c,&d);
    max=min=a;
    if(a > b)  {
      max1=a;
      min1=b;
    }
    else{
        max1=b;
        min1=a;
    }

    if(c > d)  {
        max2=c;
        min2=d;
    }
    else{
        max2=d;
        min2=c;
    }

    if(max1 > max2)  {
        max=max1;
    }
    else{
        max=max2;
    }

    if(min1 < min2)  {
        min=min1;
    }
    else{
        min=min2;
    }

    printf("Largest: %d\n",max);
    printf("Smallest: %d\n",min);

}

int main(void)
{
    practice5_6();
    return 0;
}

