//结构体的定义和使用
#include<stdio.h>
struct A
    {
        char data[10];
        int number1;
        float f1;
    }a;
int main()
{
    struct A a1=
    {
        "cbd",
        1,
        0.05
    };//这里对a1 进行初始化
    struct A a2=
    {
        "abd",
        2,
        9.09
    };//这里对a2 进行初始化
    
    printf("%s",a2.data);//使用“.”进行访问操作
    printf("%f",a1.f1);
    return 0;
}