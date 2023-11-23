#include <stdio.h>
int main()
{

    double Period_Rain[4] = {};
    double Week_Rain[7] = {};
    for (int i=0; i<7; i+=1)
    {
        double DailyRain = 0;
        for (int j=0; j<4; j+=1)
        {
            double rain = 0;
            scanf("%lf",&rain);

            Period_Rain[j] += rain;
            DailyRain += rain;
        }
        Week_Rain[i] = DailyRain;
    }

    int max_RainDay = 0;
    double max_RainVal = 0;
    for (int i=0; i<7; i+=1)
    {
        if( Week_Rain[i] > max_RainVal ){
            max_RainVal = Week_Rain[i];
            max_RainDay = i+1;
        }
    }
    printf("%d\n", max_RainDay);

    int max_RainPeriod = 0;
    double max_RainPeriodVal = 0;
    for (int i=0; i<4; i+=1)
    {
        if ( Period_Rain[i] > max_RainPeriodVal ){
            max_RainPeriodVal = Period_Rain[i];
            max_RainPeriod = i;
        }
    }
    if(max_RainPeriod == 0)
        printf("morning\n");
    else if(max_RainPeriod == 1)
        printf("afternoon\n");
    else if(max_RainPeriod == 2)
        printf("night\n");
    else if(max_RainPeriod == 3)
        printf("early morning\n");

}
