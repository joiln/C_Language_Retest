//
// Created by chen on 2021/3/4 17:58.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stdlib.h>


void  L_6_1();
void  L_6_5();
void  L_6_8();  //验证有多少个单词，单词与单词之间用空格隔开
void  L_6_9(); //
void  Q_6_1(); //用筛选法求100以内素数
void  Q_6_2(); //
void  Q_6_4(); //用迭代法求平方根。平方根迭代公试x(n+1) = 1 / 2 * ( x(n) + a / x(n) )
void  Q_6_5(); //牛顿迭代法求方程的根。
void  Q_6_6(); //
void  Q_6_7(); //
void  Q_6_9(); //
void  Q_6_10();
void  Q_6_13();
void  Q_6_14();
void  Q_6_15();

using namespace std;

int main() {
//    L_6_5();
//    L_6_8();
    Q_6_1();


    return 0;
}
/*
 *用malloc动态申请一个二维数组的三种方法
 *方法一: 利用二级指针申请一个二维数组。
 **/
void demo_1(){
    int n,m; //创建一个n*m 的二维数组
    int **num = (int **)malloc(sizeof (int *)*n);   //有n行，每行中的元素大小为 sizeof(int *)


}

void  Q_6_1(){ //用筛选法求100以内素数
    int n;
    scanf("%d",&n);
    int *num = (int  *)malloc(n * sizeof (int));    //动态开辟内存
    *(num + 0) = 0;

    for (int i = 1; i <= n; ++i) {
            num[i] = i;
    }
    *(num + 0) = 0;

    for (int i = 0; i < n; ++i) {
        printf("%d ",*(num+i));
    }



    free(num);  //动态开辟内存后，要用free()释放,因为malloc()、calloc()、realloc()申请的内存系统不是自己释放
}

void  L_6_5(){
    int a[3][4];
    int Max = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
           if(a[i][j] > Max)
               Max = a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (Max == a[i][j])
                printf("Max = %d,r = %d,l = %d",a[i][j],i+1,j+1);
        }
    }
}
void  L_6_8(){
    char str[] = "how are you?";
    gets(str);
    int word = 0;               //开始的时候把word置为0；表示起始位置，这样就能累加第一个单词
    int i = 0,num = 0;
    while (str[i] != '\0'){
        if (str[i] < 'a' && str[i] > 'z' || str[i] < 'A' && str[i] > 'Z'){
            i++;
            continue;
        }
        if(str[i] == ' ')       //遇到一个空格，把word置为0
            word = 0;
        else if (word == 0){       //遇到不是空格，且word == 0；即表示空格后为新的一个单词
            word = 1;
            num++;
        }
      i++;
    }
    printf("%d",num);

}

void  L_6_9(){

}

void  Q_6_14(){
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    int i = 0;
    while ((str1[i] == str2[i]) && str2[i] != '\0'){
        i++;
    }
    if(1);
}
