#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 1e6 + 10;
int nxt[N];

inline int kmp(const string &s1, const string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    
    nxt[0] = -1;
    for (int i = 1, j = -1; i < len2; ++i) {
        while (j >= 0 && s2[i] != s2[j + 1]) 
            j = nxt[j];
        if (s2[i] == s2[j + 1]) 
            ++j;
        nxt[i] = j;
    }
    
    for (int i = max(0, len1 - len2), j = -1; i < len1; ++i) {
        while (j >= 0 && s1[i] != s2[j + 1])
            j = nxt[j];
        if (s1[i] == s2[j + 1])
            ++j;
        if (i == len1 - 1)
            return j + 1; 
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    
    string now = s[0];
    for (int i = 1; i < n; ++i) {
        int k = kmp(now, s[i]);
        now.append(s[i].begin() + k, s[i].end());
    }
    
    cout << now << endl;
    return 0;
}