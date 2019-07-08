// 3:二叉搜索树
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 1024kB
// 描述
//    二叉搜索树在动态查表中有特别的用处，一个无序序列可以通过构造一棵二叉搜索树变成一个有序序列，构造树的过程即为对无序序列进行排序的过程。每次插入的新的结点都是二叉搜索树上新的叶子结点，在进行插入操作时，不必移动其它结点，只需改动某个结点的指针，由空变为非空即可。

//    这里，我们想探究二叉树的建立和序列输出。

// 输入
// 只有一行，包含若干个数字，中间用空格隔开。（数字可能会有重复）
// 输出
// 输出一行，对输入数字建立二叉搜索树后进行前序周游的结果。
// 样例输入
// 41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942 827 436 
// 样例输出
// 41 467 334 169 145 281 358 464 436 500 478 491 724 705 962 827 961 942 995

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

template <class T>
struct node
{
    T element;;
    node<T> * leftChild;
    node<T> * rightChild;
};

template <class T>
class binaryTree
{
private:
    node<T> * root;
public:
    binaryTree(){root = NULL;}
    binaryTree(const T & ele, node<T> * l = NULL, node<T> * r = NULL){
        root =  new node<T>;
        root->element = ele;
        root->leftChild = l;
        root->rightChild = r;
    }
    ~binaryTree(){
        node<T> * curr = root;
        stack<node<T> *> s;
        s.push(root);
        while(!s.empty()){
            curr = s.top();
            if(!curr->leftChild && !curr->rightChild){
                delete curr;
                s.pop();
                continue;
            }
            if(curr->leftChild){
                s.push(curr->leftChild);
                curr->leftChild = NULL;
            }
            if(curr->rightChild){
                s.push(curr->rightChild);
                curr->rightChild = NULL;
            }
        }
    }
    bool insert(const T & ele){
        node<T> * curr = root;
        if(!curr){
            root = new node<T>;
            root->element = ele;
            root->leftChild = NULL;
            root->rightChild = NULL;
            return true;
        }
        while(true){
            if(curr->element == ele)
                return false;
            else if(curr->element > ele){
                if(curr->leftChild){
                    curr = curr->leftChild;
                }
                else{
                    curr->leftChild = new node<T>;
                    curr = curr->leftChild;
                    curr->element = ele;
                    curr->leftChild = NULL;
                    curr->rightChild = NULL;
                    return true;
                }
            }
            else{
                if(curr->rightChild){
                    curr = curr->rightChild;
                }
                else{
                    curr->rightChild = new node<T>;
                    curr = curr->rightChild;
                    curr->element = ele;
                    curr->leftChild = NULL;
                    curr->rightChild = NULL;
                    return true;
                }
            }
        }
    }
    template <class T1>
    void inOrder(T1 op, node<T> * r = NULL){
        if(!r) r = root;
        if(!r->leftChild && !r->rightChild){
            op(r->element);
            return;
        }
        if(r->leftChild) inOrder(op, r->leftChild);
        op(r->element);
        if(r->rightChild) inOrder(op, r->rightChild);
        return;
    }
    template <class T1>
    void PreOrder(T1 op, node<T> * r = NULL){
        if(!r) r = root;
        // if(!r->leftChild && !r->rightChild){
        //     op(r->element);
        //     return;
        // }
        op(r->element);
        if(r->leftChild) PreOrder(op, r->leftChild);
        if(r->rightChild) PreOrder(op, r->rightChild);
        return;
    }
};
// template <class T>
// void Print(T a){
//     static bool flag = false;
//     if(flag) printf(" ");
//     else flag = true;
//     printf("%d",a);
// }

void Print(int a){
    static bool flag = false;
    if(flag) printf(" ");
    else flag = true;
    printf("%d",a);
}
int main(){
    int n;
    binaryTree<int> tree;
    // while(scanf("%d",&n)!=EOF){
    while(cin >> n){
        tree.insert(n);
    }
    tree.PreOrder(Print);
    printf("\n");
    return 0;
}