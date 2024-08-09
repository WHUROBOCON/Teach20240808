#include <iostream>

using namespace std;

// 双链表结点类型
template <typename T>
struct DLinkNode {
    T data;                    // 存放数据元素
    DLinkNode<T>* next;        // 指向后继结点的指针
    DLinkNode<T>* prior;       // 指向前驱结点的指针
    DLinkNode() : next(NULL), prior(NULL) {}  // 默认构造函数
    DLinkNode(T d) : data(d), next(NULL), prior(NULL) {}  // 带参构造函数
};

// 双链表类模板
template <typename T>
class DLinkList {
public:
    DLinkNode<T>* dhead;  // 双链表头结点

    // 默认构造函数
    DLinkList() {
        dhead = new DLinkNode<T>(); // 创建头结点
    }

    // 析构函数
    ~DLinkList() {
        DLinkNode<T>* p = dhead;
        while (p != NULL) {
            DLinkNode<T>* temp = p;
            p = p->next;
            delete temp; // 释放每个节点的内存
        }
    }

    // 尾插法建立双链表
    void CreateListR(T a[], int n) {
        DLinkNode<T>* s, * r;
        r = dhead;  // r 始终指向尾结点, 开始时指向头结点
        for (int i = 0; i < n; i++) {  // 循环建立数据结点
            s = new DLinkNode<T>(a[i]);  // 创建数据结点 s
            r->next = s;  // 将 s 结点插入 r 结点之后
            s->prior = r;
            r = s;
        }
        r->next = NULL;  // 将尾结点的 next 域置为 NULL
    }

    // 在双链表中序号 i 位置插入值为 e 的结点
    bool Insert(int i, T e) {
        if (i < 0) return false;  // 参数 i 错误返回 false
        DLinkNode<T>* s = new DLinkNode<T>(e); // 建立新结点 s
        DLinkNode<T>* p = geti(i - 1);  // 查找序号 i-1 的结点 p
        if (p != NULL) {  // 找到了序号 i-1 的结点
            s->next = p->next;  // 修改 s 结点的 next 域
            if (p->next != NULL)  // 修改 p 结点的非空后继结点的 prior
                p->next->prior = s;
            p->next = s;  // 修改 p 结点的 next 域
            s->prior = p;  // 修改 s 结点的 prior 域
            return true;  // 插入成功返回 true
        }
        else return false;  // 没有找到序号 i-1 的结点返回 false
    }

    // 在双链表中删除序号 i 位置的结点
    bool Delete(int i) {
        if (i < 0) return false;  // 参数 i 错误返回 false
        DLinkNode<T>* p = geti(i);  // 查找序号 i 的结点
        if (p != NULL) {  // 找到了序号 i 的结点 p
            p->prior->next = p->next;  // 修改 p 结点的前驱结点的 next
            if (p->next != NULL)  // 修改 p 结点非空后继结点的 prior
                p->next->prior = p->prior;
            delete p;  // 释放空间
            return true;  // 删除成功返回 true
        }
        else return false;  // 没有找到序号 i 的结点返回 false
    }

    // 求解算法：删除链表中第一个值为 x 的结点
    void Delx(DLinkList<T>& L, T x) {
        DLinkNode<T>* p = L.dhead->next;  // p 指向首结点
        while (p != NULL && p->data != x)  // 查找第一个值为 x 的结点
            p = p->next;
        if (p != NULL) {  // 找到值为 x 的结点 p
            p->prior->next = p->next;  // 删除 p 结点
            if (p->next != NULL)
                p->next->prior = p->prior;
            delete p;  // 释放空间
        }
    }

    // 打印链表的内容
    void PrintList() {
        DLinkNode<T>* p = dhead->next; // 跳过头结点
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

private:
    // 获取指定位置 i 的结点
    DLinkNode<T>* geti(int i) {
        if (i < 0) return NULL;
        DLinkNode<T>* p = dhead;
        int j = 0;
        while (p != NULL && j < i) {
            p = p->next;
            j++;
        }
        return p;
    }
};

// 主函数进行测试
int main() {
    int a[] = {1, 2, 3, 4, 5};
    DLinkList<int> list;
    list.CreateListR(a, 5);
    list.PrintList(); // 输出链表：1 2 3 4 5

    list.Insert(2, 10);
    list.PrintList(); // 输出链表：1 2 10 3 4 5

    list.Delete(3);
    list.PrintList(); // 输出链表：1 2 10 4 5

    list.Delx(list, 4);
    list.PrintList(); // 输出链表：1 2 10 5

    return 0;
}
