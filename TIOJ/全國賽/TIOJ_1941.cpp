#include <iostream>
#include <vector>
#include<stdio.h>  
#include<string.h>
#include <algorithm>
#define endmax 800000
using namespace std;
int main(){
//	vector<int> vec;
	int a[endmax];
	/*for(int i=0; i<800000;i++) {
	vec.push_back(0);
	}*/
	int i,j,n,st,end=-1,reg_end,max;
	while(scanf("%d",&n)!=EOF){
		//cout<<vec.size();
		memset(a,0,sizeof(a));
			for(j=0;j<n;j++){
				reg_end=end;
				cin>>st>>end;
				if(end>reg_end){
					max=*max_element(a,a+end+1);
			     //	cout<<"regend"<<reg_end<<"max"<<max<<endl;
				   	for(i=reg_end;i<=end;i++){
						a[i]=max;
					}
					for(i=st;i<=end;i++){
					a[i]=a[i]+1;
					}
				}else{
					for(i=st;i<=end;i++){
					a[i]=a[i]+1;
					}
				}
				//	for(i=0;i<=4;i++){
				//	cout<<a[i];
			//	}
				

		}
			max=*max_element(a,a+800000);		
			cout<<max;
	}
     return 0;
}
