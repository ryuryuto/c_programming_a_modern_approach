//
// Created by xhj on 2020/6/10.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>


void project12_1(void );
void project12_2(void );



int main(void ){
    project12_2();
    return 0;
}

void project12_1(void ){
    const int LENGTH = 30;
    int arr[LENGTH];
    int *p = arr;
    int c;
    printf("Enter a message: ");
    while (p < arr + LENGTH && (c = getchar()) != '\n') {
        *p++ = c;
    }
    p--;
    printf("Reversal is: ");
    while (p >= arr){
        printf("%c", *p--);
    }
}

void project12_2(void ){
    const int LENGTH = 30;
    int arr[LENGTH];
    int *p = arr;
    int c;
    printf("Enter a message: ");
    while (p < arr + LENGTH && (c = getchar()) != '\n') {
        *p++ = c;
    }
    p--;
    int *s = arr;
    bool flag = true;
    while (s < p){
        if (toupper(*s) < 'A' || toupper(*s) > 'Z'){
            s++;
            continue;
        }
        if (toupper(*p) < 'A' || toupper(*p) > 'Z'){
            p--;
            continue;
        }

        if (toupper(*s) != toupper(*p)){
            flag = false;
            break;
        }
        s++;
        p--;
    }
    if (flag)   printf("Palindrome");
    else    printf("Not a palindrome");
}