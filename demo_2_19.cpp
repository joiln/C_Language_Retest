//
// Created by chen on 2021/1/29 19:50.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    double sum = 1.0,fz,fm;
    fz = fm = 1.0;
    int sign = -1;
    while(fm <= 100){
        fm++;
        sum += sign*fz / fm;
        sign = -sign;                                                                                     
    }
    printf("%f\n",sum);
    return 0;
//    int sign = 1;
//    double deno = 2.0,sum=1.0,term;
//    while(deno <= 100){
//        sign = -sign;
//        term = sign/deno;
//        sum += term;
//        deno++;
//    }
//    printf("%f\n",sum);
//    return 0;
}

