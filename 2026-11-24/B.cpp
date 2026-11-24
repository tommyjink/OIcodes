#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=45;
int n,stk[N];
string s,z;
void solve()
{
    cin>>n>>s>>z;
    if(n>19){cout<<-1<<endl;return;}
    queue<string> q;
    map<string,int> dis;
    q.push(s);dis[s]=0;
    while(!q.empty())
    {
        string u=q.front();q.pop();
        int d=dis[u],top=0;
        if(u==z){cout<<d<<endl;return;}
        for(int i=0;i<2*n;i++)
        {
            if(u[i]=='('){stk[++top]=i;continue;}
            int l=stk[top--];
            string v=u;
            for(int j=l;j<=i;j++)
                v[j]=(u[l+i-j]=='('?')':'(');
            if(dis.count(v))continue;
            dis[v]=d+1;q.push(v);
        }
    }
    cout<<-1<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
