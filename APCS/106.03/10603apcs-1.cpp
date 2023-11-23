#include <vector>      //vector
#include <string.h>    //strlen
#include <iostream>
using namespace std;

int main(void)
{
    int i;
    int s1,s2;
    int flag;
    //字串轉數字處理 
    char s[1000];
    int num[1000];
    while(cin>>s){
    s1=0;s2=0;flag=0;
    //抓取字元陣列s  並轉成 int 的資料型態放進num陣列 
    size_t length = strlen(s);
    for(i=0;i<length;i++){
            num[i]=s[i]-'0';
    }
    //開始進行運算 
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
        }
     if(s1>s2)
         cout<<s1-s2<<endl;
     else
         cout<<s2-s1<<endl;
    }
	return 0; 
}
