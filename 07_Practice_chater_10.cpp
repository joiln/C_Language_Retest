//
// Created by chen on 2021/3/15 16:58.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct Student{
    int num;
    char name[10];
    int age;
    int addr[50];

}Student;



void L_10_1() {
    FILE *fp;
    char ch, fliename[10];
    printf("请输入文件名：");
    gets(fliename);
    if ((fp = fopen(fliename, "w")) == NULL) {
        cout << "Error";
        exit(0);
    }
    cout << "输入一个字符" << endl;
    ch = getchar();     //getchar() 从键盘获取一个字符
    while (ch != '#') {
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    }
    fclose(fp);
}

void L_10_2() {
    FILE *fp1, *fp2;
    char ch, name1[50], name2[50];
    puts("filename 1 and 2");
    gets(name1);
    gets(name2);
    if ((fp1 = fopen(name1, "r")) == NULL) {
        puts("Error");
        exit(0);
    }
    if ((fp2 = fopen(name2, "w")) == NULL) {
        puts("Error");
        exit(0);
    }
    ch = fgetc(fp1); //从fp中读取一个字符
    while (!feof(fp1)) {   //feof(file) feof检测文件结尾标准是否被读取过。是则返回1，没有被读过返回-1
        fputc(ch, fp2);      // 其实也可以改写 while(ch != EOF) （EOF == -1）
        putchar(ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
}

void L_10_3() {
    FILE *fp;
    int n, min;
    char file[100] = "D:\\Data_Structure_Codes\\C_Language_Retest\\cmake-build-debug\\file.dat";
    cin >> n;
    char ch = getchar(), ch1; //汲取回车
    char num[3][10];
    char temp[10], *(p)[10];
    for (int i = 0; i < n; ++i) {
        gets(*(num + i)); //num[i] == *(num + i)  表示从i行0列开始，类型是行
    }

//    for (int i = 0; i < n; ++i) {
//        cout << num[i] << endl;
//    }

    //选择法排序
    for (int i = 0; i < n; ++i) {
        min = i;
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(*(num + min), *(num + j)) > 0)
                min = j;
        }
        if (min != i) {
            strcpy(temp, *(num + i));
            strcpy(*(num + i), *(num + min));
            strcpy(*(num + min), (temp));
        }
    }
//    for (int i = 0; i < n; ++i) {
//        cout << num[i] << endl;
//    }

//    for (p = num; *p ; ++p) {
//        cout << *p << " ";
//    }
    if ((fp = fopen(file, "w+")) == NULL) {
        puts("Error");
        exit(0);
    }

    for (int i = 0; i < n; ++i) {
        cout << *(num +i) <<endl;
        fputs(num[i], fp);
        fputs("\n", fp);
    }
    fclose(fp);

    if ((fp = fopen(file, "r+")) == NULL) {
        puts("Error");
        exit(0);
    }
    char str[3][10];
    int i = 0;
    while (fgets(str[i],5, fp) != NULL)
    {
        cout << str[i];
        i++;
    }
    //    cout << "new file"<<endl;
//    ch1 = fgetc(fp);
//    while (!feof(fp)){
//         ch1 = fgetc(fp);
//        putchar(ch1);
//    }
    fclose(fp);
}

void L_10_4(){
    FILE *fp;
    int n,i, min;
    char file[100] = "D:\\Data_Structure_Codes\\C_Language_Retest\\cmake-build-debug\\file.dat";
    for( i = 0 ; i<10 ; i++);
//        if ( fwrite( &stud[i] , sizeof( struct student ) , 1 , fp) ! = 1 );
//
//      fwrite(a,size,long,fp);

}

//有一个磁盘文件，第一次将它 的 内 容显示在屏 幕 上 ， 第二次把它 复 制 到 另一文件上 。
void L_10_5(){
    FILE *fp1,*fp2;
    char ch;
    fopen("D:\\Data_Structure_Codes\\C_Language_Retest\\cmake-build-debug\\file.dat","r");
    fopen("D:\\Data_Structure_Codes\\C_Language_Retest\\cmake-build-debug\\file1.dat","w");
    ch = fgetc(fp1);    //从fp1 中读取一个字节
    while (!feof(fp1)){ //没有到文件尾
        putchar(ch);    //输出ch
        ch = fgetc(fp1);    //
    }
    rewind(fp1); //把文件指针移到问就按头

    ch = fgetc(fp1); //
    while (!feof(fp1)){
        fputc(ch,fp2);  //把ch 写入fp2 中
        ch = fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
}
void L10_6(){
    FILE *fp;
    Student student[10];
    char file[100] = "D:\\Data_Structure_Codes\\C_Language_Retest\\cmake-build-debug\\stu_list.dat";
    if ((fp = fopen(file, "w+")) == NULL) {
        puts("Error");
        exit(0);
    }
    for (int i = 0; i < 10; ++i) {
        fseek(fp,sizeof (Student),0);
        fread(&student[i],sizeof (Student),1,fp);
        printf("%s %d %d %c\n", student[i].name , student[i]. num , student[i]. age) ;
    }
    fclose(fp);
}



int main() {
//    L_10_1();
//    L_10_2();
    L_10_3();
    return 0;
}


