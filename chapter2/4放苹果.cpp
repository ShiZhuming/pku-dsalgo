// 4:放苹果
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
// 输入
// 第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
// 输出
// 对输入的每组数据M和N，用一行输出相应的K。
// 样例输入
// 1
// 7 3
// 样例输出
// 8
// 来源
// lwx@POJ

#include <cstdio>
using namespace std;
int t, M, N;

int put(int p, int l, int m){
    if(p == 0 && l != 0) return 0;
    if(l == 0) return 1;
    if(p * m < l) return 0;
    // if(p * m == l) return 1;
    int temp = 0;
    for(int i = m; i > 0; --i){
        temp += put(p-1, l-i, i);
    }
    return temp;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&M,&N);
        printf("%d\n",put(N,M,M));
    }
    return 0;
}