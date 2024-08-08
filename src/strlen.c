//测量字符串长度的函数
#include<stdio.h>
#include<string.h>
int main(){
    char name[40];
    printf ("please enter your name\n");
    scanf ("%s",name);
    printf("there are %d letters in your name\n",strlen(name));
    return 0;
}