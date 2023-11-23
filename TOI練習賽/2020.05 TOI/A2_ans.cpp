#include<stdio.h>
int main()
{
	int a[3]={},b[5]={},c[5]={};
	for(int i=0;i<3;i+=1)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<5;i+=1)
	{
		scanf("%d",&b[i]);
	}
	for(int i=0;i<5;i+=1)
	{
		scanf("%d",&c[i]);
	}
	int ans=0;
	for(int i=0;i<2;i+=1)
	{
		for(int j=0;j<5;j+=1)
		{
			if(a[i]==b[j])
			{
				ans+=c[j];
			}
		}
	}
	int flag=0;
	for(int i=2;i<3;i+=1)
	{
		for(int j=0;j<5;j+=1)
		{
			if(a[i]==b[j])
			{
				ans-=c[j];
				flag=1;
			}
		}
		if(ans<0)
		{
			ans=0;
		}
	}
	if(flag==0)
	{
		printf("%d\n",ans*2);	
	}
	else
	{
		printf("%d\n",ans);
	}
}
