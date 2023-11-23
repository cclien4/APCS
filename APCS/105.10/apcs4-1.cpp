#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
using namespace std;

int a[10][5];

int compute(int b)
{
	int cnt_b=0;//計算出局數
	int score=0;//計算得分 
	int i,j;	//變成直線掃描 
		for(j=0;j<5;j++){
			for(i=0;i<9;i++){ 
				if(a[i][j]==0)
					cnt_b++;
				else
					score++;				
				if(cnt_b==b)
					return score;
			}
		} 	
}

int main(void){

	int i,j;
	//輸入資料到陣列裡 
	char s[10];
	int n,o,b,cnt_b;
	int score;
	for(i=0;i<9;i++){
		cin>>n;  //第i局有n個打者 
		for(j=0;j<n;j++){ 
			cin>>s;
			if(s[0]=='H')
				a[i][j]=1;   
			else{
				o=atoi(s);
				a[i][j]=o;
			}
		}
		cout<<endl;
	}
	
	//輸出目前陣列觀看內容	
	for(i=0;i<9;i++){
		for(j=0;j<4;j++){ 
			cout<<a[i][j];
		}
		cout<<endl;
	} 
	cin>>b;  //輸入出局數 
    score=compute(b);
	cout<<score;
}
























/*
int main(void)
{
    //對於篩選空白方便 
    char b[100],c[100];
    
    while(cin>>b)    
    {
         for(int i=0;i<strlen(b);i++)     
           cout<<char(b[i]-7);
         cout<<endl;
     }
}
 string   作法     
 //對於整行取值方便 
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















