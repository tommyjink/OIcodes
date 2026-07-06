#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const double INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;

struct Point {
    long long x, y;
    Point() : x(0), y(0) {}
    Point(long long x, long long y) : x(x), y(y) {}
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
};

long long cross(const Point& o, const Point& a, const Point& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<Point> convexHull(vector<Point> pts) {
    int n = pts.size();
    if (n <= 1) return pts;
    sort(pts.begin(), pts.end());
    vector<Point> hull;
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > lower_size && cross(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    if (hull.size() > 1) hull.pop_back();
    return hull;
}

struct HullVertex {
    long long x, y;
    double slope_prev;    // 前一条边的斜率（顶点 -> 前一个顶点）
    double slope_next;    // 后一条边的斜率（顶点 -> 后一个顶点）
    double angle_prev;    // 前一条边的极角（弧度）
    double angle_next;    // 后一条边的极角（弧度）
};

// 计算斜率对应的极角（弧度，范围[0, 2π)）
double slopeToAngle(double slope) {
    if (slope == INF) return PI / 2;  // 竖直线向上
    double angle = atan(slope);
    if (angle < 0) angle += PI;       // 确保在[0, π)
    return angle;
}

bool isOriginInConvexHull(const vector<Point>& hull) {
    int m = hull.size();
    if (m == 0) return false;
    if (m == 1) return hull[0].x == 0 && hull[0].y == 0;
    
    bool has_positive = false, has_negative = false;
    for (int i = 0; i < m; ++i) {
        int j = (i + 1) % m;
        long long cr = cross(hull[i], hull[j], Point(0, 0));
        if (cr > 0) has_positive = true;
        else if (cr < 0) has_negative = true;
    }
    return has_positive && has_negative;
}

// 判断弦的极角是否在两边的极角区间内
bool isChordBetweenEdges(double chord_angle, double angle_prev, double angle_next) {
    // 处理极角区间跨0点的情况
    if (angle_prev <= angle_next + EPS) {
        return (chord_angle >= angle_prev - EPS) && (chord_angle <= angle_next + EPS);
    } else {
        return (chord_angle >= angle_prev - EPS) || (chord_angle <= angle_next + EPS);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r;
    cin >> n >> r;
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }
    
    vector<Point> hull = convexHull(pts);
    int m = hull.size();
    
    bool origin_inside = isOriginInConvexHull(hull);
    if (!origin_inside) {
        double half_circle_area = 0.5 * PI * r * r;
        cout << fixed << setprecision(10) << half_circle_area << endl;
        return 0;
    }
    
    vector<HullVertex> hull_vertices(m);
    for (int i = 0; i < m; ++i) {
        int prev = (i - 1 + m) % m;
        int next = (i + 1) % m;
        
        hull_vertices[i].x = hull[i].x;
        hull_vertices[i].y = hull[i].y;
        
        // 计算前一条边的斜率（当前顶点 -> 前一个顶点）
        long long dx_prev = hull[prev].x - hull[i].x;
        long long dy_prev = hull[prev].y - hull[i].y;
        if (dx_prev == 0) {
            hull_vertices[i].slope_prev = INF;
        } else {
            hull_vertices[i].slope_prev = (double)dy_prev / dx_prev;
        }
        
        // 计算后一条边的斜率（当前顶点 -> 后一个顶点）
        long long dx_next = hull[next].x - hull[i].x;
        long long dy_next = hull[next].y - hull[i].y;
        if (dx_next == 0) {
            hull_vertices[i].slope_next = INF;
        } else {
            hull_vertices[i].slope_next = (double)dy_next / dx_next;
        }
        
        // 计算两条边的极角
        hull_vertices[i].angle_prev = slopeToAngle(hull_vertices[i].slope_prev);
        hull_vertices[i].angle_next = slopeToAngle(hull_vertices[i].slope_next);
    }
    
    // 输出凸包顶点信息
    cout << "凸包顶点信息：\n";
    for (const auto& hv : hull_vertices) {
        cout << "顶点(" << hv.x << "," << hv.y << "):\n";
        if (hv.slope_prev == INF) 
            cout << "  前边斜率=INF, 极角=" << fixed << setprecision(6) << hv.angle_prev << " rad\n";
        else 
            cout << "  前边斜率=" << fixed << setprecision(6) << hv.slope_prev << ", 极角=" << fixed << setprecision(6) << hv.angle_prev << " rad\n";
        if (hv.slope_next == INF) 
            cout << "  后边斜率=INF, 极角=" << fixed << setprecision(6) << hv.angle_next << " rad\n";
        else 
            cout << "  后边斜率=" << fixed << setprecision(6) << hv.slope_next << ", 极角=" << fixed << setprecision(6) << hv.angle_next << " rad\n";
    }
    
    // 检查以每个顶点为中点的弦是否在两边之间
    cout << "\n弦的检查结果：\n";
    for (int i = 0; i < m; ++i) {
        const auto& hv = hull_vertices[i];
        // 计算弦的斜率（垂直于原点到该顶点的连线）
        double chord_slope;
        if (hv.y == 0) {
            chord_slope = INF;  // 竖直线
        } else {
            chord_slope = (double)(-hv.x) / hv.y;
        }
        double chord_angle = slopeToAngle(chord_slope);
        
        // 判断弦是否在两边之间（基于极角）
        bool is_between = isChordBetweenEdges(chord_angle, hv.angle_prev, hv.angle_next);
        
        // 输出调试信息
        cout << "顶点(" << hv.x << "," << hv.y << ")的弦：\n";
        if (chord_slope == INF) 
            cout << "  斜率=INF, 极角=" << fixed << setprecision(6) << chord_angle << " rad, ";
        else 
            cout << "  斜率=" << fixed << setprecision(6) << chord_slope << ", 极角=" << fixed << setprecision(6) << chord_angle << " rad, ";
        cout << (is_between ? "位于两边之间" : "不位于两边之间") << "\n";
    }
    
    return 0;
}