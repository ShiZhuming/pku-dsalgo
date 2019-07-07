// 3:stack or queue
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 65535kB
// 描述
// 栈和队列都是常用的线性结构，它们都提供两个操作：

// Push：加入一个元素。

// Pop：弹出一个元素。

// 不同的是，栈是”先进后出”，而队列则是”先进先出”。

// 给出一个线性结构的进出顺序，判定这个结构是栈还是队列。

// 输入
// 第一行输入一个整数t，代表有t组测试数据
// 对于每组测试数据，第一行输入一个整数n，代表操作的次数。
// 随后输入n行，每行包含两个整数 type val。
// 当type = 1时，表示该次操作为push操作，val表示进入的数字。当type=2时，表示该次操作为pop操作，val代表出来的数字。
// 3<=n<=2000
// 输出
// 每组测试数据输出一行。
// 输出改组数据对应的线性结构，”Stack” 或者 “Queue”。
// 题目保证是栈或者队列的一种。
// 样例输入
// 2
// 6
// 1 1
// 1 2
// 1 3
// 2 3
// 2 2
// 2 1
// 4
// 1 1
// 1 2
// 2 1
// 2 2
// 样例输出
// Stack
// Queue

#include <cstdio>
#include <iostream>
using namespace std;
#define MAXSZIE 2000
class mystack
{
private:
    int * s;
    int top;
    int maxsize;
public:
    mystack(int size = MAXSZIE):top(0),maxsize(size){
        if(size) s = new int [size];
        else s = NULL;
    }
    ~mystack(){
        if(s) delete [] s;
    }
    bool push(int a){
        if(top == maxsize) return false;
        s[top++] = a;
        return true;
    }
    bool pop(int & a){
        if(!top) return false;
        a = s[--top];
        return true;
    }
    void clear(){top = 0;}
    void show(){
        for(int i = 0; i < top; i++){
            if(i) printf(" ");
            printf("%d",s[i]);
        }
        printf("\n");
    }
};
int main(){
    int m, n, p, q;
    bool flag;
    mystack stack;
    scanf("%d",&m);
    while (m--)
    {
        scanf("%d",&n);
        stack.clear();
        flag = false;
        while (n--)
        {
            scanf("%d %d",&p,&q);
            // stack.show();//ceshi
            if(flag) continue;
            switch(p){
                case 1:stack.push(q);break;
                case 2:
                if(!stack.pop(p)||p != q){
                    // printf("p=%d;q=%d\n",p,q);//ceshi 
                    printf("Queue\n");
                    flag = true;
                }
                break;
                default:
                ;
            }
        }
        if(!flag) printf("Stack\n");
    }
    return 0;
}