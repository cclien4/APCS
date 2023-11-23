#include<bits/stdc++.h>
int arr[1000005]={};
int DP[1000005]={};
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i+=1)
    {
        scanf("%d",&arr[i]);
        if(i<2) DP[i]=arr[i];
        else if(i==2) DP[i]=arr[0]+arr[2];
        else DP[i]=max(DP[i-2]+arr[i],DP[i-3]+arr[i]);
    }
    printf("%d\n",max(DP[N-1],DP[N-2]));
}
