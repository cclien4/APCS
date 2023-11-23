#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


int i,j;
void array_move(int);
int main(void)
{
    int n;
    int x,y;
    int a[50][50],dir=0;
    int cnt;//count out 幾次   因為沒有ac是多個0 
	while(cin>>n>>dir){
	
    i=n/2;
    j=n/2;
    cnt=1;

    for(x=0;x<n;x++)
    {
       for(y=0;y<n;y++)
           cin>>a[x][y];                
    }
    //output 中心點 
    cout<<a[i][j];
    //size 1==>1  3==>5  5==>9  7==>13  9==>17
    //(size-1)/2*4  +1  =(size-1) *2 +1
    //轉彎的次數 
    if(n!=1)
    {
	    for(x=1;x<=(n-1)*2+1;x++ )
	    {
	    	//x=1,2 move one step  3,4 move two steps    (x+1)/2
	    	for(y=1;y<=(x+1)/2;y++)
	    	{
	    		array_move(dir);
	    		//cout<<a[i][j]<<"\t "<<(x+1)/2<<y<<i<<j<<endl;
	    		//最後一次轉彎會變負的... 
	    		if(i>=0 && j>=0 && cnt<n*n){
                 // if(i>=0 && j>=0){
					cout<<a[i][j];
					cnt++;
				}
			}
	    	dir++;
	    	if(dir==4) dir=0;
		}
	}
	  cout<<endl;
	}
    //system("pause");
   return 0;
} 
void array_move(int dir)
{
	switch(dir)
	{
     case 0: //left
     	i=i;     	j=j-1;
     	break;
     case 1: //up
     	i=i-1;     	j=j;
     	break;
     case 2: //right
     	i=i;     	j=j+1;
     	break;
     case 3: //down
     	i=i+1;     	j=j;
     	break;
    default :
    	break;
    }
}
