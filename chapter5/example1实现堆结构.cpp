#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<assert.h>
#include<ctype.h>
using namespace std;
 
int a[100010];
int size;
 
void siftdown( int cike )//向下移动
{
    int i = cike;///标示父节点
 
    int j =  2*i; ///标示关键值较小的节点。
    int temp = a[cike]; ///保存父节点的值
    while( j <= size)
    {
        if( j <= size -1  && a[j] > a[j+1])j++;///size减一保证范围
        if( temp > a[j]) ///比当前节点还小的话向下继续
        {
            a[i] = a[j];
            i = j;
            j = 2*j;
        }
        else break;
    }
    a[i] = temp;//回填
}
 
void siftup( int cike )
{
    int temdian = cike;
    int temp = a[temdian];
    while( (temdian > 1)&&( a[temdian/2] > temp))
    ///当下标在合理范围内且 父节点比当前节点大   根节点是 下标为1
    {
        ///父节点下移。 当前节点下标变为父节点下标、
 
        a[temdian] = a[temdian/2];//向上移
        temdian = temdian/2;
    }
    a[temdian] = temp;//回填
}
 
void insert( int  t)
{
    a[ ++size ] = t;
    siftup( size );
}
 
void del( )
{
 
    if(size==0)return ;
    printf("%d\n",a[1]);
     a[1] = a[size--];
        siftdown( 1 );
 
}
 
int main()
{
    freopen("_make.out","r",stdin);
    freopen("_ex.out","w",stdout);
    int t;
    scanf("%d",&t);
    while( t-- )
    {
        size = 0;
        int type;
        int m;
        scanf("%d",&m);
        for(int i = 0; i< m; i++)
        {
            scanf("%d",&type);
 
            if(type == 1)
            {
                int b;
                scanf("%d",&b);
                insert( b );//插入建堆
            }
            else
            {
                del();
            }
        }
         
    // printf("tree structure : \n");for(int i = 1; i <= size; i++) printf("%d ",a[i]);printf("tree end\n");//ceshi

    }

    return 0;
}