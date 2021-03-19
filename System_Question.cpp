#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


typedef struct student          //学生信息
{
    char stu_num[15];           //学号
    char name[15];              //姓名
    char stu_id[20];            //身份证号
    char institute[50];         //学院
    char stu_type;              //学生类型
    char major[50];             //专业
    char route[100];            //返校路线
    char TrafficTools[100];     //交通工具
    char isCloseContact;        //近14天是否有密切接触确诊人员
    char temperature[10];       //入校时温度
    char isFever;               //是否发烧
    char isCough;               //是否咳嗽
    char time[20];              //进校时间

}Student;


void Instruction()                  //帮助
{
    printf("====================学生返校信息管理系统====================\n");
    printf("=                                                          =\n");
    printf("=                   ***功能介绍***                         =\n");
    printf("=                                                          =\n");
    printf("=                   1.录入学生信息                         =\n");
    printf("=                   2.查找学生信息                         =\n");
    printf("=                   3.修改学生信息                         =\n");
    printf("=                   4.按顺序输出某学院学生信息             =\n");
    printf("=                   5.请求帮助                             =\n");
    printf("=                   6.退出系统                             =\n");
    printf("=                                                          =\n");
    printf("=                                                          =\n");
    printf("============================================================\n");
    return ;
}

int main()
{	char password[20]={0};
    int i=5;
    int flag;
    char c='y';
    void Instruction();                //导航界面
    void WriteStuInfo();               //录入成绩
    void Search();                     //查找学生信息
    void Print(Student stu);           //输出学生信息
    void Alter();                      //修改学生信息
    void print_Sort();                 //排序，并将排好序的学生信息写入到新的文件中

    printf("\n\n");
    printf("====================欢迎使用学生返校信息管理系统====================\n\n");

    while(i>0){
        printf("请输入登录密码：");
        scanf("%s",&password);
        if(strcmp(password,"123456")!=0){
            --i;
            printf("密码输入错误，请重新输入，您还有%d次机会\n",i);
        }
        else{
            printf("密码输入正确！");
            break;}
        if(i==0){
            exit(0);}
    }
    Instruction();
    while(c=='y'){
        printf("请输入您需要的操作（按5请求帮助）： \n");
        flag=0;
        scanf("%d",&flag);
        getchar();
        if(flag==1){                    //录入
            WriteStuInfo();
        }
        else if(flag==2){               //查找
            Search();
        }
        else if(flag==3){               //修改
            Alter();
        }
        else if(flag==4){               //排序
            print_Sort();
        }
        else if(flag==5){               //导航
            Instruction();
        }
        else if(flag==6){               //退出系统
            return 0;
        }
        else {
            printf("输入有误！请重新输入！\n ");
            continue;
        }
        printf("是否继续使用该系统（y/n）：");
        scanf("%c",&c);

    }
    system("pause");
    return 0;
}


