#include<bits/stdc++.h>
std::vector<int> v;
int SG[2000005]={};
void get_sg()
{
    int visit=1;
    for(int i=0;i<2000005;i+=1)
    {
        for(int j=0;j<(int)v.size();j+=1)
        {
            if(v[j]>i) break;
            else if(SG[i-v[j]]==0)
            {
                SG[i]=1;
                break;
            }
        }
        if(!visit)
        {
            SG[i]=1;
        }
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    while(a--)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    std::sort(v.begin(),v.end());
    get_sg();
    int T;
    scanf("%d",&T);
    int x;
    while(T--)
    {
        scanf("%d",&x);
        if(SG[x]==0) printf("Lose\n");
        else printf("Win!\n");
    }
}


