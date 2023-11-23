#include<stdio.h>
#include<string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,k,a,b,c;
    char st1[40],st2[80];
    //gets(st1);
    //gets(st2);
    
    cin>>st1>>st2;  //找到原因，更改輸入辦法
	 
    n=strlen(st1);
    k=strlen(st2);
    b=0;

    for(a=0;a<k;a++)
    {
      if(st1[b] == st2[a])
     // if(strncmp(&st1[b],&st2[a],1)==0)  //另一個判別方式 
	  {
         b=b+1;
         if(b == n)
           break; 
      }
    }
    if(b >= n)
    {
      printf("YES");
     //printf("%d %d %d",b,n,k);  //判斷線上系統給的值  
    }
    else
    {
    //	printf("%d %d %d",b,n,k);  //判斷線上系統給的值 
     printf("NO");
    }
   // system("pause");
   return 0;
}
         
       
