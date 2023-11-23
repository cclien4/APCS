#include <iostream>
using namespace std;
int main(void){
    int A[100][100];
    int m,n;
    int i,j;
    int L_flag,R_flag,L,R;
    int z;
    cin>>m>>n;
        //reset array
    for(i=0;i<100;i++)
		for(j=0;j<100;j++)
      		A[i][j]=0;
    
    //input array
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	L_flag=0;
	L=0;
	// scan
	
	for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		//found 1
			if(A[i][j]==1){
				if(L_flag==0){
					L_flag=1;
					L=j;
					cout<<i<<"  WAIT 1 :L ¦ì¸m "<<L<<endl; 
				}else{//flag 1
					for(z=L;z<=j;z++)
						A[i][z]=1;
					//reset
					cout<<i<<"FINISH :R ¦ì¸m "<<j<<endl;
					L_flag=0;
					L=0;
				}
			}
		}
			L_flag=0;
			L=0;
	}
	//output array
	for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
       system("pause");
    
}
