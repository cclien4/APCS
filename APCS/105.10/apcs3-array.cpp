#include <iostream>
#include "memory.h"
#define x 100
using namespace std;

int main(void)
{
	bool arr_f[x];
	int i,B_times;  //�p���z�����ƻP���A 
	int n,k,p;   //�ϥΪ̿�J�Ѽ� 
	int cnt_p,cnt_k; //�p����лP�˼�p time 
	//memset(arr_f,0,sizeof(arr_f));
	for(i=0;i<x;i++)
	    arr_f[i]=0;
	
	cin>>n>>p>>k;
	cnt_p=0;  //counter p
	cnt_k=0;  //  next bomb
	B_times=0; //bomb times
	while(B_times!=k)  //bomb  k times
	{
		if(arr_f[cnt_k]==0)
		{
			cnt_p++;
			if(cnt_p==p) //�p�ƨ�0���H  �ƨ�p���F 
			{
				arr_f[cnt_k]=1;
			//	cout<<"bomb"<<cnt_k<<endl;
				B_times++;//�z���F�Aflag+1 
				cnt_p=0;//�z�����A���s�p�� 
			}
        }
		cnt_k++;//���Ф@�����U�� 
        if(cnt_k==n)
          cnt_k=0; 
	}
	
	while(arr_f[cnt_k]!=0)  //���S���z�����U�@�ӤH 
		cnt_k++;
	
//	for(i=0;i<n;i++)
//		cout<<arr_f[i];
	cout<<cnt_k+1;  //array�q0�}�l  �ҥH+1���X 
	
	   system("pause");
	return 0;
}
