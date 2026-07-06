#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,len,nxt[N],cnt[N],ans[N],c[N];
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    while(n--)
    {
        cin>>s;
        len=s.length();
        s=" "+s;
        for(int i=1;i<=len;i++)
            cnt[i]=0;
        cnt[0]=0,cnt[1]=1;
        for(int i=2,j=0;i<=len;i++)
        {
            while(j&&s[i]!=s[j+1])
                j=c[j];
            if(s[i]==s[j+1])j++;
            c[i]=j;
            cnt[i]=cnt[c[i]]+1;
        }
        for(int i=2,j=0;i<=len;i++)
        {
            while(j&&s[i]!=s[j+1])
                j=nxt[j];
            if(s[i]==s[j+1])j++;
            while(j>i/2)j=c[j];
            nxt[i]=j;
            ans[i]=cnt[nxt[i]];
        }
        int tot=1;
        for(int i=1;i<=len;i++)
            tot=(tot*(ans[i]+1))%P;
        // cout<<endl;
        cout<<tot<<endl;
    }
    return 0;
}