#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
#include <thread>

// 包含跨平台创建目录的头文件
#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#define MKDIR(path) mkdir(path, 0777)
#endif

using namespace std;

// ==========================================
// 全局随机数生成器
// ==========================================
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_ll(long long l, long long r) {
    if (l > r) swap(l, r);
    return uniform_int_distribution<long long>(l, r)(rng);
}

// ==========================================
// 核心逻辑：求解器 (Standard Solution)
// ==========================================
struct Student {
    long long l, r, id;
    // 按右端点排序
    bool operator<(const Student& other) const {
        if (r != other.r) return r < other.r;
        return l < other.l;
    }
};

void solve_problem(string in_path, string out_path) {
    ifstream fin(in_path);
    ofstream fout(out_path);

    long long n, m, d;
    if (!(fin >> n >> m >> d)) return;

    vector<Student> a(m);
    for (int i = 0; i < m; i++) {
        fin >> a[i].l >> a[i].r;
        a[i].id = i;
    }

    sort(a.begin(), a.end());

    long long last_pos = -2e18; // 初始位置设为无穷小
    bool possible = true;

    for (int i = 0; i < m; i++) {
        long long cur = max(a[i].l, last_pos + d + 1);
        
        // 检查是否超过右边界 或 超过总隔间数
        if (cur > a[i].r || cur > n) {
            possible = false;
            break;
        }
        last_pos = cur;
    }

    fout << (possible ? "YES" : "NO") << endl;
    
    fin.close();
    fout.close();
}

// ==========================================
// 核心逻辑：生成器 (Data Generator)
// ==========================================
struct Interval {
    long long l, r;
};

void generate_data(string file_path, int case_id) {
    ofstream fout(file_path);
    
    // 随机种子随用例变化
    rng.seed(case_id * 19260817 + 233);

    // 模式判断：前6个点是小数据(30%)，后面是大数据(100%)
    bool is_small = (case_id <= 6);

    long long n, m, d;

    if (is_small) {
        n = rand_ll(10, 100);
        m = rand_ll(1, 10);
        d = rand_ll(0, 5);
    } else {
        n = rand_ll(100000, 1000000000LL);
        m = rand_ll(10000, 200000);
        
        // d 的取值策略：在 n/m 附近波动，制造临界情况
        long long avg = n / m;
        d = rand_ll(0, avg + 2);
    }

    if (m > n) m = n; // 修正

    vector<Interval> intervals;
    
    // 50% 概率尝试构造必定有解的数据 (Guaranteed YES)
    // 另外 50% 概率完全随机 (Random, mixed YES/NO)
    bool force_yes = (rand_ll(1, 100) <= 50);

    if (force_yes) {
        vector<long long> points;
        long long current = 1;
        bool possible = true;
        
        // 尝试生成 m 个不冲突的点
        for (int i = 0; i < m; i++) {
            long long needed = (m - 1 - i) * (d + 1);
            long long remain = n - current + 1;
            
            if (remain < needed + 1) { possible = false; break; }
            
            long long max_start = n - needed;
            if (current > max_start) { possible = false; break; }

            long long p = rand_ll(current, max_start);
            points.push_back(p);
            current = p + d + 1;
        }

        if (possible && points.size() == m) {
            for (long long p : points) {
                // 向左右随机延伸
                long long drift = is_small ? rand_ll(0, 5) : rand_ll(0, 10000);
                long long l = max(1LL, p - drift);
                long long r = min(n, p + drift);
                intervals.push_back({l, r});
            }
        } else {
            force_yes = false; // 构造失败，回退到随机
        }
    }

    if (!force_yes) {
        for (int i = 0; i < m; i++) {
            long long l = rand_ll(1, n);
            long long max_len = is_small ? 20 : n / 10;
            long long r = min(n, l + rand_ll(0, max_len));
            intervals.push_back({l, r});
        }
    }

    // 打乱顺序
    shuffle(intervals.begin(), intervals.end(), rng);

    fout << n << " " << m << " " << d << endl;
    for (const auto& iv : intervals) {
        fout << iv.l << " " << iv.r << endl;
    }
    
    fout.close();
}

// ==========================================
// 主函数
// ==========================================
int main() {
    string dir = "data";
    
    // 1. 创建文件夹
    if (MKDIR(dir.c_str()) == 0) {
        cout << "[Info] Directory 'data' created." << endl;
    } else {
        cout << "[Info] Directory 'data' already exists or creation failed (check permissions)." << endl;
    }

    cout << "Generating 20 test cases..." << endl;

    for (int i = 1; i <= 20; i++) {
        string in_file = dir + "/" + to_string(i) + ".in";
        string out_file = dir + "/" + to_string(i) + ".out";
        
        cout << "  Processing Case " << i << "... ";
        
        // 2. 生成输入
        generate_data(in_file, i);
        
        // 3. 生成输出
        solve_problem(in_file, out_file);
        
        cout << "Done." << endl;
    }

    cout << "\nAll files generated in 'data/' folder." << endl;
    return 0;
}