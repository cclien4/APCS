#include <iostream>
using namespace std;

int main(void){
	int S[100][100];
	int i,j,k;  //array use
	int R,C,N;
	int temp;
	//ARRAY SET 
	cin>>R>>C>>N;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			S[i][j]=0;
	//intput array
	k=1;
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			S[i][j]=k;
			k++;
		}
	}
	//compute array 
	for(k=2;k<=N;k++){
		if(k%2==0){ //right shift
			if(C>=2){
				for(i=0;i<R;i++){
                    temp=S[i][C-1];
				for(j=C-1;j>0;j--){
					S[i][j]=S[i][j-1];
				}
				    S[i][0]=temp;
				}
			}
				
			
		}else{  //back shift
			if(R>=2){
				for(i=0;i<C;i++){
					temp=S[R-1][i];
				for(j=R-1;j>0;j--){
					S[j][i]=S[j-1][i];
				}
					S[0][i]=temp;
				}//FOR
			}//R
			
		} //ELSE
	}//FOR
	
	//output array
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(j==(C-1))
				cout<<S[i][j];
			else
				cout<<S[i][j]<<" ";
		}
		cout<<endl;
	}
		
//	system("pause");
}
