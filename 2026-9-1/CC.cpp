#include<bits/stdc++.h>
using namespace std;
#define N 505
#define intl int
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
    intl x=0,k=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch == '-') k=-1;ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*k;
}
const intl dx[] = {0, 0, 1, -1};
const intl dy[] = {1, -1, 0, 0};
intl n, m, k, a[N][N], vis[N][N];
pair<intl,intl> s, t;
struct node{
    pair<intl,intl> p;
    intl dis, num;
};
queue<node> q;
intl bfs() {
    q.push({s, 0, 0}), vis[s.first][s.second] = 0;
    while(q.size()) {
        auto [now, dis, num] = q.front();q.pop();
        if(now == t) return dis;
        For(i,0,3) {
            pair<intl,intl> nw = {now.first + dx[i], now.second + dy[i]};
            if(nw.first < 1 || nw.first > n || nw.second < 1 || nw.second > m || vis[nw.first][nw.second] || num+a[nw.first][nw.second] > k) continue;
            q.push({nw, dis+1, num + a[nw.first][nw.second]}), vis[nw.first][nw.second ] = 1;
        }
    }
    return -1;
}
int main() {
    // freopen("maze.in","r",stdin);
    // freopen("maze.out","w",stdout);
    n = read(), m = read(), k = read();
    For(i,1,n) {
        string op;cin >> op;
        For(j,0,m-1) {
            if(op[j] == 'S') s = {i, j+1};
            if(op[j] == 'T') t = {i, j+1};
            a[i][j+1] = op[j] == '#';
        }  
    }
    printf("%d\n", bfs());
    return 0;
}
/*
5 7 1
S..#...
.#.#.#.
...#...
###.###
......T
*/