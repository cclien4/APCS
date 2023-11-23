#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


deque<int> G[100];//紀錄tree的狀況，以dequeue去做 
int V[100];//每個節點是否拜訪過 
int md; //md紀錄最大值 
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
//讓每個點都進入DFS來偵測最大的值 
	for(int i=0;i<n;i++)
	{
	   	for(int j=0;j<n;j++)
		   {
		   	    V[j]=0;
		   	    md=0;//重新設定值，預備跑下一個點 
		   }  
		      
	    V[i]=1;  //設定初始點已經走過，避免再走 
		mdr[i]=DFS(i,0);//進入DFS開始測試 
	} 

//排序每個點的到各個點的大小
//	sort(mdr,mdr+n);

	for(int i=0;i<n;i++)
    	cout<<mdr[i]<<endl;  
		
		/*測試用*/ 
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
