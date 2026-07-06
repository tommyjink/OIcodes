#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int k, n;
set<int> st[N], dist[N];
map<int, int> bkt;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n;
    vector<int> A(2*n);
    for (int i=0; i<n; ++i) cin >> A[i], --A[i];
    for (int i=n; i<2*n; ++i) A[i]=A[i-n];

    auto calc = [&](int x, int y){return min(abs(y-x), k-abs(y-x));};
    for (int i=0, j=0; i<n; ++i){
        while (calc(A[i], A[j]) < calc(A[i], A[j+1])){
            // printf("i=%d j=%d calc(i, j)=%d calc(i, j+1)=%d\n", i, j, calc(A[i], A[j]), calc(A[i], A[j+1]));
            ++j;
        }
        st[i].insert(j%n); st[j%n].insert(i); dist[i].insert(j%n);
        if (calc(A[i], A[j]) == calc(A[i], A[j+1])){
            st[i].insert((j+1)%n); st[(j+1)%n].insert(i); dist[i].insert((j+1)%n);
        }
    }
    // for (int i=0; i<n; ++i){
    //     printf("i=%d:", i); for (int x : st[i]) printf("%d ", x); puts("");
    // }
    int ans=0;
    for (int i=0; i<n; ++i) ans = max(ans, (int)st[i].size());

    for (int i=0; i<n; ++i) if (dist[i].size()==2){
        int x=*dist[i].begin(), y = *dist[i].rbegin();
        if (dist[x].count(y) || dist[y].count(x)) ans=max(ans, 3);
    }

    cout << ans << '\n';
    return 0;
}

