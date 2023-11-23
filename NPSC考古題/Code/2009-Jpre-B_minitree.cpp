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

//�T�{�I�O�_���s������ 
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
     //��a�ϤW����T�[�J��}�C�� 
     for(int i=0;i<m;i++) scanf("%d %d %d",&s[i].p1,&s[i].p2,&s[i].value);
     //Reset�I��head��m 
     for(int i=0;i<200;i++) head[i]=i;
     //�}�l���ɧǱƦC 
     sort(s,s+m,compare);
     while( find(1)!=find(n) ){
       
       int p1boss=find( s[put].p1 );
       int p2boss=find( s[put].p2 );
       
       head[p2boss]=head[p1boss];    
	   //���ثe���min�O���X��                      
       min=s[put].value;
       put++;
     }
     printf("%d\n",min);
 
 }
 return 0;   
}
