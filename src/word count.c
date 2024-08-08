//统计一段话中的字符数，单词数，行数
#include<stdio.h>
// void charater_count(charater,c)
// {

// }

// void word_count(word,c,prev)
// {

// }

// void line_count(line)
// {

// }

// int main()
// {
//     printf ("please enter the text you want to analyzed('|' to terminate):\n");
    
// }

#include<ctype.h>
#include<stdbool.h>
#define STOP '|'
int main()
{
    char c;           //读入字符 
    char prev;        //读入的前一个字符
    long n_chars =0L; //字符数
    int n_lines =0;   //行数
    int n_words=0;  //单词数
    int p_lines=0;    //不完整的行数
    bool inword = false;
    printf ("please enter the text you want to analyzed ('|' to terminate) :\n");
    prev ='\n';       //用于识别完整的行
    while ((c = getchar ()!=STOP))
    {
        n_chars++;    //统计字符
        if ((c=='\n'))
        {
            n_lines++;
        }
        if ((!isspace(c)&&!inword))
        {
            inword=true;      //开始一个新的单词
            n_words++;        //统计单词
        }
        if (isspace(c)&&inword)
        {
            inword=false;     //到达单词末尾
            
        }
        prev=c;           //保存字符
    }
    if (prev!='\n')
    {
        printf("characters=%ld,words=%d,lines=%d",
        n_chars,n_words,n_lines);
        return 0;
    }
    

}