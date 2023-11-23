#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <math.h>
using namespace std;

int a[10][5];

int bitcount(unsigned int n)
{
   int count = 0 ;
   while (n)
   {
      count++ ;
      n &= (n - 1) ; //����t�⤧�B
   }
   return count ;
}


int compute(int b)
{
	int cnt_b=0;//�p��X����
	int score=0;//�p��o�� 
	int cnt=0;//�p�� �S�]�����A
	unsigned int state=0; 
	int i,j;	//�ܦ����u���y 
		for(j=0;j<5;j++){
			for(i=0;i<9;i++){ 
				if(a[i][j]==0){ 
					cnt_b++;
					if(cnt_b%3==0){  //���S�]�M�� �íp��o���o��  
						cnt= bitcount(state>>3);
						state = 0; //�M�ťثestate 
						score = score +cnt; //�֥[�ثe�o�� 
					}
				} 
				else if(a[i][j]==4){
						cnt= bitcount(state);
						state = 0; //�M�ťثestate 
						score = score +cnt+1; //�֥[�ثe�o�� 1�O�����̥��� 
				}
				else{   //�S���X��  �ھ�1-4  shift �ӭp�� 
					state=state<<a[i][j];
					state=state+pow(2,a[i][j]-1);		
				} 
				
			//	cout<<"state"<<state<<"score"<<score<<endl;					
				if(cnt_b==b){
					cnt= bitcount(state>>3); //���S�]�M�� �íp��o���o�� 
					score = score +cnt;
					return score;
				}
					
			}
		} 	
}

int main(void){

	int i,j;
	//��J��ƨ�}�C�� 
	char s[10];
	int n,in,o,b,cnt_b;
	int score;
	while(cin>>in){
	for(i=0;i<9;i++){
		if(i==0)
		   	n=in;
		else
			cin>>n;  //��i����n�ӥ��� 
		for(j=0;j<n;j++){ 
			cin>>s;
			if(s[0]=='H')
				a[i][j]=4;   
			else{
				o=atoi(s);
				a[i][j]=o;
			}
		}
		cout<<endl;
	}
	
	//��X�ثe�}�C�[�ݤ��e	

	cin>>b;  //��J�X���� 
    score=compute(b);
	cout<<score<<endl;
	}
	return 0;
}











