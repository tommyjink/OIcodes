#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int q,now=0;
struct node
{
    int ans=0;
    priority_queue<int> no;
    priority_queue<int,vector<int>,greater<int> > yes;
    void back(int x,int y)
    {
        no.push(x);
        int t=no.top();
        no.pop();
        yes.push(t);
        ans+=t;
        no.push(y);
    }  
    void front(int x,int y)
    {
        yes.push(x);
        ans+=x;
        int t=yes.top();
        yes.pop();
        ans-=t;
        no.push(t);
        ans+=y;
        yes.push(y);
    }
    void init()
    {
        ans=0;
        while(!no.empty())no.pop();
        while(!yes.empty())yes.pop();
    }
}s[2];
deque<int> dq;
void solve()
{
    now=0;
    s[0].init();
    s[1].init();
    while(!dq.empty())dq.pop_back();
    cin>>q;
    while(q--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        { 
            s[now].front(x,y);
            if(!dq.empty())s[now^1].front(dq.front(),x);
            dq.push_front(x);
            dq.push_front(y); 
        }
        else if(op==2)
        {
            now^=1;
            if(dq.empty())
            {
                s[now].back(x,y);
            }
            else
            {
                s[now].front(dq.front(),x);
                s[now].back(dq.back(),y);
            }
            dq.push_front(x);
            dq.push_back(y);
        }
        else
        {
            s[now].back(x,y);
            if(!dq.empty())s[now^1].back(dq.back(),x);
            dq.push_back(x);
            dq.push_back(y);
        }
        cout<<s[now].ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}