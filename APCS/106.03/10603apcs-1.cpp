#include <vector>      //vector
#include <string.h>    //strlen
#include <iostream>
using namespace std;

int main(void)
{
    int i;
    int s1,s2;
    int flag;
    //�r����Ʀr�B�z 
    char s[1000];
    int num[1000];
    while(cin>>s){
    s1=0;s2=0;flag=0;
    //����r���}�Cs  ���ন int ����ƫ��A��inum�}�C 
    size_t length = strlen(s);
    for(i=0;i<length;i++){
            num[i]=s[i]-'0';
    }
    //�}�l�i��B�� 
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
