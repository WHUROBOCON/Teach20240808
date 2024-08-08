//to learn scanf and printf
#include<stdio.h>
int main(){
    int age;        //变量
    float assets;   //变量
    char pet[30];   //字符变量
    printf("enter your age ,assets, and favorite pet.\n");
    scanf("%d,%f",&age, &assets);   //使用数字变量时需要&
    scanf("%s", pet);              //使用字符变量时不用&
    printf("%d $ %f %s",age,assets,pet);
    return 0;

}