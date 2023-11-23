#include <cstdio>
#include <iostream>
using namespace std;
int main(void)        /*高精度?算?乘C++代?，含?乘?果位?及末尾0?量??*/
{
  unsigned long c=100000,i=0,j=0,k,M=0,N;
  cout<<"n!(不超?40000):",cin>>N;  
  long *a=new long [k=N];
  for(*a=1;++i<N;k?j+=(k/=5):0)a[i]=0;
  for(;N;j?a[++M]=j:0,N--)for(i=j=0;i<=M;i++)a[i]=(j+=a[i]*N)%c,j/=c;
      for(j=a[M],cout<<M*5+(j>9999?5:j>999?4:j>99?3:j>9?2:1)<<endl<<j;M;)printf("%05ld",a[--M]);
  delete []a;
  cin.ignore(),cin.ignore();
  return 0;
}
