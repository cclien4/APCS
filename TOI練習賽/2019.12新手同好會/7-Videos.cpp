#include<stdio.h>
#include<string.h>

int main()
{
    int N=0;
    scanf("%d",&N);

    char name[51][16]= {};
    double Recommend[51]={};
    for(int i=0; i<N; i+=1)
    {
        scanf("%s",name[i]);

        int Watch_people = 0, Relative = 0;
        int Video_length = 0, avg_watchtime = 0;
        scanf("%d %d %d %d", &Watch_people, &Video_length, &avg_watchtime, &Relative );

        double avg = (double)avg_watchtime/Video_length;
        Recommend[i] = Watch_people * avg * Relative;
    }

    bool tmp[51]={};
    for(int i=0; i<N; i+=1)
    {
        double Max_val = 0;
        int Max_pos = 0;
        {        for(int j=0; j<N; j+=1)

            if( tmp[j] == false )
            {
                if( Recommend[j] > Max_val ){
                    Max_val = Recommend[j];
                    Max_pos = j;
                }
            }
        }
        printf("%s\n", name[ Max_pos ]);
        //printf("[%f]\n",Max_val);
        tmp[ Max_pos ] = true;
    }
}
