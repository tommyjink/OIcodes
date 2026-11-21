#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int h[N];
set<int> s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        s.insert(h[i]);
    }
    int l,r,z=0,ans=0;
    cin>>l>>r;
    for(int i=1;i<=q;i++){
        z=0;
        if(s.size()!=n){
            for(int a=l;a<r;a++){
                for(int b=a+1;b<=r;b++){
                    if(h[b]>h[a])break;
                    if(h[b]==h[a])z=max(z,(b-a)*h[a]);
                }
            }
        }
        ans^=z+i;
        int x=(l+37*z)%n+1,y=(l+r+53*z)%n+1;
        l=min(x,y);
        r=max(x,y);
    }
    cout<<ans<<endl;
    return 0;
}