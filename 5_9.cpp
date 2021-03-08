//
// Created by chen on 2021/3/1 17:28.
//

#include <iostream>
#include <stdio.h>

using namespace std;
int wanshu(int num);

int main() {
    int sum;
    for (int i = 2; i < 1000; ++i) {
        sum = 0;
        for (int j = 1; j < i; ++j) {
            if(i % j == 0) sum += j;
        }
        if(i == sum){
            printf("%d ,is",i);
            for (int j = 1; j < i; ++j) {
                if (i%j == 0)
                    printf("%d ",j);
            }
            cout << endl;
        }
    }
    return 0;
}

//int wansh(int num){
//    int a[1000];
//    for (int i = 0; i < ; ++i) {
//
//    }
//}


