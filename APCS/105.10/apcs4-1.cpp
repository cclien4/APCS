#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
using namespace std;

int a[10][5];

int compute(int b)
{
	int cnt_b=0;//�p��X����
	int score=0;//�p��o�� 
	int i,j;	//�ܦ����u���y 
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
	//��J��ƨ�}�C�� 
	char s[10];
	int n,o,b,cnt_b;
	int score;
	for(i=0;i<9;i++){
		cin>>n;  //��i����n�ӥ��� 
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
	
	//��X�ثe�}�C�[�ݤ��e	
	for(i=0;i<9;i++){
		for(j=0;j<4;j++){ 
			cout<<a[i][j];
		}
		cout<<endl;
	} 
	cin>>b;  //��J�X���� 
    score=compute(b);
	cout<<score;
}
























/*
int main(void)
{
    //���z��ťդ�K 
    char b[100],c[100];
    
    while(cin>>b)    
    {
         for(int i=0;i<strlen(b);i++)     
           cout<<char(b[i]-7);
         cout<<endl;
     }
}
 string   �@�k     
 //�������Ȥ�K 
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















