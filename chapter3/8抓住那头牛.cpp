// 8:抓住那头牛
// 查看 提交 统计 提问
// 总时间限制: 2000ms 内存限制: 65536kB
// 描述
// 农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上，农夫起始位于点N(0<=N<=100000)，牛位于点K(0<=K<=100000)。农夫有两种移动方式：

// 1、从X移动到X-1或X+1，每次移动花费一分钟
// 2、从X移动到2*X，每次移动花费一分钟

// 假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多少时间才能抓住牛？


// 输入
// 两个整数，N和K
// 输出
// 一个整数，农夫抓到牛所要花费的最小分钟数
// 样例输入
// 5 17
// 样例输出
// 4

#include <cstdio>
#define MAX 100000
using namespace std;

struct step
{
    int minute;
    int position;
    step(int m = 0,int p = 0):minute(m),position(p){}
};

template <class T>
struct node
{
    node<T> * next;
    T element;
};

template <class T>
class myqueue
{
private:
    node<T> * front;
    node<T> * rear;
public:
    myqueue(int size = 0){
        front = new node<T>;
        front -> next = NULL;
        rear = front;
    }
    ~myqueue(){
        node<T> * previous;
        while(front -> next){
            previous = front;
            front = front -> next;
            delete previous;
        }
    }
    void clear(){
        node<T> * previous;
        while(front -> next){
            previous = front;
            front = front -> next;
            delete previous;
        }
    }
    bool push(T a){
        rear -> next = new node<T>;
        if(!(rear -> next)) return false;
        rear = rear -> next;
        rear -> element = a;
        rear -> next = NULL;
        return true;
    }
    bool pop(T & a){
        if(!(front -> next)) return false;
        node<T> * previous = front;
        front = front -> next;
        a = front -> element;
        delete previous;
        return true;
    }
    bool empty(){
        return front == rear;
    }
};

int main(){
    int N, K;
    bool visited[MAX + 1];
    for(int i = 0; i < MAX + 1; i ++) visited[i] = false;
    step temp;
    scanf("%d %d",&N, &K);
    myqueue<step> queue;
    queue.push(step(0,N));
    while(queue.pop(temp)&&temp.position != K){
        if(temp.position < MAX && !visited[temp.position + 1]) {
            temp.minute ++;
            temp.position ++;
            queue.push(temp);
            visited[temp.position] = true;
            temp.position --;
            temp.minute --;
        }
        if(temp.position > 0 && !visited[temp.position - 1]) {
            temp.minute ++;
            temp.position --;
            queue.push(temp);
            visited[temp.position] = true;
            temp.position ++;
            temp.minute --;
        }
        if(temp.position * 2 <= MAX && !visited[temp.position  * 2]) {
            temp.minute ++;
            temp.position *= 2;
            queue.push(temp);
            visited[temp.position] = true;
            temp.position /= 2;
            temp.minute --;
        }
    }
    printf("%d\n",temp.minute);
    return 0;
}