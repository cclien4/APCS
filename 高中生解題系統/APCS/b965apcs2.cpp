#include <iostream>
#include <algorithm>
using namespace std;


int after[10][10]; //最後的陣列 
int before[10][10]; //before

void Overturn(int R,int C)
{
	int temp;
	for(int i=0;i<(R/2);i++)
	{
		for(int j=0;j<C;j++)
		{
			temp=after[i][j];
			after[i][j]=after[R-1-i][j];
			after[R-1-i][j]=temp;
		}
	}
}

void rotation(int R,int C)
{
	//------進行轉矩陣動作 ----------
	for(int i=0;i<C;i++)
	{
		for(int j=0;j<R;j++)
		{
			before[i][j]=after[j][C-1-i];
		}
	}
	//-------進行旋轉後的給值---------
	for(int i=0;i<C;i++)
	{
		for(int j=0;j<R;j++)
		{
			after[i][j]=before[i][j];
		}
	}
	 
}
int main()
{

	int R,C,M; 		//輸入的陣列及操作 
	int max=0,min=0;		
	//scanf("%d %d %d",&R,&C,&M);
	while(cin>>R>>C>>M){
	
		int otrt[10];//Overturn and rotation
		int count_m0=0,flag=0;//用在rotation判別 
		//輸入陣列內容 
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
			//	scanf("%d",&after[i][j]);
			    cin>>after[i][j];
			}
		}
		//輸入指令內容
		for(int i=0;i<M;i++){
		//	scanf("%d",&otrt[i]);
		    cin>>otrt[i];
			if(otrt[i]==0)
				count_m0++;
		}
		
		//進行旋轉或是翻轉的判別
		for(int i=M-1;i>=0;i--)
		{
			if(otrt[i]==1 && flag==0){
				Overturn(R,C);
			}
			else if(otrt[i]==1 && flag==1){
				Overturn(C,R);
			}
			else if(otrt[i]==0 && flag==0){
				rotation(R,C);
				flag=1;
			}
			else{
				rotation(C,R);
				flag=0;
			}
				
		} 
		
		if(count_m0==0 || count_m0%2==0){
		    cout<<R<<" "<<C<<endl;
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					if(j!=C-1)
				        cout<<after[i][j]<<" ";
				    else
				        cout<<after[i][j];
				}
				if(i!=R-1)
	           	   cout<<endl;    	   
			}
		}
		else
		{
		      cout<<C<<" "<<R<<endl;
			for(int i=0;i<C;i++){
				for(int j=0;j<R;j++){
					if(j!=R-1)
				        cout<<after[i][j]<<" ";
				    else
				        cout<<after[i][j];
				}
				if(i!=C-1)
				cout<<endl;
			}
		}
       cout<<endl;
	}
	return 0;
}
