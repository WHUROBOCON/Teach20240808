//使用变宽的输出手段
#include <stdio.h>
int main(){
    unsigned width, precision;
    int number = 256;
    double weight = 242.5;

    printf("enter a field width:\n");
    scanf("%d",& width);
    printf ("the number is : %*d", width,number);     //此处%*d 表示一个规定长度的数字，需要长度和数字两个量定义
    printf ("now enter a width and a precision\n");
    scanf ("%d,%d",&width,&precision);
    printf("the  weight = %*.*f\n",width,precision,weight);   //此处%*.*f 表示规定总长度和小数部分有效位数的float型数字，需3量定义
    return 0;
}