#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
//size�J�M�����A�N�wmap�N���A���o�{�x�s�Ŷ������A�]���Q��map+vector���� 

struct subject
{
  int wei; //weight
  int ff; //f
};


vector<subject> sub;

//map<int,multimap<int,int> > mmap;
//map<int,multimap<int,int> >::iterator it;

//vector <int>wv;
//vector <int>fv;
//vector <int>subject;

int main(void){
    unsigned long long ans;
    int n;   //�@�X����� 
    int i,j;
    int k,m;
    int w,f;
    
    while(cin>>n){
   //     wv.clear();
    //    fv.clear();
    //    wf.clear();
        //  input data information
        for(i=0;i<n;i++){
            cin>>w;
            //Push back new subject created with default constructor.
    		sub.push_back(subject());
    		//Vector now has 1 element @ index 0, so modify it.
    		sub[i].wei = w;
    
            //sub.wei.push_back(w);
		}   
        for(i=0;i<n;i++){
            cin>>f;
            sub[i].ff = f;
		}
	//	for(i=0;i<n;i++){
    //        wf.push_back(wv[i]*fv[i]);
	//	}
		//output test
		for(i=0;i<n;i++){
            cout<<sub[i].wei;
		}
		//step1  ����f�j�p�� (�v�T�̤j)
		//step2  ����w�j�p��(�v�T�p)
		//step3  �i�氻�� ( �Q�γ̤j�u���@�d �i���`�M�}�C�P�O) 

		
    }
}
