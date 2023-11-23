#include <iostream>
#include <set>
#include <math.h>
using namespace std;

const int N = 100;      // ���~�`�ƤW��
const int W = 100000;   // �I�]�@���W��
                        //�]�i�H�ϥΪ��~���`���q�@�����ȡ^
int cost[N], weight[N]; // ���~�����ȻP���q
int c[N + 1][W + 1];    // DP���

// n�����~�ӼơAw���I�]�@������C
int knapsack(int n, int w)
{
    if (w < 0) return -1e9; // �@����O�����A�G�u�ण��C
    if (n == 0) return 0;   // �S�����~�ɡA�N�S��cost�C

    // memoization�A����Ū���O���骺���סC
    if (c[n][w]) return c[n][w];

    // ���j�D�o�p���D������
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
