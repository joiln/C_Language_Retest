//
// Created by chen on 2021/3/4 22:21.
//

#include <iostream>
#include <cstdio>
#include <cmath>

void  L_7_6();  //用弦截法求方程 f(x) = x3-5x2 + 16x-80 = 0 的根
void  L_7_7();  //
int  L_7_8(int n); //用递归方法求 n!
void  L_7_9();  //汉诺塔问题-->经典的递归问题
void  L_7_15(); //有 一个一维 数组 ， 内 放 10 个学生成绩，写 一个 函 数 ， 求 出 平均分 、 最高分和最低分

void  Q_7_1();
void  Q_7_2();  //
void  Q_7_3();  //
void  Q_7_4(); //

void  Q_7_6(); //
void  Q_7_7(); //
void  Q_7_9(); //
//void  Q_7_10();
void  Q_7_11();
void  Q_7_12(); //用函数+牛顿迭代法，用牛 顿 迭代法求根。 方程为 ax3 +bx2 + cx + d = O，系数 α、b、c 、d 的值依次为1、2、3、4，由主 函数输 入。 求 z 在 1 附近的一个实根。 求出根后由主 函数输出
void  Q_7_13();
void  Q_7_16();
void  Q_7_17();
void  Q_7_18();//给 出 年 、月 、 日 ，计算该 日 是该年的第 n 天 。
bool is_leap(int year);

int age(int age);

using namespace std;

int main() {
//    L_7_7();
    Q_7_18();
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

void  Q_7_12(){

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