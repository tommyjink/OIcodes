#include <bits/stdc++.h>
using namespace std;


int minSubsequences(vector<int>& a) {
    vector<int> tails; 
    
    for (int x : a) {
        
        auto it = upper_bound(tails.begin(), tails.end(), x);
        
        if (it == tails.end()) {
            
            tails.push_back(x);
        } else {
            
            *it = x;
        }
    }
    
    return tails.size(); 
}


void test() {
    
    vector<int> a1 = {1, 3, 2, 4};
    cout << "测试1: [1,3,2,4] -> " << minSubsequences(a1) << " 个序列" << endl;
    
    
    
    vector<int> a2 = {5, 4, 3, 2, 1};
    cout << "测试2: [5,4,3,2,1] -> " << minSubsequences(a2) << " 个序列" << endl;
    
    
    
    vector<int> a3 = {1, 2, 3, 4, 5};
    cout << "测试3: [1,2,3,4,5] -> " << minSubsequences(a3) << " 个序列" << endl;
    
    
    
    vector<int> a4(500000);
    for (int i = 0; i < 500000; i++) {
        a4[i] = rand() % 1000000;
    }
    cout << "测试4: 长度500000随机数组 -> " << minSubsequences(a4) << " 个序列" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    test();
    
    
    int n;
    cout << "\n请输入数组长度: ";
    cin >> n;
    
    vector<int> a(n);
    cout << "请输入 " << n << " 个数字: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int result = minSubsequences(a);
    cout << "最少需要分成 " << result << " 个单调不降的子序列" << endl;
    
    return 0;
}