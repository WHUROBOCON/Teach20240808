//continue的用法，跳过部分循环，直到循环结束
#include <stdio.h>
int main()
{
    const float MIN=0.0f;
    const float MAX=100.0f;

    float score;
    float total;
    int n=0;
    float min=MAX;
    float max=MIN;

    printf("Enter the first score (q to quit):");

    while(scanf("%f",&score) ==1) 
        {
        if(score <MIN||score >MAX)  //检查数据的合理性
            {
            printf("%0.1f is an invalid value.Try again:",score);
            continue ;                  //跳转至while 检查条件
            }
        printf("accepting %0.1f:\n",score);
        min= (score<min) ?score :min;              //大小比较函数
        max=(score>max)? score :max;
        total+=score;
        n++;
        printf("please enter next score of enter q to quit:");
        }
    if (n>0)
    {
        printf("Average of %d scorce is %0.1f.\n", n, total/n);
        printf("Low=%0.1f,High=%0.1f\n",MIN,MAX);
    }
    else printf ("no valid scores were entered.");
    return 0;
}