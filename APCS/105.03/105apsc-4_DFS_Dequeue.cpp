#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


deque<int> G[100];//����tree�����p�A�Hdequeue�h�� 
int V[100];//�C�Ӹ`�I�O�_���X�L 
int md; //md�����̤j�� 
int DFS(int,int);


int main()
{
  int a,b,n,m;
  int mdr[100];
    cin>>n; 
    for(int i=0;i<n;i++){
      G[i].clear();        
      V[i]=0;
	  mdr[i]=0;      
    }
    for(int i=0;i<n-1;i++){
      cin >> a >> b;     
      G[a].push_back(b);
      G[b].push_back(a);     
    }
//���C���I���i�JDFS�Ӱ����̤j���� 
	for(int i=0;i<n;i++)
	{
	   	for(int j=0;j<n;j++)
		   {
		   	    V[j]=0;
		   	    md=0;//���s�]�w�ȡA�w�ƶ]�U�@���I 
		   }  
		      
	    V[i]=1;  //�]�w��l�I�w�g���L�A�קK�A�� 
		mdr[i]=DFS(i,0);//�i�JDFS�}�l���� 
	} 

//�ƧǨC���I����U���I���j�p
//	sort(mdr,mdr+n);

	for(int i=0;i<n;i++)
    	cout<<mdr[i]<<endl;  
		
		/*���ե�*/ 
	//	mdr[0]=DFS(1,0);
		  
}

int DFS(int x,int level){
  int target;
  for(int i=0;i<G[x].size();i++){
    if (level>md) md=level;
    target=G[x][i];
    if (V[target] == 1) continue;        
    V[target]=1;
    DFS(target,level+1);      
  }
 // if(md>md_reg)
 //   md_reg=md;
    
    return md;
}
