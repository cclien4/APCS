#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#define data 3
using namespace std;


struct str{
       int kind;
       //string s;
       char content[100];
	   //int c_cnt[26];
	   bool c_tf[26];
};
int main(){
    str in_str[data];
    int min=999;
    int min_i;
	//reset
	for(int i=0;i<data;i++){
		in_str[i].kind=0;
		for(int j=0;j<26;j++)
		   in_str[i].c_tf[j]=false;
	}
	//reset
	//Input Data
	for(int i=0;i<data;i++){
		cout<<in_str[i].kind<<endl;
	}

    for(int i=0;i<data;i++){
	 cin>>in_str[i].content;
	// sort(in_str[i].content.begin(),in_str[i].content.end());   sort  �r�궶��
	 //cout<<in_str[i].content[0]-65;   //����ASCII
	}
	//�֭p�ƶq�r��
	for(int i=0;i<data;i++)
	for(int j=0;j<strlen(in_str[i].content);j++)
	   in_str[i].c_tf[in_str[i].content[j]-65]=true;
	//�p��r�������ƶq
	for(int i=0;i<data;i++){
		for(int j=0;j<26;j++){
			if(in_str[i].c_tf[j]==true)
					 in_str[i].kind++;
		}
	}
	//�D�X�̤p�r��
	for(int i=0;i<data;i++){
		 if(min>in_str[i].kind){
			min=in_str[i].kind;
			min_i=i;
		}else if(min==in_str[i].kind){   //�Ĥ@�Ӧr����p��
			if(int(in_str[min_i].content[0]-48) > int(in_str[i].content[0]-48) )
				   min_i=i;
		}
	}

	cout<<in_str[min_i].content;
	system("pause");
	
	return 0;
}
