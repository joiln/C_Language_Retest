//
// Created by chen on 2021/3/3 21:31.
//

#include <iostream>
#include <cstdio>
#include <cmath>

void  Q_5_11(); //
void  Q_5_12(); //
void  Q_5_13(); //用迭代法求平方根。平方根迭代公试x(n+1) = 1 / 2 * ( x(n) + a / x(n) )
void  Q_5_14(); //牛顿迭代法求方程的根。
void  Q_5_15(); //
void  Q_5_16(); //
void  Q_5_17(); //

using namespace std;

int main() {
//    Q_5_17();
//    Q_5_12();
    Q_5_15();
    return 0;
}

void  Q_5_11(){

}

//猴子吃桃问题就是迭代问题
void  Q_5_12(){
    int x1 = 1,x2; //设第10天有x1 = 1个桃子,前一天有x2个。今天吃一半减一个，昨天的数量为今天的加一乘二。
    for (int day = 0; day < 10; ++day) {
        x2 = (x1+1)*2;              //前一天为x个，后一天个数y为x/2-1   ==> 所以有y = x/2-1 ==> x = (y+1)*2
         x1 = x2;
    }
    printf("%d",x2);
}
void  Q_5_13(){
    float a,x0,x1;
    scanf("%f",&a);     //x1 表示下x(n+1)
    x0 = a/2.0;
    x1 = 1.0/2*(x0+a/x0);
    do{
        x0 = x1;
        x1 = 1.0/2*(x0+a/x0);
    }while (fabs(x0-x1) >= 1e-5);
    printf("%8.2f",x1);
}
void  Q_5_14(){
    float f,f1,x0,x1;
    x1 = 1.5;
    do{
        f = ((2*x0-4)*x0-3)*x0-6;     //f为原函数，f1
        f1 = (6*x0-8)*x0+3;
        x1 = x0-f/f1;                //牛顿迭代公试 x1 = x0 - f/f1 ,x1 代表下一个点
    }while (fabs(x0 - x1) >= 1e-5);
    printf("%5.2f",x1);
}

//用二分法求方程的根 x0为求出来的中点
void  Q_5_15(){
    float x0,x1,x2,f0,f1,f2;
   do{
       scanf("%f,%f",&x1,&x2);
    f1 = x1*((2*x1-4)*x1+3)-6 ;
    f2 = x2*((2*x2-4)*x2+3)-6;
    }while (f1*f2 > 0);
   do{
       x0 = (x1+x2)/2;
       f0 =  x0*((2*x0-4)*x0+3)-6;
       if((f0*f1) > 0){
           x1 = x0;
           f1 = f0;
       }else{
           x2 = x0;
           f2 = f0;
       }
   }while (fabs(f0) >= 1e-5);
   printf("%f",x0);
}

//
void  Q_5_17(){
    int a,b,c;
    for (int a = 1; a <= 3; ++a) {
        for (int b = 1; b <= 3; ++b) {           //一个人只能跟另外一组中的一个人比赛。
            if(a !=b){
                for (int c = 1; c <= 3; ++c) {
                    if(a != c && b != c)
                    if(a != 1 && c != 1 &&c != 3) {
                        printf("a-%d,b-%d,c-%d",a,b,c);
                    }
                }
            }

        }
    }
}

