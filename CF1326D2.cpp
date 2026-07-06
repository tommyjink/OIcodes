#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;
const int  maxn=4000007;

int T;
string s,rev;
string t;
string s1,s2;
string ans;
int nxt1[maxn],nxt2[maxn];
int ans1,ans2;
bool check(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1])return 0;
	}
	return 1;
}
int main(){
   	scanf("%d",&T);while(T--){
    
		t="";
   		cin>>s;
   		int len=s.size();
        for(int i=0;i<=2*len;i++)nxt1[i]=nxt2[i]=0;
       	
        if(check(s)){
        	cout<<s<<endl;
        	continue;
        }
   		int p=0,q=len-1;
   		while(s[p]==s[q])p++,q--;
   		t=s.substr(0,p);
   		s=s.substr(p,q-p+1);
   		rev=s;
        reverse(rev.begin(),rev.end());
        s1=s+"$"+rev,s2=rev+"$"+s;
        int j=0;
        for(int i=2;i<=s1.size();i++){
            while(j&&s1[i-1]!=s1[j])j=nxt1[j];
            if(s1[j]==s1[i-1])j++;
            nxt1[i]=j;
        }
        j=0;
        for(int i=2;i<=s2.size();i++){
            while(j&&s2[i-1]!=s2[j])j=nxt2[j];
            if(s2[j]==s2[i-1])j++;
            nxt2[i]=j;
        }
    
        if(nxt1[s1.size()]<nxt2[s2.size()]){
        	ans=s2.substr(0,nxt2[s2.size()]);
        }else{
        	ans=s1.substr(0,nxt1[s1.size()]);
        }
        
        cout<<t<<ans;
        reverse(t.begin(),t.end());
        cout<<t<<endl;
   	}
	return 0;
}
