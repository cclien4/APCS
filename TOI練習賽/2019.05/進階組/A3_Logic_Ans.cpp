#include<bits/stdc++.h>
int num[1000005];
int check[1000005];
struct Instructs
{
    int op,p,q;
};
void Print(int p, std::vector<Instructs> &ins)
{
    int &n=num[p];
    if(!check[p])
    {
        int len=ins.size();
        for(int i=0; i<len; i++)
        {
            if(p%ins[i].p==0)
            {
                int op=ins[i].op;
                if(op==2)
                    n &= ins[i].q;
                else if (op==3)
                    n |= ins[i].q;
                else
                    n ^= ins[i].q;
            }
        }
        check[p]=1;
    }
    printf("%d\n",n);
}
int main()
{
    memset(check, 0, sizeof(check));
    int N;
    scanf("%d", &N);
    std::vector<Instructs> ins;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &num[i]);
    }
    int op;
    while(scanf("%d", &op)!=EOF&&op!=0)
    {
        if(op==1)
        {
            int p;
            scanf("%d", &p);
            Print(p, ins);
        }
        else
        {
            Instructs temp;
            temp.op=op;
            scanf("%d%d", &temp.p,&temp.q);
            ins.push_back(temp);
        }
    }
}
