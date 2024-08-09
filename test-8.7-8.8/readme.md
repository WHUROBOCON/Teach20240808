# 程序说明
## list.c
void list_init(list *l); 功能：初始化链表
void list_insert(list *l, int i, list_node *node);功能：在第i个位置（从0开始）加入node
bool list_search(list *l, int val);
void list_remove(list *l, int i);
void list_delete(list *l);


# 学习报告


**问题一：** 弄不懂list和list_node两个结构体
答：list_node通常表示链表中的**一个节点**，至少包含每个节点的数据（数据可以是任何类型）和指向下一个节点的指针。list是**整个数据链表**，它通常包含指向链表第一个节点（即头节点）的指针，以及其他可能需要的信息，比如链表的长度、尾节点的指针（在双向链表中）等。
    
    typedef struct list_node {  
        int data;     // 节点存储的数据  
        struct list_node *next; // 指向下一个节点的指针  
    } list_node;

     typedef struct list{  
        list_node *head;    // 指向链表头节点的指针  
        list_node *tail;    // 指向链表尾节点的指针（可选）  
        int length;         // 链表的长度（可选）  
        // 其他信息...  
    } list;

**问题二：** 有点不理解链表初始化了，和清空有什么不同？

    void list_init(list *l) {  
        l->head = NULL;  
        l->tail = NULL; 
    }

  1. 程序说明：大致就是程序所实现的功能
   2. 学习报告：学习过程中遇到的问题和学习记录

