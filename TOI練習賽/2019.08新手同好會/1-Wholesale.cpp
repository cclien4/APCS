#include <stdio.h>
int main()
{
    int M=0,T=0;
    scanf("%d",&M);
    while(scanf("%d",&T) && T!=0)
    {
        if(T%M==0) printf("%d\n",T/M);
        else printf("%d\n",M-(T%M));
    }
}
