#include <iostream>
#include<algorithm>
using namespace std;
typedef struct{
  int p1;
  int p2;
  int value;
}Side;

bool compare(Side a,Side b)
{
 if(a.value<b.value) return 1;
 else return 0;
}

int head[200];

//確認點是否都連接完成 
int find(int n)
{ if(head[n]!=n) head[n]=find(head[n]);
  return head[n];  
}

int main(){
  int all;
  int n,m;
  scanf("%d",&all);
  while(all--){
     int put=0;
     int min;
     scanf("%d %d",&n,&m);          
     Side s[m]; //street
     //把地圖上的資訊加入到陣列裡 
     for(int i=0;i<m;i++) scanf("%d %d %d",&s[i].p1,&s[i].p2,&s[i].value);
     //Reset點的head位置 
     for(int i=0;i<200;i++) head[i]=i;
     //開始做升序排列 
     sort(s,s+m,compare);
     while( find(1)!=find(n) ){
       
       int p1boss=find( s[put].p1 );
       int p2boss=find( s[put].p2 );
       
       head[p2boss]=head[p1boss];    
	   //把到目前為止的min記錄幾來                      
       min=s[put].value;
       put++;
     }
     printf("%d\n",min);
 
 }
 return 0;   
}
