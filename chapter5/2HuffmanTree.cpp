// 2:Huffman编码树
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 65535kB
// 描述


// 构造一个具有n个外部节点的扩充二叉树，每个外部节点Ki有一个Wi对应，作为该外部节点的权。使得这个扩充二叉树的叶节点带权外部路径长度总和最小：

//                                      Min( W1 * L1 + W2 * L2 + W3 * L3 + … + Wn * Ln)

// Wi:每个节点的权值。

// Li:根节点到第i个外部叶子节点的距离。

// 编程计算最小外部路径长度总和。

// 输入
// 第一行输入一个整数t，代表测试数据的组数。
// 对于每组测试数据，第一行输入一个整数n，外部节点的个数。第二行输入n个整数，代表各个外部节点的权值。
// 2<=N<=100
// 输出
// 输出最小外部路径长度总和。
// 样例输入
// 2
// 3
// 1 2 3
// 4
// 1 1 3 5
// 样例输出
// 9
// 17
// 提示
// 仅考查huffman树的建立，数据范围小，可以不需要使用堆结构.
// 不过鼓励使用第一题实现的堆来寻找最小和次小元素。

#include<cstdio>
#include<queue>
int main(){
    int t, n, m, v;
    std::priority_queue<int,std::vector<int>,std::greater<int>> p;
    scanf("%d",&t);
    while (t--)
    {
        v = 0;
        while (!p.empty())
        {
            p.pop();
        }
        scanf("%d",&n);
        while (n--)
        {
            scanf("%d",&m);
            p.push(m);
        }
        while (true)
        {
            m = p.top();
            p.pop();
            if(p.empty()){
                printf("%d\n",v);
                break;
            }
            else{
                m += p.top();
                p.pop();
                v += m;
                p.push(m);
            } 
        }    
    }
    return 0;
}