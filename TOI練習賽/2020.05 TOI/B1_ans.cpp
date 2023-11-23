//dog
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>

struct data{
	int h, l;
};

int ans=0;
int maze[1005][1005], used[1005][1005]={0};

void solve(int n, int h, int l)
{
	int dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
	std::queue<data> q;
	q.push((data){h, l});
	used[h][l]=1;
	++ans;
	while(q.size())
	{
		data out=q.front();
		q.pop();
		for(int i=0; i<4; ++i)
		{
			int nx=out.h+dx[i], ny=out.l+dy[i];
			if(0<=nx&&nx<n&&0<=ny&&ny<n&&used[nx][ny]==0&& abs(maze[nx][ny]-maze[out.h][out.l])<=2)
			{
				used[nx][ny]=1;
				q.push((data){nx, ny});
				++ans;
			}
		}
	}
	return;
}

int main()
{
	int n, h, l;
	memset(used, 0, sizeof(used));
	scanf("%d%d%d", &n, &h, &l);
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) scanf("%d", &maze[i][j]);
	solve(n, h, l);
	printf("%d\n", ans);
	return 0;
}
