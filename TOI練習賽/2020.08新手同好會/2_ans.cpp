#include<stdio.h>
using namespace std;
int main()
{
    int archerX, archerY, archerlevel, range;
    scanf("%d%d%d%d", &archerX, &archerY, &archerlevel, &range);
    int num;
    scanf("%d", &num);
    int sum=0;
    for(int i=0; i<num; ++i)
    {
        int x, y, level;
        scanf("%d%d%d", &x, &y, &level);
        int distance = (archerX-x)*(archerX-x)+(archerY-y)*(archerY-y);
        if(distance <= range*range)
        {
            if(level <= archerlevel)
            {
                sum+=1;
            }
        }
    }
    printf("%d\n", sum);
}
