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
	//所有人進入queue 
	for(i=1;i<=n;i++)
	{
		dq.push_back(i); //注意資料結構的塞入 
	}
	it=dq.begin();

	while(dq.size()!=n-k)
	{
		//開始清除
		for(i=0;i<p;i++)
		{
			it++;
			//因為是從1開始數，第一次數扣掉 
			if(flag==0)
			{
				it--;
				flag=1;
			}
			if(it==dq.end())
				it=dq.begin();			
		}
	//	cout<<"清出的是"<<*it<<endl;
			dq.erase(it);
			it--;

	}
	cout<<dq.at(0);
	
}
