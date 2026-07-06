#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fast_gets ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define open_f_same freopen("data.in", "r", stdin);freopen("data.out", "w", stdout);
#define close_f fclose(stdin);fclose(stdout);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)){
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
inline void write(int x){
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
vector<int> a;
int n, k;
bool check_g(double mid) {
    int cnt = 0;
    double sum = 0.0;
    for (int num : a) {
        sum += log(num) - mid;
        if (sum >= 0) {
            cnt++;
            sum = 0.0;
        }
    }
    return cnt >= k;
}
bool check_q(double q) {
    double q_sq = q * q;
    int cnt = 0;
    double sum = 0.0;
    for (int num : a) {
        sum += (static_cast<long long>(num) * num - q_sq);
        if (sum >= 0) {
            cnt++;
            sum = 0.0;
        }
    }
    return cnt >= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    double min_a = *min_element(a.begin(), a.end());
    double max_a = *max_element(a.begin(), a.end());
    double left_g = log(min_a);
    double right_g = log(max_a);
    for (int i = 0; i < 100; ++i) {
        double mid = (left_g + right_g) / 2;
        if (check_g(mid)) {
            left_g = mid;
        } else {
            right_g = mid;
        }
    }
    double g = exp(left_g);
    max_a = *max_element(a.begin(), a.end());
    double left_q = 0.0;
    double right_q = max_a;
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (left_q + right_q) / 2;
        if (check_q(mid)) {
            left_q = mid;
        } else {
            right_q = mid;
        }
    }
    double q = left_q;

    cout << g << ' ' << q << endl;

    return 0;
}