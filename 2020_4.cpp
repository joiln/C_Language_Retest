//
// Created by chen on 2021/3/18 10:22.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define Goble_cur_patient 40000000
#define weight1 0.7
#define weight2 0.3
#define file "C:\\Users\\chen\\Desktop\\Information.txt"

using namespace std;

typedef struct Infomation {
    char date[20];
    char country[50];
    char continent[20];
    float poeple;
    float area;
    float estabilsh_area;
    float density;
    float add_patient;
    float sum_patient;
    float cur_patient;  //现存确诊人数
    float cur_patient_dest;  //现存确诊人数密度
    float cur_patient_rate;  //现存确诊人口比例
    float sum_death;
    float sum_cure;
    float death_rate;
    float cure_rate;
    float severe_rate;
} Info;

void Introducation() {
    printf("====================全球疫情管理系统=============================\n");
    printf("                      功能选择菜单\n                                 ");
    printf("\n");
    printf("1.录入信息\n\n");
    printf("==============================================================\n");
}

void Show(Info info);   //输出疫情信息
void Insert();         //录入消息
void Serach();          //查找
void Print_sort();      //排序打印
void ReadInfo();        //读取文件数据
void Login();              //登录
void function(int flag);    //  功能菜单


int main() {
    char c;
    int flag;
    Info info = {0};
    Login();
    cout << "选择功能,输入序号" << endl;
    cin >> flag;
    function(flag);
    return 0;
}

void Login() {
    char paswd[20];
    int count = 5;
    char c = 'y';
    while (count > 0) {
        printf("请登录，输入密码\n");
        scanf("%s", paswd);
        if (strcmp(paswd, "123456") == 0) {
            Introducation();
            break;
        } else {
            count--;
            printf("密码错误，请重新输入，还有%d次机会\n", count);
        }
        if (count == 0) {
            cout << "次数用完退出\n";
            exit(0);
        }
    }
}

void function(int flag) {    //功能菜单
    char c = 'y';

    while (c == 'y') {
        if (flag == 1) {            //录入疫情信息
            Insert();
        } else if (flag == 2) {
            // Show(Info info);
        } else if (flag == 3) {
            Insert();
        } else if (flag == 4) {
            Insert();
        } else if (flag == 5) {
            Insert();
        } else if (flag == 6) {
            Insert();
        } else {
            printf("输入有误！请重新输入！\n ");
            continue;
        }
        printf("是否继续使用该系统（y/n）：");
        scanf("%c", &c);
    }
}


void Insert() {
//       printf("insert");
    FILE *fp;
    char c = 'y';
    Info info = {0};    //对结构体进行初始化

    // Show(info);
    while (c == 'y') {
        printf("请输入以下信息\n");
        printf("请输入日期(如2021-03-19)\n");
        getchar();
        gets(info.date);

        printf("请输入国家名\n");
        getchar();
        gets(info.country);
        //           puts(info.country);
        getchar();

        printf("请输入所属洲\n");
        getchar();
        gets(info.continent);

        printf("请输入国家总人数\n");
        //getchar();
        scanf("%f", info.poeple);

        printf("请输入国土面积(平方公里)\n");
        //getchar();
        scanf("%f", info.area);

        printf("请输入建成区面积(平方公里)\n");
        //getchar();
        scanf("%f", info.estabilsh_area);

        printf("人口密度\n");
        //getchar();
        float density;
        density = info.poeple / info.estabilsh_area;
        printf("%5.3f", density);
        info.density = density;
        printf("==========================================");
        printf("以下是每日疫情录入数据");

        printf("请输入累计确诊人数\n");
        scanf("%f", info.sum_patient);

        printf("请输入累计确诊人数\n");
        scanf("%f", info.add_patient);

        printf("请输入累计死亡人数\n");
        scanf("%f", info.sum_death);

        printf("请输入累计确诊治愈人数\n");
        scanf("%f", info.sum_cure);

        printf("请输入累计确诊人数\n");
        scanf("%f", info.sum_patient);

        info.cure_rate = info.cur_patient / info.sum_patient;
        printf("计算得治愈率：\n");
        printf("%f", info.cure_rate);

        info.death_rate = info.sum_death / (info.sum_death + info.sum_cure);
        printf("计算得死亡率：\n");
        printf("%f", info.death_rate);

        info.cur_patient = info.sum_patient - info.sum_death - info.sum_cure;
        printf("计算得现存确诊人数：\n");
        printf("%f", info.cur_patient);

        printf("计算得现存确诊人数密度（人/平方公里）：\n");
        info.cur_patient_dest = info.cur_patient / info.estabilsh_area;
        printf("%f", info.cur_patient_dest);

        printf("计算得现存确诊人口占比：\n");
        info.cur_patient_rate = info.cur_patient / info.poeple;
        printf("%f", info.cur_patient_rate);

        printf("计算得%s的疫情严重程度为：\n", info.country);
        info.severe_rate = (info.cur_patient_dest * weight1 + weight2 * info.cur_patient_rate)
                           * (info.cur_patient * 1000000 / Goble_cur_patient) * 10000;
        printf("%f", info.severe_rate);

        if ((fp = fopen(file, "a")) == NULL) {
            printf("Error");
            exit(0);
        }


        printf("是否还需要输入数据？");
        scanf("%s", &c);
        if (c == 'n')
            break;
    }

}

void Show(Info info) {
    printf("Show");
    printf("\n+++++++++++++++++++学生信息++++++++++++++++++");
    printf("日期：%s\n", info.date);
    printf("国家：%s\n所属洲：%s\n人口总数：%d\n国土面积:\n建成区面积:\n人口密度:\n", info.country, info.continent, info.poeple, info.area,
           info.estabilsh_area, info.density);
    printf("新增确诊：%d\n累计确诊：%d\n累计死亡：%d\n累计治愈：%d", info.add_patient, info.sum_patient, info.sum_death, info.sum_cure);
    printf("当前死亡率：%d\n 当前治愈率：%d\n 严重指数：%d\n", info.death_rate, info.cure_rate, info.severe_rate);
}

void Serach() {
    printf("Serach");
}

void Print_sort() {
    printf("Print_sort");
}

void ReadInfo() {
    printf("ReadInfo");
}
