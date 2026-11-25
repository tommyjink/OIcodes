#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
string s;
int id[N],n,m,num[N];
vector<int> pos[N];
void prep(int *c)
{
    int now=0;
    for(int i=0;i<=2;i++)
    {
        if(c[i]=='1')
            for(int j='1';j<='9';j++)
                num[j]=++now;
        if(c[i]=='a')
            for(int j='a';j<='z';j++)
                num[j]=++now;
        if(c[i]=='A')
            for(int j='A';j<='Z';j++)
                num[j]=++now;
    }
    m=now;
}
bool cmp(int x,int y)
{
    return num[s[x]]==num[s[y]]?x<y:num[s[x]]<num[s[y]];
}
int cal(int *c)
{
    prep(c);
    for(int i=1;i<=m;i++)
        pos[i].clear();
    for(int i=1;i<=n;i++)
        pos[num[s[i]]].push_back(i);
    sort(id+1,id+1+n,cmp);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int j=i+1;
        while(j<=n&&id[j]>id[j-1])j++;
        j--;
        // cout<<i<<"___"<<j<<endl;
        int tmp=j-i+1;
        if(i!=1)
        {
            int lst=num[s[id[i-1]]];
            int p=upper_bound(pos[lst].begin(),pos[lst].end(),id[i])-pos[lst].begin()-1;
            // cout<<p<<"!!!"<<endl;
            tmp+=p+1;
        }
        if(i!=n)
        {
            int nxt=num[s[id[j+1]]];
            int p=upper_bound(pos[nxt].begin(),pos[nxt].end(),id[j])-pos[nxt].begin()-1;
            tmp+=pos[nxt].size()-p-1;
        }
        // cout<<tmp<<"??"<<endl;
        res=max(res,tmp);
        i=j;
    }
    // cout<<"____"<<endl;
    return res;
}
void solve()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;i++)id[i]=i;
    int ans=0,c[3]={'1','A','a'};
    do
    {
        ans=max(ans,cal(c)); 
    } while((next_permutation(c,c+3)));
    // cout<<n<<"|||||||"<<endl;
    cout<<n-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}