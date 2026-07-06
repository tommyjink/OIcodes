#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e6+10,M=20,L=205;
int nxt[M],n=0,f[N],ans=0;
vector<int> v[N];
string s[L],h="";
void kmp(string s1,string s2)
{
    int len1=s1.length()-1,len2=s2.length()-1;
    for(int i=2,j=0;i<=len2;i++)
    {
        while(j&&s2[i]!=s2[j+1])j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=len1;i++)
    {
        while(j&&s1[i]!=s2[j+1])j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        if(j==len2)v[i].push_back(i-j+1);
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    while(cin>>s[++n]&&s[n]!=".")s[n]=" "+s[n];
    string t;
    while(cin>>t)h+=t;
    n--;
    cin>>h;
    h=" "+h;
    for(int i=1;i<=n;i++)
        kmp(h,s[i]);
    f[0]=true;
    for(int i=1;i<h.length();i++)
        for(auto j:v[i])
            if(f[j-1])f[i]=true,ans=max(ans,i);
    cout<<ans<<endl;
    return 0;
}