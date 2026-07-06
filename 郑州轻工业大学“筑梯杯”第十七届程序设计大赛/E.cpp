#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int q,len,a[N],p=N/2;
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>q;
    while(q--){
        int op,x;
        cin>>op;
        if(op==1){
        	cin>>x;
            
            len++;
        }
        else if(op==2){
        	cin>>x;

            len++;
        }
        else{

            len--;
        }
    }   
    return 0;
}
/*
12
1 1
2 2
2 3
1 4
1 5
1 6
3
3
3
3
3
3
*/