void WriteStuInfo()                 //录入学生信息
{	 FILE *fp;
    char c='y';
    char file[50]="C:\\Users\\chen\\Desktop\\";

    void Print(Student stu);


    while(c=='y'){
        Student stu={0};                        //初始化
        printf("请按照下列提示完成信息录入：\n\n");

        printf("请输入学号：\n");
        gets(stu.stu_num);
        printf("\n\n");

        printf("请输入姓名：\n");
        //getchar();
        gets(stu.name);
        printf("\n\n");

        printf("请输入身份证号：\n");
        //getchar();
        gets(stu.stu_id);
        printf("\n\n");

        printf("请输入学生类型（本科生：1/硕士生：2/博士生：3）：\n");
        //getchar();
        stu.stu_type=getchar();
        printf("\n\n");

        printf("请输入所在学院：\n");
        getchar();
        gets(stu.institute);
        printf("\n\n");

        printf("请输入所在专业：\n");
        //getchar();
        gets(stu.major);
        printf("\n\n");

        printf("请输入返校所经城市：\n");
        //getchar();
        gets(stu.route);
        printf("\n\n");

        printf("请输入交通工具：\n");
        //getchar();
        gets(stu.TrafficTools);
        printf("\n\n");

        printf("过去14天是否密切接触确诊人员（是：1/否：0）：\n");
        //getchar();
        stu.isCloseContact=getchar();
        printf("\n\n");

        printf("请输入入校时的温度：\n");
        getchar();
        gets(stu.temperature);
        printf("\n\n");

        printf("是否发烧（是：1/否：0）：\n");
        //getchar();
        stu.isFever=getchar();
        printf("\n\n");

        printf("是否咳嗽（是：1/否：0）：\n");
        getchar();
        stu.isCough=getchar();
        printf("\n\n");

        printf("请输入入校时间：\n");
        getchar();
        gets(stu.time);
        printf("\n\n");

        //strcat(str1,str2) 把str2 追加到str1最后面
        strcat(file,stu.institute); //给文件加上名字
        strcat(file,".txt");    //加后缀

        fp=fopen(file,"a");            //用“a”的方式打开文件，向文件末尾继续添加新的数据（不删除原有数据）
        if(fp==NULL)
        {
            printf("文件无法打开！");
            exit(0);
        }
        if(fwrite(&stu,sizeof(Student),1,fp)!=1) //fwrite 一次性写入一组数据（数组或者结构体变量的值）
//   fwrite中参数依次含义：第一个参数是将要输入数据的起始地址，
//            第二个参数：是要读入的字节数，上例的字节数时一个Student 结构体的大小
//            第三个参数：要写入的数据项个数（每个长度为第二个参数的大小）
//            第四个参数：将要写入文件指针
//    fread(1,2,3,4) 表示将从4文件中读取3个2*size 大小的数据存放到1中
        {
            printf("无法录入！");
        }
        fclose(fp);

        printf("是否继续录入（y/n）:\n");
        scanf("%c",&c);
        getchar();
    }

}

void Search()                       //查找学生
{	char c='y';
    int flag;                       //查询方式
    FILE *fp;
    int isSearch;
    void Print(Student stu);
    Student stu={0};       //结构体记得初始化
    while(c=='y'){
        char stu_info[50]={0},ins[50]={0},file[50]="C:\\Users\\chen\\Desktop\\";
        printf("请输入学生所在学院：\n");
        gets(ins);
        strcat(file,ins);
        strcat(file,".txt");


        if ((fp=fopen(file,"r") ) == NULL   ){ //打开该学院的文件
            cout << "failed open file";
            exit(0);
        }

        printf("请输入查找方式（学号：1/姓名：2/身份证号：3）：\n");

        scanf("%d",&flag);
        getchar();

        printf("请输入学生信息：\n");
        gets(stu_info);


        isSearch=0;                                         //是否查找到该学生
        while(fread(&stu,sizeof(Student),1,fp)==1)
        {
            if(flag==1)                                         //按学号查找
            {
                if(!strcmp(stu.stu_num,stu_info))
                {
                    Print(stu);
                    isSearch=1;
                    break;
                }
            }
            if(flag==2)                                         //按姓名查找
            {
                if(!strcmp(stu.name,stu_info))
                {
                    Print(stu);
                    isSearch=1;
                }
            }
            if(flag==3)
            {
                if(!strcmp(stu.stu_id,stu_info))                //按身份证号查找
                {
                    Print(stu);
                    isSearch=1;
                    break;
                }
            }

        }
        if(!isSearch)
            printf("查无此人\n");
        fclose(fp);

        printf("是否继续查找（y/n）：\n");
        scanf("%c",&c);
        getchar();

    }

}
void Print(Student stu)             //输出学生信息
{
    printf("\n*****************学生信息*****************\n\n");
    printf("学号: %s\n姓名: %s\n身份证号: %s\n学生类型: %c\n",stu.stu_num,stu.name,stu.stu_id,stu.stu_type);
    printf("学院: %s\n专业: %s\n返校路线: %s\n交通工具: %s\n",stu.institute,stu.major,stu.route,stu.TrafficTools);
    printf("过去14天是否密切接触确诊人员（是：1/否：0）： %c\n返校温度: %s\n",stu.isCloseContact,stu.temperature);
    printf("是否发烧（是：1/否：0）: %c\n是否咳嗽（是：1/否：0）: %c]\n返校时间: %s\n",stu.isFever,stu.isCough,stu.time);
}

