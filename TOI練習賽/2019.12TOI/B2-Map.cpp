#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    int arr1[101][101]={};
    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    int arr2[101][101]={};
    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            scanf("%d",&arr2[i][j]);
        }
    }

    int sum=0;
    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            sum=0;
            for(int a=0;a<n;a+=1)
            {
                sum+=arr2[a][j];
            }
            for(int b=0;b<m;b+=1)
            {
                sum+=arr2[i][b];
            }
            sum-=arr2[i][j];
            if(sum%2!=0)
            {
                if(arr1[i][j]==0) arr1[i][j]=1;
                else if(arr1[i][j]==1) arr1[i][j]=0;
            }
        }
    }

    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
}
