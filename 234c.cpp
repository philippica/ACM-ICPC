//9min8s
#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define maxn 100009
int a[maxn],sl[maxn],sr[maxn];
using namespace std;
ifstream fin ("input.txt");
ofstream fout("output.txt");
int main()
{
	int n;
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
		sl[i] = sl[i-1] + (a[i]>=0);
	}
	for(int i=n;i>=1;i--)
	{
		sr[i] = sr[i+1] + (a[i]<=0);
	}
	int ans = 0x3f3f3f3f;
	for(int i=1;i<=n-1;i++)
	{
		ans = min(ans,sl[i]+sr[i+1]);
	}
	fout<<ans<<endl;
	return 0;
}

