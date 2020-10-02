#include<cstdio>
#include<memory.h>
#define SIZEMAX 50
int N;
int p[SIZEMAX][SIZEMAX];

int main(int argc, char const *argv[])
{
    scanf("%d",&N);
    int MAX = (2*N-1)*(2*N-1);
    memset(p,0,SIZEMAX*SIZEMAX*sizeof(int));
    // 1.第一个数字写在第一行的中间
    p[0][N-1] = 1;
    int x = 0;
    int y = N-1;
    for (int i = 2; i <= MAX; i++)
    {
        
        x--;
        y++;
        if ((x == -1 && y == 2*N-1) || ( 0 <= x && x < 2*N-1 && y >= 0 && y < 2*N-1 && p[x][y] != 0))
        {
            // printf("if开始p[%d][%d]=%d\t",x,y,i);
            x += 2;
            y--;
            // printf("if结束p[%d][%d]=%d\n",x,y,i);
        }
        else
        {
            // printf("开始p[%d][%d]=%d\t",x,y,i);
            if (x == -1)
            {
                x = 2*N-2;
            }
            if (y == 2*N-1)
            {
                y = 0;
            }
            // printf("p[%d][%d]=%d\n",x,y,i);
        }
        p[x][y] = i;
        
    }
    for (int i = 0; i < 2*N-1; i++)
    {
        for (int j = 0; j < 2*N-1; j++)
        {
            if (j)
            {
                printf(" ");
            }
            printf("%d",p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
