//11-19 REVIEW(HASH):
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int P=1e9+7,N=1e6+10;
int base1[N]={1},base2[N]={1};
int n,m,h1[N]={0},h2[N]={0};
string s,t;
void init()
{
    for(int i=1;i<N;i++)
        base1[i]=base1[i-1]*13331%P,
        base2[i]=base2[i-1]*998244353%P;
    for(int i=1;i<N;i++)
    {
        h1[i]=(h1[i-1]*13331%P+(s[i]-'A'))%P;
        h2[i]=(h2[i-1]*998244353%P+(s[i]-'A'))%P;
    }
}
pii gethash(int x,int y)
{
    int hh1=((h1[y]-h1[x-1]*base1[y-x+1]%P)%P+P)%P;
    int hh2=((h2[y]-h2[x-1]*base2[y-x+1]%P)%P+P)%P;
    return pii(hh1,hh2);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s>>t;
    n=s.length();
    m=t.length();
    s=" "+s;
    t=" "+s;
    pii tt=pii(0,0);
    for(int i=1;i<=m;i++)
        tt.first=(tt.first*13331%P+(t[i]-'A'))%P,
        tt.second=(tt.second*998244353%P+(t[i]-'A'))%P;
    cout<<tt.first<<","<<tt.second<<endl;
    cout<<gethash(1,m).first<<","<<gethash(1,m).second<<endl;
    for(int i=1;i<=n-m+1;i++)
        if(gethash(i,i+m-1)==tt)cout<<i<<endl;
    return 0;
}









/*



//11-16 REVIEW:
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,nxt[N];
string s1,s2;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2;
    n=s1.length(),m=s2.length();
    s1=" "+s1,s2=" "+s2;
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&s2[j+1]!=s2[i])j=nxt[j];
        if(s2[j+1]==s2[i])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=n;i++)
    {
        while(j&&s2[j+1]!=s1[i])j=nxt[j];
        if(s2[j+1]==s1[i])j++;
        if(j==m)j=nxt[j],cout<<i-m+1<<endl;
    }
    for(int i=1;i<=m;i++)
        cout<<nxt[i]<<" ";
    return 0;
}


*/











/*#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int nxt[N],len1,len2;
string s1,s2;
vector<int> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s1>>s2;
    len1=s1.length();
    len2=s2.length();
    s1=" "+s1;
    s2=" "+s2;
    for(int i=2,j=0;i<=len2;i++)
    {
        while(j&&s2[i]!=s2[j+1])
            j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=len1;i++)
    {
        while(j&&s1[i]!=s2[j+1])
            j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        if(j==len2)
            ans.push_back(i-len2+1);
    }
    for(auto v:ans)cout<<v<<endl;
    for(int i=1;i<=len2;i++)cout<<nxt[i]<<" ";
    return 0;
}*/