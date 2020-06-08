//
// Created by xhj on 2020/6/4.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


void selection_sort(int arr[], int length);
int calculatePower(int x, int n);
int roll_dice(void );
bool play_game(void );



void project1(void ){
    int arr[20];
    int length;
    int input;
    printf("Enter a series of integers(less than 20, end with period): ");

    for (length = 0; length < 20 && scanf("%d", &input) == 1; ++length) {//根据scanf的返回值判断成功读取的个数
        arr[length] = input;
    }
    selection_sort(arr, length);

    printf("sorted array: ");
    for (int i = 0; i < length; ++i) {
        printf("%5d", arr[i]);
    }

}

void selection_sort(int arr[], int length){

    if (length <= 1) return;
    else{
        int maxPosition = 0;
        for (int i = 1; i < length; ++i) {
            if (arr[i] > arr[maxPosition])
                maxPosition = i;

        }
        if (maxPosition != (length - 1)){
            int temp = arr[length - 1];
            arr[length - 1] = arr[maxPosition];
            arr[maxPosition] = temp;
        }

        selection_sort(arr, length - 1);
    }
}

void project7(void ){
    int x, n;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter n: ");
    scanf("%d", &n);

    if (n > 0)  printf("%d raised by the power of %d is %d", x, n, calculatePower(x, n));

}

int calculatePower(int x, int n){
    if (n == 0) return 1;
    else if(n % 2 == 0) return calculatePower(x, n/2) * calculatePower(x, n/2);
    else  return x * calculatePower(x, n - 1);
}



void project8(void ){
    int play = 'y', win = 0, lose = 0;
    bool result;
    srand((unsigned )time(NULL));//初始化一次？ 每次调用rand之前都调用的话，会产生相同的随机数
    while (play == 'y'){
        if(play_game()){
            printf("You win!\n\n");
            win++;
        } else  {
            printf("You lose!\n\n");
            lose++;
        }
        printf("Play again? ");
        while ((play = getchar()) != 'y' && play != 'n')    printf("Enter y or n: ");
    }
    printf("Wins: %-5d Losses: %d", win, lose);

}

int roll_dice(void ){
    return rand() % 6 + rand() % 6;
}

bool play_game(void ){
    int sum, point;
    bool flag = true;
    bool result;

    for (int i = 0; flag; ++i) {
        sum = roll_dice();
        printf("You rolled: %d\n", sum);
        if (i == 0){
            if (sum == 7 || sum == 11)  {
                result = true;
                flag = false;
            }
            else if (sum == 2 || sum == 3 || sum == 12){
                result = false;
                flag = false;
            }
            else{
                printf("Your point is %d\n", sum);
                point = sum;
            }
        } else{
            if (sum == point){
                result = true;
                flag = false;
            }
            else if (sum == 7){
                result = false;
                flag = false;
            }
        }
    }

    return result;
}


//int main(void ){
//    project8();
//
//    return 0;
//}