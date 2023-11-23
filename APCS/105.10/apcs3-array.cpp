#include <iostream>
#include "memory.h"
#define x 100
using namespace std;

int main(void)
{
	bool arr_f[x];
	int i,B_times;  //計算爆炸次數與狀態 
	int n,k,p;   //使用者輸入參數 
	int cnt_p,cnt_k; //計算指標與倒數p time 
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
			if(cnt_p==p) //計數到0的人  數到p次了 
			{
				arr_f[cnt_k]=1;
			//	cout<<"bomb"<<cnt_k<<endl;
				B_times++;//爆炸了，flag+1 
				cnt_p=0;//爆炸完，重新計算 
			}
        }
		cnt_k++;//指標一直往下找 
        if(cnt_k==n)
          cnt_k=0; 
	}
	
	while(arr_f[cnt_k]!=0)  //找到沒有爆炸的下一個人 
		cnt_k++;
	
//	for(i=0;i<n;i++)
//		cout<<arr_f[i];
	cout<<cnt_k+1;  //array從0開始  所以+1後輸出 
	
	   system("pause");
	return 0;
}
