//
// Created by chen on 2021/3/17 21:10.
//
#include <stdio.h>
#include <string.h>

void min_d() {
    char test[200000];
    scanf("%s", test);
    int i = 0;            //循环标记
    int distance = 0;     //当前距离
    int index = -1;      //当一个r所在位置
    while (test[i] != '\0') {
        if (test[i] == 'R') {
            if (i - index > distance)
                distance = i - index;
            index = i;
        }
        i++;
    }
    if ((i - index) > distance)
        distance = i - index;
    printf("%d\n", distance);
}

int main() {
    int d;
    scanf("%d", &d);
    for (int i = 0; i < d; i++) {
        min_d();
    }
    return 0;
}

//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//using namespace std;
//void process(char *str){
//    char *p;
//    p = str;
//    for (int i = 0 ; *p != '\0' ; ++p) {
//        if()
//    }
//}
//
//int main() {
//    int t;
//    scanf("%d",&t);
//    char *signal = (char *)malloc(sizeof (char ));
//    for (int i = 0; i < t; ++i) {
//        scanf("%d",signal);
//        process(signal);
//    }
//    return 0;
//}

/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int m = -1, step = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'L')
                step++;
            else if (s[i] == 'R') {
                m = max(m, step);
                step = 0;
            }

        }
        m = max(m, step);
        if (m == -1)
            m = len;
        cout << m + 1 << endl;
    }
}
*/