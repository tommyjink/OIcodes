#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,nxt[N];
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>s;
    s=" "+s;
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1;i<=n;i++)
    {
        int x=i-nxt[i];
        int y=i/x;
        int z=y%k;
        if(i%x)
            if(y/k-z>0)cout<<"1";
            else cout<<"0";
        else if(y/k-z>=0)cout<<"1";
        else cout<<"0";
    }

    return 0;
}