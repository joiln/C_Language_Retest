#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


typedef struct student          //ѧ����Ϣ
{
    char stu_num[15];           //ѧ��
    char name[15];              //����
    char stu_id[20];            //���֤��
    char institute[50];         //ѧԺ
    char stu_type;              //ѧ������
    char major[50];             //רҵ
    char route[100];            //��У·��
    char TrafficTools[100];     //��ͨ����
    char isCloseContact;        //��14���Ƿ������нӴ�ȷ����Ա
    char temperature[10];       //��Уʱ�¶�
    char isFever;               //�Ƿ���
    char isCough;               //�Ƿ����
    char time[20];              //��Уʱ��

}Student;


void Instruction()                  //����
{
    printf("====================ѧ����У��Ϣ����ϵͳ====================\n");
    printf("=                                                          =\n");
    printf("=                   ***���ܽ���***                         =\n");
    printf("=                                                          =\n");
    printf("=                   1.¼��ѧ����Ϣ                         =\n");
    printf("=                   2.����ѧ����Ϣ                         =\n");
    printf("=                   3.�޸�ѧ����Ϣ                         =\n");
    printf("=                   4.��˳�����ĳѧԺѧ����Ϣ             =\n");
    printf("=                   5.�������                             =\n");
    printf("=                   6.�˳�ϵͳ                             =\n");
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
    void Instruction();                //��������
    void WriteStuInfo();               //¼��ɼ�
    void Search();                     //����ѧ����Ϣ
    void Print(Student stu);           //���ѧ����Ϣ
    void Alter();                      //�޸�ѧ����Ϣ
    void print_Sort();                 //���򣬲����ź����ѧ����Ϣд�뵽�µ��ļ���

    printf("\n\n");
    printf("====================��ӭʹ��ѧ����У��Ϣ����ϵͳ====================\n\n");

    while(i>0){
        printf("�������¼���룺");
        scanf("%s",&password);
        if(strcmp(password,"123456")!=0){
            --i;
            printf("��������������������룬������%d�λ���\n",i);
        }
        else{
            printf("����������ȷ��");
            break;}
        if(i==0){
            exit(0);}
    }
    Instruction();
    while(c=='y'){
        printf("����������Ҫ�Ĳ�������5����������� \n");
        flag=0;
        scanf("%d",&flag);
        getchar();
        if(flag==1){                    //¼��
            WriteStuInfo();
        }
        else if(flag==2){               //����
            Search();
        }
        else if(flag==3){               //�޸�
            Alter();
        }
        else if(flag==4){               //����
            print_Sort();
        }
        else if(flag==5){               //����
            Instruction();
        }
        else if(flag==6){               //�˳�ϵͳ
            return 0;
        }
        else {
            printf("�����������������룡\n ");
            continue;
        }
        printf("�Ƿ����ʹ�ø�ϵͳ��y/n����");
        scanf("%c",&c);

    }
    system("pause");
    return 0;
}


