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

/*
 * 两两比较，再对比较结果进行比较，用的if最少
 */
void practice5_7(void)
{
    int a,b,c,d,max,min,max1,min1,max2,min2;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a,&b,&c,&d);

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

void practice5_8(void)
{
    int hour, minute, minutesSinceMidnight;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour,&minute);
    minutesSinceMidnight = hour * 60 + minute;
    printf("Closest departure time is ");
    if(minutesSinceMidnight < 8 * 60)  {
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    }else if (minutesSinceMidnight < 9 * 60 + 43){
        if((minutesSinceMidnight - 8 * 60) < ((9 * 60 + 43) - minutesSinceMidnight))
            printf("8:00 a.m., arriving at 10:16 a.m.\n");
        else
            printf("9:43 a.m., arriving at 11:52 a.m.\n");
    }else if (minutesSinceMidnight < 11 * 60 + 19){
        if((minutesSinceMidnight - (9 * 60 + 43)) < ((11 * 60 + 19) - minutesSinceMidnight))
            printf("9:43 a.m., arriving at 11:52 a.m.\n");
        else
            printf("11:19 a.m., arriving at 1:31 p.m.\n");
    }else if (minutesSinceMidnight < 12 * 60 + 47){
        if((minutesSinceMidnight - (11 * 60 + 19)) < ((12 * 60 + 47) - minutesSinceMidnight))
            printf("11:19 a.m., arriving at 1:31 p.m.\n");
        else
            printf("12:47 a.m., arriving at 3:00 p.m.\n");
    }else if (minutesSinceMidnight < 14 * 60){
        if((minutesSinceMidnight - (12 * 60 + 47)) < (14 * 60 - minutesSinceMidnight))
            printf("12:47 a.m., arriving at 3:00 p.m.\n");
        else
            printf("2:00 p.m., arriving at 4:08 p.m.\n");
    }else if (minutesSinceMidnight < 15 * 60 + 45){
        if((minutesSinceMidnight - 14 * 60) < ((15 * 60 + 45) - minutesSinceMidnight))
            printf("2:00 p.m., arriving at 4:08 p.m.\n");
        else
            printf("3:45 p.m., arriving at 5:55 p.m.\n");
    }else if (minutesSinceMidnight < 19 * 60){
        if((minutesSinceMidnight - (15 * 60 + 45)) < (19 * 60 - minutesSinceMidnight))
            printf("3:45 p.m., arriving at 5:55 p.m.\n");
        else
            printf("7:00 p.m., arriving at 9:20 p.m.\n");
    }else if (minutesSinceMidnight < 21 * 60 + 45){
        if((minutesSinceMidnight - 19 * 60) < ((21 * 60 + 45) - minutesSinceMidnight))
            printf("7:00 p.m., arriving at 9:20 p.m.\n");
        else
            printf("9:45 p.m., arriving at 11:58 p.m.\n");
    }


}

//int main(void)
//{
//    practice5_8();
//    return 0;
//}

