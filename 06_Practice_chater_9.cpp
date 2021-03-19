//
// Created by chen on 2021/3/14 12:46.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

//结构体的运用
struct Person{
    char name[20];
    int count;
}leader[3] = {"LM",0,"XW",0,"ZS",0};

//Q_9_4
struct Sutdent{
    int num;
    char name[20];
    int score;
};

void Q_9_3(){
    char leadr_name[20];
    for (int i = 0; i < 3; ++i) {
        scanf("%s",leadr_name);
        for (int j = 0; j < 3; ++j) {
            if (strcmp(leader[j].name,leadr_name) == 0)
                leader[j].count ++;
        }
        printf("Reslut");
        for (int j = 0; j < 3; ++j) {
            printf("%s %d",leader[j].name,leader[j].count);
        }
        sort(1,2);
    }

}
//定义结构体数组，用选择法给结构体中的数排序；
void Q_9_4(){
    int n;
    scanf("%d",&n);
    struct  Sutdent *sutdent = (Sutdent *)malloc(sizeof (Sutdent) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %d",&sutdent[i].num,sutdent[i].name,&sutdent[i].score);
    }
    struct Sutdent temp;
    for (int i = 0; i < n-1; ++i) {     //选择法排序
        int min = i;                    //假定第一个是最小的
        for (int j = i + 1; j < n; ++j) {   //从它后一个开始，依次比较，只要找到比下标min还小的，就把下标赋值给min
            if (sutdent[j].score < sutdent[min].score){
                min = j;    //
            }
        }
        if (min != i){          //交换
            temp = sutdent[i];
            sutdent[i] = sutdent[min];
            sutdent[min] = temp;                //当结构体内部成员变量全部相同的时候，可以进行整体替换。而不用每个成员变量进行替换
        }
    }
    for (int i = n-1; i >= 0; --i) {
        printf("%d %s %d\n",sutdent[i].num,sutdent[i].name,sutdent[i].score);
    }
}

//结构体指针的运用
void Q_9_6(){
    int n;
    scanf("%d",&n);
    struct  Sutdent *sutdent = (Sutdent *)malloc(sizeof (Sutdent) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %d",&sutdent[i].num,sutdent[i].name,&sutdent[i].score);
    }
    struct Sutdent *p;

    for (p = sutdent;p < sutdent + n; p++){             //利用结构体指针指向结构体数组的起始地址，将每个成员的变量输出。p再自加
        printf("%d %s %d \n",p->num,p->name,p->score);
    }
}
//链表的操作
typedef struct list{
    int data;
    struct  list *next;
    list(){data = 0; next = nullptr;} //C++中初始化结构体
}Linklist;

//链表的创建是动态创建的，是一个节点一个节点链接起来的。
Linklist *init_list(int n){                          //指针函数，创建完链表后返回链表的起始地址，给主函数中的头节点 head
    //Linklist *head,p1,p2;
    Linklist *header =(Linklist *)malloc(sizeof (Linklist));  //创建一个头节点，
    Linklist *p = header;  //创建一个p指针，起桥梁作用，用于遍历链表

    for (int i = 0; i < n ; ++i) {
        Linklist *node = (Linklist *)malloc(sizeof (Linklist));
        node->data = i + 1;
        node->next =NULL;
        //
        p->next = node;        //让头节点指向node
        p = p->next;        //让p向后移，现在p指向node，
    }
    return header;
}


//打印链表,本链表有头节点，需要处理头节点无数据的问题
void show(Linklist *list_header){
    Linklist *p;  //p 是用来遍历链表的锚点
    p = list_header; //linklist 结构 头节点 -> 节点一 -> 节点二 -> 节点三 ->NULL
    while (p->next != NULL){   //由于头节点的存在，因此while中的判断为p->next
        p = p->next;           //如果头节点的指向的节点不为空，p向后移
        printf("%d ",p->data);
    }
    cout << endl;
}

//插入元素
Linklist *insertElem(Linklist *list_header,int data,int num){
    Linklist *p,*node;
    p = list_header;
    for (int i = 0; i < num; ++i) {
        if (p == NULL){
            cout << "Error";
            return p;
        }
        p = p->next; //往后移动
    }
    node = (Linklist *)malloc(sizeof (Linklist));
    node->data = data;

    node->next = p->next;   //先将新节点的next指向要插入位置的下一个节点
    p->next = node;         //再让前一个节点指向新节点，完成插入。
}                           //如果顺序相反的话，会导致丢失后面节点地址

