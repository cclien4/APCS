#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long Euclidean(unsigned long long a,unsigned long long b){
		while( a!=0 and b!=0 ){
            if( a >= b )
                a = a%b;
            else if( b > a ) 
                b = b%a;
        }
        if( a >= b )
            return a;
        else
            return b;
}

int main(){
	unsigned long long num[100];
	unsigned long long n,i,j;
	unsigned long long ans,tmp;
	while(cin>>n){
		for(i=0;i<n;i++)
		   cin>>num[i];
		//  scanf("%llu",&num[i]);
		ans=num[0];
		sort(num,num+n);
		
		for(i=1;i<n;i++){
			tmp=Euclidean(num[0],num[i]);
			if(tmp<ans)
				ans=tmp;
		}
//		printf("%llu\n",ans);
		cout<<ans<<endl;
	}

}
