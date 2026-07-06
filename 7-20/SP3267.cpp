#include<bits/stdc++.h>
using namespace std;

#define maxn 1000010
int n, m, a[maxn], cnt[maxn], ans[maxn], bein[maxn], l = 1, r, now;

struct node
{
	int l, r, id;
}q[maxn];

bool cmp(node a, node b)
{
	return bein[a.l] == bein[b.l] ? a.r < b.r : bein[a.l] < bein[b.l];
}

void add(int x)//加入操作 （右移 
{
	if(cnt[a[x]] == 0)
		++ now;
	++ cnt[a[x]];
}

void del(int x)//删除（左移 
{
	-- cnt[a[x]];
	if(cnt[a[x]] == 0)
		-- now;
}

void print(int x)//要从后往前输出，所以来递归输出 
{
	if(x / 10)
		print(x / 10);
	//printf("%d", x % 10);
	putchar(x % 10 + '0');
	//printf("K"); 
}

int main()
{
    scanf("%d", &n);//输入 
	for(int i = 1; i <= ceil((double) n / sqrt(n)); ++ i)
		for(int j = (i - 1) * sqrt(n) + 1; j <= i * sqrt(n); ++ j)
			bein[j] = i;//这是分的块 
    for(int i=1;i<=n;i++)
        cout<<bein[i]<<" ";
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);//还是输入 
	scanf("%d", &m);//继续输入 
	for(int i = 1; i <= m; ++ i)
	{
		scanf("%d%d", &q[i].l, &q[i].r);//还要输入 
		q[i].id = i;//记录下序号，cmp中要用 
	}
    sort(q + 1, q + m + 1, cmp);//排序 
    /*这种作法就不需要add和del 
    for(int i = 1; i <= m; ++i) {
        int ql = q[i].l, qr = q[i].r;
        while(l < ql) now -= !--cnt[aa[l++]];
        while(l > ql) now += !cnt[aa[--l]]++;
        while(r < qr) now += !cnt[aa[++r]]++;
        while(r > qr) now -= !--cnt[aa[r--]];
        ans[q[i].id] = now;
    }
	*/
	for(int i = 1; i <= m; ++ i)
	{
		while(l < q[i].l)//l右移 
			del(l ++);
		while(l > q[i].l)//l左移 
			add(-- l);
		while(r < q[i].r)//r右移 
			add(++ r);
		while(r > q[i].r)//r左移 
			del(r --);
		ans[q[i].id] = now;
	}
    for(int i = 1; i <= m; ++ i)
	{
		print(ans[i]);//输出 
		printf("\n");//记得换行 
	}
	return 0;
}
