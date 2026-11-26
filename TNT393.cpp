#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2005;
int n,m,b[N][N],p1[N],p2[N];
int l1[N],l2[N],r1[N],r2[N];
pii c[2*N];
int cnt1(int l,int r)
{
    if(l>r)return 0;
    if(l&1)return (r-l)/2+1;
    else return (r-l+1)/2;
}
int cnt0(int l,int r)
{
    if(l>r)return 0;
    if(l&1)return (r-l+1)/2;
    else return (r-l)/2+1;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        for(int j=1;j<=m;j++)
            if(s[j-1]-'0')
                b[i][j]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j])
            {
                if(p1[j])p2[j]=p1[j],p1[j]=i;
                else p1[j]=i;
            }
            c[j*2-1]={p1[j],j};
            c[j*2]={p2[j],j};
        }
        stack<int> s1,s2;
        for(int j=1;j<=2*m;j++)
            l1[j]=l2[j]=0,r1[j]=r2[j]=2*m+1;
        for(int j=2*m;j>=1;j--)
        {
            vector<int> d;
            while(!s1.empty()&&c[j]>c[s1.top()])
            {
                // cout<<j<<"!!"<<endl;
                l1[s1.top()]=j;
                d.push_back(s1.top());
                s1.pop();
            }
            while(!s2.empty()&&c[j]>c[s2.top()])
            {
                l2[s2.top()]=j;
                s2.pop();
            }
            reverse(d.begin(),d.end());
            for(int x:d)s2.push(x);
            s1.push(j);
        }
        while(!s1.empty())s1.pop();
        while(!s2.empty())s2.pop();
        for(int j=1;j<=2*m;j++)
        {
            vector<int> d;
            while(!s1.empty()&&c[j]>c[s1.top()])
            {
                r1[s1.top()]=j;
                d.push_back(s1.top());
                s1.pop();
            }
            while(!s2.empty()&&c[j]>c[s2.top()])
            {
                r2[s2.top()]=j;
                s2.pop();
            }
            reverse(d.begin(),d.end());
            for(int x:d)s2.push(x);
            s1.push(j);
        }
        // for(int j=1;j<=2*m;j++)
        //     cout<<c[j].first<<" ";
        // cout<<endl;
        // for(int j=1;j<=2*m;j++)
        //     cout<<l1[j]<<" ";
        // cout<<endl;
        // for(int j=1;j<=2*m;j++)
        //     cout<<l2[j]<<" ";
        // cout<<endl;
        // for(int j=1;j<=2*m;j++)
        //     cout<<r1[j]<<" ";
        // cout<<endl;
        // for(int j=1;j<=2*m;j++)
        //     cout<<r2[j]<<" ";
        // cout<<endl;
        for(int j=1;j<=2*m;j++)
        {
            ans+=c[j].first*cnt1(l1[j]+1,j)*cnt0(j,r1[j]-1);
            ans-=c[j].first*cnt1(l2[j]+1,l1[j])*cnt0(j,r1[j]-1);
            ans-=c[j].first*cnt1(l1[j]+1,j)*cnt0(r1[j],r2[j]-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}