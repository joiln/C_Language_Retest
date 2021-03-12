//
// Created by chen on 2021/3/4 22:51.
//
// 第八章 指针

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#define N 4

using namespace std;


//返回指针值的函数 例题
// 编写一个名为 str_chr()的函数，它的作用是在一个长串中找到指定字符第次出现的位置，返回该字符的地址。
char *str_chr(char *p,char s){
    while (*p != '\0' && *p != s){
        p++;                        //指针可以向后移动，利用*p 来判断p所指向的地址内容是否==s或者=='\0'
    }
    if(*p == '\0'){
        return 0;
    } else
        return p;
}

void demo_str_chr(){
    char str[] = "abcdefghi";
    char *p,s;
    scanf("%c",&s);
    p = str_chr(str,s);
    if (p == 0){
        printf("no");
    } else
    printf("%d",(p-str) + 1); //p-str => p代表s再字符串中位置所在的地址，-str 表示减去起始地址，就能知道第几位
}                             // 下标是从0开始，所以+1

//指针数组 例题
//将若干字符串按字母顺序（由小到大）输出。
//n个字符串，每个字符串中有m个字符，将字符串中每个按由小到大输出
/*
 解题思路：定义一个指针数组，用各字符串对它进行初始化，然后用选择法排序但不是移动字符串，而是改变指针数组的各元素的指向。
 * */

void sort(char *string[]){
    char *temp;
    int min;                        //最小下标
    for (int i = 0; i < N - 1; ++i) {
        min = i;                    //假定下表i是最小的
        for (int j = i + 1; j < N; ++j) {
            if(strcmp(string[min],string[j]) > 0)   //strcmp(str1,str2) 将两个字符串自左向右逐个比较(ASCII值大小比较)；
                                                    // A->Z > a->z 当出现有a、b 两个不同的字符，谁大，所在的字符串就大
                                                    // 当 str1 > str2  返回正值； str1 = str2 返回零；str1 < str2 返回负值；
            min = j;                                //比较每个字符串首地址中字母的大小；
        }
        if(min != i){
            temp = string[i];
            string[i] = string[min];
            string[min] = temp;
        }
    }
}

void print_str( char *string[]) {
    for (int i = 0; i < N; ++i) {
        printf("%s\n",string[i]);     //打印指针数字组中每个元素，即打印每个字符串
    }
}

void demo_2(){
    char *string[]={
            "Follow me","BASIC","Great Wall","Computer design"};
    sort(string);
    print_str(string);
}

//例题8.8 将数组a中前m个按相反顺序存放
void reverse(int *num,int m){
    int temp;
    int *p,*i,*j;
    int n = (m-1)/2;
    i= num;j = num + m - 1; p = num + n;         //利用指针 首尾对调 i为首，j为尾，p为中间位置
    for(;i <= p;i++,j--){
        temp = *i;
        *i = *j;
        *j = temp;
    }
}
void L_8_8(){
    int n,m;
    int *p;             //d定义一个int 类型的指针变量p
    scanf("%d",&n);
    int *num = (int *)malloc(sizeof (int ) *n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",num+i);
    }
    puts("input m:");
    scanf("%d",&m);
    reverse(num,m);

//    for (int i = 0; i < n; ++i) {
//        printf("%d ",*(num+i));
//    }
    for(p = num;p < num + n;p++){
        printf("%d ",*p);
    }

}
//选择法进行排序
void select_sort(int *num,int n){
    int temp;
    int min;
    for (int i = 0; i < n - 1; ++i) {      //由于不用与自己比较，所以只循环n-1次
        min = i;                    //假定最小的一个下标是i
        for (int j = i + 1; j < n; ++j) {      //从i下标，后一个数开始比较，因为前面的数是最小的
            if (num[min] > num[j])
                min = j;
        }
        if(min != i){   //如果最小下标不为i，则要把 下标为min的值 与 下标为i的值 互换
            temp = num[i];
            num[i] = num[min];
            num[min] = temp;
        }
    }
}
void L_8_10(){
    int n;
    int *p;             //d定义一个int 类型的指针变量p
    scanf("%d",&n);
    int *num = (int *)malloc(sizeof (int ) *n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",num+i);
    }
    select_sort(num,n);

    for(p = num ;p < num + n;p++ ){
        cout << *p << " ";
    }
    cout << endl;
    for(p = num + n-1;p >= num;p-- ){ //由于是从num起始的地址，一直到num+n-1 的地址，所以反向输出时，p从num+n-1开始；到p>=num为止
        cout << *p << " ";
    }
    cout << endl;
}
//用指针输出二维数组中任意一行一列的元素
void L_8_13(){
    int i,j;
   int num[3][4] = {3,2,1,4,5,8,7,9,4,5,1,9};
   int b[] = {3,2,1,4,5,8,7,9,4,5,1,9};//用b[]来表示二维数组，用一维数组a[i]表示二位数组a[n][m]，a[i][j] = *(*(p + i) + j) = a[i*m + j]
   int (*p)[4];
   p = num;
   scanf("%d,%d",&i,&j);
   printf("%d\n",*(*(p + i) + j)); //用指向二维数组的指针表示二维数组
   printf("%d",b[i * 4 +j]);        //用一维数组表示二位数组 a[i][j] = a[i*m+j] m表示一行中有多少列
}
//8.14 例题
void average(float  *p,int n){  //*p 是传进来的成绩数组的地址
    float *q;
    float sum = 0.0;
    for(q = p;q < (p + n);q++){
        sum += *q;
    }
    printf("%5.2f ",sum/n);
}
void  search(float (*p)[4],int n){
    for (int i = 0; i < 4; ++i) {
        printf("%5.2f ",*(*(p + n) + i)); //要求序号为二的学生的每科成绩，p+n 代表第n行，即n的一个学生,*(*(p+n)+i) 表示各科成绩
    }
}
void unpass_search(float (*p)[4],int n){
    int flag;
    for (int i = 0; i < n; ++i) {
        flag = 0;
        for (int j = 0; j < 4; ++j) {
            if(*(*(p + i)+j) < 60)
                flag = 1;
        }
            if (flag == 1){
                printf("bu ji ge");
                for (int k = 0; k < 4; ++k) {
                    printf("%5.2f ",*(*(p + i) + k));
                }
                cout << "\n";
            }

    }
}

