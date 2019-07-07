# include<iostream>
# include<algorithm>
 
using namespace std;
 
typedef struct LNode{
  int num;
  int pow;
  struct LNode * next;
}LNode, * LinkList;
 
bool cmp(LNode a, LNode b)
{
    return a.pow>b.pow;
}
 
void ListInsert(LNode * pHead, int a, int b)
{
    LNode * p=new LNode;
    p->num=a;
    p->pow=b;
    p->next=pHead->next;
    pHead->next=p;
}
LNode * find(LNode * pHead, int b)
{
    LNode *p=pHead->next;
    while(p&&p->pow!=b)
    {
        p=p->next;
    }
    return p;
}
 
void sort(LNode * pHead)
{
    LNode * p, *q;
    int ta, tb;
    for(p=pHead->next; p!=NULL; p=p->next)
      for(q=pHead->next; q->next!=NULL; q=q->next)
      {
            if(q->pow<q->next->pow)
            {
                ta=q->num;
                tb=q->pow;
                q->num=q->next->num;
                q->pow=q->next->pow;
                q->next->num=ta;
                q->next->pow=tb;
            }
 
      }
 
}
 
 
int main(void)
{
    LNode * pHead = NULL, *p, *q;
    int n, t, a, b, i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        pHead = new LNode;
        pHead->next=NULL;
        t=1;
        while(t<=2)
        {
            while(cin>>a>>b)
            {
                if(b<0)
                break;
                if((p=find(pHead, b))!=NULL)
                {
                    p->num+=a;
                }
                else
                ListInsert(pHead, a, b);
 
            }
            t++;
        }
        sort(pHead);
        p=pHead->next;
        while(p!=NULL)
        {
            if(p->num==0)
            {
                p=p->next;
                continue;
            }
            cout<<"[ "<<p->num<<" "<<p->pow<<" ]"<<" ";
            p=p->next;
        }
        cout<<endl;
        p=pHead->next;
        while(!p)
        {
            q=p;
            p=p->next;
            delete q;
        }
    }
    return 0;
}