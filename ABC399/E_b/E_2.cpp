#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n,num[1000005],nxt[1000005],vis[1000005],x,y,ans;
string a,b;

int dfs(int a,int b){
    vis[a] = b;
    if(nxt[a] == 0 || nxt[a] == a){
        return 0;
    }
    if(vis[nxt[a]] == b){
        y = nxt[a];
        return -1;
    }
    else if(vis[nxt[a]] != 0){
        return 1;
    }
    int c = dfs(nxt[a],b);
    if(c < 0){
        return -1 + c;
    }
    return 1 + c;
}

signed main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        if(nxt[a[i]-'a'+1] == 0){
            nxt[a[i]-'a'+1] = b[i] - 'a' + 1;
        }
        else if(nxt[a[i]-'a'+1] != b[i] - 'a' + 1){
            cout << -1;
            return 0;
        }
    }
    for(int i=1;i<=26;i++){
        if(vis[i] == 0 && nxt[i] != i){
            x = dfs(i,i);
            if(x < 0){
                if(x == -26){
                    cout << -1;
                    return 0;
                }
                ans++;
                x = -x;
            }
            ans += x;
        }
    }
    cout << ans;
    
    return 0;
}