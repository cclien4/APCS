#include <iostream>
#include <math.h>
#include <algorithm>   
using namespace std;

int main()
{
	int a,b,temp;
    int i,j;
    int x[100][100];
	
	
	while(cin>>a>>b)
	{
	
		for(i=0;i<a;i++)
	       for(j=0;j<b;j++)
	          cin>>x[i][j];
        //------------swap  start----------
        if(a<b)
        {
        
    	    for(i=0;i<a;i++)
    	    {
    	       for(j=i;j<b;j++)
                 swap(x[i][j],x[j][i]);

            }
         }
         else
         {
     	    for(j=0;j<a;j++)
    	    {
    	       for(i=0;i<j;i++)
                 swap(x[j][i],x[i][j]);
            } 
         }
  //------------swap  end----------
        for(i=0;i<b;i++)
		{
	       for(j=0;j<a;j++)
	       { 
	           if(j!=(a-1)) 
	             cout<<x[i][j]<<" ";
	           else
	              cout<<x[i][j];
	       } 
		  	cout<<endl;	
	    }
    }
	return 0;
 }
