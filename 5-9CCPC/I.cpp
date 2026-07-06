#include <bits/stdc++.h>
#define int long long
#define lowbit(x) x&(-x)
using namespace std;
const int N = 1e3+10;
char s1[N], s2[N];
int nxt[N],n,m,t[N*2];
vector<int> v;
void init_nxt(int len)
{
    nxt[0] = nxt[1] = 0;
    for (int i = 1; i < len; i++)
    {
        int j = nxt[i];
        while (j && s2[i] != s2[j])
        {
            j = nxt[j];
        }
        if (s2[i] == s2[j])
            nxt[i + 1] = j + 1;
        else
            nxt[i + 1] = 0;
    }
}
void kmp(char s1[], char s2[])
{
    int i = 0, j = 0, len1 = strlen(s1), len2 = strlen(s2);
    init_nxt(len2);
    for (i = 0; i < len1; i++)
    {
        while (j && s1[i] != s2[j])
        {
            j = nxt[j];
        }
        if (s1[i] == s2[j])
            j++;
        if (j == len2)
            v.push_back(i - len2 + 1 + 1);
    }
}
void add(int x,int w)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=w;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(nxt,0,sizeof(nxt));
        memset(t,0,sizeof(t));
        v.clear();
        cin>>n>>m;
        cin >> s1 >> s2;
        kmp(s1, s2);
        // cout<<"1"<<endl;
        int ans=0;
        for(auto i:v)
            if(!(query(i+m-1)-query(i-1)))ans++,add(i+m-1,1);
        cout<<ans<<endl;
    }
    return 0;
}