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
    float cur_patient;  //�ִ�ȷ������
    float cur_patient_dest;  //�ִ�ȷ�������ܶ�
    float cur_patient_rate;  //�ִ�ȷ���˿ڱ���
    float sum_death;
    float sum_cure;
    float death_rate;
    float cure_rate;
    float severe_rate;
} Info;

void Introducation() {
    printf("====================ȫ���������ϵͳ=============================\n");
    printf("                      ����ѡ��˵�\n                                 ");
    printf("\n");
    printf("1.¼����Ϣ\n\n");
    printf("==============================================================\n");
}

void Show(Info info);   //���������Ϣ
void Insert();         //¼����Ϣ
void Serach();          //����
void Print_sort();      //�����ӡ
void ReadInfo();        //��ȡ�ļ�����
void Login();              //��¼
void function(int flag);    //  ���ܲ˵�


int main() {
    char c;
    int flag;
    Info info = {0};
    Login();
    cout << "ѡ����,�������" << endl;
    cin >> flag;
    function(flag);
    return 0;
}

void Login() {
    char paswd[20];
    int count = 5;
    char c = 'y';
    while (count > 0) {
        printf("���¼����������\n");
        scanf("%s", paswd);
        if (strcmp(paswd, "123456") == 0) {
            Introducation();
            break;
        } else {
            count--;
            printf("����������������룬����%d�λ���\n", count);
        }
        if (count == 0) {
            cout << "���������˳�\n";
            exit(0);
        }
    }
}

void function(int flag) {    //���ܲ˵�
    char c = 'y';

    while (c == 'y') {
        if (flag == 1) {            //¼��������Ϣ
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
            printf("�����������������룡\n ");
            continue;
        }
        printf("�Ƿ����ʹ�ø�ϵͳ��y/n����");
        scanf("%c", &c);
    }
}


void Insert() {
//       printf("insert");
    FILE *fp;
    char c = 'y';
    Info info = {0};    //�Խṹ����г�ʼ��

    // Show(info);
    while (c == 'y') {
        printf("������������Ϣ\n");
        printf("����������(��2021-03-19)\n");
        getchar();
        gets(info.date);

        printf("�����������\n");
        getchar();
        gets(info.country);
        //           puts(info.country);
        getchar();

        printf("������������\n");
        getchar();
        gets(info.continent);

        printf("���������������\n");
        //getchar();
        scanf("%f", info.poeple);

        printf("������������(ƽ������)\n");
        //getchar();
        scanf("%f", info.area);

        printf("�����뽨�������(ƽ������)\n");
        //getchar();
        scanf("%f", info.estabilsh_area);

        printf("�˿��ܶ�\n");
        //getchar();
        float density;
        density = info.poeple / info.estabilsh_area;
        printf("%5.3f", density);
        info.density = density;
        printf("==========================================");
        printf("������ÿ������¼������");

        printf("�������ۼ�ȷ������\n");
        scanf("%f", info.sum_patient);

        printf("�������ۼ�ȷ������\n");
        scanf("%f", info.add_patient);

        printf("�������ۼ���������\n");
        scanf("%f", info.sum_death);

        printf("�������ۼ�ȷ����������\n");
        scanf("%f", info.sum_cure);

        printf("�������ۼ�ȷ������\n");
        scanf("%f", info.sum_patient);

        info.cure_rate = info.cur_patient / info.sum_patient;
        printf("����������ʣ�\n");
        printf("%f", info.cure_rate);

        info.death_rate = info.sum_death / (info.sum_death + info.sum_cure);
        printf("����������ʣ�\n");
        printf("%f", info.death_rate);

        info.cur_patient = info.sum_patient - info.sum_death - info.sum_cure;
        printf("������ִ�ȷ��������\n");
        printf("%f", info.cur_patient);

        printf("������ִ�ȷ�������ܶȣ���/ƽ�������\n");
        info.cur_patient_dest = info.cur_patient / info.estabilsh_area;
        printf("%f", info.cur_patient_dest);

        printf("������ִ�ȷ���˿�ռ�ȣ�\n");
        info.cur_patient_rate = info.cur_patient / info.poeple;
        printf("%f", info.cur_patient_rate);

        printf("�����%s���������س̶�Ϊ��\n", info.country);
        info.severe_rate = (info.cur_patient_dest * weight1 + weight2 * info.cur_patient_rate)
                           * (info.cur_patient * 1000000 / Goble_cur_patient) * 10000;
        printf("%f", info.severe_rate);

        if ((fp = fopen(file, "a")) == NULL) {
            printf("Error");
            exit(0);
        }


        printf("�Ƿ���Ҫ�������ݣ�");
        scanf("%s", &c);
        if (c == 'n')
            break;
    }

}

void Show(Info info) {
    printf("Show");
    printf("\n+++++++++++++++++++ѧ����Ϣ++++++++++++++++++");
    printf("���ڣ�%s\n", info.date);
    printf("���ң�%s\n�����ޣ�%s\n�˿�������%d\n�������:\n���������:\n�˿��ܶ�:\n", info.country, info.continent, info.poeple, info.area,
           info.estabilsh_area, info.density);
    printf("����ȷ�%d\n�ۼ�ȷ�%d\n�ۼ�������%d\n�ۼ�������%d", info.add_patient, info.sum_patient, info.sum_death, info.sum_cure);
    printf("��ǰ�����ʣ�%d\n ��ǰ�����ʣ�%d\n ����ָ����%d\n", info.death_rate, info.cure_rate, info.severe_rate);
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
