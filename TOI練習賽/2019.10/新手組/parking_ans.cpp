#include <stdio.h>
int main()
{
    int a,b,c;
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i+=1)
    {
        int k=0;
        scanf("%d %d %d",&a,&b,&c);
        for(int j=a+1;j<b;j+=1)
        {
            if(j%c!=0) printf("%d ",j);
            else k+=1;
        }
        if(k==(b-a-1)) printf("No free parking spaces.");
        printf("\n");
    }
}
