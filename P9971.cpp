#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int xo[10],yo[10],tot=0,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        tot=0;
        for(int i=1;i<=5;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=5;j++)
            {
                if(s[j-1]=='o')
                    xo[++tot]=i,
                    yo[tot]=j;
            }
        }
        if(tot==1)ans=0;
        else if(tot==2)ans=1;
        else if(tot==3)ans=0;
        else
        {
            if(xo[4]==xo[1]+1&&yo[4]==yo[1]+1&&xo[2]==xo[1]&&xo[3]==xo[4])ans=0;
            else if(xo[4]==xo[1]+3&&yo[4]==yo[1])ans=0;
            else if(xo[4]==xo[1]&&yo[4]==yo[1]+3)ans=0;
            else ans=1;
        }
        if(ans)cout<<"Far"<<endl;
        else cout<<"Away"<<endl;
    }
    return 0;
}
/*

1
.....
oo...
o....
o....
.....

1
.....
oooo.
.....
.....
.....

1
.....
o....
o....
o....
o....

*/