//
// Created by xhj on 2020/6/8.
//

#include <stdio.h>
#include <stdbool.h>

void push_stack(int stack[], int *top, int c);
int pop_stack(int stack[], int *top);
bool stack_empty(int *top);
bool stack_full(int *top, int STACK_SIZE);
void project10_1(void );
void project10_6(void );
void project10_7(void );
bool is_operator(char c);
bool is_digit(char c);



int main(void ){
    project10_7();
    return 0;
}

void project10_1(void ){
    const int STACK_SIZE = 20;
    int c;
    int stack[STACK_SIZE], top = 0;
    bool flag = true;

    int popped;
    printf("Enter parentheses and/or braces: ");
    while (flag && (c = getchar()) != '\n'){
        if (c == '(' || c == '{'){
            push_stack(stack, &top, c);
        }
        else if (c == ')' || c == '}'){
            if (stack_empty(&top))
                flag = false;
            else{
                popped = pop_stack(stack, &top);
                if ((c == ')' && popped != '(') || (c == '}' && popped != '{')){
                    flag = false;
                }
            }
        } else
            flag = false;
    }

    if (flag)   printf("Parentheses/braces are nested properly");
    else    printf("Parentheses/braces aren't matched");

}

void project10_6(void ){
    const int STACK_SIZE = 10;
    int stack[STACK_SIZE];
    int top = 0;
    char c;
    bool flag = true;
    int a, b;

    while (flag){
        if (top == 0)
            printf("Enter an RPN expression: ");

        scanf(" %c", &c);

        if (is_digit(c)){
            if (stack_full(&top, STACK_SIZE)){
                printf("Expression is too complex\n");
                flag = false;
            } else{
                push_stack(stack, &top, c - '0');//字符转化成整型数字
            }
        }
        else if (is_operator(c)){
            if (c == '+' || c == '-' || c == '*' || c == '/'){
                if(top < 2) {
                    printf("Not enough operands in expression\n");
                    flag = false;
                }
                if (flag){
                    b = pop_stack(stack, &top);
                    a = pop_stack(stack, &top);
                    if (c == '+')
                        push_stack(stack, &top, a + b);
                    else if (c == '-')
                        push_stack(stack, &top, a - b);
                    else if (c == '*')
                        push_stack(stack, &top, a * b);
                    else if (c == '/')
                        push_stack(stack, &top, a / b);
                }
            } else{
                if(top < 1) {
                    printf("Not enough operands in expression\n");
                    flag = false;
                }
                if (flag){
                    printf("Value of expression: %d\n", pop_stack(stack, &top));
                    top = 0;
                }
            }
        } else
            flag = false;
    }
}

void project10_7(void ){
    const int MAX_LENGTH = 10;
    int arr[MAX_LENGTH];
    int c, length;

    //每一个数字的表示
    const int segments[10][7] = {
            {1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 1},
            {1, 1, 1, 1, 0, 0, 1},
            {0, 1, 1, 0, 0, 1, 1},
            {1, 0, 1, 1, 0, 1, 1},
            {1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1},
    };

    printf("Enter a number: ");
    for (length = 0; length < MAX_LENGTH && (c = getchar()) != '\n';) {
        if (is_digit((char )c)){
            arr[length] = c - '0';//字符转化成整型数字
            ++length;
        }
    }

    //一共3行
    //
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < length; ++j) {
            //宽度是3个字符
            if (i == 0){
                //0位
                printf(" ");
                if (segments[arr[j]][0] == 1)   printf("_");
                else    printf(" ");
                printf(" ");
            } else if (i == 1){
                //1位、5位和6位，先5位，后6位，后1位
                if (segments[arr[j]][5] == 1)   printf("|");
                else    printf(" ");
                if (segments[arr[j]][6] == 1)   printf("_");
                else    printf(" ");
                if (segments[arr[j]][1] == 1)   printf("|");
                else    printf(" ");
            }
//            else if (i == 2){
//                //6位
//                printf(" ");
//                if (segments[arr[j]][6] == 1)   printf("-");
//                else    printf(" ");
//                printf(" ");
//            }
            else if (i == 2){
                //2位、3位和4位，先4位，后3位，后2位
                if (segments[arr[j]][4] == 1)   printf("|");
                else    printf(" ");
                if (segments[arr[j]][3] == 1)   printf("_");
                else    printf(" ");
                if (segments[arr[j]][2] == 1)   printf("|");
                else    printf(" ");
            }
//            else if (i == 4){
//                //3位
//                printf(" ");
//                if (segments[arr[j]][3] == 1)   printf("-");
//                else    printf(" ");
//                printf(" ");
//            }
            printf("    ");
        }
        printf("\n");
    }

}

bool is_operator(char c){
    bool result;
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
            result = true;
            break;
        default:
            result = false;
    }
    return result;
}

bool is_digit(char c){
    bool result;
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            result = true;
            break;
        default:
            result = false;
    }
    return result;
}

void push_stack(int stack[], int *top, int c){
    stack[*top] = c;
    (*top)++;
}

int pop_stack(int stack[], int *top){
    (*top)--;
    return stack[*top];
}

bool stack_empty(int *top){
    return *top == 0;
}

bool stack_full(int *top, int STACK_SIZE){
    return *top == STACK_SIZE;
}
