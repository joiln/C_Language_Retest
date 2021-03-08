//
// Created by chen on 2021/3/1 15:40.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool sushu(int num);
bool sushu2(int num);
void lizi_5_7();
void lizi_5_8_fib(); //斐波那契数列
void lizi_5_3();    //求最大公约数和最小公倍数
void Q_2_6();       //2-6,输出100-200的素数
void Q_2_8();       //求方程的根(韦达定理)
void l_2_8();       //输出2000-2500是闰年的
void l_2_8_1();     //闰年另外一种写法
void maopao();      //冒泡（常规）
void maopao_1();    //冒泡（改进）
void maopao_2();    //冒泡（再次改进）


int main() {
//    int grdee;
//    scanf("%d",&grdee);
//    switch (grdee/10){
//        case 10:printf("%c",'A');
//            break;
/*        int num;
        scanf("%d",&num);
    for (int i = 1; i <= num; ++i) {
        if(sushu2(i)) {
            // cout << "shide";
            printf("%d shide\n",i);
        } else
            cout << i <<"bushi"<< endl;
    }
*/
//    lizi_5_7();
//    lizi_5_8_fib();
//    lizi_5_3();
//     Q_2_6();
//     l_2_8();
//        Q_2_8();
//    maopao();
    maopao_2();
        return 0;
}



bool sushu(int num){
    double k;
    int i;
    if(num < 2)
        return false;
    for ( i = 2; i < num; ++i)
        if(num % i == 0)
            break;
    if(i < num){                        //i小于num，表示有比num小的数可以把num除尽，不是素数
        return false;                   //跳出for循环的条件是
    } else
        return true;
}

bool sushu2(int num){
    double k;
    int i;
    k = sqrt(num);
    for ( i = 2; i < k; ++i)
        if(num % i == 0){
            break;
        }
    if (i > k)              //为什么是i>k,因为i在循终止的时候都是i=k，或者i>1，k有可能小数
        return true;
    else
        return false;

}
//2-6,输出100-200的素数
void Q_2_6(){
    int i,j;
    for(i = 100;i <200;++i){
        //    double k = sqrt(i);
        for (j = 2; j < i; ++j) {
            if(i % j == 0)
                break;
        }
        if (j == i)
            printf("%d ",i);
    }
}

void lizi_5_7(){
    double sign = 1.0;
    double fm = 1.0,sum = 0,term = 1.0;
    int couts = 0;
    while (fabs(term)>=1e-6){
        sum += term;
        sign = -sign;
        fm += 2;
        term = sign/fm;
        couts++;
    }
    printf("%10.6f\n",4*sum);
    cout << couts << endl;
}

void lizi_5_8_fib(){
    int f1 = 1,f2 = 1,f3;
    printf("%d %d ",f1,f2);
    for (int i = 0; i < 38; ++i) {
       f3 = f1+f2;
       f1 = f2;
       f2 = f3;
       printf("%d ",f3);
    }
}

//辗转相除法，C语言最大公约数和最小公倍数
void lizi_5_3(){
    int n,m,temp1,temp2;
    int a,b;
    //n为比较大的一个数，m为比较小的一个数，temp为暂时储存变量
    scanf("%d%d",&n,&m);
    //先判断谁大谁小,
    if(n<m){
        temp1 = n;
        n = m;
        m = temp1;
    }
    a = n;
    b = m;
   // printf("%d%d",n,m);       //辗转相除法，就是将大由小的取余，下一轮，小的作为除数。被除数是上一次的除数。直到除数为零
                                //最小公倍数是两个数乘积，再除以最大公约数
    while ((temp2 = n % m) != 0){
        n = m;
        m = temp2;
    }
    printf("zuida:%d",m);
    printf("zuixiagongbeishu:%d",a*b/m);
}

//求方程的根(韦达定理)
void Q_2_8(){
    double a,b,c,derta;
    scanf("%f%f%f",&a,&b,&c);
    derta =  b*b-4*a*c;
    if(derta == 0){
        printf("x1=x2=%f",-1*(b/2*a));
    }
    else if(derta > 0){
        printf("x1=%f,x2=%f",(-1*b+sqrt(derta)/2*a),(-1*b-sqrt(derta)/2*a));
    } else
        printf("no_gen");
}

