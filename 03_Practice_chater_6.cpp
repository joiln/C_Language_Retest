//
// Created by chen on 2021/3/4 17:58.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stdlib.h>


void  L_6_1();
void  L_6_5();
void  L_6_8();  //验证有多少个单词，单词与单词之间用空格隔开
void  L_6_9(); //
void  Q_6_1(); //用筛选法求100以内素数
void  Q_6_2(); //用选择法对10个整数排序
void  Q_6_3(); //求3*3矩阵的对角线之和
void  Q_6_4(); //链表 插入
void  Q_6_5(); //牛顿迭代法求方程的根。
void  Q_6_6(); //
void  Q_6_7(); //魔方阵
void  Q_6_9(); //折半查找
void  Q_6_10(); //统计大小写、数字、空格、其它字符个数
void  Q_6_13(); //将两个字符串拼接起来，不要用strcat()
void  Q_6_14();
void  Q_6_15();
void  q();


typedef struct list_node{
    int data;
    struct list_node * next;
}node;

node * init_list();
void sort_insert_node(node *list,int elem);
int search_elem(node *list,int elem);



using namespace std;



int main() {
//    L_6_5();
//    L_6_8();
//    Q_6_1();
//    Q_6_2();
//    Q_6_3();
//    node *list,*temp;
//    list = init_list();
//    search_elem(list,5);
//    sort_insert_node(list,4);
//    temp = list;
//    while (temp->next){
//        printf("%d",temp->data);
//        temp = temp->next;
//    }
//    Q_6_7();
//    Q_6_9();
    Q_6_13();

    return 0;
}

void  q(){


}
/*  s[][];
 * 多维数组元素地址：s[0] 地址等价与*(s+0)    s[0][1] 的地址等价于*(s+0)+1  ==> &s[0][1]  其内容为： *(*(s+0)+1)
 *  *(s+i)+j ==> &s[i][j]   即s的首地址+i，表示第i行，*(s+i)表示第i行的地址，+j表示在i行地址处再+j, 即i行上第j的个元素
 *
 *多维数组的指针变量：
 * 数组指针 ==> 指向由m个元素组成的一维数组的指针变量   //todo 格式： 数据类型 (*p)[m];   例子： int (*p)[4];
 *
 *由于小括号的优先级别最高，因此要首先计算小括号，所以指定变量p首先是一个指针变量，其次它指向一个长度为m的一维数组，P为二级指针。
 * 这就是数组指针的定义方式。
 *
 *  int s[3][4];
    int (*p)[4];
    p=s, p指向s数组，p++的值为s+1，它只能对行进行操作，不能对行中的某个元素进行操作，可以使用
    *(*(p+)+j)访问第行第列的数据。

    用指向多维数组的指针作为函数参数
    一维数组的地址可以作为函数参数，多维数组的地址也可作函数参数。在用指针变量作形参以接受实参数组名传递来的地址时，
    有两种方法：用指向变量的指针变量 和 用指向一维数组的指针变量（上一个例子p=a[0]）

    例：double (int (*p)[4],int n);   传进去一个二维数组

用指针变量指向一个字符串
    用指针变量指向一个字符串常量对于字符串而言，也可以不定义字符数组，直接定义指向字符串的指针变量，利用该指针变量对字符串进行操作
    char *string ="I am a student. ";
    printf(" %s\n"，string);


 *
 * */

/*
 *用malloc动态申请一个二维数组的三种方法
 *方法一: 利用二级指针申请一个二维数组。
 **/
