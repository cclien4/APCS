#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int n,k;
	cin>>n>>k;
	int i,ptr[n],d[n];
	for(i=0;i<n;i++)
	   cin>>ptr[i];
	
	sort(ptr,ptr+n); //±Æ§Ç¸ê®Æ 
	for(i=1; i<n; i++) d[i] = ptr[i] - ptr[i-1];
	//for(i=0;i<n;i++)
//	   cout<<ptr[i];
	
	int low = 0, high = 1000000000;
	while(low <= high) {
			
			int mid = (low+high) / 2;
			int sum = 0, use = 0;
			for(i=1; i<n; i++) {
			if(sum+d[i] < mid) sum += d[i];
				else {
					use++;
					sum = 0;
				}
			}
			if(use < k) high = mid - 1;
			else low = mid + 1;
		}
		cout<<high;
	system("pause");
	
	return 0;
} 
