#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000;
int n,a[N][N],b[N][N];
string s[N];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            int len=min(s[i].length(),s[j].length());
            int leni=s[i].length();
            int lenj=s[j].length();
            for(int k=0;k<len;k++)
            {
                if(s[i][k]!=s[j][k])break;
                a[i][k]=a[j][k]=1;
            }
            for(int k=0;k<len;k++)
            {
                if(s[i][leni-1-k]!=s[j][lenj-1-k])break;
                b[i][leni-1-k]=b[j][lenj-1-k]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int len=s[i].length();
        for(int j=1;j<len;j++)
        {
            if(a[i][j-1]&&b[i][j])
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}