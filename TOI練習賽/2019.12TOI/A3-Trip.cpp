#include<iostream>
#define N 205
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int main()
{
    IOS;
    int n, m, q;
    cin >> n >> m >> q;
    bool dis[N][N] = {};
    for(int i = 0; i < n; i+=1)
    {
    	dis[i][i] = true;
	}
    for(int i = 0; i < m ; i+=1)
    {
        int a, b;
        cin >> a >> b;
        dis[a][b] = true;
    }
    for(int k = 0; k < n; k+=1)
    {
        for(int i = 0; i < n; i+=1)
        {
            for(int j = 0; j < n; j+=1)
            {
                dis[i][j] = dis[i][j] || (dis[i][k] && dis[k][j]);
            }
        }
    }
    for(int i = 0; i < q; i+=1)
    {
        int a, b;
        cin >> a >> b;
        if(dis[a][b])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
