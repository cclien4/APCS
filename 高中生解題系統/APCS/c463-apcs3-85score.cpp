#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
//size�J�M�����A�N�wmap�N���A���o�{�x�s�Ŷ������A�]���Q��map+vector���� 
const size_t max_size = 100000;


map<int,vector<int> > mmap;
map<int,vector<int> >::iterator it;
vector<int> vec;
int depth[max_size];

void Tree_H(int v){
	int i,max=0,vx;
  //  i=0;
    if(mmap[v][0]!=0){   //�N��data���O0
		for(i=0;i<mmap[v].size();i++){
			Tree_H(mmap[v][i]);
			vx=mmap[v][i];
			if(depth[vx] + 1 > depth[v] )
			 depth[v] = depth[vx] + 1;
		}
	}
}

int main(void)
{

    bitset <max_size> b;  //�p��root�O���� 
    int n;   //�@�X����� 
	int i,j; //�j��ϥ� 
	int k;   //�榳�X����� 
	int m;	 //���Ƥ��e 
	int h;  //���`�M���� 
	int root;//��root 
    
    
    while(cin>>n){
        mmap.clear();
        memset (depth,0,max_size-1);
        b.reset();   
        h=0;
        for(i=1;i<=n;i++){
			cin>>k;
			if(k==0){
				mmap[i].push_back(k);
				//mmap.insert(pair<int,int>(i,0));
			}else{
				for(j=0;j<k;j++){
				cin>>m;
				b[m-1]=1;
				mmap[i].push_back(m);
				//mmap.insert(pair<int,int>(i,m));
				}
			}
		}
		for(i=0;i<n;i++){
		 	if(b[i]==0){
		 		root=i;
		 		break;
			 }
		 }
		 cout<<root+1<<endl;
	/*	for (it=mmap.begin(); it!=mmap.end(); ++it){
			for(j=0;j<mmap[it->first].size();j++){
				cout << it->first << " => " << mmap[it->first][j];
			}
			cout<<endl;
		}	*/
	/*	for (i=0;i<mmap.size();i++){
			for(j=0;j<mmap[i].size();j++){
				cout <<mmap[i][j];
			}
			cout<<endl;
		}*/
		Tree_H(root+1);
		//cout<<h<<endl;
		
		for(i=1;i<=n;i++)
			h=h+depth[i];
			cout<<h<<endl;

		      
    }
}