void demo_1(){
    int n,m; //创建一个n*m 的二维数组
    int **num = (int **)malloc(sizeof (int *)*n);   //分配每一行的首地址。有n行，每行中的元素大小为 sizeof(int *)

    for (int i = 0; i < n; ++i) {
        num[i] = (int *)malloc(sizeof (int )* m);   //给每行中每个元素开辟空间
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
        printf("%d",num[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        free(num[i]);       //释放每一行中的没个元素
    }
    free(num);  //释放每一行，即释放整个二维数组
}
//用数组指针形式申请一个二维数组。
// 数组指针==>int *(num)[2];


void demo_2(){
    int n,m;
    int **num = (int **)malloc(sizeof (int *) * n); //n行

}




void  Q_6_1(){ //用筛选法求100以内素数
    int n;
    scanf("%d",&n);
    int *num = (int  *)malloc(n * sizeof (int));    //动态开辟内存
    *(num + 0) = 0;

    for (int i = 1; i <= n; ++i)   {
           *(num + i) = i;
    }
    *(num + 1) = 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        for (int j = i+1; j < n; ++j) {
            if(*(num + i) != 0 && *(num + j) != 0){
                if(*(num + j) % *(num + i) == 0)
                *(num + j) = 0;

            }
        }

    }
    for (int i = 0; i < n; ++i) {
        if (*(num + i) != 0)
        printf("%d ",*(num + i));

    }
    free(num);  //动态开辟内存后，要用free()释放,因为malloc()、calloc()、realloc()申请的内存系统不是自己释放
}

void  Q_6_2(){
    int min,n;
    scanf("%d",&n);
    int *num = (int *)malloc(sizeof (int) * n);
    *(num + 0) = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&num[i]);
    }
    for (int i = 1; i <= n; ++i) {
       // min = i;
        for (int j = i + 1; j <= n; ++j) {
            if(*(num + i) > *(num + j)){
               // min = j;
                *(num + 0) = *(num + i);
                *(num + i) = *(num + j);
                *(num + j)  = num[0];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << num[i] << " ";
    }
}
void Q_6_3(){
    int n;
    int sum = 0;
    scanf("%d",&n);
    int **num = (int **)malloc( sizeof (int *) * n);
    for (int i = 0; i < n; ++i) {
        num[i] = (int *)malloc( sizeof (int ) * n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&num[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
      sum += num[i][i]; //主对角线
      sum += num[i][n-1-i];//副对角线
    }
    cout << sum <<endl;
}
/*
 头结点、头指针和首元结点

 头结点：有时，在链表的第一个结点之前会额外增设一个结点，结点的数据域一般不存放数据（有些情况下也可以存放链表的长度等信息），此结点被称为头结点。
若头结点的指针域为空（NULL），表明链表是空表。头结点对于链表来说，不是必须的，在处理某些问题时，给链表添加头结点会使问题变得简单。

首元结点：链表中第一个元素所在的结点，它是头结点后边的第一个结点。

头指针：永远指向链表中第一个结点的位置（如果链表有头结点，头指针指向头结点；否则，头指针指向首元结点）。

//todo 头结点和头指针的区别： 头指针是一个指针，头指针指向链表的头结点或者首元结点；头结点是一个实际存在的结点，它包含有数据域和指针域。

两者在程序中的直接体现就是：头指针只声明而没有分配存储空间，头结点进行了声明并分配了一个结点的实际物理内存。

    *单链表中可以没有头节点，但必须有头指针

 */

//创建链表
node * init_list(){
    node list;
    int n;
    scanf("%d",&n);
    node * head = (node *)malloc(sizeof (node));  //创建一个头节点
    node * temp = head;                          //声明一个指针指temp 将头结点的地址赋给 temp，用于遍历链表
    //生成链表
    for (int i = 0; i < n; ++i) {
        node *num = (node *)malloc(sizeof (node)); //创建一个节点，存放数据
        num->data = i;
        num -> next = NULL;
        temp ->next = num;                      //temp 指向这个节点
        temp = temp ->next;
    }
    return head;
}
int search_elem(node *list,int elem){
    node *p = list;
    int count = 1;
    while (p->next != NULL){
        if(p->data == elem){
            return count;
        }
        else
            count ++ ;
        p = p->next;
    }
    return -1;
}
//按顺序插入
void sort_insert_node(node *list,int elem){
    node * temp;
    temp = list;
    while (temp -> next != NULL){
        if(temp -> data < elem)
            temp = list -> next;
        else
            temp->data = elem;
    }
}

bool delate_node(node *list,int elem){
    node *p,*temp;

}

void  L_6_5(){
    int a[3][4];
    int Max = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
           if(a[i][j] > Max)
               Max = a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (Max == a[i][j])
                printf("Max = %d,r = %d,l = %d",a[i][j],i+1,j+1);
        }
    }
}
/*
魔方阵：
 只有奇数阶魔方阵，不为奇数，自动 n + 1
 1在第一行的中间开始
 规律：1.当前数字能被n整除，放在前一个的下方，即列不变，行 + 1
      2.当不为第一行以及最后一行时，下一个数字放在其右上方。即行-1，列 + 1
      3.当在第一行时，下一个数放在最后一行，列 + 1
      4.当为n行时，下一个数放在第一行，列 + 1

 * */
void  Q_6_7(){
    int m,n,first;
    scanf("%d",&m);
    if (m % 2 == 0){
        n = m + 1;
    } else{
        n = m;
    }
    int **num = (int **)malloc(sizeof (int *)*n);
    for (int i = 0; i < n; ++i) {
        num[i] = (int *)malloc(sizeof (int )*n);
    }//创建二维数组

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            num[i][j] = 0;
        }
    }//给数组全部赋值为0

    first = n/2;
    num[0][first] = 1;  //数字1 的起始位置

    int row = 0,cul = first;
    for (int i = 2; i < m*m; ++i) {
        if (i % n == 0){
            num[row + 1][cul] = i;
        }
        if (row == 0){
            row= n;
        } else{
            row = row+1;
        }
        if (1);


    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << num[i][j] << " " ;
        }
        cout << endl;
    }
    for (int i = 2; i < n; ++i) {

    }
}

