#include <iostream>
#include <set>
using namespace std;
int main (){
    int score[20];	//�̦h20�����Z 
	int num,i,j,n; 		//�X�ӤH 
    multiset<int> mset;
    multiset<int>::iterator it;

    while(cin>>n){
           mset.clear();       
    for(i=0;i<n;i++){
           cin>>j;
           mset.insert(j);      
    }
    //�L�X�Ҧ����Z 
    //for (it=mset.begin(); it!=mset.end();it++){
    //    if(it!=mset.end())
    //        cout << *it << ' ';
    //}
    it=mset.begin();
    for(i=0;i<n;i++){
          if(i!=n-1)
           cout<<*it<<' ';
          else
           cout<<*it;
          it++;
    }
    
    
    //��60��it��m 
      cout<<endl;
    it=mset.lower_bound(60);
    
   if(it==mset.begin())
        cout<<"best case"<<endl<<*it<<endl;
   else if(it==mset.end()){
        it--;
        cout<<*it<<endl<<"worst case"<<endl;
   }else{
         it--;
         cout<<*it<<endl;
         it++;
         cout<<*it<<endl;
   }
   }
   // system("pause");
}
