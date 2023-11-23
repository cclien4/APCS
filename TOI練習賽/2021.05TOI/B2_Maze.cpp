#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
const int N = 500 + 5;

using namespace std;

int dis[N][N];
char maze[N][N];

int main()
{
	int n, dh[4]={-1, 1, 0, 0}, dw[4]={0, 0, -1, 1};
	bool flag = false;

	queue<pii> q;

	memset(dis, -1, sizeof(dis));

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%s", maze[i]);
	}
	dis[0][0] = 0;
	q.push(mp(0, 0));

	while(q.size())
	{
		pii u = q.front(); q.pop();
		if(u.first==n-1 && u.second==n-1)
		{
			printf("%d\n", dis[u.first][u.second]);
			flag = true;
			break;
		}

		for(int i=0; i<4; ++i)
		{
			int nh = u.first+dh[i], nw = u.second+dw[i];

			if(0<=nh && nh<n && 0<=nw && nw<n && maze[nh][nw]!='#' && dis[nh][nw]==-1)
			{
				dis[nh][nw] = dis[u.first][u.second]+1;
				q.push(mp(u.first+dh[i], u.second+dw[i]));
			}
		}
	}

	if(flag == false)
	{
		printf("-1\n");
	}

	return 0;
}