//输出2000-2500是闰年的
void l_2_8() {
    int count = 0;
    for (int i = 2000; i <=2500 ; ++i) {
        if((i % 4 == 0) && (i % 100 != 0)||(i % 400 == 0)){
            printf("%d ",i);
            count++;
        }
        if(count % 10 == 0){
            printf("\n");
        }
    }
}
//闰年另外一种写法
void l_2_8_1() {
    for (int i = 2000; i <=2500 ; ++i) {

    }
}
// 牛顿迭代法 求导后带入x0，若
void Q_5_14(){
    double x0,x1,f,f1;
    x1=1.5;
    do{
        x0 = x1;
        f=1;
        f1=2;
        x1 = x0-f/f1;
    }while (fabs(x0-x1)>=1e-5);
        printf("s");
}

void maopao(){
    int t;
    int a[10];
   
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < 10-1; ++i) {            //-1是因为第一位和自己比没有意义，所以不用和自己比，少一次
        for (int j = 0; j < 10-1-i; ++j) {         //-i 是因为已经把i个数大小排序确定好了,就不用循环总的次数
            if(a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ",a[i]);
    }

}

//https://blog.csdn.net/weixin_43570367/article/details/102763690

//冒泡优化：增加一个标记(flag)，每次发生交换，就进行标记，如果某次循环完没有标记，则说明已经完成排序，
// 数组有序，剩下的几趟排序就不需要再去执行了，可以提前结束排序。
void maopao_1(){
    int a[10];

    for (int i = 0; i < 10; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < 10-1; ++i) {            //-1是因为第一位和自己比没有意义，所以不用和自己比，少一次
        bool flag = true;
        for (int j = 0; j < 10-1-i; ++j) {         //-i 是因为已经把i个数大小排序确定好了。
            int t;
            if(a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                //元素不是有序的，发生交换，标记false
                flag = false;
            }
            //说明没有发生交换
            if (flag)
                break;
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ",a[i]);
    }
}

//再优化，定义arrBoundary 是无序数组的边界，每次比较比到这里为止，不需要进行后面的排序了。
void maopao_2(){
    int a[10];
    // 最后一次交换的下标
    int lastSwapIndex = 0;
    // 无序数组的边界，每次比较比到这里为止
    int arrBoundary = 10-1;
    int t = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < 10-1; ++i) {            //-1是因为第一位和自己比没有意义，所以不用和自己比，少一次
        bool flag = true;
        for (int j = 0; j < arrBoundary; ++j) {         //-i 是因为已经把i个数大小排序确定好了。
            if(a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                //元素不是有序的，发生交换，标记false
                flag = false;
                //最后一次交换的位置
                lastSwapIndex = j;
            }
            //说明没有发生交换
            if (flag)
                break;
            //把最后一次交换的下标赋值给无序数组的边界
            arrBoundary = lastSwapIndex;
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ",a[i]);
    }
}




//谁是小偷问题
/*公安人员审问四名窃贼嫌疑犯。已知，这四人当中仅有一名是窃贼，还知道这四人中每人要么是诚实的，要么总是说谎的。在回答公安人员的问题中：

甲说："乙没有偷，是丁偷的。"

乙说："我没有偷，是丙便的。"

丙说："甲没有偷，是乙偷的。"

丁说："我没有偷。"

请根据这四人的答话判断谁是盗窃者。
2.问题分析与算法设计
假设A、B、C、D分别代表四个人，变量的值为1代表该人是窃贼。因为只有一个盗贼，一个为1其余三个为0，则A+B+C+D=1
由题目已知：四人中仅有一名是窃贼，且这四个人中的每个人要么说真话，要么说假话，而由于甲、乙、丙三人都说了两句话："X没偷，X偷了"，故不论该人是否说谎，他提到的两人中必有一人是小偷。故在列条件表达式时，可以不关心谁说谎，谁说实话。这样，可以列出下列条件表达式：
甲说："乙没有偷，是丁偷的。" B+D=1
乙说："我没有偷，是丙偷有。" B+C=1
丙说："甲没有偷，是乙偷的。" A+B=1
丁说："我没有偷。" A+B+C+D=1   或者说丁说假话则表示丁偷了即D=1且A=0 B=0 C=0   或者说丁说真话丁没有偷，其他三人偷的即D=0且A+B+C=1
或者可理解为，其中丁只说了一句话，无法判定其真假，表达式反映了四人中仅有一名是窃贼的条件A+B+C+D=1



 */
void Q_whoisthrif(){
    int a,b,c,d;
    for (int i = 'a'; i < 'd'; ++i) {
        if(1);

    }
}
/*有A、B、C、D、E这5个人，每个人额头上都帖了一张黑或白的纸。5人对坐，每 个人都可以看到其他人额头上纸的颜色。5人相互观察后：
A说：“我看见有3人额头上贴的是白纸，1人额头上贴的是黑纸。”
B说：“我看见其他4人额头上贴的都是黑纸。”
C说：“我看见1人额头上贴的是白纸，其他3人额头上贴的是黑纸 。”
D说：“我看见4人额头上贴的都是白纸。”
E什么也没说。

现在己知额头上贴黑纸的人说的都是谎话，额头贴白纸的人说的都是实话。问这5人 谁的额头上贴的是白纸，谁的额头上贴的是黑纸？
 A=> 转化为C语言：A为白说实话：a && b + c + d + e == 3   A为慌：！a && b + c + d + e ！= 3
 B=> b && a + c + d + e == 4 同理
 C=> c && a + b + d + e == 1 同理
 D=> d && a + b + c + e == 4 同理


 */
void  Q_heiyubai(){
    int a,b,c,d,e;
    for (int a = 0; a <=1 ; ++a) {
        for (int b = 0; b <=1 ; ++b) {
            for (int c = 0; c <=1 ; ++c) {
                for (int d = 0; d <=1 ; ++d) {
                    for (int e = 0; e <=1 ; ++e) {
                            if( (a && b + c + d + e == 3 || !a && b + c + d + e != 3) &&
                                    (b &&a + c + d + e == 4 || !b &&a + c + d + e != 4)

                                    );
                    }
                }
            }
        }
    }


}
/*诚实族和说谎族是来自两个岛屿的不同民族，已知诚实族的人永远说真话，而说谎族的人永远说假话。

一天，谜语博士遇到3个人，知道他们可能是来自诚实族或说谎族的。为了调查这3个人到底来自哪个族，博士分别问了他们问题，下面是他们的对话：
博士问：“你们是什么族的？ ”
第1个人回答说：“我们之中有2个来自诚实族。”
第2个人说：“不要胡说，我们3个人中只有一个是来自诚实族的。”
第3个人接着第2个人的话说：“对，确实只有一个是诚实族的。”

请根据他们的回答编程判断出他们分别是来自哪个族的。
 a,b,c 0表慌，1表真话
 1个人回答说：“我们之中有2个来自诚实族。” 为真时：a && a+b+c == 2 为假时: !a && a+b+c!=2
 b && a+b+c == 1 || !b && a+b+c !=1
 c && a+b+c == 1 || !c && a+b+c != 1

 */

//void Q_cs_(){
//    int a,b,c;
//    for (int a = 0; a <=1 ; ++a) {
//        for (int b = 0; i < ; ++i) {
//            for (int j = 0; j < ; ++j) {
//
//            }
//        }
//    }
//
//}

/*两面族是岛屿上的一个新民族，他们的特点是说话时一句真话一句假话，真假交替。即如果第一句说的是真话，则第二句必为假话；如果第一句说的是假话，
 则第二句必然是真话。但第一句话到底是真是假却不得而知。现在谜语博士碰到了3个人，
 这3个人分别来自3个不同的民族，诚实族、说谎族和两面族。谜语博士和这3个人分别进行了对话。

首先，谜语博士问左边的人：“中间的人是哪个族的？”，左边的人回答说：“是诚实族的”。
 =>l说真话：
 来说假话：

谜语博士又问中间的人：“你是哪个族的？”，中间的人回答说：“两面族的”。

最后，谜语博士问右边的人：“中间的人到底是哪个族的？”，右边的人回答说：“是说谎族的”。

现在请编程求出这3个人各自来自哪个族。
 l = 1,m=1,r=1表示左中右来自诚实
 ll,mm,rr,=1 表示 两面
 ！ll && ！rr 表示来自 慌 后同理

 *
 *
 * */
//void Q_cs_2(){
//    int l,m,r,ll,mm,rr;
//    for (int i = 0; i < ; ++i) {
//
//    }
//}

/*
 a,b,c



 */