//用户输入pi的值，判断是否足够精确
#include<stdio.h>
#include<iso646.h>   //包含and替代&&，or替代||的头文件
void detect(double differntial)
{

        if (differntial>=0.00001)
            printf("too big try again\n");
        else if  (differntial<=-0.00001)          
            printf("too small try again\n");            
        else 
            printf(" the value is accurate enough");
}
int main(){
    const double  ANSWER = 3.14159;
    double value=0;
    double differntial;
    printf("please enter the value of pi you remember:\n");
    scanf("%lf",&value);
    differntial = value- ANSWER;

    while (1)
    {    
        fflush(stdin);
        detect(differntial);
        scanf("%lf",&value);
        differntial = value- ANSWER;
    }
    return 0;
}