void WriteStuInfo()                 //¼��ѧ����Ϣ
{	 FILE *fp;
    char c='y';
    char file[50]="C:\\Users\\chen\\Desktop\\";

    void Print(Student stu);


    while(c=='y'){
        Student stu={0};                        //��ʼ��
        printf("�밴��������ʾ�����Ϣ¼�룺\n\n");

        printf("������ѧ�ţ�\n");
        gets(stu.stu_num);
        printf("\n\n");

        printf("������������\n");
        //getchar();
        gets(stu.name);
        printf("\n\n");

        printf("���������֤�ţ�\n");
        //getchar();
        gets(stu.stu_id);
        printf("\n\n");

        printf("������ѧ�����ͣ���������1/˶ʿ����2/��ʿ����3����\n");
        //getchar();
        stu.stu_type=getchar();
        printf("\n\n");

        printf("����������ѧԺ��\n");
        getchar();
        gets(stu.institute);
        printf("\n\n");

        printf("����������רҵ��\n");
        //getchar();
        gets(stu.major);
        printf("\n\n");

        printf("�����뷵У�������У�\n");
        //getchar();
        gets(stu.route);
        printf("\n\n");

        printf("�����뽻ͨ���ߣ�\n");
        //getchar();
        gets(stu.TrafficTools);
        printf("\n\n");

        printf("��ȥ14���Ƿ����нӴ�ȷ����Ա���ǣ�1/��0����\n");
        //getchar();
        stu.isCloseContact=getchar();
        printf("\n\n");

        printf("��������Уʱ���¶ȣ�\n");
        getchar();
        gets(stu.temperature);
        printf("\n\n");

        printf("�Ƿ��գ��ǣ�1/��0����\n");
        //getchar();
        stu.isFever=getchar();
        printf("\n\n");

        printf("�Ƿ���ԣ��ǣ�1/��0����\n");
        getchar();
        stu.isCough=getchar();
        printf("\n\n");

        printf("��������Уʱ�䣺\n");
        getchar();
        gets(stu.time);
        printf("\n\n");

        //strcat(str1,str2) ��str2 ׷�ӵ�str1�����
        strcat(file,stu.institute); //���ļ���������
        strcat(file,".txt");    //�Ӻ�׺

        fp=fopen(file,"a");            //�á�a���ķ�ʽ���ļ������ļ�ĩβ��������µ����ݣ���ɾ��ԭ�����ݣ�
        if(fp==NULL)
        {
            printf("�ļ��޷��򿪣�");
            exit(0);
        }
        if(fwrite(&stu,sizeof(Student),1,fp)!=1) //fwrite һ����д��һ�����ݣ�������߽ṹ�������ֵ��
//   fwrite�в������κ��壺��һ�������ǽ�Ҫ�������ݵ���ʼ��ַ��
//            �ڶ�����������Ҫ������ֽ������������ֽ���ʱһ��Student �ṹ��Ĵ�С
//            ������������Ҫд��������������ÿ������Ϊ�ڶ��������Ĵ�С��
//            ���ĸ���������Ҫд���ļ�ָ��
//    fread(1,2,3,4) ��ʾ����4�ļ��ж�ȡ3��2*size ��С�����ݴ�ŵ�1��
        {
            printf("�޷�¼�룡");
        }
        fclose(fp);

        printf("�Ƿ����¼�루y/n��:\n");
        scanf("%c",&c);
        getchar();
    }

}

void Search()                       //����ѧ��
{	char c='y';
    int flag;                       //��ѯ��ʽ
    FILE *fp;
    int isSearch;
    void Print(Student stu);
    Student stu={0};       //�ṹ��ǵó�ʼ��
    while(c=='y'){
        char stu_info[50]={0},ins[50]={0},file[50]="C:\\Users\\chen\\Desktop\\";
        printf("������ѧ������ѧԺ��\n");
        gets(ins);
        strcat(file,ins);
        strcat(file,".txt");


        if ((fp=fopen(file,"r") ) == NULL   ){ //�򿪸�ѧԺ���ļ�
            cout << "failed open file";
            exit(0);
        }

        printf("��������ҷ�ʽ��ѧ�ţ�1/������2/���֤�ţ�3����\n");

        scanf("%d",&flag);
        getchar();

        printf("������ѧ����Ϣ��\n");
        gets(stu_info);


        isSearch=0;                                         //�Ƿ���ҵ���ѧ��
        while(fread(&stu,sizeof(Student),1,fp)==1)
        {
            if(flag==1)                                         //��ѧ�Ų���
            {
                if(!strcmp(stu.stu_num,stu_info))
                {
                    Print(stu);
                    isSearch=1;
                    break;
                }
            }
            if(flag==2)                                         //����������
            {
                if(!strcmp(stu.name,stu_info))
                {
                    Print(stu);
                    isSearch=1;
                }
            }
            if(flag==3)
            {
                if(!strcmp(stu.stu_id,stu_info))                //�����֤�Ų���
                {
                    Print(stu);
                    isSearch=1;
                    break;
                }
            }

        }
        if(!isSearch)
            printf("���޴���\n");
        fclose(fp);

        printf("�Ƿ�������ң�y/n����\n");
        scanf("%c",&c);
        getchar();

    }

}
void Print(Student stu)             //���ѧ����Ϣ
{
    printf("\n*****************ѧ����Ϣ*****************\n\n");
    printf("ѧ��: %s\n����: %s\n���֤��: %s\nѧ������: %c\n",stu.stu_num,stu.name,stu.stu_id,stu.stu_type);
    printf("ѧԺ: %s\nרҵ: %s\n��У·��: %s\n��ͨ����: %s\n",stu.institute,stu.major,stu.route,stu.TrafficTools);
    printf("��ȥ14���Ƿ����нӴ�ȷ����Ա���ǣ�1/��0���� %c\n��У�¶�: %s\n",stu.isCloseContact,stu.temperature);
    printf("�Ƿ��գ��ǣ�1/��0��: %c\n�Ƿ���ԣ��ǣ�1/��0��: %c]\n��Уʱ��: %s\n",stu.isFever,stu.isCough,stu.time);
}

