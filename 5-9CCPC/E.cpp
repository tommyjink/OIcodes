#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P = 1e9 + 7;
string s;
int n, len;
void solve()
{
    cin >> s >> n;
    s += '+';
    len = s.length();
    int G = 0, D = 0, U = 0, T = 0,tg=0,td=0,tu=0,tt=0;
    int nowG = 0, nowD = 0, nowU = 0, nowT = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '+')
        {
            G += nowG, D += nowD, U += nowU, T += nowT;
            nowG = nowD = nowU = nowT = 0;
        }
        else
        {
            nowG *= 10, nowD *= 10, nowU *= 10, nowT *= 10;
            if (s[i] == 'G')
                nowG++;
            if (s[i] == 'D')
                nowD++;
            if (s[i] == 'U')
                nowU++;
            if (s[i] == 'T')
                nowT++;
            if(G+nowG>n)tg=1;
            if(D+nowD>n)td=1;
            if(U+nowU>n)tu=1;
            if(T+nowT>n)tt=1;
        }
    }
    if(tg)G=0;
    if(td)D=0;
    if(tu)U=0;
    if(tt)T=0;
    // G+=nowG,D+=nowD,U+=nowU,T+=nowT;
    // cout<<G<<" "<<D<<" "<<U<<" "<<T<<"!!!!!!!!"<<endl;
    for (int g = 0; g <= 9; g++)
        for (int d = 0; d <= 9; d++)
            for (int u = 0; u <= 9; u++)
            {
                int t = n - (G * g + U * u + D * d);
                if (T != 0)
                {
                    if (t % T)
                        continue;
                    t /= T;
                    if (t > 9 || t < 0)
                        continue;
                }
                else t=0;
                if ((G%P * g%P + U%P * u%P + D%P * d%P + T%P * t%P)%P == n%P&&G * g + U * u + D * d + T * t == n)
                {
                    cout << "Yes" << endl;
                    cout << g << " " << d << " " << u << " " << t << endl;
                    return;
                }
            }
    cout << "No" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}