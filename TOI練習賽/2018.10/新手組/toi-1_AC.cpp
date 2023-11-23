#include<iostream>
#include<cmath>
using namespace std;
bool prime[1000000];
void rett()
{
    for (int i=0; i<1000000; i++)
        prime[i] = true;
 
    prime[0] = false;
    prime[1] = false;
 
    // 只需要刪掉sqrt(20000000)以下的質數的倍數。
    int xx=sqrt(1000000);
    for (int i=2; i<=xx; i++)
        if (prime[i])
            for (int k=(1000000-1)/i, j=i*k; k>=i; k--, j-=i)
                if (prime[k])
                    prime[j] = false;
}


int main()
{
	int n,a,b;
	int count=0;
	rett();
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			for(int i=a;i<=b;i++)
			{
				if(prime[i])
				count++;
			}
			cout<<count<<"\n";
			count=0;
		}
	}
	
	
	
	
	
}

