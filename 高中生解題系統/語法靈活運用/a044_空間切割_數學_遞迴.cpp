/*http://blog.xuite.net/yamtsl2000/twblog/
122401413-%E7%9B%B4%E7%B7%9A%E5%88%86%E5%8
9%B2%E5%B9%B3%E9%9D%A2%E3%80%81%E5%B9%B3%E
9%9D%A2%E5%88%86%E5%89%B2%E7%A9%BA%E9%96%9
3%E5%85%AC%E5%BC%8F%E7%9A%84%E6%8E%A8%E5%B0%8E*/


//相異n個平面==>切割成C(n+1,3)+n+1個區域
//C(n,m)的算法=n! / (m!(n-m)!)  n>m
/*
此作法，會產生溢位問題 

#include <iostream>
#include <math.h>
using namespace std;
long factorial(long n)
{
    if(n == 1)
        return 1;
    else
        return n * factorial(n - 1) ;
}

int main(void)
{
	unsigned long long int c = 0;

   
    unsigned long long n;
	while(cin>>n)
	{
	  if(n==0 || n==1)
	     c=0;
	  else if(n==2)
	     c=1;
	  else
	  	 c = factorial(n+1) / (factorial(3) * factorial(n - 2));

	   cout<<c+n+1<<endl;
	}
	//system("pause");
	return 0;
}

*/


#include <iostream>
using namespace std;

int main() {
//(1+n)(n平方-n+6)/6 
int n;
while(cin>>n){
cout<<(1+n)*(n*n-n+6)/6<<endl;
}
return 0;
}


