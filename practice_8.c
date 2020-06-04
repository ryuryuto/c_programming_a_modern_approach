//
// Created by xhj on 2020/6/1.
//

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void exercise4(void ){
    bool a[7]={true,[6]=true};
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        printf("%d : ", i);
        printf(a[i] ? "true" : "false");
        printf("\n");
    }
}

void exercise5(void ){
    int fib_numbers[40];
    fib_numbers[0] = 0;
    fib_numbers[1] = 1;

    for (int i = 2; i < sizeof(fib_numbers)/sizeof(fib_numbers[0]); ++i) {
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
    }
    for (int j = 0; j < sizeof(fib_numbers)/sizeof(fib_numbers[0]); ++j) {
        printf("%d  ", fib_numbers[j]);
    }
}

void exercise11(void ){
    char checker_board[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if((i + j) % 2 == 0)
                checker_board[i][j] = 'B';
            else
                checker_board[i][j] = 'R';

            printf("%c  ", checker_board[i][j]);
        }
        printf("\n");
    }


}

void project9(void ){
    const int LENGTH = 10;
    char arr[LENGTH][LENGTH];
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                         'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                         'Y', 'Z'};
    int walkCount = 0;//走路的步数
    bool flag = true;

    for (int i = 0; i < LENGTH; ++i) {
        for (int j = 0; j < LENGTH; ++j) {
            arr[i][j] = '.';
        }
    }

    srand((unsigned )time(NULL));

    int i, j;
    //起点为四条边的任意一点
    int start_x = rand() % 4;
    int start_y = rand() % 10;
    switch (start_x) {
        case 0:
            i = start_x;
            j = start_y;
            break;
        case 1:
            i = start_y;
            j = 9;
            break;
        case 2:
            i = 9;
            j = start_y;
            break;
        case 3:
            i = start_y;
            j = 0;
            break;
        default:
            flag = false;
            break;
    }

    if (flag){
        arr[i][j] = alphabet[walkCount];
        walkCount++;
        int direction;
        bool allowedDirection[4] = {true, true, true ,true};
        int directionFalseCount = 0;//方向是false的数目
        int x, y;//坐标
        while (walkCount < 26){
            directionFalseCount = 0;
            //如果四个方向都是false，直接退出
            for (int k = 0; k < 4; ++k) {
                if(allowedDirection[k] == false)    directionFalseCount++;
            }
            if(directionFalseCount == 4) break;


            direction = rand() % 4;
            switch (direction) {
                case 0:
                    x= i - 1;
                    y = j;
                    break;
                case 1:
                    x = i;
                    y = j + 1;
                    break;
                case 2:
                    x= i + 1;
                    y = j;
                    break;
                case 3:
                    x = i;
                    y = j - 1;
                    break;
                default:
                    flag = false;
                    break;
            }
            if (!flag)  break;
            else if(!allowedDirection[direction]){//已经标记为不能走的方向
                continue;
            }
            else if((x < 0 || x >= LENGTH || y < 0 || y >= LENGTH) ||
            arr[x][y] != '.'){//超出边界或已经走过
                allowedDirection[direction] = false;//这个方向不能再走
            }
            else{
                arr[x][y] = alphabet[walkCount];
                walkCount++;
                i = x;
                j = y;
                //重置
                for (int k = 0; k < 4; ++k) {
                    allowedDirection[k] = true;
                }
            }

        }
        if (flag){
            //输出结果
            for (int m = 0; m < LENGTH; ++m) {
                for (int n = 0; n < LENGTH; ++n) {
                    printf("    %c", arr[m][n]);
                }
                printf("\n");
            }
        }

    }


}

void project14(void ){
    char arr[50];
    int length = 0;
    char c;
    printf("Enter a sentence: ");

    while ((c = (char )getchar()) != '\n' && c != '.' && c != '!' && c != '?') {
        arr[length] = c;
        length++;
    }

    int start, end = length - 1;
    for (int i = length - 1; i >= 0; --i) {
        if (arr[i] == ' '){
            if ((i + 1) <= end && arr[i + 1] != ' ')//起点不能是空白且不能超过终点
                start = i + 1;
            else{
                end = i - 1;
                continue;
            }
            for (int j = start; j <= end; ++j) {
                printf("%c", arr[j]);
            }
            printf(" ");
            end = i - 1;
        }
    }
    //输出第一个word,确保不是空白
    if(end >= 0 && arr[0] != ' ' && arr[end] != ' '){
        for (int i = 0; i <= end; ++i) {
            printf("%c", arr[i]);
        }
    }

    printf("%c", c);
}

void project15(void ){
    int original[80], encrypted[80];
    int length;
    int amount;
    int c;
    printf("Enter message to be encrypted: ");

    for (length = 0; length < 80 && (c = getchar()) != '\n'; ++length) {
        original[length] = c;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &amount);

    for (int i = 0; i < length; ++i) {
        if(original[i] >= 'a' && original[i] <= 'z')
            encrypted[i] = (original[i] - 'a' + amount) % 26 + 'a';
        else if (original[i] >= 'A' && original[i] <= 'Z')
            encrypted[i] = (original[i] - 'A' + amount) % 26 + 'A';
        else
            encrypted[i] = original[i];
    }

    printf("Encrypted message: ");
    for (int i = 0; i < length; ++i) {
        printf("%c", encrypted[i]);
    }

}


void project17(void ){
    int size, x, y;
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);

    if(size < 1 || size > 99 || size % 2 == 0){
        printf("Not a valid size");
        return;
    }

    int arr[size][size];

    //初始化数组
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            arr[i][j] = 0;
        }
    }

    //起始
    x = 0;
    y = size / 2;
    arr[x][y] = 1;
    for (int i = 2; i <= size * size; ++i) {
//        x = (x - 1 + size) % size;
//        y = (y + 1) % size;
        if (arr[(x - 1 + size) % size][(y + 1) % size] != 0){//已经有值
            //更新x y
            x = x + 1;
            arr[x][y] = i;
        }
        else{
            //更新x y
            x = (x - 1 + size) % size;
            y = (y + 1) % size;
            arr[x][y] = i;
        }

    }

    //输出结果
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {;
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

//int main(void ){
//    project17();
//
//    return 0;
//}
