#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	vector <int> dq;
	vector <int>::iterator it;
	int a,n,p,i,reg_it;
    int flag=0,k;
	cin>>n>>p>>k;
	//�Ҧ��H�i�Jqueue 
	for(i=1;i<=n;i++)
	{
		dq.push_back(i); //�`�N��Ƶ��c����J 
	}
	it=dq.begin();

	while(dq.size()!=n-k)
	{
		//�}�l�M��
		for(i=0;i<p;i++)
		{
			it++;
			//�]���O�q1�}�l�ơA�Ĥ@���Ʀ��� 
			if(flag==0)
			{
				it--;
				flag=1;
			}
			if(it==dq.end())
				it=dq.begin();			
		}
	//	cout<<"�M�X���O"<<*it<<endl;
			dq.erase(it);
			it--;

	}
	cout<<dq.at(0);
	
}
