#include <iostream>
#include <set>
#include <math.h>
using namespace std;

const int N = 100;      // 物品總數上限
const int W = 100000;   // 背包耐重上限
                        //（可以使用物品的總重量作為此值）
int cost[N], weight[N]; // 物品的價值與重量
int c[N + 1][W + 1];    // DP表格

// n為物品個數，w為背包耐重限制。
int knapsack(int n, int w)
{
    if (w < 0) return -1e9; // 耐重能力不足，故只能不放。
    if (n == 0) return 0;   // 沒有物品時，就沒有cost。

    // memoization，直接讀取記憶體的答案。
    if (c[n][w]) return c[n][w];

    // 遞迴求得小問題的答案
    return c[n][w] = max(
        knapsack(n-1, w-weight[n]) + cost[n],
        knapsack(n-1, w)
    );
}


int main(){
	int x,n,s;
	int ans,sum;
	cin>>x>>n>>s;
	for(int i=0;i<x;i++){
		cin>>cost[i];
		weight[i]=cost[i];
	}
	sum=0;
	ans=knapsack(x,n-s);
	for(int i=0;i<x;i++)

	cout<<ans;
}
