
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;
string s[N];
unordered_map<string,pair<string,bool>>def;
string dfs(string s){
    string r;
    for(int i=0,j;i<s.size();i+=j){
        for(j=0;i+j<s.size()&&('0'<=s[i+j]&&s[i+j]<='9'||'a'<=s[i+j]&&s[i+j]<='z'||'A'<=s[i+j]&&s[i+j]<='Z'||s[i+j]=='_');j++);
        if(j){
            string tmp=s.substr(i,j);
            if(def.count(tmp)&&!def[tmp].second){
                def[tmp].second=1;
                r+=dfs(def[tmp].first);
                def[tmp].second=0;
            }else r+=tmp;
        }else r+=s[i++];
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<=n;i++)getline(cin,s[i]);
    for(int i=1;i<=n;i++){
        if(s[i][0]=='#'){
            if(s[i].substr(1,6)=="define"){
                int p=s[i].find_first_of(' ',8);
                string name=s[i].substr(8,p-8),content=s[i].substr(p+1);
                def[name]={content,0};
            }else{
                string name=s[i].substr(7);
                def.erase(name);
            }
            cout<<'\n';
        }else cout<<dfs(s[i])<<'\n';
    }
    return 0;
}
