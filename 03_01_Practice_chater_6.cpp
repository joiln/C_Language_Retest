//
// Created by chen on 2021/3/11 13:01.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stdlib.h>
using namespace std;


int str_len(char *str);
void str_cat(char *from,char *to);
void str_copy(char *from,char *to);
void Q_6_13(); //拼接两个字符串，不用strcat
void Q_6_15(); //将s1中的字符复制到s2中
void Q_6_15_1();// 指针操作
void Q_6_14();  //比较大小

int main() {
    Q_6_13();
    return 0;
}
int str_len(char *string1){
    int count = 0;
    while (*string1 != '\0')
        count++;
    return count;
}

void str_cat(char *from,char *to){

}

void str_copy(char *from,char *to){

}

//拼接两个字符串，不用strcat
void Q_6_13() {
   char s1[80],s2[40];
   int i = 0,j = 0;
   scanf("%s",s1);
   scanf("%s",s2);
    while (s1[i] != '\0'){      //找到s1串的最后一位的下标，即 \0 的下标
        i++;                    // i = 3;
    }

    while (s2[j] != '\0'){
        s1[i++] = s2[j++];          //i++ 是先使用i，再++ ;s1[i] = s2[j] => i=i+1,j=j+1
    }
    s1[i] = '\0';                   //最后 再把末尾的位置复制成 \0
    puts(s1);
}
//将s1中的字符复制到s2中
void Q_6_15() {
    char s1[80],s2[80];
    scanf("%s",s1);
//    scanf("%s",s2);
    for (int i = 0; i <= strlen(s1); ++i) { // <=表示把 \0 也复制到了s2中
        s2[i] = s1[i];
    }
//    printf("%s",s2);
    puts(s2);
}
void Q_6_14(){
    char s1[80],s2[80];
    gets(s1);
    gets(s2);
    int i = 0;
    int res = 0;
    while ((s1[i] != '\0') && (s1[i] == s2[i]))
        i++;
    if(s1[i] == '\0' && s2[i] == '\0'){
        res = 0;
    } else{
        res = s1[i]-s2[i];
    }
    cout << res << endl;
}
//指针操作
void Q_6_15_1(){
    char *string1,*string2;
    char str[80];
    scanf("%s",str);
//    string1 = str;
//    printf("%s",string1); //打印指针不需要&以及*，它的名字就代表起始地址
//    puts(string1);
    string2 = str;
    puts(string2);
}