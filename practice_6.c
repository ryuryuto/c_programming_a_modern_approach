//
// Created by xhj on 2020/5/27.
//
#include <stdio.h>
#include <stdbool.h>

void practice6_1(void ){
    float a, b=0;
    int count=1;
    do {
        printf("Enter a number: ");
        scanf("%f",&a);
        if(a > 0 && a > b)  b = a;
    }while (a>0);

    if(b > 0)    printf("The largest number entered was %.2f", b);

}

void practice6_2(void ){
    int m, n;
    printf("Enter two integers: ");
    scanf("%d%d", &m, &n);
    while (n > 0){
        //m < n的话没有关系

//        if(m < n){
//            int temp=m;
//            m=n;
//            n=temp;
//        }
        int remainder=m%n;
        m=n;
        n=remainder;

    }


    printf("Greatest common divisor: %d", m);

}
/**
 * 除以最大公约数
 */
void practice6_3(void ){
    int a, b, m, n;
    printf("Enter a fraction: ");
    scanf("%d/%d", &a, &b);
    m=a,n=b;
    while (n > 0){
        //m < n的话没有关系

//        if(m < n){
//            int temp=m;
//            m=n;
//            n=temp;
//        }
        int remainder=m%n;
        m=n;
        n=remainder;

    }


    printf("In lowest terms: %d/%d", a/m, b/m);

}

void practice6_8(void ){
    int days, start;
    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week(1=Sun, 7=Sat): ");
    scanf("%d", &start);
    for (int j = 0; j < (start-1); ++j) {
        printf("    ");//4 spaces
    }
    for (int i = 1; i <= days; ++i) {
        printf("  %2d",i);//2 spaces and 2 width integer
        if((i+start-1)%7==0) printf("\n");
    }


}

void practice6_10(void ){
    int year, month, day, y, m, d, count=1;

    do {
        printf("Enter a date: ");
        scanf("%d/%d/%d", &m, &d, &y);
        if(y > 0 && m > 0 && d > 0){
            if (count == 1){
                year=y;
                month=m;
                day=d;
            } else{
                if(y < year){
                    year=y;
                    month=m;
                    day=d;
                }
                else if(y == year && m < month){
                    month=m;
                    day=d;
                }
                else if(y == year && m == month && d < day){
                    day=d;
                }
            }
            ++count;
        }

    }while (y > 0 && m > 0 && d > 0);

    if(year > 0 && month > 0 && day > 0)
        printf("%.2d/%.2d/%.2d is the earliest date.", month, day, year);

}

void practice6_11(void ){
    unsigned long long num,factorial;
    float e=1;
    printf("Enter a  number: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; ++i) {
        factorial=1;
        for (int j = 1; j <= i; ++j) {
            factorial*=j;
        }
        e+=1.0f/((float )factorial);

    }
    printf("e approximately is %f",e);

}

//int main(void ){
//    practice6_11();
//    return 0;
//}