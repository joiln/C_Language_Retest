//
// Created by chen on 2021/3/1 15:16.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int unm,y;
    scanf("%d",&unm);
    if(unm < 0)
        y = -1;
    else if(unm > 0)
        y = 1;
    else
        y = 0;
    printf("%d",y);
    return 0;
}