void L_8_14(){
    float  score[3][4] = {65,67,70,60,80,87,90,81,90,99,100,98};
    average(*score,12);
    search(score,2);
    unpass_search(score,3);

}

//将a字符串赋值给b
void L_8_19()
{
    char a[] = "hahahahahhahaha !";
    char b[50],*p,*q;
    p = a;q =b;
    int i;
    for ( i = 0;*p != '\0';p++,q++){ //当在验证 是否为'\0'是，p与q已经为 '\0' 的下标了。
        *q = *p;
        i++;
    }
    *(q) = '\0';                    //所以最后直接让q所在下标的地址 赋值 '\0'
    printf("%s,%d",b,*(q + i));
}

//有若干个学生的成绩（每个学生有4门课程），要求在用户输入学生序号以 后 ，能输出该学生的全部成绩。用指针函数来实现。

float *search_1(float (*p)[4],int n){   //指向函数的指针：int (*p)(int ,int){}  指针函数(返回指针值的函数) int

    /*  p是一个指针，指向包含4个float型元素的一维数组的指针变量
    指向二维数组的指针，int (*p)[n]   指针数组：int *p[n]
    */



}


void L_8_25(){
    float score[ ][4] = { {60 , 70 , 80 , 90 } , { 56 , 89 , 67 , 88 } , { 34 , 78 , 90 , 66 } } ;
    float *p;
    int n;
    cout << "输入序号" << endl;
    cin >> n;
    p = search_1(score,n);
    for (int i = 0; i < 4; ++i) {
        cout << *(p + i) << " " << endl;
    }

}

int main() {
//    demo_str_chr();
// demo_2();
    int a[]={1,2,3,4,5,6};
    int *p;
    for (p = a; p < (a + 6); p++) {
//        printf("%d ",*p);
    }
    printf("\n");
// L_8_8();
// L_8_9();
//    L_8_10();
//    L_8_13();
 L_8_19();
    return 0;
}


/*
指针数组：
 一个数组，若其元素均为指针类型数据，称为指针数组，也就是说，指针数组中的每一个元素都存放一个地址，相当于一个指针变量。
 一维指针数组的一般形式为：
                        类型名 * 变量名[数组长度];
    例：int *p[4];
    p是一个长度为4的一维数组，该数组的4个元素全部都是 整型指针 ，因此p为指针数组,由于[]的优先级比*高，因此该变量首先是一个一维数组。
    其次，该数组中全部都是指针，故该变量为指针数组。

 可以定义字符型指针数组，让数组中的指针指向若干个字符串，增加字符串处理的灵活性，提高字符串处理的效率。
 用户可以定义长度不等的若干字符串，使用指针数组进行处理。相对于定义二维字符数组存储字符串而言，可以节省大量内存单元



 与 数组指针 区别开来
 数组指针 是一个指针指向一个数组，指针指向数组的开头地址。若数组为char类型，则指针也要为char类型 =>类型相同

    指向一维数组 a[n] => int *p; p = a;  指向二维数组 a[][m] => int (*p)[m]; p = a;



*/