#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

string int2str(int &i) 
{
	string s;
	stringstream ss(s);
	ss << i;

	return ss.str();
}
int main(void)
{
    int a,i,flag,cnt_f;
    int b;
    string ans="";
    string s;
    while(cin>>a)
    {
           ans="";
           b=a;
           for(i=2;i<=a;i++)
           {
               flag=0;
               cnt_f=1;
               if(b%i==0) 
               {
			       while(b%i==0)
	               {
	                  if(flag==0)
	                     ans=ans+int2str(i);
	                    
	                  else
	                     cnt_f++;
	                  flag=1;
	                  b=b/i;
	               }
	            	if(cnt_f>1)
                   		ans=ans+"^"+int2str(cnt_f);
               		if(b!=1)
               			ans=ans+" * ";
	           }
               else if(b==1)
               		break;
           }    
		   cout<<ans<<endl;      
    }
    
} 
