#include<stdio.h>

int main()
{
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    for( int i = 0; i < m; ++i )
    {
        int array[105] = {};
        int colored[105] = {};
        int black = 0;

        int start = -1, end = -1;
        for( int j = 0; j < n; ++j )
        {
            scanf("%d", &array[j]);
            if(array[j] == 1)
            {
                black += 1;
                colored[j] = 1;

                if(start == -1) start = j;
                else if(start != -1)
                {
                    end = j;
                    for( int k = start+1; k < end; ++k )
                    {
                        colored[k] = 1;
                    }

                    start = -1;
                    end = -1;
                }
            }
        }

        for( int j = 0; j < n; ++j )
        {
            if(black < 2)
            {
                printf("%d ", array[j]);
            }
            else if(black >= 2)
            {
                printf("%d ", colored[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
