#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e6+10;
int n,lst,fr,cl,cr;
int sum[3][N],cnt[3];
string s;
int get(char c)
{
    if(c=='C')return 0;
    if(c=='W')return 1;
    return 2;
}
char put(int x)
{
    if(x==0)return 'C';
    if(x==1)return 'W';
    return 'P';
}
bool ok(int lf,int rf)
{
    int len=cnt[0]+cnt[1]+cnt[2];
    if(!len)return lf==-1||rf==-1||lf!=rf;
    for(int i=0;i<3;i++)
        if(cnt[i]*2>len+1-(lf==i)-(rf==i))return false;
    return true;
}
bool check(int len)
{
    int L=max(1LL,lst-len+1);
    int R=min(fr+1,n-len+1);
    for(int l=L;l<=R;l++)
    {
        int r=l+len-1;
        for(int i=0;i<3;i++)
            cnt[i]=sum[i][r]-sum[i][l-1];
        int lf=(l==1?-1:get(s[l-1]));
        int rf=(r==n?-1:get(s[r+1]));
        if(ok(lf,rf))
        {
            cl=l;
            cr=r;
            return true;
        }
    }
    return false;
}
void build()
{
    int l=cl,r=cr;
    for(int i=0;i<3;i++)
        cnt[i]=sum[i][r]-sum[i][l-1];
    int lf=(l==1?-1:get(s[l-1]));
    int rf=(r==n?-1:get(s[r+1]));
    string t=s;
    int last=lf;
    for(int i=l;i<=r;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(!cnt[j]||j==last)continue;
            cnt[j]--;
            if(ok(j,rf))
            {
                t[i]=put(j);
                last=j;
                break;
            }
            cnt[j]++;
        }
    }
    cout<<"Possible"<<endl;
    cout<<l<<" "<<r<<endl;
    for(int i=1;i<=n;i++)
        cout<<t[i];
    cout<<endl;
}
void solve()
{
    cin>>n>>s;
    s=" "+s;
    fr=n;
    lst=0;
    for(int i=0;i<3;i++)
        sum[i][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            sum[j][i]=sum[j][i-1];
        sum[get(s[i])][i]++;
        if(i<n&&s[i]==s[i+1])
        {
            fr=min(fr,i);
            lst=max(lst,i);
        }
    }
    if(!lst)
    {
        cout<<"Beautiful"<<endl;
        return;
    }
    for(int i=0;i<3;i++)
        cnt[i]=sum[i][n];
    if(!ok(-1,-1))
    {
        cout<<"Impossible"<<endl;
        return;
    }
    int l=1,r=n,ans=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    check(ans);
    build();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
