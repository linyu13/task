#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// char *convertAndMerge(char strs[2][20]) {
//     int len1 = strlen(strs[0]), len2 = strlen(strs[1]); //
//     分别计算二维数组的大小 char *str = (char *)malloc(sizeof(char) * (len1 +
//     len2)); // 为str分配内存 strcpy(str, strs[0]); // 将strs[0]复制到str
//     strcat(str, strs[1]); // 将str[1]拼接到str后面
//     int len = len1 + len2;
//     for (int i = 0; i < len; i++) {
//         if (str[i] >= 'A' && str[i] <= 'Z') // 大写变小写
//             str[i] += 32;
//         else if (str[i] >= 'a' && str[i] <= 'z') // 小写变大写
//             str[i] -= 32;
//     }
//     return str;
// }
// int main(void) {
//     char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
//     printf("%s\n", words[0]);
//     printf("%s\n", words[1]);
//     char *str = convertAndMerge(words);
//     printf("str = %s\n", str);
//     free(str);
// }
// int main()
// {
//     int n=pow(2,2);
//     printf("%d\n",n);
//     return 0;
// }
// char *convert(const char *s) {
//     int n = strlen(s); // 读取字符串s的长度
//     char *a = (char *)malloc(n); // 为新字符串a分配一块大小为n个char*的空间
//     strcpy(a, s); // 将字符串"粘贴"到字符串a(s为不可改变的常量)
//     char *q = a;  // 定义一个char类型指针q指向字符串a的地址
//     while (*a != '\0') {//当a指向的不是'\0'时进入循环
//         if (*a >= 'a' && *a <= 'z') {
//             *a -= 32;//小写变为大写
//         } else if (*a >= 'A' && *a <= 'Z') {
//             *a += 32;//大写变为小写
//         }
//         a++;//指向下一个
//     }
//     return q; // 返回字符串a的地址
// }
// int main() {
//     char *str = "XiyouLinux Group 2022";
//     char *temp = convert(str);
//     puts(temp);
//     return 0;
// }
#include <stdio.h>

struct Example {
    char a;
    double c;    // 1字节
    int b;     // 4字节
    // double c;  // 8字节
}t1;

int main() {
    struct Example example;
    size_t max_alignment = 0;

    if (sizeof(char) > max_alignment) {
        max_alignment = sizeof(char);
    }
    if (sizeof(int) > max_alignment) {
        max_alignment = sizeof(int);
    }
    if (sizeof(double) > max_alignment) {
        max_alignment = sizeof(double);
    }

    printf("最大对齐数为: %zu\n", max_alignment);
    printf("%zu\n",sizeof(t1));
    return 0;
}