void Q_6_9(){
    int num[] = {1,2,3,4,5,7,8,9,10,11},n = 10;
    int low,high,mid; //s区间开始，e为区间结束，mid为折半
    int flag = 0;
    int m,count;
    scanf("%d",&m);

        if (m < num[0] && m > num[9])
        {
            printf("no m");
        }

        low = 0;
        high = n-1;
        while (low <= high){
            mid = (low + high)/2;
            if (num[mid] == m){
                flag = 1;
                count = mid;
            } else if(num[mid] < m){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
    if (flag == 1)
    printf("zhaodao:%d is NO.%d",num[count],count);
    else
        printf("no is m");
}

void  Q_6_10(){
    int n,m;
    scanf("%d,%d",&n,&m);
    int upp=0,lower=0,shuzi = 0,kongge = 0,qita = 0;
    char **num = (char **)malloc(sizeof (char *)*n);
    for (int i = 0; i < n; ++i) {
        num[i] = (char *)malloc(sizeof (char )*m);
    }
    for (int i = 0; i < n; ++i) {
        gets(*(num + i));   //获取一行字符
        for (int j = 0; j < m && num[i][j] != '\0'; ++j) {
            if (num[i][j] >= 'A' && num[i][j] <= 'A')
                upp ++;
            else
                qita++;
        }
        cout << " 00" << endl;
    }

}
void Q_6_13(){
    int count = 0;
    char * string1,*string2,*temp;
//    gets(string1);
//    gets(string2);
//    scanf("%s",string1);
//    scanf("%s",string2);
    for (int i = 0; string1[i] != '\0'; ++i) {
        count++;
    }
    for (int i = 0; string2[i] != '\0'; ++i) {
        count++;
    }
    cout << count;
    char *string = (char *)malloc(sizeof (char )*count);

}


void  L_6_8(){
    char str[] = "how are you?";
    gets(str);
    int word = 0;               //开始的时候把word置为0；表示起始位置，这样就能累加第一个单词
    int i = 0,num = 0;
    while (str[i] != '\0'){
        if (str[i] < 'a' && str[i] > 'z' || str[i] < 'A' && str[i] > 'Z'){
            i++;
            continue;
        }
        if(str[i] == ' ')       //遇到一个空格，把word置为0
            word = 0;
        else if (word == 0){       //遇到不是空格，且word == 0；即表示空格后为新的一个单词
            word = 1;
            num++;
        }
      i++;
    }
    printf("%d",num);

}

void  L_6_9(){

}

void  Q_6_14(){
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    int i = 0;
    while ((str1[i] == str2[i]) && str2[i] != '\0'){
        i++;
    }
    if(1);
}
