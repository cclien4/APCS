#include <iostream>
#include <math.h> 
#include <time.h>
using namespace std;
//   TLEÁ¿¸Ñ 
/* 
int main(void)
{
    int a,b,flag;
    int i,j,cnt;
    a=99999000; b=100000000;
   // while(cin>>a>>b)
    {
       cnt=0;
       for(i=a;i<=b;i++)
       {
            flag=0;
             for(j=2;j<i;j++)
             {
                 if(i%j==0)
                 {
                    flag=1;
                    break;
                 }
             }
             if(flag==0)
                cnt++;
                                      
       }          
        cout<<cnt<<endl;    
           
    }
    cout<<"time used="<<((double) clock()/CLOCKS_PER_SEC )<<endl; 
    system("pause");  
    return 0;
    
}
*/ 

int main(void)
{
    int a,b,flag;
    int i,j,cnt;
    a=99999000; b=100000000;
   // while(cin>>a>>b)
    {
       cnt=0;
       for(i=a;i<=b;i++)
       {
            if (i == 1) continue;            
            flag=0;
             for(j=2;j<=sqrt(i);j++)
             {
                 if(i%j==0)
                 {
                    flag=1;
                    break;
                 }
             }
             if(flag==0)
                cnt++;
                                      
       }          
        cout<<cnt<<endl;                  
    }
    
     cout<<"time used="<<((double) clock()/CLOCKS_PER_SEC )<<endl; 
     system("pause");           
    return 0;
    
}

