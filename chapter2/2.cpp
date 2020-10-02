#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int n;

typedef pair<int,int> term;
typedef vector<term> polunomial;

bool comp (const term & a, const term & b)
{
    return a.second > b.second;
}

void input(polunomial & p)
{
    int x,y;
    char c;
    while (true)
    {
        scanf("%d %d",&x,&y);
        c = getchar();
        if (y<0)
        {
            sort(p.begin(),p.end(),comp);
            return;
        }
        p.push_back(term(x,y));
    }
}

void output(polunomial & p)
{
    if(p.empty())
    {
        // printf("[ 0 0 ]\n");
        printf("\n");
        return;
    }
    for (polunomial::iterator i = p.begin(); i != p.end(); ++i)
    {
        printf("[ %d %d ]",i->first,i->second);
        if (i == p.end() - 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }
    return;
}

void merge(polunomial & p)
{
    for (polunomial::iterator i = p.begin(); i != p.end()-1; ++i)
    {
        if (i->second == (i+1)->second)
        {
            (i+1)->first += i->first;
            p.erase(i);
            --i;
        }
    }
    for (polunomial::iterator i = p.begin(); i != p.end(); ++i)
    {
        if (i->first == 0)
        {
            p.erase(i);
            --i;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    getchar();
    while (n--)
    {
        // 有序（幂次，系数）对，幂次大的在前
        polunomial a,b,c;
        input(a);
        input(b);
        // debug
        // output(a);
        // output(b);
        // debug end
        merge(a);
        merge(b);
        polunomial::iterator pa = a.begin();
        polunomial::iterator pb = b.begin();
        while (pa != a.end() || pb != b.end())
        {
            if (pb == b.end() || pa != a.end() && pa->second > pb->second)
            {
                c.push_back(*pa);
                ++pa;
            }
            else if (pa == a.end() || pb != b.end() && pa->second < pb->second)
            {
                c.push_back(*pb);
                ++pb;
            }
            else if (pa->second == pb->second)
            {
                c.push_back(term(pa->first+pb->first,pa->second));
                ++pa;
                ++pb;
            }
        }
        merge(c);
        output(c);
    }
    return 0;
}