#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 1e7 + 10;
const int P = 998244353; // NTT常用的质数
const int G = 3;          // 998244353 的原根
const int Gi = 332748118; // 原根在模 P 意义下的逆元 (即 1/3 mod P)

int n, m, limit = 1, l = 0, r[N];
int a[N], b[N];

// 快速幂：用于计算原根的幂以及最后的除法（逆元）
int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void ntt(int *A, int type) {
    // 第一步：位逆序置换 (Bit-reversal Permutation)，和 FFT 完全一样
    for (int i = 0; i < limit; i++)
        if (i < r[i]) swap(A[i], A[r[i]]);

    // 第二步：从底向上合并
    for (int len = 1; len < limit; len *= 2) {
        // 计算当前层的单位根 Wn
        // FFT 中是 exp(i * pi / len)
        // NTT 中是 g^((P-1) / (2 * len))，注意这里的 2*len 就是这层循环对应的 n
        int Wn = qpow(type == 1 ? G : Gi, (P - 1) / (len * 2));
        
        for (int i = 0; i < limit; i += len * 2) {
            int w = 1;
            for (int j = 0; j < len; j++, w = w * Wn % P) {
                int x = A[i + j], y = w * A[i + len + j] % P;
                // 蝴蝶操作
                A[i + j] = (x + y) % P;
                A[i + j + len] = (x - y + P) % P; // 防止负数
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= m; i++) cin >> b[i];

    // 确定长度，和 FFT 一样
    while (limit <= n + m) limit <<= 1, l++;
    for (int i = 0; i < limit; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));

    // 正向变换
    ntt(a, 1), ntt(b, 1);
    
    // 点值表示法直接相乘
    for (int i = 0; i < limit; i++) a[i] = a[i] * b[i] % P;

    // 逆变换
    ntt(a, -1);

    // 最后一步：FFT 是除以 limit，NTT 是乘以 limit 的逆元
    int inv = qpow(limit, P - 2);
    for (int i = 0; i <= n + m; i++)
        cout << a[i] * inv % P << " ";

    return 0;
}





// #include<bits/stdc++.h>
// #define int long long
// #define endl "\n"
// using namespace std;
// const int N=1e7+10;
// const double pi=acos(-1);
// int n,m,limit=1,l=0,r[N];
// struct Complex
// {
//     double x,y;
//     Complex(double xx=0,double yy=0){x=xx,y=yy;}
// }a[N],b[N];
// Complex operator +(Complex a,Complex b){return {a.x+b.x,a.y+b.y};}
// Complex operator -(Complex a,Complex b){return {a.x-b.x,a.y-b.y};}
// Complex operator *(Complex a,Complex b){return {a.x*b.x-a.y*b.y,a.y*b.x+a.x*b.y};}
// void fft(Complex *A,int type)
// {
//     for(int i=0;i<limit;i++)
//         if(i<r[i])swap(A[i],A[r[i]]);
//     for(int len=1;len<limit;len*=2)
//     {
//         Complex Wn(cos(pi/len),sin(pi/len)*type);
//         for(int i=0;i<limit;i+=len*2)
//         {
//             Complex w(1,0);
//             for(int j=0;j<len;j++,w=w*Wn)
//             {
//                 Complex x=A[i+j],y=w*A[i+len+j];
//                 A[i+j]=x+y,A[i+j+len]=x-y;
//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>m;
//     for(int i=0;i<=n;i++)cin>>a[i].x;
//     for(int i=0;i<=m;i++)cin>>b[i].x;
//     while(limit<=n+m)limit<<=1,l++;
//     for(int i=0;i<limit;i++)
//         r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
//     fft(a,1),fft(b,1);
//     for(int i=0;i<limit;i++)a[i]=a[i]*b[i];
//     fft(a,-1);
//     for(int i=0;i<=n+m;i++)
//         cout<<(int)(a[i].x/limit+0.5)<<" ";
//     return 0;
// }