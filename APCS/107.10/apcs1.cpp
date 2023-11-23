#include <iostream>
using namespace std;

int main(){
	int m[10];
	int n,i,j;
	int max,a,a_cnt;  //a為名次  ,a_cnt為最高獎金次數  max為最高獎金
	int m_cnt;//計算獎金總和
	while(cin>>n){
		m_cnt=0;
		a_cnt=0;
		for(i=0;i<n;i++){ //一共輸入幾屆
			max=0;
			cin>>a;
			for(j=0;j<10;j++){   //輸入獎金的陣列
				cin>>m[j];
				if(m[j]>max)
					max=m[j];
			}
			m_cnt=m_cnt+m[a-1];
			if(m[a-1]==max)
			   a_cnt++;
		}
		
		cout<<m_cnt<<endl<<a_cnt<<endl;
		
	}
	return 0;
}
