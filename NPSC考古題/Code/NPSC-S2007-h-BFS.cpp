/**********************************************************************************/

#include <cstdio>
#include <queue>
#include <set>

#define WITHIN(n,a,b) ((a)<=(n) && (n)<=(b))

using namespace std;

int ten[10], mr[]={-1,-3,1,3};
set<int> status;

inline int find_zero(int n)
{
    for(int i=0; i<9; i++)
        if( ((n/ten[i]) % 10) == 0 )
            return i;
    
    return -1;
}

inline int exchange(int n, int s, int t)
{
    int u,v,d;
    
    u = (n/ten[s]) % 10;
    v = (n/ten[t]) % 10;
    d = u - v;
    n -= d * ten[s];
    n += d * ten[t];
    
    return n;
}

void BFS(void)
{
    int i,u,nu,z,nz,count,step;
    queue<int> que;
    
    u = 123456780;
    que.push(u);
    status.insert(u);
    count = que.size();
    step = 1;
    
    while( !que.empty() && step < 50 ) {
        u = que.front();
        que.pop();
        z = find_zero(u);
        for(i=0; i<4; i++) {
            nz = z + mr[i];
            if( WITHIN(nz, 0, 8) && !(z%3==0 && i==0) && !((z+1)%3==0 && i==2) ) {
                nu = exchange(u, z, nz);
                if( status.insert(nu).second )
                    que.push(nu);
            }
        }
        
        if( --count == 0 ) {
            count = que.size();
            ++step;
        }
    }
}

int main(void)
{
    int N,i,j,chess;

    for(i=ten[0]=1; i<10; i++)
        ten[i] = ten[i-1] * 10;

    BFS();

    scanf("%d", &N);
    while( N-- ) {
        for(i=chess=0; i<9; i++) {
            scanf("%d", &j);
            chess *= 10;
            chess += j;
        }

        printf("%s\n", status.count(chess) ? "Easy" : "Hard" );
    }

    return 0;
}
