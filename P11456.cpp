#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,P=1e9+7;
int n,f[N],sum[2],l,tag[N];
string s;
vector<int> v,vv;
void add(int &x,int y)
{
    x=((x+y)%P+P)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    int lst=0;
    for(int i=0;i<=n;i++)tag[i]=1;
    sum[0]=f[0]=1;
    int L=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='R')lst=i;
        for(int p:v)
            if(p>0&&tag[p-1])
            {
                tag[p-1]=0;
                if(p-1>=L)add(sum[(p-1)&1],-f[p-1]);
                vv.push_back(p-1);
            }
        v.clear();
        for(int p:vv)v.push_back(p);
        vv.clear();
        if(s[i]=='B')v.push_back(i);
        L=max(0ll,2*lst-i-1);
        while(l>L)l--,add(sum[l&1],tag[l]*f[l]);
        while(l<L)add(sum[l&1],-tag[l]*f[l]),l++;
        if(s[i]=='X')add(f[i],f[i-1]);
        if(s[i]!='R')add(f[i],sum[i&1]);
        add(sum[i&1],f[i]);
    }
    cout<<f[n]<<endl;
    return 0;
}