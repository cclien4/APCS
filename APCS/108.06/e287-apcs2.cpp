#include <iostream>
#include <algorithm>
using namespace std;

int arr[100][100];
bool arrf[100][100];
int c[4];
//0 UP 1 DOWN 2 LEFT 3 RIGHT  4 error
int comparr(int i,int j,int n,int m){
	int a1,a2,a3,a4;
	if(i-1<0) c[0]=9999999; else
	c[0] = arrf[i-1][j] ? 9999999 : arr[i-1][j];   //give data  i,j -1
	if(i+1==n) c[1]=9999999; else
	c[1] = arrf[i+1][j] ? 9999999 : arr[i+1][j];
	if(j-1<0) c[2]=9999999; else
	c[2] = arrf[i][j-1] ? 9999999 : arr[i][j-1];
	if(j+1==m) c[3]=9999999; else
	c[3] = arrf[i][j+1] ? 9999999 : arr[i][j+1];
	sort(c,c+4);
/*	for(int k=0;k<4;k++){
		cout<<"cb:"<<c[k];
	}
	
	cout<<endl;
	for(int k=0;k<4;k++){
		cout<<"cf:"<<c[k];
	}*/
	//cout<<"c0:"<<c[0]<<endl;
	if(c[0]==9999999 )
		return 4;
	else if(c[0]==arr[i-1][j])
		return 0;
	else if(c[0]==arr[i+1][j])
		return 1;
	else if(c[0]==arr[i][j-1])
		return 2;
	else if(c[0]==arr[i][j+1])
		return 3;
}

int main(void){
	int n,m;
	int i,j;
	int min=99999999;
	int mini,minj;
	int sum=0;
	int dir;
	while(cin>>n>>m){
		sum=0;

			
		//input array  and mem min[i][j]
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>arr[i][j];
				if(min > arr[i][j]){
					min=arr[i][j];
					mini=i;
					minj=j;
				}
			}
		}
		//=========compare array=============//
	//	while(){
	//0 UP 1 DOWN 2 LEFT 3 RIGHT  4 error
		i=mini;
		j=minj;
		arrf[i][j]=1;
		do{
			dir=comparr(i,j,n,m);
			sum=sum+arr[i][j];
			if(dir==0){
				arrf[i-1][j]=1;  //arrf  give data ==> i+1 j+1
				i=i-1;
				j=j;
			}else if(dir==1){
				arrf[i+1][j]=1;
				i=i+1;
				j=j;
			}else if(dir==2){
				arrf[i][j-1]=1;
				i=i;
				j=j-1;
			}else if(dir==3){
				arrf[i][j+1]=1;
				i=i;
				j=j+1;
			}
			//	cout<<dir<<endl;;
		}while(dir!=4);
		cout<<sum<<endl;
	//	}
		
		//=========compare array=============//
		//cout<<mini<<minj<<endl;
		
	}
	
	return 0;
	
}
