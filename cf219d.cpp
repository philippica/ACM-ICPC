#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 400009
using namespace std;
int next[maxn],head[maxn],point[maxn],value[maxn],x,y;
int now=0,cnt[maxn],visit[maxn],deep[maxn],dp[maxn];
int ans = 0x3f3f3f3f;
int edge[maxn],turn[maxn];
void add(int x,int y,int v)
{
	next[++now] = head[x];
	head[x] = now;
	point[now] = y;
	value[now] = v;
}
int dfs(int s,int d,int dd)
{
	visit[s]=1;
	deep[s] = dd;
	turn[s] = d;
	int ret = 0,edg = 0;
	for(int i=head[s];i;i=next[i])
	{
		int u = point[i];
		if(visit[u])continue;
		ret += dfs(u,d+value[i],dd+1);
		ret += value[i];
		edg += edge[u]+1;
	}
	edge[s] = edg;
	return dp[s]=ret;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y,0);
		add(y,x,1);
	}
	memset(dp,-1,sizeof(dp));
	dfs(1,0,0);
	int h = 0,an[maxn];
	for(int i=1;i<=n;i++)
	{
		//printf("i:%d deep: %d dp:%d turn:%d edge:%d \n",i,deep[i],dp[i],turn[i],edge[i]);
		int u = dp[1]-turn[i]+(deep[i]-turn[i]);
		if(u<ans)
		{
			ans = u;
			an[h=1] = i;
		}
		else if(u==ans)
		{
			an[++h]=i;
		}
	}
	
	printf("%d\n",ans);
	for(int i=1;i<=h;i++)printf("%d ",an[i]);
}
