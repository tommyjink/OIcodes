
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,inf=1e18;
int n,m;
vector<int>b[N],a[N],ans[N],mn[N];
void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)b[i].clear(),a[i].clear(),ans[i].clear(),mn[i].clear();
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        b[i].push_back(0);
        for(int j=1;j<=m;j++)b[i].push_back(s[j-1]=='1');
    }
    bool f=0;
    if(n>m){
        for(int i=1;i<=m;i++){
            a[i].push_back(0);
            for(int j=1;j<=n;j++)a[i].push_back(b[j][i]);
        }
        swap(n,m);f=1;
    }else{
        for(int i=1;i<=n;i++){
            a[i].push_back(0);
            for(int j=1;j<=m;j++)a[i].push_back(b[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        ans[i].push_back(0),mn[i].push_back(0);
        for(int j=1;j<=m;j++)ans[i].push_back(inf),mn[i].push_back(inf);
    }
    vector<int>L(m+1),R(m+1);
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)mn[i][j]=inf;
        for(int r=l+1;r<=n;r++){
            for(int j=1;j<=m;j++)L[j]=R[j]=0;
            for(int j=1;j<=m;j++)L[j]=(a[l][j]&&a[r][j])?j:L[j-1];
            for(int j=m-1;j>=1;j--)R[j]=(a[l][j+1]&&a[r][j+1])?j+1:R[j+1];
            for(int j=1;j<=m;j++){
                if(a[r][j]&&a[l][j]){
                    if(L[j-1])mn[r][j]=min(mn[r][j],(j-L[j-1]+1)*(r-l+1));
                    if(R[j])mn[r][j]=min(mn[r][j],(R[j]-j+1)*(r-l+1));
                }else if(L[j]&&R[j])mn[r][j]=min(mn[r][j],(R[j]-L[j]+1)*(r-l+1));
            }
        }
        for(int i=1;i<=m;i++)ans[n][i]=min(ans[n][i],mn[n][i]);
        for(int r=n-1;r>=l;r--){
            for(int i=1;i<=m;i++){
                mn[r][i]=min(mn[r][i],mn[r+1][i]);
                ans[r][i]=min(ans[r][i],mn[r][i]);
            }
        }
    }
    if(!f){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cout<<(ans[i][j]==inf?0:ans[i][j])<<" ";
            cout<<"\n";
        }
    }else{
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++)cout<<(ans[i][j]==inf?0:ans[i][j])<<" ";
            cout<<"\n";
        }
    }
}
signed main(){
    int T;cin>>T;
    while(T--)sol();
    return 0;
}
