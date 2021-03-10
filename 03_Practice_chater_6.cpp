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
void  q();

using namespace std;

int main() {
//    L_6_5();
//    L_6_8();
    Q_6_1();

    return 0;
}
void  q(){


}
/*  s[][];
 * 多维数组元素地址：s[0] 地址等价与*(s+0)    s[0][1] 的地址等价于*(s+0)+1  ==> &s[0][1]  其内容为： *(*(s+0)+1)
 *  *(s+i)+j ==> &s[i][j]   即s的首地址+i，表示第i行，*(s+i)表示第i行的地址，+j表示在i行地址处再+j, 即i行上第j的个元素
 *
 *多维数组的指针变量：
 * 数组指针 ==> 指向由m个元素组成的一维数组的指针变量   //todo 格式： 数据类型 (*p)[m];   例子： int (*p)[4];
 *
 *由于小括号的优先级别最高，因此要首先计算小括号，所以指定变量p首先是一个指针变量，其次它指向一个长度为m的一维数组，P为二级指针。
 * 这就是数组指针的定义方式。
 *
 *  int s[3][4];
    int (*p)[4];
    p=s, p指向s数组，p++的值为s+1，它只能对行进行操作，不能对行中的某个元素进行操作，可以使用
    *(*(p+)+j)访问第行第列的数据。

    用指向多维数组的指针作为函数参数
    一维数组的地址可以作为函数参数，多维数组的地址也可作函数参数。在用指针变量作形参以接受实参数组名传递来的地址时，
    有两种方法：用指向变量的指针变量 和 用指向一维数组的指针变量（上一个例子p=a[0]）

    例：double (int (*p)[4],int n);   传进去一个二维数组

用指针变量指向一个字符串
    用指针变量指向一个字符串常量对于字符串而言，也可以不定义字符数组，直接定义指向字符串的指针变量，利用该指针变量对字符串进行操作
    char *string ="I am a student. ";
    printf(" %s\n"，string);


 *
 * */

/*
 *用malloc动态申请一个二维数组的三种方法
 *方法一: 利用二级指针申请一个二维数组。
 **/
void demo_1(){
    int n,m; //创建一个n*m 的二维数组
    int **num = (int **)malloc(sizeof (int *)*n);   //分配每一行的首地址。有n行，每行中的元素大小为 sizeof(int *)

    for (int i = 0; i < n; ++i) {
        num[i] = (int *)malloc(sizeof (int )* m);   //给每行中每个元素开辟空间
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
        printf("%d",num[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        free(num[i]);       //释放每一行中的没个元素
    }
    free(num);  //释放每一行，即释放整个二维数组
}
//用数组指针形式申请一个二维数组。
// 数组指针==>int *(num)[2];


void demo_2(){
    int n,m;
    int **num = (int **)malloc(sizeof (int *) * n); //n行

}




void  Q_6_1(){ //用筛选法求100以内素数
    int n;
    scanf("%d",&n);
    int *num = (int  *)malloc(n * sizeof (int));    //动态开辟内存
    *(num + 0) = 0;

    for (int i = 1; i <= n; ++i)   {
           *(num + i) = i;
    }
    *(num + 1) = 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        for (int j = i+1; j < n; ++j) {
            if(*(num + i) != 0 && *(num + j) != 0){
                if(*(num + j) % *(num + i) == 0)
                *(num + j) = 0;

            }
        }

    }
    for (int i = 0; i < n; ++i) {
        if (*(num + i) != 0)
        printf("%d ",*(num + i));

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
