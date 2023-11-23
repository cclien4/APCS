#include<stdio.h>

int main()
{
    int N = 0;

    scanf("%d",&N);
    int area = 0, row = 0, num = 0;
    if(N >= 1 && N <= 2500)
    {
        area = 1;
        
        if(N%25 == 0)
        {
            row = N/25;
            num = 25;
        }
        else
        {
            row = N/25 + 1;
            num = N % 25;
        }           
    }
    else if(N > 2500 && N <= 7500)
    {
        area = 2;
        
        if((N-2500)%50 == 0)
        {
            row = (N-2500)/50;
            num = 50;
        }
        else
        {
            row = (N-2500)/50 + 1;
            num = N % 50;
        }
    }
    else if(N > 7500 && N <= 10000)
    {
        area = 3;
        
        if((N-7500)%25 == 0)
        {
            row = (N-7500)/25;
            num = 25;
        }
        else
        {
            row = (N-7500)/25 + 1;
            num = N % 25;
        }
    }

    printf("%d %d %d\n", area, row, num);

    return 0;
}
