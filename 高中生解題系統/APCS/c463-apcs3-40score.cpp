#include <iostream>
#include <string.h>
#include <bitset>
#include <algorithm>
//#define size 100000
const size_t size = 100;
using namespace std;
//http://www.csie.ntnu.edu.tw/~u91029/Tree.html

bool adj[size][size];
int depth[size];

void DFS(int x, int px,int n) // px�Ox������
{
    for (int y=0; y<n; ++y)
        if (adj[x][y] && y != px)
        {
            depth[y] = depth[x] + 1;
            DFS(y, x,n);
        }
}

int main(void)
{
	int n;   //�@�X����� 
	int i,j; //�j��ϥ� 
	int k;   //�榳�X����� 
	int m;	 //���Ƥ��e 
	int h;  //���`�M���� 
	int root;//��root 
	bitset <size> b,leaf;
	while(cin>>n){
//	cin>>n;
	//	memset (adj,0,size);
	    for(i=0;i<n;i++)
	    	for(j=0;j<n;j++)
	    		adj[i][j]=0;
		memset (depth,0,size-1);
		b.reset();
		leaf.reset();
		h=0;
		//��J�}�C�һݭn����� 
		for(i=0;i<n;i++){
			cin>>k;
			for(j=0;j<k;j++){
				cin>>m;
				b[m-1]=1;
				adj[i][m-1]=1; 
			}
		}
		//�}�l����root
		 for(i=0;i<n;i++){
		 	if(b[i]==0){
		 		root=i;
		 		break;
			 }
		 }
		cout<<root+1<<endl;
	    //�}�l�������� 
	    for (i=0; i<n; ++i){
	    	DFS(i, i,n);
	    	sort(depth,depth+n);
	    	h=h+depth[n-1];
	    	for (j=0; j<n; ++j)
	    	    depth[j]=0;
	   }
    	cout<<h<<endl;
    //	for (int i=1; i<=n; ++i)
      //   	cout << "�`�I" << i << "���`�׬O" << depth[i]<<endl;
	}
	return 0;
}
