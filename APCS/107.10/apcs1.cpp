#include <iostream>
using namespace std;

int main(){
	int m[10];
	int n,i,j;
	int max,a,a_cnt;  //a���W��  ,a_cnt���̰���������  max���̰�����
	int m_cnt;//�p������`�M
	while(cin>>n){
		m_cnt=0;
		a_cnt=0;
		for(i=0;i<n;i++){ //�@�@��J�X��
			max=0;
			cin>>a;
			for(j=0;j<10;j++){   //��J�������}�C
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
