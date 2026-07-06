#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6;
string s;
int done[N];
struct node
{
    char c;
    int pos;
};
stack<node> sl;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[')
            sl.push((node){s[i], i});
        else if (s[i] == ')' && (!sl.empty()) && sl.top().c == '(')
        {
            done[sl.top().pos] = done[i] = true;
            sl.pop();
        }
        else if (s[i]==']'&&(!sl.empty()) && sl.top().c == '[')
        {
            done[sl.top().pos] = done[i] = true;
            sl.pop();
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if(done[i])cout<<s[i];
        else if(s[i]=='('||s[i]==')')cout<<"()";
        else cout<<"[]";
    }
    return 0;
}