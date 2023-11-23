#include<bits/stdc++.h>
const int sizes=10000005;
char farm[sizes]={};
int main()
{
    int L;
    scanf("%d",&L);
    for(int i=0;i<L;i+=1)
    {
        scanf(" %c",&farm[i]);
    }
    double large=99999999;
    int ind=-1;
    for(int i=1;i<=5;i+=1)
    {
        int range=i*2-1;
        int num=0;
        for(int j=0;j<L;j+=range)
        {
            while(farm[j]=='1' && j<L)
            {
                j++;
            }
            num+=(j<L);
        }
        double money=(1.32*i+1.07)*num;
        if(large>=money)
        {
            large=money;
            ind=i;
        }
    }
    printf("%.2f %d\n",large,ind);
}
