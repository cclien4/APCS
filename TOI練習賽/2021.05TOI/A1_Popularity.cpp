#include<stdio.h>

int main()
{
	int a=0,b=0;
	scanf("%d%d",&a,&b);
	int area[100][100]={};
	for(int i=0;i<a;++i)
	{
		for(int j=0;j<b;++j)
		{
			scanf("%d",&area[i][j]);
		}
	}
	for(int i=0;i<a;++i)
	{
		for(int j=0;j<b;++j)
		{
			int cnt=0;
			if(area[i][j]!=0 && j!=b-1)
			{
				printf("%d ",area[i][j]);
			}
			else if (area[i][j]!=0 && j==b-1)
			{
				printf("%d\n",area[i][j]);
			}
			else if(area[i][j]==0)
			{
				if(i-1>=0)
				{
					if(area[i-1][j]!=0)
					{
						cnt+=1;
						area[i][j]+=area[i-1][j];
					}
				}
				if(i+1<a)
				{
					if(area[i+1][j]!=0)
					{
						cnt+=1;
						area[i][j]+=area[i+1][j];
					}
				}

				if(j-1>=0)
				{
					if(area[i][j-1]!=0)
					{
						cnt+=1;
						area[i][j]+=area[i][j-1];
					}
				}
				if(j+1<b)
				{
					if(area[i][j+1]!=0)
					{
						cnt+=1;
						area[i][j]+=area[i][j+1];
					}
				}
				if(cnt)
				{
					area[i][j]/=cnt;
				}
				if(j!=b-1)
				{
					printf("%d ",area[i][j]);
				}
				else if (j==b-1)
				{
					printf("%d\n",area[i][j]);
				}
				area[i][j]=0;
			}
		}
	}
}
