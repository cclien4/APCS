#include<stdio.h>

int main()
{
    int num=0;
    int maximum=-10,ans=0;
    scanf("%d",&num);
    while(num)
    {
        int temp=num;
        if(temp%7==0)
        {
            temp=temp%70+5000000;
        }
        else
        {
            temp=77-temp%77;
        }
        if(temp>maximum&&temp!=0)
        {
            maximum=temp;
            ans=num;
        }
        scanf("%d",&num);
    }
    printf("%d\n",ans);
}
