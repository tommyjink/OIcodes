#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int n;
double a[N];

struct Node {
    double x, y;
    double ratio() const { return x / y; }
};

Node stk[N];  
int top;     

double ans[N]; 
int ans_cnt;   

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &a[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        double x = a[i], y = 1.0;
        while (top > 0 && x / y < stk[top].ratio()) {
            x += stk[top].x;
            y += stk[top].y;
            --top;
        }
        stk[++top] = {x, y};
    }
    
    int pos = n;
    while (top > 0) {
        double val = stk[top].ratio();
        int cnt = stk[top].y;
        while (cnt--) {
            ans[pos--] = val;
        }
        --top;
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%.9lf\n", ans[i]);
    }
    
    return 0;
}