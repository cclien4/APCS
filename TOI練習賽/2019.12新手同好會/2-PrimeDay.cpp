#include <stdio.h>
#include <math.h>
int main()
{
    int D = 0;
    int N = 0, M = 0;
    scanf("%d", &D);
    for(int i = 0; i < D; i += 1)
    {
        scanf("%d", &N);
        M = N;
        int Digit = 10000000;
        bool Check = true;
        while(M > 0)
        {
            for(int j = 2; j <= sqrt(M); j += 1)
            {
                if(M % j == 0)
                {
                    Check = false;
                    break;
                }
            }
            if(Check == false) break;
            M %= Digit;
            Digit /= 10;
        }
        if(Check == true) printf("%d is a Prime Day!\n", N);
        else printf("%d isn't a Prime Day!\n", N);
    }
}
