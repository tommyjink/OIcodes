#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 超弦历单位定义
const ll SUPER_YEAR = 40;
const ll SUPER_CYCLE = 30 * SUPER_YEAR;
const ll SUPER_GENERATION = 20 * SUPER_CYCLE;
const ll SUPER_CENTURY = 12 * SUPER_GENERATION;
const ll SUPER_EPOCH = 5 * SUPER_CENTURY;

// 量子环历单位定义
const ll QUANTUM_HOUR = 1;
const ll QUANTUM_SMALL = 35 * QUANTUM_HOUR;
const ll QUANTUM_MIDDLE = 25 * QUANTUM_SMALL;
const ll QUANTUM_LARGE = 15 * QUANTUM_MIDDLE;

// 膜历单位定义
const ll MEM_DAY = 1;
const ll MEM_CYCLE = 32 * MEM_DAY;
const ll MEM_ERA = 22 * MEM_CYCLE;
const ll MEM_EPOCH = 18 * MEM_ERA;

ll compute_super_days(ll se, ll sc, ll sg, ll sy, ll sd) {
    ll total_days = (se - 1) * SUPER_EPOCH + (sc - 1) * SUPER_CENTURY + (sg - 1) * SUPER_GENERATION + (sy - 1) * SUPER_CYCLE + (sd - 1) * SUPER_YEAR;
    
    // 计算超弦奇点影响
    if (se % 5 == 0 && sc == 10 && sg == 10 && sy == 20) {
        total_days += 10;
    }
    
    // 计算量子扰动影响（简化处理为 2 天）
    if (se % 7 == 0) {
        total_days -= 2;
    }
    
    return total_days;
}

void convert_to_quantum(ll total_days, ofstream &outfile) {
    ll qlgc = total_days / QUANTUM_LARGE + 1;
    total_days %= QUANTUM_LARGE;
    ll qlmc = total_days / QUANTUM_MIDDLE + 1;
    total_days %= QUANTUM_MIDDLE;
    ll qlsc = total_days / QUANTUM_SMALL + 1;
    total_days %= QUANTUM_SMALL;
    ll qlh = total_days + 1;
    outfile << qlgc << " " << qlmc << " " << qlsc << " " << qlh << "\n";
}

void convert_to_mem(ll total_days, ofstream &outfile) {
    ll be = total_days / MEM_EPOCH + 1;
    total_days %= MEM_EPOCH;
    ll bea = total_days / MEM_ERA + 1;
    total_days %= MEM_ERA;
    ll bc = total_days / MEM_CYCLE + 1;
    total_days %= MEM_CYCLE;
    ll bd = total_days + 1;
    outfile << be << " " << bea << " " << bc << " " << bd << "\n";
}

void generate_testcases() {
    srand(time(0));
    
    for (int i = 1; i <= 20; ++i) {
        ofstream infile(to_string(i) + ".in");
        ofstream outfile(to_string(i) + ".out");
        
        int T = 10; // 每个测试文件包含 10 组测试数据
        infile << T << "\n";
        
        while (T--) {
            ll se = rand() % 1000 + 1;
            ll sc = rand() % 12 + 1;
            ll sg = rand() % 20 + 1;
            ll sy = rand() % 30 + 1;
            ll sd = rand() % 50 + 1;
            
            infile << se << " " << sc << " " << sg << " " << sy << " " << sd << "\n";
            
            ll total_days = compute_super_days(se, sc, sg, sy, sd);
            convert_to_quantum(total_days, outfile);
            convert_to_mem(total_days, outfile);
        }
        
        infile.close();
        outfile.close();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    generate_testcases();
    return 0;
}