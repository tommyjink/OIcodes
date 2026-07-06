#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 2e4;  
ll ans[MAX_N + 1];      


void precompute() {
    
    for (int n = 1; n <= MAX_N; ++n) {
        ll sum = 0;          
        ll* contrib = new ll[n + 1]();  
        
        
        for (int d = 1; d <= n; ++d) {
            int m = n / d;  
            if (m < 2) continue;  
            
            for (int k = 2; k <= m; ++k) {
                int x = k * d;
                int add = m - k + 1;  
                contrib[x] += add;
            }
        }
        
        
        for (int x = 1; x <= n; ++x) {
            sum += x + contrib[x];
        }
        ans[n] = sum;
        
        delete[] contrib;  
    }
}

int main() {
    
    precompute();
    cout<<"DONE";
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}