//
// Created by xhj on 2020/6/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



void exercise13_5(int argc, char *argv[]);
void exercise13_6(char *p);
void exercise13_12(const char *file_name, char *extension);
int read_line(char str[], int n);
void project13_2b(void );
void project13_2c(void );
void project13_4(int argc, char *argv[]);
void project13_10(char *name);
void project13_18(void );




int main(int argc, char *argv[]){
    char c[10];
    project13_18();

    return 0;
}


void exercise13_5(int argc, char *argv[]){
    char **p = argv;//字符指针数组
    p++;
    char *s;
    while (*p != NULL){//字符指针数组是否为空
        s = *p;
        while (*s != '\0'){//字符串是否到头
            putchar(toupper(*s));
            s++;
        }
        p++;
    }
}

void exercise13_6(char *p){
    while (*p != '\0' && *(p + 1) != '\0' && *(p + 2) != '\0'){
        if(*p == 'f' && *(p + 1) == 'o' && *(p + 2) == 'o'){
            *p = *(p + 1) = *(p + 2) = 'x';
        }
        p++;
    }
}

void exercise13_12(const char *file_name, char *extension){
    //应该从最后开始查找
    const char *p = file_name + strlen(file_name) - 1;
    for (; p != file_name && *p != '.'; --p) {
    }
    if(*p == '.')   strcpy(extension, ++p);
    else strcpy(extension, "");
}


void project13_2b(void ){
    const int MAX_REMIND = 50;
    const int MSG_LEN = 60;

    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], time_str[6], msg_str[MSG_LEN+1];
    int day, hour, minute, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day, time and reminder(separated by space): ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        else if(day < 1 || day > 31){
            printf("day must between 1 and 31");
            continue;
        }

        sprintf(day_str, "%2d", day);//比较2和10的话，其实是2前面有空白，空白比数字小

        //读取时间
        scanf("%d:%d", &hour, &minute);
        if(hour < 0 || hour > 24 || minute < 0 || minute > 60){
            printf("hour must between 0 and 24 and minute must between 0 and 60");
            continue;
        }

        sprintf(time_str, "%2d:%.2d", hour, minute);


        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0 ||//day比较大小
                    (strcmp(day_str, reminders[i]) == 0 && strcmp(time_str, reminders[i] + sizeof(day_str)) < 0))
                //day相同，比较time
                break;
//            else if (strcmp(day_str, reminders[i]) == 0 && strcmp(time_str, reminders[i] + sizeof(day_str)) < 0)
//                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], " ");
        strcat(reminders[i], time_str);
        strcat(reminders[i], " ");
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay  Time  Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
}

void project13_2c(void ){
    const int MAX_REMIND = 50;
    const int MSG_LEN = 60;

    char reminders[MAX_REMIND][MSG_LEN+3];
    char month_day_str[6], msg_str[MSG_LEN + 1];
    int month, day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter month, day(month/day) and reminder(separated by space): ");


        scanf("%d/%d", &month, &day);
        if(month < 1 || month > 12 || day < 1 || day > 31){
            break;
        }

        sprintf(month_day_str, "%2d/%2d", month, day);


        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(month_day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], month_day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nMonth/Day Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = (char)ch;
    str[i] = '\0';
    return i;
}

void project13_4(int argc, char *argv[]){
    char **p = argv + argc - 1;
    for (; p != argv ; --p) {
        printf("%s ", *p);
    }
}


void project13_10(char *name){
    int c;
    char initial[3];
    printf("Enter a first and last name: ");
    //保留first name 的首字母，其余丢弃
    initial[0] = (char)getchar();
    initial[1] = '.';
    initial[2] = '\0';

    while (getchar() != ' '){}
    //last name
    scanf("%s", name);
    strcat(name, ", ");
    strcat(name, initial);
}

void project13_18(void ){
    char *monthName[] = {"January", "Feburary", "March", "April", "May", "June", "July", "Auguest", "September",
                     "October", "November", "December"};
    int year, month, day;
    printf("Enter a date(mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("You entered the date %s %d, %d", monthName[month - 1], day, year);

}