void Alter()                        //修改学生信息
{	FILE *fp;
    int isSearch;
    int pos,num;
    void Print(Student stu);
    int i;

    char c='y';
    while(c=='y'){
        char newfile[10000]="C:\\Users\\chen\\Desktop\\";//不给10000的话被判断溢出
        char stu_info[50],ins[50];//ins 为学院信息
        char file[50]="C:\\Users\\chen\\Desktop\\";
        Student all_stu[50],goal_stu,stu={0};
        printf("请输入学生所在学院：\n");
        gets(ins);
        strcat(file,ins);
        strcat(file,".txt");


        fp=fopen(file,"r");                                      //打开该学院的文件

        printf("请输入学生身份证号：\n");
        gets(stu_info);

        isSearch=0;                                          //是否查找到该学生
        pos=0;num=0;
        for(pos=0;fread(&stu,sizeof(Student),1,fp)==1;pos++){
            if(!strcmp(stu.stu_id,stu_info)){
                goal_stu=stu;
                isSearch=1;
            }
            else {
                all_stu[num++]=stu;
            }
        }


        if(isSearch){
            fclose(fp);
            fp=fopen(file,"w");
            for( i=0; i<num; i++){
                fwrite(&all_stu[i],sizeof(Student),1,fp);
            }

            fclose(fp);

            printf("请按照下列提示完成该学生信息修改：\n\n");

            printf("请输入学号：");
            gets(stu.stu_num);
            printf("\n");

            printf("请输入姓名：");
            //getchar();
            gets(stu.name);
            printf("\n");

            printf("请输入身份证号：");
            //getchar();
            gets(stu.stu_id);
            printf("\n");

            printf("请输入学生类型（本科生：1/硕士生：2/博士生：3）：");
            //getchar();
            stu.stu_type=getchar();
            printf("\n");

            printf("请输入所在学院：");
            getchar();
            gets(stu.institute);

            printf("\n");

            printf("请输入所在专业：");
            //getchar();
            gets(stu.major);
            printf("\n");


            strcat(newfile,stu.institute);
            strcat(newfile,".txt");
            fp=fopen(newfile,"a");
            fwrite(&stu,sizeof(Student),1,fp);
        }
        else
            printf("查无此人\n");

        fclose(fp);                                       //输出一下原来文件内目前的信息
        puts(file);
        fp=fopen(file,"r");
        while(fread(&stu,sizeof(Student),1,fp)==1){
            Print(stu);
        }
        fclose(fp);
        printf("是否继续修改（y/n）:\n");
        scanf("%c",&c);
        getchar();

    }

}
void print_Sort()                   //排序
{	FILE *fp;
    int j, Min;
    int num=0;
    int i;
    Student all_stu[50]={0},stu={0};
    char newfile[10000]="C:\\Users\\chen\\Desktop\\sort_"; //将排好序的学生信息放进新的文件中（文件名已改变！）
    char ins[20],file[50]="C:\\Users\\chen\\Desktop\\";
    printf("请输入学院名称：");
    gets(ins);
    strcat(file,ins);
    strcat(file,".txt");

    fp=fopen(file,"r");                                         //打开文件



    while(fread(&all_stu[num++],sizeof(Student),1,fp)==1){
        //Print(all_stu[num-1]);
    }
    fclose(fp);

    for( i=0;i<num-1;i++){                                  //按照学号从小到大排序（选择排序）
        Min=i;
        for(j=i+1;j<num;j++){
            if(strcmp(all_stu[Min].stu_num,all_stu[j].stu_num)>0){
                Min=j;
            }
        }
        if(Min!=i){
            Student temp=all_stu[i];
            all_stu[i]=all_stu[Min];
            all_stu[Min]=temp;
        }
    }

    //sort(all_stu,all_stu+num,cmp);                             //结构体自定义排序，也可以用上面的选择排序（上面的选择排序只写了一个关键字排序）


    strcat(newfile,ins);
    strcat(newfile,".txt");

    fp=fopen(newfile,"w");                                     //用“w”的方式打开文件
    for( i=0;i<num;i++){
        fwrite(&all_stu[i],sizeof(Student),1,fp);
    }
    fclose(fp);

    fp=fopen(newfile,"r");                                      //输出排序好的文件内容
    while(fread(&stu,sizeof(Student),1,fp)==1){
        Print(stu);
    }
    fclose(fp);
}


