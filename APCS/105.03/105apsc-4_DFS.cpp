#include <cstdio>
#include <stdio.h>
#include <cstdlib>
int min=999,book[101],n,e[101][101];

void dfs(int cur,int dis)
{
	int j;
	if(cur==n)
	{
		if(dis<min) min=dis;
		return;
	} 
	
	for(j=0;j<n;j++)
	{
		if(e[cur][j]!=999 && book[j]==0)
		{
			book[j]=1;
			dfs(j,dis+e[cur][j]);
			book[j]=0;
		}
		
	}
	return;
}

int main()
{
	int i,j,m,a,b;
	scanf("%d",&n);
	m=n-1;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=999;
			
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;
	}
/*
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("%d",e[i][j]);
		printf("\n");
	*/
	book[0]=1;
	dfs(0,0);
	printf("%d",min);
	return 0;
}
