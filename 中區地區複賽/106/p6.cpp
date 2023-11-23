#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int grid[3][10];
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int ans[3][10];
bool FoundAns;
int N;

bool Better() {
	for(int i=0;i<3;i++)
		for(int j=0;j<N;j++)
			if(ans[i][j] != grid[i][j]) return ans[i][j] > grid[i][j];
	return false; 	//Same
}

void DFS(int x, int y, int cur) {
	//printf("(%d,%d) cur=%d\n", x, y, cur);
	
	if(cur == 3 * N) {
		if(FoundAns) {
			if(Better()) memcpy(ans, grid, sizeof(grid));
		} else {
			FoundAns = true;
			memcpy(ans, grid, sizeof(grid));
		}
	} else {
		for(int i=0;i<8;i++) { 	//Enumerate 8 directions
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(0 <= nx && nx < 3 && 0 <= ny && ny < N && !grid[nx][ny]) {
				grid[nx][ny] = cur+1;
				DFS(nx, ny, cur+1);
				grid[nx][ny] = 0;
			}
		}
	}
}

int main() {
	while(scanf("%d", &N) == 1) {
		memset(grid, 0, sizeof(grid));
		memset(ans, 0, sizeof(ans));
		FoundAns = false;
		
		grid[0][0] = 1;
		DFS(0,0,1);
		grid[0][0] = 0;

		if(FoundAns) {
			for(int i=0;i<3;i++)
				for(int j=0;j<N;j++)
					if(i==0 && j==0){
						printf("%d", ans[i][j]);
					} else {
						printf(" %d", ans[i][j]);
					}
			printf("\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
} 
