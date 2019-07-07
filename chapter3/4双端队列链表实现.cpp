// 4:双端队列
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 65535kB
// 描述
// 定义一个双端队列，进队操作与普通队列一样，从队尾进入。出队操作既可以从队头，也可以从队尾。编程实现这个数据结构。

// 输入
// 第一行输入一个整数t，代表测试数据的组数。

// 每组数据的第一行输入一个整数n，表示操作的次数。

// 接着输入n行，每行对应一个操作，首先输入一个整数type。

// 当type=1，进队操作，接着输入一个整数x，表示进入队列的元素。

// 当type=2，出队操作，接着输入一个整数c，c=0代表从队头出队，c=1代表从队尾出队。

// n <= 1000
// 输出
// 对于每组测试数据，输出执行完所有的操作后队列中剩余的元素,元素之间用空格隔开，按队头到队尾的顺序输出，占一行。如果队列中已经没有任何的元素，输出NULL。
// 样例输入
// 2
// 5
// 1 2
// 1 3
// 1 4
// 2 0
// 2 1
// 6
// 1 1
// 1 2
// 1 3
// 2 0
// 2 1
// 2 0
// 样例输出
// 3
// NULL

#include <iostream>
#include <cstdio>
using namespace std;

template <class T>
struct node
{
    node<T> * next;
    node<T> * previous;
    T element;
};

template <class T>
class mydequeue
{
private:
    node<T> * front;
    node<T> * rear;
public:
    mydequeue(int size = 0){
        front = new node<T>;
        front -> previous = NULL;
        front -> next = NULL;
        rear = front;
    }
    ~mydequeue(){
        while(front -> next){
            front = front -> next;
            delete (front -> previous);
        }
        front -> previous = NULL;
    }
    void clear(){
        while(front -> next){
            front = front -> next;
            delete (front -> previous);
        }
        front -> previous = NULL;
    }
    bool push(T a){
        rear -> element = a;
        rear -> next = new node<T>;
        rear -> next -> previous = rear;
        rear = rear -> next;
        rear -> next = NULL;
        return true;
    }
    bool pop_front(T & a){
        if(!(front -> next)) return false;
        a = front -> element;
        front = front -> next;
        delete (front -> previous);
        front -> previous = NULL;
        return true;
    }
    bool pop_back(T & a){
        if(!(rear -> previous)) return false;
        rear = rear -> previous;
        a = rear -> element;
        delete (rear -> next);
        rear -> next = NULL;
        return true;
    }
    template<class T1>
    friend void print(mydequeue<T1> & a){
        node<T1> * temp = a.front;
        if(temp -> next == NULL){
            printf("NULL\n");
            return;
        }
        while(temp -> next){
            printf("%d",temp -> element);
            temp = temp -> next;
            if(temp -> next) printf(" ");
            else printf("\n");
        }
        return;
    }
};

int main(){
    int t, n, p, q;
    mydequeue<int> dequeue;
    scanf("%d",&t);
    while(t--){
        dequeue.clear();
        scanf("%d",&n);
        while(n--){
            scanf("%d %d",&p,&q);
            switch(p){
                case 1:
                dequeue.push(q);
                break;
                case 2:
                if(q) dequeue.pop_back(q);
                else dequeue.pop_front(q);
                break;
                default:
                ;
            }
        }
        print(dequeue);
    }
    return 0;
}


