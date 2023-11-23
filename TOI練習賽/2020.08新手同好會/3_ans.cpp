#include<stdio.h>

int main()
{
    int N=0,M=0;
    scanf("%d%d",&N,&M);
    int S=0,E=0;
    int temp[500]={};
    for(int i=0;i<M;++i)
    {
        scanf("%d %d",&S,&E);
        for(int j=S;j<E;++j)
        {
            temp[j]=1;
        }
    }
    for(int i=0;i<N;++i)
    {
        if(temp[i]==0)
        {
            int counter=1;
            int index=i;
            while(temp[index+1]==0&&index+1<N)
            {
                counter+=1;
                temp[index+1]=1;
                index+=1;
            }
            printf("%d %d\n",i,i+counter);
        }
    }
}
