#include<stdio.h>
#include<stdlib.h>

long max(long a[], long n)                //���a����������ֵ���������±�
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

    for (i = 1; i <= m - k + 1; i++)            //���1��ʼ��k����֮�ͣ�����m-k+1�� ���Ӽ��ܷ�������ʱ�̵�
    {                                //����������ʱ�̣��Ѽ��ܷ������ǹ�ʽ����������ŵ�����r��
        sum = 0;
        for (j = i; j <= i + k - 1; j++)
            sum += p[j];
        r[i] = sum;
    }
    c = max(r, m - k + 1);                    //��ʱcΪr���������������±꣬�����ܷ�����������ʱ��
    for (t = c; t <= c + k - 1; t++)            //���ܷ���ʱ����k������С��������ס�Ĺ�ʽ����
    {
        if (q[t] == 1)
            sum_1 += p[t];
    }
    for (j = 1; j <= m; j++)                //С��������ס��ʽ�ĸ���
    {
        if (q[j] == 1)
            sum_2 += p[j];
    }
    SUM = sum_2 - sum_1 + r[c];            //���ʽ��Ϊ������ס��-�����ڼ�������ס��+���ܷ�����ס��
    printf("%ld", SUM);
    return 0;
}
 
