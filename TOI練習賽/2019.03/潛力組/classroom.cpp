#include<bits/stdc++.h>
#define SIZE 10000005
int arr[SIZE]= {};
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i+=1)
    {
        int T1, T2;
        scanf("%d%d",&T1, &T2);
        arr[T1]+=1;
        arr[T2]-=1;
    }
    int ans=1, now=0; // at least one classroom
    for(int i=0; i<SIZE; i+=1)
    {
        now+=arr[i];
        ans=std::max(ans, now);
    }
    printf("%d\n",ans);
}
