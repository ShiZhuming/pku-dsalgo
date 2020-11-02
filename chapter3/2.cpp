// 22:15
// 22:59
#include<cstdio>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int factor();
int term();
int exp();

int exp() {
    int value = term();
    while (true)
    {
        switch (cin.peek())
        {
        case '+':
            getchar();
            value += term();
            break;
        case '-':
            getchar();
            value -= term();
            break;
        case '\n':
            getchar();
        default:
            return value;
            break;
        }
    }
}

int term() {
    int value = factor();
    while (true)
    {
        switch (cin.peek())
        {
        case '*':
            getchar();
            value *= factor();
            break;
        case '/':
            getchar();
            value /= factor();
            break;
        default:
            return value;
            break;
        }
    }
}

int factor() {
    int value = 0;
    if (cin.peek() == '(')
    {
        getchar();
        value = exp();
        getchar();
    }
    else
    {
        scanf("%d",&value);
    }
    return value;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    getchar();
    while (N--)
    {
        // while(!sign.empty()) sign.pop();
        // while(!number.empty()) number.pop();
        printf("%d\n",exp());
    }
    return 0;
}