//查找data删除元素
Linklist *delElem_num(Linklist *list_header, int data){
    Linklist *p1,*p2; //p1 为指向要删除的节点，p2指向要删除节点之前的一个
    p1 = p2 = list_header;
    while (p1->next != NULL)    //由于头节点的存在，因此while中的判断为p1->next
    {                           //相当于直接跳过头节点，判断头节点指向的下一个节点
        p1 = p1->next;
        if (p1->data == data){

            p2->next = p1->next;//把要删除的前一个节点的next指向要删除节点的后一个，
            break;              // 实现删除操作
        } else
            p2 = p2->next;
    }
    free(p1);
   // cout  << p1->data << " has deleted." << endl;
    return list_header;
}
//按照序号删除元素
Linklist *delElem_seq(Linklist *list_header, int seq){
    Linklist *temp = list_header;
    Linklist *del = NULL;
    for (int i = 0; i < seq-1; ++i) {   // seq-1 让temp指向被删除的前一个节点
        temp = temp->next;
    }
    del = temp->next; //让del指向被删除的节点
    temp->next = del->next;
    free(del);
    return list_header;
}

//链表元素的查找
int selectElem(Linklist *list_header,int data){
    Linklist *p;
    p = list_header;
    int count = 1;
    while (p->next != NULL){
        p = p->next;
        if (p->data == data){
            return count;
        }
        count++;
    }
    //没有找到，返回-1
    return -1;
}

//链表反转
void ReverseList(Linklist *list_header){
    Linklist *p,*cur,*pre; //cur 用来遍历整个链表,并保存当前节点。 pre 用来保存cur前一个节点地址
    p = list_header; //p指针指向链表的头节点

    cur = list_header->next; //让cur指向第一个节点
    pre = nullptr;

    if (p->next == NULL || p->next->next == NULL)   //只有头节点或者一个节点的时候，直接返回
        return;
    while (cur){    //当前节点不为空时
        p = cur->next;     //p指向当前节点的下一个节点,保存后续节点地址，防止地址丢失
        cur->next = pre;   //调整指向，把当前节点的next指向前一个
        pre = cur;         //pre 后移
        cur = p;           //cur 后移
    }
    list_header->next = pre;
}

//链表
void List(){
    int n,ins_num,ins_seq,del_num,del_seq;
//    cin >> n;
    Linklist *list_header;
    list_header= init_list(5);
    show(list_header);
//    cout << " enter insert number:"<< endl;
//    cin >> ins_num;
//    cout << " enter insert sequence:"<< endl;
//    cin >> ins_seq;
    cout << " enter delete sequence:"<< endl;
    cin >> del_seq;

//    insertElem(linklist,ins_num,ins_seq-1);
//    show(linklist);

//    delElem_num(linklist,del_num);
//    show(linklist);
    delElem_num(list_header,del_seq);
    show(list_header);
    int select_num;
    cin >> select_num;
    cout << "data " << select_num << " is NO." << selectElem(list_header,select_num) << endl;
    ReverseList(list_header);
    show(list_header);
}

//快速排序

//交换两个数
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//划分左右半区函数
int partition(int *num,int low,int high){
    int p = *(num + high);  //基准数p每次都是最后一个 => num[high]
    int i = low;            //i 指向第一个数
    int j = high - 1;       //j 指向基准数p前一个数

    while (1){
        while (num[i] < p)
            i++; //如果这个数小于基准数p，继续往后面找,直到这个数>=p，才停下来
        while (num[j] > p)
            j--;  //如果这个数大于基准数p，继续往后面找,直到这个数<=p，才停下来
                                //--j 表示j先自减1，在使用j；即指向high前一个元素，
        if (i < j) //如果i、j 没有交错，则交换i与j处的数。
            swap(num + i,num + j);
        else {  //否则，i > j 小的下标比大的下标大，发生交错，停止遍历。



        }

    }
    //把i处的数与最后一个元素交换，即基准数交换，把基准数放到i的位置
    swap(num + i,num + high);
    return i; //返回i的位置
}

//快排核心代码
void sort(int *num,int low,int high){
    if (low < high) { //如果有两个及其以上的数，才进行划分，一个数默认已经排序好了
        int mid = partition(num,low,high);  //划分左右区
        sort (num,low,mid - 1); //递归，对左半区进行排序
        sort (num,mid + 1,high); //递归，对友邦去进行排序
    }
}

//快排调用
void Qsort(){
    int n;
    cin >>n;
    int *num = (int *)malloc(sizeof (int ) *n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",(num + i));
    }
    sort(num,0,n-1);
    for (int i = 0; i < n; ++i) {
        cout << *(num + i) << " ";
    }
    free(num);
}




int main() {
 //   Q_9_6();
//   Qsort();
    List();
    return 0;
}


