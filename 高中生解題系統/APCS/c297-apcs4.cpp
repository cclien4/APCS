#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <math.h>
using namespace std;

int a[10][5];

int bitcount(unsigned int n)
{
   int count = 0 ;
   while (n)
   {
      count++ ;
      n &= (n - 1) ; //關鍵演算之處
   }
   return count ;
}


int compute(int b)
{
	int cnt_b=0;//計算出局數
	int score=0;//計算得分 
	int cnt=0;//計算 壘包的狀態
	unsigned int state=0; 
	int i,j;	//變成直線掃描 
		for(j=0;j<5;j++){
			for(i=0;i<9;i++){ 
				if(a[i][j]==0){ 
					cnt_b++;
					if(cnt_b%3==0){  //把壘包清空 並計算這局得分  
						cnt= bitcount(state>>3);
						state = 0; //清空目前state 
						score = score +cnt; //累加目前得分 
					}
				} 
				else if(a[i][j]==4){
						cnt= bitcount(state);
						state = 0; //清空目前state 
						score = score +cnt+1; //累加目前得分 1是打擊者本身 
				}
				else{   //沒有出局  根據1-4  shift 來計算 
					state=state<<a[i][j];
					state=state+pow(2,a[i][j]-1);		
				} 
				
			//	cout<<"state"<<state<<"score"<<score<<endl;					
				if(cnt_b==b){
					cnt= bitcount(state>>3); //把壘包清空 並計算這局得分 
					score = score +cnt;
					return score;
				}
					
			}
		} 	
}

int main(void){

	int i,j;
	//輸入資料到陣列裡 
	char s[10];
	int n,in,o,b,cnt_b;
	int score;
	while(cin>>in){
	for(i=0;i<9;i++){
		if(i==0)
		   	n=in;
		else
			cin>>n;  //第i局有n個打者 
		for(j=0;j<n;j++){ 
			cin>>s;
			if(s[0]=='H')
				a[i][j]=4;   
			else{
				o=atoi(s);
				a[i][j]=o;
			}
		}
		cout<<endl;
	}
	
	//輸出目前陣列觀看內容	

	cin>>b;  //輸入出局數 
    score=compute(b);
	cout<<score<<endl;
	}
	return 0;
}











