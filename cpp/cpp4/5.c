#include <stdio.h>
int main() {
    float MB = 0, Mbs = 0;
    scanf("%f%f", &MB, &Mbs);
    float downlode = MB / Mbs * 1.0;
    printf("At %.2f megabits per second, a file of %.2f megabits\n", Mbs, MB);
    printf("downlodes in %.2f seconds.\n", downlode);
    return 0;
}