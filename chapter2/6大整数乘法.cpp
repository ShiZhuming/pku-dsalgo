// 6:大整数乘法
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 求两个不超过200位的非负整数的积。

// 输入
// 有两行，每行是一个不超过200位的非负整数，没有多余的前导0。
// 输出
// 一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
// 样例输入
// 12345678900
// 98765432100
// 样例输出
// 1219326311126352690000
// 提示
// 30%的数据，输入的两个整数不超过8位。

#include <cstdio>
#include <cstring>
#include <iostream>
#include <memory.h>
#define MAXLEN 205
using namespace std;
class bigint
{
public:
    int len;
    int * num;
public:
    bigint(char * _bigint = NULL);
    bigint(const bigint & _bigint);
    ~bigint();
    bigint operator*(const bigint & a);
    friend istream & operator>>(istream & op, bigint & a){
        char temp[MAXLEN];
        op >> temp;
        a = bigint(temp);
        return op;
    }
    friend ostream & operator<<(ostream & op, bigint b){
        for(int i = b.len - 1; i >= 0; --i){
            op << b.num[i];
        }
        return op;
    }
};

bigint::bigint(char * _bigint)
{
    if(!_bigint){len = 0; num = NULL; return;}
    len = strlen(_bigint);
    num = new int [len];
    for(int i = 0; i < len; i++){
        num[i] = _bigint[len - i - 1] - '0';
    }
}

bigint::bigint(const bigint & _bigint){
    if(!_bigint.len){len = 0; num = NULL; return;}
    len = _bigint.len;
    num = new int [len];
    for(int i = 0; i < len; i++){
        num[i] = _bigint.num[i];
    }
}

bigint::~bigint()
{
    if(!len) delete [] num;
}

bigint bigint::operator*(const bigint & a)
{
    int templen = len + a.len + 3;
    int * temp = new int [templen];
    memset(temp,0,templen*sizeof(int));
    for(int i = 0; i < len; i++){
        for(int j = 0; j < a.len; j++){
            temp[i + j] += num[i] * a.num[j];
        }
    }
    for(int i = 0; i < templen; i++){
        temp[i + 1] += temp[i]/10;
        temp[i] %= 10;
    }
    for(int i = templen - 1; i >= 0; --i){
        if(!temp[i]) templen--;
        if(temp[i]) break;
    }
    char tempchar[MAXLEN*2];
    for(int i = 0; i < templen; i++) tempchar[templen - 1 - i] = '0' + temp[i];
    tempchar[templen] = '\0';
    delete [] temp;
    return bigint(tempchar);
}

int main(){
    bigint a,b;
    cin >> a >> b;
    // cout << a.len << b.len << endl;//ceshi
    cout << a*b << endl;
    return 0;
}
