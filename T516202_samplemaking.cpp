#include <bits/stdc++.h>
using namespace std;
int fa[100005],f[100005];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void creat(int n)
{
	for(int i=1;i<=n;i++)fa[i]=i;
    int root=rand()%n+1;
    for(int i=1;i<=n;i++)
    {
        if(i==root) continue;
        int father;
        do{
			father=rand()%n+1;
		}while(find(i)==find(father));
        f[i]=father;
        fa[find(i)]=find(father);
    }
    for(int i=1;i<=n;i++)
    {
        if(root==i) continue;
        cout<<i<<' '<<f[i]<<endl;
    }
}
int main()
{
	int N=5,M=5;
    srand(time(0));
    cout<<N<<" "<<M<<endl;
	creat(N),creat(M);
    
}