#include <iostream>
#include <math.h> 
using namespace std;
int main(void){
	int N,F;  //題目需求變數 
	int i,j; //
	int y[10],r[10];//y為玩家出的N拳  r為機器人出的N次拳  N<11
	bool flag;
	while(cin>>F>>N){ 
		//input 人出的拳 
		for(i=0;i<N;i++){
			cin>>y[i];
		}
		//input 機器人出的拳  flag紀錄次數 
		r[0]=F;
		r[1]=y[0];
		flag=0;
		for(i=2;i<N;i++){
			if(y[i-1]==y[i-2]){
				//變成獲勝的拳
				if(y[i-1]==0)
				   	r[i]=5;
				else if(y[i-1]==2)
					r[i]=0;
				else
					r[i]=2;
			}	
			else
				r[i]=y[i-1];
		} 
		//compare 兩邊的拳
		for(i=0;i<N;i++){
			if(y[i]!=r[i]){ //當不相同的時候 必有獲勝或輸 
				if( (y[i]==0 && r[i]==2) || (y[i]==2 && r[i]==5) || (y[i]==5 && r[i]==0) ){ //0 win 2  2  win 5  5 win 0
					for(j=0;j<=i;j++)
						cout<<r[j]<<" "; 
				    cout<<": Lost at round "<<i+1<<endl;
				}else{
					for(j=0;j<=i;j++)
						cout<<r[j]<<" "; 
				    cout<<": Won at round "<<i+1<<endl;
				} 
				break;
			} 
		}
		if(i==N){  //表示平手 
			for(j=0;j<i;j++)
				cout<<r[j]<<" "; 
			cout<<": Drew at round "<<i<<endl;
		} 
		 
	}//while 
} 
