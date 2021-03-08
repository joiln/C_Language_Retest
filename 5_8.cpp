//
// Created by chen on 2021/3/1 16:34.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int a,b,c;
    for (int i = 100; i < 1000; ++i) {
        a = i/100;
        b = i/10-a*10;
        c = i-b*10-a*100;
        //c = i%10.0;
        //if(i == pow(a,3)+pow(b,3)+pow(c,3))
         //   printf("%f ",i);
       if(i == a*a*a+b*b*b+c*c*c)
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}


