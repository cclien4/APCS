// NPSC 2008 高中組決賽 
// 題目 H - 幼稚國王的行程 
// By sagit at TCGS
#include <cstdlib>
#include <cstdio>

using namespace std;

const int MAX=1002, VERY_LONG=100000;
int G[MAX][MAX], D[MAX], V[MAX], Ans[MAX], An, Num, Dis;
// G 記錄兩點之間的距離, D 記錄到某點的最短距離, V 記錄該點是否已完成 
// Ans 記錄答案, An 為答案個數, Num 為點的總數, Dis 為要求的距離 

int main()
{
    freopen("ph.in", "rt", stdin);
    freopen("ph.out", "w+t", stdout);
    int k, m, i, j, a, b, c;
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d%d%d", &Num, &m, &Dis);
        for (i=1; i<=Num; i++)          // 將所有點的距離設為很大 
            for (j=1; j<=Num; j++)
                G[i][j]=VERY_LONG;
        for (i=0; i<m; i++)             // 輸入每個點的距離 
        {
            scanf("%d%d%d", &a, &b, &c);
            if (a==b||G[a][b]<c) continue; // 連到自己或重覆而較長的邊不處理 
            G[a][b]=c;
        }
        for (i=1, An=0; i<=Num; i++)    // 逐點做 Dijkstra 
        {
            for (j=1; j<=Num; j++)      // 啟始化動作 
                D[j]=G[i][j], V[j]=0;
            while (1)
            {
                for (j=1, a=0, b=VERY_LONG-1; j<=Num; j++) // 找一個最近的點 
                    if (!V[j]&&D[j]<b) a=j, b=D[j];
                if (a==0||b>Dis) break; // 找不到就離開 
                V[a]=1;
                for (j=1; j<=Num; j++)  // 以該點更新相鄰點的距離 
                    if (!V[j]&&D[a]+G[a][j]<D[j]) D[j]=D[a]+G[a][j];
                if (D[i]<=Dis)          // 若回到原點在限定距離內, 則找到答案 
                {
                    Ans[An++]=i;
                    break;
                }
            }
        }
        printf("%d\n", An);             // 列印答案 
        for (i=0; i<An; i++)
        {
            if (i>0) printf(" ");
            printf("%d", Ans[i]);
        }
        printf("\n");
    }
//    system("PAUSE");
    return 0;
}
