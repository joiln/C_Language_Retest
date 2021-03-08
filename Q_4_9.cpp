//
// Created by chen on 2021/2/7 17:52.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int num,a[6];
    int i = 0;
    int count = 0;
    scanf("%d",&num);
    while (num >99999){
        cout << "重新输入"<<endl;
        scanf("%d",&num);
    }
    while(num != 0){
        a[i] = num%10;
//        cout << i << endl;
        num = num/10;
        i++;
        count++;
    }
//    cout << "i:" << count << endl;
        cout << count <<endl;
    for (int j = 0; j < count; ++j) {
        printf("%d ",a[count-1-j]);
    }
    cout << endl;
    for (int k = 0; k < count; ++k) {
        printf("%d ",a[k]);
    }

    return 0;
}


