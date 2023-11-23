#include <iostream>
#include <math.h>
using namespace std;


int main(void)
{
	int n,m,j,total=0;
	int i,cmt,cmt_a[100];
	int cnt_a=0,flag=0;
	while(cin>>n>>m)
	{
		flag=0;
		for(i=n;i<=m;i++)
		{
			cmt=i;
			total=0;
			cnt_a=0;
			//把i的值做拆解，並且放入陣列裡 
			while(cmt!=0)
			{
				cmt_a[cnt_a]=cmt%10;
				cmt=cmt/10;
				cnt_a++;
			}
			//開始判斷是否為阿姆斯壯數 
			for(j=0;j<cnt_a;j++)
			{
				total=total+pow(cmt_a[j],cnt_a);
			}
			
			if(i==total)
		    {
			   cout<<i<<" ";
			   flag=1;
		    }
		}
		
		if(flag == 0)
		    cout<<"none";
		cout<<endl;
		
	}
}
