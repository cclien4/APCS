#include <iostream>
#include <string.h>
#include <string>


using namespace std;

int main(void)
{
    
    char b[100],c[100];
    
    while(cin>>b)
    {
         for(int i=0;i<strlen(b);i++)     
           cout<<char(b[i]-7);
         cout<<endl;
     }
   // system("pause");
}
/*  string   §@ªk 
#include<iostream>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		for(int i=0; i<s.size(); i++){
		char c=s[i]-7;
		cout<<c;
		}
		cout<<endl;
	}
}*/
