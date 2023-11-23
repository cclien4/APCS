#include <iostream>
#include <cstdio>

using namespace std;

int T;
int now[3][3];

int vx[] = {0, -1, 0, 1};
int vy[] = {-1, 0, 1, 0};

inline int abs(int x)
{
    return x > 0 ? x : -x ;
}

bool DFS(int O, int D, int x, int y)
{
    if( O > 30 ) return false;

    bool OK = true;

    for(int i = 0; i < 8; i++)
        if( now[i/3][i%3] != i+1 )
            OK = false;

    if( OK ) return true;

    for(int vi = 0; vi < 4; vi++)
    {
        if( abs(D-vi) == 2 ) continue;

        int nx = x+vx[vi];
        int ny = y+vy[vi];

        if( 0 > nx || nx >= 3 ) continue;
        if( 0 > ny || ny >= 3 ) continue;

        swap(now[x][y], now[nx][ny]);

        if( DFS(O+1, vi, nx, ny) ) return true;

        swap(now[x][y], now[nx][ny]);
    }

    return false;
}

int main()
{
    scanf("%d", &T);

    while( T-- )
    {

        int sx, sy;

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                scanf("%d", &now[i][j]);
                if( !now[i][j] ) sx = i, sy = j;
            }

		if( DFS(0, -3, sx, sy) ) printf("Easy");
        else printf("Hard");
       // if( DFS(0, -3, sx, sy) ) puts("Easy");
       // else puts("Hard");
    }
}
