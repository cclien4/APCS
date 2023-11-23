#include<stdio.h>
using namespace std;
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int pizza = M*8;
    if(pizza < N*2)
    {
        printf("Not enough\n");
    }
    else if(pizza > N*3)
    {
        printf("Too much\n");
    }
    else
    {
        printf("yes\n");
    }
}
