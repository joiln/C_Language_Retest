#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


int main() {
    int n;
    int a[10010], b[10010], pos[10010];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",a[i]);           //进隧道顺序
    }
    for (int i = 1; i <=n ; ++i) {
        scanf("%d",b[i]);           //出遂道顺序
        pos[b[i]] = i;                    //记录出隧道时各车的位置
    }
    int temp = 0; int count = 0;    //temp 用于记录前一个车的出隧道 顺序

    for (int i = 1; i <= n; ++i) {    //遍历每个车
        if(pos[a[i]] < temp){
            count++;
        }
        if(pos[a[i]] > temp)
            temp  = pos[a[i]];
    }
    cout << count << endl;
}