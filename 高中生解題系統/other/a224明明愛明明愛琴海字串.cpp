#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string a;
while(getline(cin, a)){
	int len = a.length();
	char s[10001] = "\0";
	for(int i=0, j=0 ; i < len;i++){
		if(isalpha(a[i]))	{
			s[j] = a.at(i);
			j++;
		}
	}
  	int odd=0;
  	int abc[26]={0};   
    for(int j=0;j<26;j++){
       	for(int i=0;i<strlen(s);i++){
           	if(s[i]==65+j||s[i]==97+j){
           	  abc[j]++;
         	}    
		}
    }
    for(int k=0;k<26;k++)  if(abc[k] %2==1)	  odd ++ ;        
    if(odd>=2)    cout<<"no..."<<endl;
    else	cout<<"yes !"<<endl;
}
	return 0;
}
