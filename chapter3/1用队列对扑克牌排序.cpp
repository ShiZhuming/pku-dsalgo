// 1:用队列对扑克牌排序
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 假设这里有36张扑克牌，分别为A1~A9,B1~B9,C1~C9,D1~D9，其中A代表方片，B代表草花，C代表红桃，D代表黑桃，那么，设定如下的排序规则：

// 1.对于两张卡牌，X1Y1与X2Y2，X1与X2表示A～D，Y1与Y2表示1～9，如果X1与X2不同，那么依照D>C>B>A的方式进行排序

// 2.假如有X1与X2相同时，那么就比较Y1与Y2的大小。

// 例如，对于如下的四张牌，有如下的升序排序结果：

// D3，C4，A4，C1

// 升序排序的结果为A4，C1，C4，D3

// 有人提出了如下的排序策略：

// 先建立9个队列，用于存放点数的大小，将卡牌依点数存放入各自的队列之中，然后再按队列1到队列9依次出队。

// 例如，对于上面的结果，依次进队后，结果如下：

// 队列1：C1；队列3：D3，队列4：C4，A4

// 将其依次出队后，结果为C1，D3，C4，A4

// 然后，再建立4个队列，用于存放花色。将卡牌依花色A～D存放入队列1～4中，然后再按队列1到队列4依次出队。

// 例如，对于上面刚刚出队的序列C1，D3，C4，A4，将其依次进队，结果如下：

// 队列1：A4；队列3：C1，C4；队列4：D3

// 将其依次出队后，结果为A4，C1，C4，D3，排序结束。


// 请根据上面的算法，编写一个用队列对扑克牌排序的程序，要求依照上面的排序规则，根据先花色后点数的方法进行排序。

// 输入
// 输入分为两行，第一行为一个整数n，表示一共有n张牌（1<=n<=100）
// 第二行用XY的形式表示每一张牌，其中X为A～D，Y为1～9
// 输出
// 输出三个部分
// 第一个部分为第一次进队出队的结果，用Queue1:...表示，共9行，结果用空格分隔，下同
// 第二部分为第二次进队出队的结果，用QueueA:...表示，共4行
// 第三部分为一行，即将卡牌排序后的结果（升序排序）
// 样例输入
// 8
// D8 A6 C3 B8 C5 A1 B5 D3
// 样例输出
// Queue1:A1
// Queue2:
// Queue3:C3 D3
// Queue4:
// Queue5:C5 B5
// Queue6:A6
// Queue7:
// Queue8:D8 B8
// Queue9:
// QueueA:A1 A6
// QueueB:B5 B8
// QueueC:C3 C5
// QueueD:D3 D8
// A1 A6 B5 B8 C3 C5 D3 D8
// 提示
// 第二次入队出队时，可以复用第一次时9个队列中的4个。所以其实只需要开辟9个队列即可。

#include <cstdio>
#include <iostream>
using namespace std;
#define MAXSIZE 36

struct card
{
    char side;
    int id;
    friend istream & operator>>(istream & op, card & a){return op >> a.side >> a.id;}
    friend ostream & operator<<(ostream & op, card a){return op << a.side << a.id;}
};


class myqueue
{
private:
    card * q;
    int front;
    int rear;
public:
    myqueue(){
        q = new card [MAXSIZE];
        front = 0;
        rear = 0;
    }
    ~myqueue(){
        if(q) delete [] q;
    }
    bool push(card a){
        if(rear == MAXSIZE) return false;
        q[rear++] = a;
        return true;
    }
    bool pop(card & a){
        if(front == rear) return false;
        a = q[front++];
        return true;
    }
    void show(){
        for(int i = front; i < rear; ++i){
            cout << q[i];
            if(i != rear - 1) cout << " ";
        }
    }
};

int main(){
    int n;
    card temp;
    myqueue queue[9 + 4];
    scanf("%d",&n);
    while(n--){
        cin >> temp;
        queue[temp.id - 1].push(temp);
    }
    for(int i = 0; i < 9; ++i){
        printf("Queue%d:",i+1);
        queue[i].show();
        printf("\n");
    }
    for(int i = 0; i < 9; ++i){
        while(queue[i].pop(temp)) queue[temp.side - 'A' + 9].push(temp);
    }
    for(int i = 9; i < 9 + 4; ++i){
        printf("Queue%c:",'A' + i - 9);
        queue[i].show();
        printf("\n");
    }
    for(int i = 9; i < 9 + 4; i++){
        if(i != 9) printf(" ");
        queue[i].show();
    }
    printf("\n");
    return 0;
}