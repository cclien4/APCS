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
    
    cin>>st1>>st2;  //����]�A����J��k
	 
    n=strlen(st1);
    k=strlen(st2);
    b=0;

    for(a=0;a<k;a++)
    {
      if(st1[b] == st2[a])
     // if(strncmp(&st1[b],&st2[a],1)==0)  //�t�@�ӧP�O�覡 
	  {
         b=b+1;
         if(b == n)
           break; 
      }
    }
    if(b >= n)
    {
      printf("YES");
     //printf("%d %d %d",b,n,k);  //�P�_�u�W�t�ε�����  
    }
    else
    {
    //	printf("%d %d %d",b,n,k);  //�P�_�u�W�t�ε����� 
     printf("NO");
    }
   // system("pause");
   return 0;
}
         
       
