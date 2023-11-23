#include <stdio.h>
int main()
{
    int Sum[1001] = {0};
    int maxPower = 0;  //record the max power in input
    for(int i=0;i<2;i+=1)
    {
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j+=1)
        {
            int Power,Coef;
            scanf("%d %d",&Power, &Coef);
            Sum[Power] += Coef;
            if(Power > maxPower) maxPower = Power;
        }
    }
    bool Check = false; //check if there is no item
    for(int i=maxPower;i>=0;i-=1)
    {
        if(Sum[i] != 0)
        {
            printf("%d:%d\n",i,Sum[i]);
            Check = true;
        }
    }
    if(Check == false) printf("NULL!");

    return 0;
}
