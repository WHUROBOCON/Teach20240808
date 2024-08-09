#include<iostream>
#include<cstdio>
using namespace std;
//可以直接使用#include<queue>调用，然后使用队列的容器类
//但是如果要实现底层功能的调用，还是建议自己打板子，所以本次 以自己打板子为主
const int MaxSize=100;		//队列的容量
template <typename T>
class SqQueue				//非循环队队列类模板
{
public:
   T* data;  				//存放队中元素
   int front, rear;			//队头和队尾指针
   //队列的基本运算算法
   SqQueue()			//构造函数
   {  data=new T[MaxSize];	//为data分配容量为MaxSize的空间
      front=rear=-1;		//队头队尾指针置初值
   }
   
   ~SqQueue()			//析构函数
   {
      delete [] data;
   }
   bool empty()		//判队空运算 
   {
      return (front==rear); 
   }
   bool push(T e)				//进队列运算
   {  if (rear==MaxSize-1)		//队满上溢出
         return false;
      rear++;
      data[rear]=e;
      return true;
   }
   bool pop(T& e)			//出队列运算
   {  if (front==rear)		//队空下溢出
         return false;
      front++;
      e=data[front];
      return true;
   }
   bool gethead(T& e)		//取队头运算
   {  if (front==rear)		//队空下溢出
         return false;
      int head=front+1;
      e=data[head];
      return true;
   }
   
};

int main()
{

return 0;
}
//队列相较于栈，改编为先进先出原则，可以变为循环队列，优先队列等。