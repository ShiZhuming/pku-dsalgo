// 1:实现堆结构
// 查看 提交 统计 提问
// 总时间限制: 3000ms 内存限制: 65535kB
// 描述
// 定义一个数组，初始化为空。在数组上执行两种操作：

// 1、增添1个元素，把1个新的元素放入数组。
 
// 2、输出并删除数组中最小的数。

// 使用堆结构实现上述功能的高效算法。

// 输入
// 第一行输入一个整数t，代表测试数据的组数。
// 对于每组测试数据，第一行输入一个整数n，代表操作的次数。
// 每次操作首先输入一个整数type。
// 当type=1，增添操作，接着输入一个整数u，代表要插入的元素。
// 当type=2，输出删除操作，输出并删除数组中最小的元素。
// 1<=n<=100000。
// 输出
// 每次删除操作输出被删除的数字。
// 样例输入
// 2
// 5
// 1 1
// 1 2
// 1 3
// 2
// 2
// 4
// 1 5
// 1 1
// 1 7
// 2
// 样例输出
// 1
// 2
// 1
// 提示
// 每组测试数据的复杂度为O(nlgn)的算法才能通过本次，否则会返回TLE(超时)
// 需要使用最小堆结构来实现本题的算法

#include <cstdio>
using namespace std;

#define MAXSIZE 100000 + 10

#define leftchild(x) (2*x+1)
#define rightchild(x) (2*x+2)
#define parent(x) (x%2?(x-1)/2:(x-2)/2)
#define sibling(x) (x%2?(x+1):(x-1))

template <class T>
class minHeap
{
private:
    T * root;
    int size;
    int maxsize;
public:
    minHeap(int maxs = 0):size(0),maxsize(maxs){
        if(maxs) root = new T [maxsize];
        else root = NULL;
    }
    ~minHeap(){
        if(root) delete [] root;
    }
    void clear(){
        if(!root) return;
        // delete [] root;
        // if(maxsize) root = new T [maxsize];
        // else root = NULL;
        size = 0;
    }
    void siftUp(int pos){
        T temp = root[pos];
        if(pos && root[pos] < root[parent(pos)]){
            temp = root[pos];
            root[pos] = root[parent(pos)];
            root[parent(pos)] = temp;
        }
        if(sibling(pos) < size && root[sibling(pos)] < root[parent(pos)]){
            temp = root[sibling(pos)];
            root[sibling(pos)] = root[parent(pos)];
            root[parent(pos)] = temp;
        }
        if(pos) siftUp(parent(pos));
    }
    void siftDown(int pos){
        T temp = root[pos];
        if(rightchild(pos) < size){//有右子树
            if(root[leftchild(pos)] < root[rightchild(pos)] && root[pos] > root[leftchild(pos)]){
                temp = root[pos];
                root[pos] = root[leftchild(pos)];
                root[leftchild(pos)] = temp;
                siftDown(leftchild(pos));
            }
            else if(root[leftchild(pos)] >= root[rightchild(pos)] && root[pos] > root[rightchild(pos)]){
                temp = root[pos];
                root[pos] = root[rightchild(pos)];
                root[rightchild(pos)] = temp;
                siftDown(rightchild(pos));
            }
            else return;
        }
        else if(leftchild(pos) < size && root[pos] > root[leftchild(pos)]){
            temp = root[pos];
            root[pos] = root[leftchild(pos)];
            root[leftchild(pos)] = temp;
            siftDown(leftchild(pos));
        }
        else return;
        
    }
    bool push(const T & ele){
        if(!root || size == maxsize) return false;
        root[size++] = ele;
        siftUp(size - 1);
        return true;
    }
    bool pop(T & ele){
        if(!size) return false;
        ele = root[0];
        root[0] = root[--size];
        siftDown(0);
        return true;
    }
    void printer(){
        printf("tree structure : \n");
        for(int i = 0; i < size; i++) printf("%d ",root[i]);
        printf("tree end\n");
    }
};

int main(){

    freopen("_make.out","r",stdin);
    freopen("_mine.out","w",stdout);

    int t, n, p, q;
    minHeap<int> heap(MAXSIZE);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        heap.clear();
        while(n--){
            scanf("%d",&p);
            switch(p){
                case 1:
                scanf("%d",&q);
                heap.push(q);
                break;
                case 2:
                if(heap.pop(q))
                    printf("%d\n",q);
                break;
                default:
                ;
            }
        }
        // heap.printer();//ceshi
    }
    return 0;
}