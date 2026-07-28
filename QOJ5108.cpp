#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,INF=1e15;
int n,cnta=0,cntb=0,tag[N];
struct node
{
    int sum,mn,id;
}a[N],b[N];
bool cmp(node x,node y)
{
    return x.mn>y.mn;
}
bool cmp1(node x,node y)
{
    return x.mn-x.sum<y.mn-y.sum;
}
void ret()
{
    cout<<"impossible"<<endl;
    exit(0);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        int now=0,mn=INF;
        for(char c:s)
        {
            if(c=='(')now++;
            else now--;
            mn=min(mn,now);
        }
        if(now<0)b[++cntb]={now,mn,i};
        else a[++cnta]={now,mn,i};
    }
    sort(a+1,a+1+cnta,cmp);
    sort(b+1,b+1+cntb,cmp1);
    int now=0;
    vector<int> ans;
    for(int i=1;i<=cnta;i++)
    {
        if(now<-a[i].mn)ret();
        now+=a[i].sum;
        ans.push_back(a[i].id);
    }
    for(int i=1;i<=cntb;i++)
    {
        if(now<-b[i].mn)ret();
        now+=b[i].sum;
        ans.push_back(b[i].id);
    }
    if(now!=0)ret();
    for(int i:ans)cout<<i<<endl;
    return 0;
}