//
// Created by chen on 2021/3/1 14:14.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double yuanzhu(double r, double h);
double l,s,bmj,qtj;


int main() {
    //double a,b,c,s,area;
   // scanf("%f,%f,%f",&a,&b,&c);
   // s = 1.0/2*(a+b+c);
    //area = sqrt(s*(s-a)*(s-b)*(s-c));
    //cout << s << " " << area << endl;
    double r,h,v;
    scanf("%lf%lf",&r,&h);
    v = yuanzhu(r,h);
    printf("%6.2f,%6.2f,%6.2f,%6.2f,%6.2f",l,s,bmj,v);

    return 0;
}

double yuanzhu(double r, double h){
    double v;
    l = 2*3.14*r;
    s = r*r*3.14;
    v = s*h;
    qtj = 3/4*3.14*(r*r*r);
    bmj = s*2+(l*h);
    return v;
}



