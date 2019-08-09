// 4:由中根序列和后根序列重建二叉树
// 查看 提交 统计 提问
// 总时间限制: 500ms 内存限制: 65535kB
// 描述
// 我们知道如何按照三种深度优先次序来周游一棵二叉树，来得到中根序列、前根序列和后根序列。反过来，如果给定二叉树的中根序列和后根序列，或者给定中根序列和前根序列，可以重建一二叉树。本题输入一棵二叉树的中根序列和后根序列，要求在内存中重建二叉树，最后输出这棵二叉树的前根序列。

// 用不同的整数来唯一标识二叉树的每一个结点，下面的二叉树



// 中根序列是9 5 32 67

// 后根序列9 32 67 5

// 前根序列5 9 67 32

// 输入
// 两行。第一行是二叉树的中根序列，第二行是后根序列。每个数字表示的结点之间用空格隔开。结点数字范围0～65535。暂不必考虑不合理的输入数据。
// 输出
// 一行。由输入中的中根序列和后根序列重建的二叉树的前根序列。每个数字表示的结点之间用空格隔开。
// 样例输入
// 9 5 32 67
// 9 32 67 5
// 样例输出
// 5 9 67 32
// 查看 提交 统计 提问
// 注意：这是练习题，不是作业题

// 全局题号
// 5414
// 添加于
// 2013-08-30
// 提交次数
// 801
// 尝试人数
// 367
// 通过人数
// 355
// Other language verions
// English
// 你尚未尝试此题

#include<cstdio>
#define MAX 10000
int tLR[MAX], LtR[MAX], LRt[MAX];
int length = 0, pos = 0;
void f(int begin, int end, int shift){//begin end 对应于LRt序列
    if(begin == end)
    {
        return;
    }
    tLR[pos++] = LRt[end - 1];
    int root = begin + shift;
    for ( ; root < end + shift; root++)
    {
        if(LtR[root] == LRt[end - 1])
        {
            break;
        }
    }
    root -= shift;
    f(begin, root, shift);
    f(root, end - 1, shift + 1);
}
int main(){
    for (int i = 0; ; i++)
    {
        scanf("%d",LtR + i);
        if(getchar()=='\n'){
            break;
        }
    }
    for (int i = 0; ; i++)
    {
        scanf("%d",LRt + i);
        // if(getchar()=='\n'){// or EOF;
        if(getchar()==EOF){// on openjudge!!!;
            length = ++i;
            break;
        }
    }
    f(0, length, 0);
    for(int i = 0; i < length; i++)
    {
        if(i)
        {
            printf(" ");
        }
        printf("%d",tLR[i]);
    }
    return 0;
}