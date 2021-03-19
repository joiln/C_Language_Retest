//
// Created by chen on 2021/3/4 22:21.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void  L_7_6();  //用弦截法求方程 f(x) = x3-5x2 + 16x-80 = 0 的根
void  L_7_7();  //
int  L_7_8(int n); //用递归方法求 n!
void  L_7_9();  //汉诺塔问题-->经典的递归问题
void  L_7_15(); //有 一个一维 数组 ， 内 放 10 个学生成绩，写 一个 函 数 ， 求 出 平均分 、 最高分和最低分

void  Q_7_1();
void  Q_7_2();  //
void  Q_7_3();  //FFFFFFFN5
void  Q_7_4(); //
void  Q_7_5(){
    char *s = (char *)malloc(sizeof (char ));
    char *a = (char *)malloc(sizeof (char ));
    gets(s);    //遇到回车才停止，空格全部计入
    //rintf("%d",strlen(s));
    for (int i = strlen(s)-1,k = 0; i >=0; --i,k++) {
        a[k] = s[i];
    }
    printf("%s",a);
    free(s);
    free(a);
}
void  Q_7_6() {
    char s[] = "hahaha";
    char a[] = "+ahaha";
    int i,j;
    for (i = 0; s[i] != '\0' ; ++i);
    for (j = 0;  a[j] != '\0' ; ++j);
    cout << i << endl;
    cout << j << endl;
    char *str = (char *)malloc(sizeof (char )*(i+j));
    for (int k = 0; k < i; ++k) {
        str[k] = s[k];
    }
    for (int k = i, m = 0; k < (i+j) && m < j; ++k) {
        str[k] = a[m];
        m++;
    }
    str[i+j] = '\0';
    printf("%s\n",str);
    for (int k = 0; str[k] != '\0'; ++k) {
        cout << str[k];
    }
}
//写一个函数，将一个字 符 串 中 的元 音 字母复制到另 一字 符 串 ，然后输出。
void  Q_7_7(){
    int i,k;
    char *s = (char *)malloc(sizeof (char ));
    char *num = (char *)malloc(sizeof (char )),*p;
    gets(s);
//    strlwr(s);
    for (k = 0, i = 0; s[i] != '\0' ; ++i) {
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||
          s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ) {
          num[k] = s[i];
            k++;
      }
    }
    printf("%s",num);

//    printf("%d",'a' == 'a' );
}
void  Q_7_9(){
    char *s = (char *)malloc(sizeof (char ));
    gets(s);
    for (int i = strlen(s); i > 0; --i) {
        s[i * 2] = s[i];
        s[i * 2 -1] = ' ';
    }
    printf("%s",s);
}
void  Q_7_10();
void  Q_7_11();
void  Q_7_12(); //用函数+牛顿迭代法，用牛 顿 迭代法求根。 方程为 ax3 +bx2 + cx + d = O，系数 α、b、c 、d 的值依次为1、2、3、4，由主 函数输 入。 求 z 在 1 附近的一个实根。 求出根后由主 函数输出
//用递归方法求 n 阶勒让德多项 式的值
float ard(int x,int n){
    float px;
    if(n == 0)
        px = 1;
    else if( n== 1)
        px = x;
    else
        px = (2*n -1 )*x *ard(x,(n-1))-(n-1)*ard(x,(n-2))/n;
    return px;
}
void  Q_7_13(){
    int n;
    int x;
    float ans;
    scanf("%d,%d",&x,&n);
    ans = ard(x,n);
    printf("%f",ans);
}

void  Q_7_17();// 数字转化为字符串
void  Q_7_18();// 给 出 年 、月 、 日 ，计算该 日 是该年的第 n 天 。
bool is_leap(int year);
void covert(int n);
int age(int age);
using namespace std;

long hextodec(char *str){
    int n = 0;
    for (int i = 0; str[i] != '\0'  ; ++i) {
        if (str[i] <= '9' && str[i] >= '0')
            n = n*16 + str[i]-48;   //0的ASCII是48，字符减去ascii后就是数字 或者-'0'
        if (str[i] <= 'F' && str[i] >= 'A')
            n = n*16 + str[i]-'A' + 10;
        if (str[i] <= 'f' && str[i] >= 'a')
            n = n * 16 + str[i] -'a' +  10;  //-'a' + 10 转化为10进制下的A-F 或者a-f 对应的值

    }
    return n;

}
// 写一个函数。输入一个十六进制，输出十进制
void  Q_7_16(){
    char  str[] = "75BCD15";
    printf("16jinzhi:%s\n",str);
    printf("10 jizhi: %ld",hextodec(str));

}
void  Q_7_16_1(){
    char s[50];
    gets(s);
    int t;
    long sum = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] <= '9' && s[i] >= '0')
            t = s[i]-'0';
        else if (s[i] <= 'F' && s[i] >= 'A')
            t = s[i] - 'A' + 10;        //s[i] 全部都是字符，-'A'将其转化为数字 +10表示A-F 代表的十进制数，A=a=10，B=b=11 .....
        else
            t = s[i] - 'a' + 10;
            sum = sum *16 + t;
    }
    printf("10 jinzhi : %ld",sum);
}


int main() {
//    L_7_7();
//    Q_7_18();
//    Q_7_16();
//    Q_7_13();
//    Q_7_6();
//    Q_7_5();
//    Q_7_7();
//    Q_7_9();
    return 0;
}
/*
void  L_7_6(){
    float x0,x1,x2,f0,f1,f2;

    do {
        scanf("%f,%f",&x1,&x2);
        f1 = x1*x1*x1-5*x1*x1+16*x1-80;
        f2 = x2*x2*x2-5*x2*x2+16*x2-80;
    } while (f1*f2 > 0);
    do{
        x0 = (x1*f2-x2*f1)/(f2-f1);
        f0 = x0*x0*x0-5*x0*x0+16*x0-80;
        if(){

        } else{

        }
    } while ();
}
*/

void  L_7_7(){
    int n;
    scanf("%d",&n);
    age(n);
    printf("%d",age);

}

int age(int n){
    int ag;
    if (n == 1){
        ag = 10;
    }else
    ag  = age(n-1)+2;
    return ag;
}

void  L_7_8(){

}
float res(float a,float b,float c,float d){
    float x0 = 1,x1,f0,f1;
}
//给 出 年 、月 、 日 ，计算该 日 是该年的第 n 天 。
void  Q_7_18(){
    int y,m,d;          //y年，m月，d天
    int sum = 0;
    int month[] = {31,28,31,30,31,30,31,31,31,31,30,31};
    scanf("%d,%d,%d",&y,&m,&d);
    if(m >= 3 && is_leap(y) == true){
        d = d +1;
    }
    for (int i = 0; i < m; ++i) {
        sum += month[m-1];
    }

    printf("sum = %d",sum+d);

}
//leap(int year) 判断是否是闰年
//sum_day(int m,int d) 判断是第几天
bool is_leap(int year){
    if (year % 4 == 0 && year % 400 != 0 || year % 100 == 0){
        return true;
    } else
        return false;
}

void  Q_7_4(){
    int a[3][3];

}





void covert(int n){
    int i;
    if((i=n/10) != 0)
        covert(i);      //递归处理每个数字
//    printf("%c",i%10 + '0');
    putchar(n%10 + '0');    //也可以是n%10 + 48
    putchar(32); //空格的ascii为32
}

void Q_7_17(){
    int n;
    scanf("%d",&n);
    if (n < 0){
        putchar('-');
        n =- n;
    }
    covert(n);
}