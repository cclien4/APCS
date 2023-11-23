#include <iostream> 
#include <algorithm>
using namespace std;


int main()
{
	int N,M,IN[20],OUT[20],i,j,k;
	int ans,ao[20],flag=0;  //flag為了讓最後別有空白   和輸出-1 
	cin>>N>>M;
	j=0;
	k=0;
	while(N>k)
	{
		for(i=0;i<M;i++)
		{
			cin>>IN[i];
		}
		sort(IN,IN+i);
		OUT[j]=IN[i-1];
		k++;
		j++;
	}
	for(i=0;i<N;i++) 
		cout<<OUT[i]<<endl;/*
	ans=0;
	for(i=0;i<N;i++)  //compute out array sum
		ans=ans+OUT[i];
    cout<<ans<<endl;
    for(i=0;i<N;i++)  //output 
    {
		if(ans%OUT[i]==0)
    	{
    		if(flag==1) cout<<" ";
    		flag=1;
    		cout<<OUT[i];
		}
	}
	if(flag==0)
		cout<<"-1";*/
	return 0;
	
}
