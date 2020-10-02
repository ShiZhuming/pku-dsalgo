#include<cstdio>
// 计算n是几位数
int count(int n)
{
    int k = 0;
    while (n!=0)
    {
        k++;
        n/=10;
    }
    return k;
}
// 提供11...10（n-1个1）这个数
// int number(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     int m = 10;
//     n-=2;
//     while (n--)
//     {
//         m = m*10+m;
//     }
//     return m;
// }
int maxNumber[10] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
int number[11] = {0, 0, 10, 110, 1110, 11110, 111110, 1111110, 11111110, 111111110, 1111111110};
// 计算S_k的长度
int len(int k)
{
    int n = count(k);
    return n*k-number[n]+(n-1);
}
// 计算前n位数的S_k总和


int main()
{
    
    return 0;
}