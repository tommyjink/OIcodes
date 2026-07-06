#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1005;
const int M = 1005;
int mp1[N][N], mp2[N][N];
struct node {
    int t, x, y, ans;
} qry[M];
int n, m, q, T, xa, ya, xb, yb;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q >> T;
    cin >> xa >> ya;
    cin >> xb >> yb;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            mp1[i][j] = mp2[i][j] = 0;
    mp1[xa][ya] = 2;
    mp1[xb][yb] = 1;
    for(int i = 0; i < q; i++) {
        cin >> qry[i].t >> qry[i].x >> qry[i].y;
        qry[i].ans = -1;
        if(qry[i].t == 1) {
            qry[i].ans = mp1[qry[i].x][qry[i].y];
        }
    }
    for(int t = 2; t <= T; t++) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                int st = mp1[i][j];
                if(st == 3) mp2[i][j] = 0;
                else if(st == 1 || st == 2) mp2[i][j] = st;
                else {
                    int w = 0, l = 0;
                    if(i-1 >= 1) {
                        if(mp1[i-1][j] == 1) w = 1;
                        if(mp1[i-1][j] == 2) l = 1;
                    }
                    if(i+1 <= n) {
                        if(mp1[i+1][j] == 1) w = 1;
                        if(mp1[i+1][j] == 2) l = 1;
                    }
                    if(j-1 >= 1) {
                        if(mp1[i][j-1] == 1) w = 1;
                        if(mp1[i][j-1] == 2) l = 1;
                    }
                    if(j+1 <= m) {
                        if(mp1[i][j+1] == 1) w = 1;
                        if(mp1[i][j+1] == 2) l = 1;
                    }
                    if(l && !w) mp2[i][j] = 2;
                    else if(w && !l) mp2[i][j] = 1;
                    else if(l && w) mp2[i][j] = 3;
                    else mp2[i][j] = 0;
                }
            }
        for(int i = 0; i < q; i++) {
            if(qry[i].t == t) {
                qry[i].ans = mp2[qry[i].x][qry[i].y];
            }
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                mp1[i][j] = mp2[i][j];
    }
    int em = 0, wa = 0, la = 0, co = 0;
    for(int i = 0; i < q; i++) {
        if(qry[i].ans == 0) em++;
        else if(qry[i].ans == 1) wa++;
        else if(qry[i].ans == 2) la++;
        else if(qry[i].ans == 3) co++;
    }
    cout << em << " " << wa << " " << la << " " << co << endl;
    return 0;
}