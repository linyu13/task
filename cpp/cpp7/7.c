#include <stdio.h>
int main(void) {
    double h = 0;
    double all_pay = 0;
    double over_pay = 0;
    double rate = 0;
    double net_in = 0;
    printf("请输入一周工作的小时数：");
    scanf("%lf", &h);
    while (h < 0) {
        scanf("%lf", &h);
    }
    if (h > 40) {
        over_pay = ((h - 40) * 1.5) * 10;
        all_pay = over_pay + 40 * 10;
    } else
        all_pay = h * 10;
    if (all_pay <= 300)
        rate = all_pay * 0.15;
    else if ((all_pay > 300) && (all_pay <= 450))
        rate = (300 * 0.15) + ((all_pay - 300) * 0.2);
    else
        rate = (300 * 0.15) + ((450 - 300) * 0.2) + ((all_pay - 450) * 0.25);
    net_in = all_pay - rate;
    printf("一周工作%.1lf小时,工资总额=%.1lf美元,税金=%.1lf美元,净收入=%.1lf美元\n",h, all_pay, rate, net_in);
    return 0;
}