void Alter()                        //�޸�ѧ����Ϣ
{	FILE *fp;
    int isSearch;
    int pos,num;
    void Print(Student stu);
    int i;

    char c='y';
    while(c=='y'){
        char newfile[10000]="C:\\Users\\chen\\Desktop\\";//����10000�Ļ����ж����
        char stu_info[50],ins[50];//ins ΪѧԺ��Ϣ
        char file[50]="C:\\Users\\chen\\Desktop\\";
        Student all_stu[50],goal_stu,stu={0};
        printf("������ѧ������ѧԺ��\n");
        gets(ins);
        strcat(file,ins);
        strcat(file,".txt");


        fp=fopen(file,"r");                                      //�򿪸�ѧԺ���ļ�

        printf("������ѧ�����֤�ţ�\n");
        gets(stu_info);

        isSearch=0;                                          //�Ƿ���ҵ���ѧ��
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

            printf("�밴��������ʾ��ɸ�ѧ����Ϣ�޸ģ�\n\n");

            printf("������ѧ�ţ�");
            gets(stu.stu_num);
            printf("\n");

            printf("������������");
            //getchar();
            gets(stu.name);
            printf("\n");

            printf("���������֤�ţ�");
            //getchar();
            gets(stu.stu_id);
            printf("\n");

            printf("������ѧ�����ͣ���������1/˶ʿ����2/��ʿ����3����");
            //getchar();
            stu.stu_type=getchar();
            printf("\n");

            printf("����������ѧԺ��");
            getchar();
            gets(stu.institute);

            printf("\n");

            printf("����������רҵ��");
            //getchar();
            gets(stu.major);
            printf("\n");


            strcat(newfile,stu.institute);
            strcat(newfile,".txt");
            fp=fopen(newfile,"a");
            fwrite(&stu,sizeof(Student),1,fp);
        }
        else
            printf("���޴���\n");

        fclose(fp);                                       //���һ��ԭ���ļ���Ŀǰ����Ϣ
        puts(file);
        fp=fopen(file,"r");
        while(fread(&stu,sizeof(Student),1,fp)==1){
            Print(stu);
        }
        fclose(fp);
        printf("�Ƿ�����޸ģ�y/n��:\n");
        scanf("%c",&c);
        getchar();

    }

}
void print_Sort()                   //����
{	FILE *fp;
    int j, Min;
    int num=0;
    int i;
    Student all_stu[50]={0},stu={0};
    char newfile[10000]="C:\\Users\\chen\\Desktop\\sort_"; //���ź����ѧ����Ϣ�Ž��µ��ļ��У��ļ����Ѹı䣡��
    char ins[20],file[50]="C:\\Users\\chen\\Desktop\\";
    printf("������ѧԺ���ƣ�");
    gets(ins);
    strcat(file,ins);
    strcat(file,".txt");

    fp=fopen(file,"r");                                         //���ļ�



    while(fread(&all_stu[num++],sizeof(Student),1,fp)==1){
        //Print(all_stu[num-1]);
    }
    fclose(fp);

    for( i=0;i<num-1;i++){                                  //����ѧ�Ŵ�С��������ѡ������
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

    //sort(all_stu,all_stu+num,cmp);                             //�ṹ���Զ�������Ҳ�����������ѡ�����������ѡ������ֻд��һ���ؼ�������


    strcat(newfile,ins);
    strcat(newfile,".txt");

    fp=fopen(newfile,"w");                                     //�á�w���ķ�ʽ���ļ�
    for( i=0;i<num;i++){
        fwrite(&all_stu[i],sizeof(Student),1,fp);
    }
    fclose(fp);

    fp=fopen(newfile,"r");                                      //�������õ��ļ�����
    while(fread(&stu,sizeof(Student),1,fp)==1){
        Print(stu);
    }
    fclose(fp);
}


