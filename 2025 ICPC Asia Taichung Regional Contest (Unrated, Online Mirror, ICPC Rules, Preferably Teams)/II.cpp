#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
struct Point {
    ll x, y;
    Point() {}
    Point(ll x_, ll y_) : x(x_), y(y_) {}
    Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator + (const Point& p) const { return Point(x + p.x, y + p.y); }
    bool operator == (const Point& p) const { return x == p.x && y == p.y; }
    bool operator < (const Point& p) const { return x < p.x || (x == p.x && y < p.y); }
};

ll cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

ll dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

double len(const Point& a) {
    return sqrt(dot(a, a));
}

int sign(ll x) {
    return (x > 0) - (x < 0);
}

// Check if point o is inside convex polygon v (strictly inside)
bool point_in_convex_polygon(const Point& o, const vector<Point>& v) {
    int n = v.size();
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        ll c = cross(v[i] - o, v[(i+1)%n] - o);
        if (c > 0) left++;
        else if (c < 0) right++;
        if (left > 0 && right > 0) return false;
    }
    return true;
}

vector<Point> convex_hull(vector<Point> pts) {
    int n = pts.size();
    if (n <= 1) return pts;
    sort(pts.begin(), pts.end());
    vector<Point> hull(n * 2);
    int k = 0;
    for (int i = 0; i < n; hull[k++] = pts[i++])
        while (k > 1 && cross(hull[k-1] - hull[k-2], pts[i] - hull[k-2]) <= 0) k--;
    for (int i = n - 2, t = k; i >= 0; hull[k++] = pts[i--])
        while (k > t && cross(hull[k-1] - hull[k-2], pts[i] - hull[k-2]) <= 0) k--;
    hull.resize(k - 1);
    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    vector<Point> hull = convex_hull(pts);
    int h = hull.size();

    // Check if origin inside hull
    Point origin(0, 0);
    if (point_in_convex_polygon(origin, hull)) {
        double area = M_PI * r * r / 2.0;
        cout << fixed << setprecision(10) << area << "\n";
        return 0;
    }

    double min_support = 1e18;
    for (int i = 0; i < h; i++) {
        Point a = hull[i], b = hull[(i+1)%h];
        ll cr = abs(cross(a, b));
        double le = len(b - a);
        double dist = cr / le;
        min_support = min(min_support, dist);
    }

    double m = min_support;
    double area = r * r * acos(m / r) - m * sqrt(r * r - m * m);
    cout << fixed << setprecision(10) << area << "\n";
    
    return 0;
}