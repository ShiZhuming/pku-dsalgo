// 21:40
// 22:09 AC
#include<cstdio>
#include<stack>
#include<vector>
#include<set>
using namespace std;

int n, m, k;

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    m = 1;
    stack<int> s;
    // int,int 分别是(push 0,pop 1),number
    vector<pair<int,int> > v;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&k);
        if (k>n||k<=0)
        {
            printf("NO\n");
            return 0;
        }
        if (!s.empty()&&k==s.top())
        {
            v.push_back(pair<int,int>(1,k));
            s.pop();
            continue;
        }
        if (k<m)
        {
            printf("NO\n");
            return 0;
        }
        
        while (k>=m)
        {
            v.push_back(pair<int,int>(0,m));
            s.push(m);
            if (k==m)
            {
                v.push_back(pair<int,int>(1,k));
                s.pop();
                m++;
                break;
            }
            else {
                m++;
            }
        }
    }
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        printf("%s %d\n",i->first?"POP":"PUSH",i->second);
    }
    return 0;
}