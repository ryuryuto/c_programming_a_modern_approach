//
// Created by xhj on 2020/5/28.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

void practice7_1(void ){
    for (short i = 100; i < 1000; ++i) {
        if((short)(i*i) <(short)((i - 1) * (i - 1))){
            printf("%30hd%30hd\n", i,(short)(i * i));
            break;
        }

    }
    for (int j = 10000; j < 100000; ++j) {
        if((j * j) < ((j - 1) * (j - 1))){
            printf("%30d%30d\n", j, (j * j));
            break;
        }
    }
//    printf("%30ld%30ld\n", 3037000499, 3037000499 * 3037000499);
    for (long k = 1000000000L; k < 10000000000L; ++k) {
        if((long)(k * k) < (long)((k - 1) * (k - 1))){
            printf("%30ld%30ld\n", k, (long)(k * k));
            break;
        }

    }
}

void practice7_2(void ){
    int c;
    for (int j = 1; j < 100; ++j) {
        printf("%10d%10d\n", j, j * j);

        if(j % 24 == 0){

            printf("Press Enter to continue...");
            //可能输入连串任意字符，全部从输入流缓存取出
            while ((c = getchar()) != '\n'){
//                printf("Press Enter to continue...");
            }
        }
    }
}

void practice7_4(void ){
    int c;
    printf("Enter phone number: ");
    while ((c = toupper(getchar()) ) != '\n'){
        switch (c) {
            case 'A':   case 'B':   case 'C':
                putchar('2');
                break;
            case 'D':   case 'E':   case 'F':
                putchar('3');
                break;
            case 'G':   case 'H':   case 'I':
                putchar('4');
                break;
            case 'J':   case 'K':   case 'L':
                putchar('5');
                break;
            case 'M':   case 'N':   case 'O':
                putchar('6');
                break;
            case 'P':   case 'R':   case 'S':
                putchar('7');
                break;
            case 'T':   case 'U':   case 'V':
                putchar('8');
                break;
            case 'W':   case 'X':   case 'Y':
                putchar('9');
                break;
            default:
                putchar(c);
                break;
        }
    }

}

void practice7_7(void ){
    int a, b, c, d, x, y, m, n;
    char operator;
    bool flag = true;

    printf("Enter two fractions separated by an operator: ");
    scanf("%d/%d%c%d/%d", &a, &b, &operator, &c, &d);
//    operator = getchar();
//    scanf("%d/%d", &c, &d);
    switch (operator) {
        case '+':
            x = a * d + b * c;
            y = b * d;
            break;
        case '-':
            x = a * d - b * c;
            y = b * d;
            break;
        case '*':
            x = a * c;
            y = b * d;
            break;
        case '/':
            x = a * d;
            y = b * c;
            break;
        default:
            printf("%c is not a valid operator", operator);
            flag = false;
            break;
    }
    if (flag){
        m = x;
        n = y;

        while (n > 0){
            //m < n的话没有关系

            int remainder=m%n;
            m=n;
            n=remainder;
        }

        printf("%d/%d %c %d/%d is %d/%d", a, b, operator, c, d, x/m, y/m);
    }
}

void practice7_8(void)
{
    int hour, minute, minutesSinceMidnight;
    char t1, t2;
    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c%c", &hour, &minute, &t1, &t2);
    t1 = toupper(t1);
    t2 = toupper(t2);

    switch (t1) {
        case 'A':
            if (t2 != 'M' && t2 != '\n'){
                printf("not a vaid 12-hour");
                return;
            }
            break;
        case 'P':
            if (t2 != 'M' && t2 != '\n'){
                printf("not a vaid 12-hour");
                return;
            }
            else{
                hour += 12;
            }
            break;
    }

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

void practice7_11(void ){
    int initial,c;
    printf("Enter a first and last name: ");
    //保留first name 的首字母，其余丢弃
    initial = getchar();
    while (getchar() != ' '){}
    //输出 last name
    while ((c=getchar()) != '\n'){
        printf("%c",c);
    }
    //最后输出 first name 的首字母
    printf(", %c.",initial);

}

void practice7_12(void ){
    float result, operand;
    int operator;
    bool flag = true;

    printf("Enter an expression: ");
    //读取第一个数字
    scanf("%f", &result);

    while ((operator = getchar()) != '\n'){
        scanf("%f", &operand);
        switch (operator) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case '*':
                result *= operand;
                break;
            case '/':
                result /= operand;
                break;
            default:
                flag = false;
                printf("not valid operator");
                break;
        }
        if (!flag) break;
    }

    if (flag)   printf("value of expression: %f", result);
}

void practice7_13(void ){
    int count=0, lengthSum=0, c;
    float averageLength;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n'){
        //单词分隔符
        if (c == ' ' || c == ',' || c == '.' || c == '!')
            ++count;
        else
            ++lengthSum;
    }

    if(count != 0){
        averageLength = (float)lengthSum / count;
        printf("Average word length: %.1f", averageLength);
    }
}

void practice7_14(void ){
    int count=0, lengthSum=0, c;
    double number, squareRoot, guess = 1;

    printf("Enter a positive number: ");
    scanf("%lf", &number);

    if(number > 0){
        squareRoot = (guess + number / guess) / 2;
        while (fabs(guess - squareRoot) > 0.00001){
            guess = squareRoot;
            squareRoot = (guess + number / guess) / 2;
        }
        printf("Square root: %f", squareRoot);
    }
    else printf("not a valid number");
}

void practice7_15(void ){
    int number;
    double factorial = 1;
//    printf("Enter a positive integer: ");
//    scanf("%d", &number);

    for (number = 6; number < 100 && factorial > 0 && !isinf(factorial) ; ++number) {
        factorial = 1;
        for (int i = 1; i <= number; ++i) {
            factorial *= i;
        }
    }

    printf("from number: %d overflows", number - 1);

}

//int main(void ){
//
//    practice7_15();
////int i=46340;
////    printf("%30d%30d\n", i, i * i);
//    return 0;
//}

