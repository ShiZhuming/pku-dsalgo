// 7:滑动窗口
// 查看 提交 统计 提问
// 总时间限制: 12000ms 内存限制: 65536kB
// 描述
// 给定一个长度为n（n<=10^6）的数组。有一个大小为k的滑动窗口从数组的最左端移动到最右端。你可以看到窗口中的k个数字。窗口每次向右滑动一个数字的距离。
// 下面是一个例子：
// 数组是 [1 3 -1 -3 5 3 6 7]， k = 3。

// 窗口位置	最小值	最大值
// [1  3  -1] -3  5  3  6  7 	-1	3
//  1 [3  -1  -3] 5  3  6  7 	-3	3
//  1  3 [-1  -3  5] 3  6  7 	-3	5
//  1  3  -1 [-3  5  3] 6  7 	-3	5
//  1  3  -1  -3 [5  3  6] 7 	3	6
//  1  3  -1  -3  5 [3  6  7]	3	7


// 你的任务是得到滑动窗口在每个位置时的最大值和最小值。


// 输入
// 输入包括两行。
// 第一行包括n和k，分别表示数组的长度和窗口的大小。
// 第二行包括n个数字。
// 输出
// 输出包括两行。
// 第一行包括窗口从左至右移动的每个位置的最小值。
// 第二行包括窗口从左至右移动的每个位置的最大值。
// 样例输入
// 8 3
// 1 3 -1 -3 5 3 6 7
// 样例输出
// -1 -3 -3 -3 3 3
// 3 3 5 5 6 7

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
class mydqueue
{
private:
    node<T> * front;
    node<T> * rear;
public:
    mydqueue(int size = 0){
        front = new node<T>;
        front -> previous = NULL;
        front -> next = NULL;
        rear = front;
    }
    ~mydqueue(){
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
    bool top_front(T & a){
        if(!(front -> next)) return false;
        a = front -> element;
        return true;
    }
    bool top_back(T & a){
        if(!(rear -> previous)) return false;
        a = rear -> previous -> element;
        return true;
    }
    bool empty(){
        return front == rear;
    }
};

int main(){
    int n, k, q = 0;
    mydqueue<int> maxq, minq;
    scanf("%d %d",&n,&k);
    // int p[10];//ceshi
    int * p = new int [n];
    for(int i = 0; i < n; i++) scanf("%d",p + i);
    // printf("test\n");//ceshi
    // printf("test%d",n);//ceshi
    // for(int i = 0; i < n; i++) printf("%d",p[i]);//ceshi
    // cout << n << k << endl;//ceshi  
    // printf("%d %d",n,k);//ceshi
    // /*
    for(int i = 0; i < n; i++){
        // cout << maxq.top_back(q) <<  endl;//ceshi
        // /*
        if(minq.top_back(q)){
            // cout << "q = " << q << endl;//ceshi
            // /*
            while(p[q] > p[i]){
                minq.pop_back(q);
                if(!minq.top_back(q)) break;
            }
            minq.top_front(q);
            while(i - q >= k){
                minq.pop_front(q);
                if(!minq.top_front(q)) break;
            }
            // */
        }
        // else maxq.push(i);
        minq.push(i);
        minq.top_front(q);
        // */
        // /*
        if(i > k - 1) printf(" ");
        if(i >= k - 1) printf("%d",p[q]);
        // */
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        // cout << maxq.top_back(q) <<  endl;//ceshi
        // /*
        if(maxq.top_back(q)){
            // cout << "q = " << q << endl;//ceshi
            // /*
            while(p[q] < p[i]){
                maxq.pop_back(q);
                if(!maxq.top_back(q)) break;
            }
            maxq.top_front(q);
            while(i - q >= k){
                maxq.pop_front(q);
                if(!maxq.top_front(q)) break;
            }
            // */
        }
        // else maxq.push(i);
        maxq.push(i);
        maxq.top_front(q);
        // */
        // /*
        if(i > k - 1) printf(" ");
        if(i >= k - 1) printf("%d",p[q]);
        // */
    }
    printf("\n");
    // */
    delete [] p;
    // printf("ttest\n");//ceshi
    
    return 0;
}