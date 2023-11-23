#include<bits/stdc++.h>
using namespace std;
int bintodec(char s[])
{
    int re=0;
    int base=1;
    for(int i=strlen(s)-1; i>=0; i-=1)
    {
        re+=(base*(s[i]=='1'));
        base=base<<1;
    }
    return re;
}
bool visit[1200000]= {};
int main()
{
    int N;
    scanf("%d",&N);
    int num[50005]= {};
    for(int i=0; i<N; i+=1)
    {
        char s[25]= {};
        scanf("%s",s);
        num[i]=bintodec(s);
    }
    char ans[30]= {};
    scanf("%s",ans);
    int goal=bintodec(ans);
    vector<int> v;
    bool found=false;
    for(int i=0; i<N; i+=1)
    {
        if(found) break;
        int len=v.size();
        for(int j=0; j<len; j+=1)
        {
            if(num[i]+v[j]>goal) continue;
            else if(num[i]+v[j]==goal)
            {
                found=true;
                break;
            }
            if(!visit[num[i]+v[j]])
            {
                visit[num[i]+v[j]]=true;
                v.push_back(num[i]+v[j]);
            }
        }
        if(!visit[num[i]] && num[i]<=goal)
        {
            visit[num[i]]=true;
            v.push_back(num[i]);
            if(num[i]==goal)
            {
                found=true;
            }
        }
    }
    char print[2][20]={"NO","YES"};
    printf("%s\n",print[found]);
}
