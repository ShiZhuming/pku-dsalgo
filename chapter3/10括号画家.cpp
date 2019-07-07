// 10:括号画家
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 262144kB
// 描述
// Candela是一名漫画家，她有一个奇特的爱好，就是在纸上画括号。这一天，刚刚起床的Candela画了一排括号序列，其中包含小括号()、中括号[]和大括号{}，总长度为N。这排随意绘制的括号序列显得杂乱无章，于是Candela定义了什么样的括号序列是美观的：
// (1) 空的括号序列是美观的；
// (2) 若括号序列A是美观的，则括号序列(A)、[A]、{A}也是美观的；
// (3) 若括号序列A、B都是美观的，则括号序列AB也是美观的；
// 例如 [(){}]() 是美观的括号序列，而 )({)[}]( 则不是。
// 现在Candela想知道她画出的括号序列是不是美观的。你能帮帮她吗？

// 输入
// 一个括号序列，长度不超过10000。
// 输出
// 如果它是美观的，输出Yes，否则输出No。
// 样例输入
// {}[(){}]()
// 样例输出
// Yes

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXSIZE 10000
#define RETURN {printf("No\n");return 0;}

template<class T>
class mystack
{
private:
    T * s;
    int maxsize;
    int Top;
public:
    mystack(int _maxsize = 0):maxsize(_maxsize),Top(0){
        if(maxsize) s = new T [maxsize];
        else s = NULL;
    }
    ~mystack(){
        if(s) delete [] s;
    }
    bool push(T a){
        if(Top == maxsize) return false;
        s[Top++] = a;
        return true;
    }
    bool pop(T & a){
        if(!Top) return false;
        a = s[--Top];
        return true;
    }
    bool top(T & a){
        if(!Top) return false;
        a = s[Top-1];
        return true;
    }
    bool empty(){
        return !Top;
    }
};

int main(){
    char c, d;
    mystack<char> stack(MAXSIZE);
    while((c = getchar()) != '\n' && c != EOF){
        // cout << "\'" << (int)c << "\"" << endl;// ceshi
        switch(c){
            case '{':
            case '[':
            case '(':
            stack.push(c);
            break;
            case '}':
            // cout << stack.top(d) << d << endl;// ceshi
            if(!stack.top(d)||d != '{') RETURN
            else stack.pop(d);
            break;
            case ']':
            if(!stack.top(d)||d != '[') RETURN
            else stack.pop(d);
            break;
            case ')':
            if(!stack.top(d)||d != '(') RETURN
            else stack.pop(d);
            break;
            default:
            ;            
        }
    }
    // cout << stack.empty() << endl;// ceshi
    if(stack.empty()) printf("Yes\n");
    else printf("No\n");
    return 0;
}