#include <iostream>
using namespace std;
int f(int n)
{
    if(n==1)
        return 1;
    else
        return n+f(n-1);
}

long long g(int n)
{
    if(n==1)
        return 1;
    else
        return f(n)+g(n-1);
}


int main(void)
{
    int n;
    //int a,b;
    unsigned long long int a,b;
    while(cin>>n)
    {
             a=f(n);
             b=g(n);
             cout<<a<<" "<<b<<endl;    
    }  
    
}
/*
如果計算時間太長時，可以以下這樣做 

const int maxn = 30010 ;
int f[maxn] ;
long long g[maxn] ;

int main(){
	//build f[] ,g[] ---------------------
	f[1]=g[1]=1 ;
	for (int i=2 ;i<maxn ;i++ ){
		f[i] = i + f[i-1] ;
	}
	for (int i=2 ;i<maxn ;i++ ){
		g[i] = f[i] + g[i-1] ;
	}

	//solve ------------------------------
	int n ;
	while ( cin >> n ){
		cout << f[n] << " " << g[n] << endl ;
	}
}*/
