#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
using namespace std;
const double eps = 1e-10;
const int N = 1e6 + 10;
int n;
double x[N], y[N], a, b, c;
double cal(double X, double Y)
{
    double maxdis = 0.0;
    for (int i = 1; i <= n; i++)
        maxdis = max(maxdis, ((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i])));
    return maxdis;
}
double f(double X)
{
    return (-a * X - c) / b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        cin >> a >> b >> c;
        if(fabs(b)<eps)
        {
            double L = -2e5, R = 2e5;
            for(int i=0;i<200;i++)
            {
                double k = (R - L) / 3.0;
                double x=0.0,y1=L+k,y2=R-k;
                if(cal(x,y1)<cal(x,y2))
                    R = y2;
                else
                    L = y1;
            }
            cout<<fixed<<setprecision(15)<<sqrt(cal(0,L))<<endl;
            continue;
        }
        double L = -2e5, R = 2e5;
        for(int i=0;i<200;i++)
        {
            double k = (R - L) / 3.0;
            double x1 = L + k, x2 = R - k;
            double y1 = f(x1), y2 = f(x2);
            if (cal(x1, y1) < cal(x2, y2))
                R = x2;
            else
                L = x1;
        }
        cout<<fixed<<setprecision(15)<<sqrt(cal(L, f(L)))<<endl;
        // printf("%.8lf,%.8lf\n",L,f(L));
    }
    return 0;
}
/*
3
4
0 0
0 1
1 0
1 1
1 -1 0
3
0 1
0 2
0 3
1 0 0
3
-1 1
0 1
1 1
0 1 1


*/