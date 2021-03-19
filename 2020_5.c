#include<stdio.h>
#include<stdlib.h>

long max(long a[], long n)                //求出a数组中最大的值，返回其下标
{
    long i, c, max;
    max = a[1];
    for (i = 1; i <= n; i++) {
        if (a[i] > max) {
            max = a[i];
            c = i;
        }
    }
    return c;
}

int main() {
    long m, k, i, j, c, t, sum, sum_1 = 0, sum_2 = 0, SUM = 0;
    scanf("%ld%ld", &m, &k);

    long *p = (long *) malloc(sizeof(long) * (m + 1));
    long *q = (long *) malloc(sizeof(long) * (m + 1));
    long *r = (long *) malloc(sizeof(long) * (m - k + 2));

    for (i = 1; i <= m; i++)
        scanf("%ld", &p[i]);
    for (j = 1; j <= m; j++)
        scanf("%ld", &q[j]);

    for (i = 1; i <= m - k + 1; i++)            //求从1开始，k个数之和，共求m-k+1个 即从技能发动最早时刻到
    {                                //技能最晚发动时刻，把技能发动所记公式数求出来，放到数组r里
        sum = 0;
        for (j = i; j <= i + k - 1; j++)
            sum += p[j];
        r[i] = sum;
    }
    c = max(r, m - k + 1);                    //此时c为r数组中最大的数的下标，即技能发动收益最大的时刻
    for (t = c; t <= c + k - 1; t++)            //技能发动时刻起k分钟内小军正常记住的公式个数
    {
        if (q[t] == 1)
            sum_1 += p[t];
    }
    for (j = 1; j <= m; j++)                //小军正常记住公式的个数
    {
        if (q[j] == 1)
            sum_2 += p[j];
    }
    SUM = sum_2 - sum_1 + r[c];            //最大公式数为正常记住的-技能期间正常记住的+技能发动记住的
    printf("%ld", SUM);
    return 0;
}
 
