#include <stdio.h>
int main()
{
    int n=0,k=0,tmp=0;
    scanf("%d",&n);
    while(tmp<n)
    {
        k+=1;
        int s=k*4;
        tmp+=s;
        if(tmp>=n)
        {
            tmp-=s;
            break;
        }
    }
    int ans=n-tmp-1;
    ans/=k;
    if(ans==0) printf("Pen");
    else if(ans==1) printf("Pineapple");
    else if(ans==2) printf("Apple");
    else if(ans==3) printf("Pineapple pen");
}
