#include <iostream>
#include <vector>      //vector
#include <string.h>    //strlen
using namespace std;

int main(void)
{
    int i;
    int s1,s2;
    int flag;
    char s[1000];
    vector <int> num;
    while(cin>>s){
    s1=0;s2=0;flag=0;
    num.clear();
    size_t length = strlen(s);
    for(i=0;i<length;i++){
            num.push_back(s[i]-'0');
    }
    //for(i=0;i<length;i++){
  //          cout<<num[i];
  //  }

    
        for(i=0;i<length;i++)
        {
           if(flag==0)
           {
               s1=s1+ num[i];
               flag=1;       
           }          
           else
           {
               s2=s2+ num[i];
               flag=0; 
           }  
        //   cout<<"s1="<<s1;
       //    cout<<"s2="<<s2<<endl;
        }
     if(s1>s2)
         cout<<s1-s2<<endl;
     else
         cout<<s2-s1<<endl;
    }
return 0;
    

       
  //  system("pause");
    
}
