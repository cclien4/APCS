#include <iostream>
#include <math.h> 
#include <deque>
using namespace std;

int main(void)
{
    int a,b,c,flag,flag2;
    int i,j,cnt;
    int reg_i;
    deque<int> dq;
    while(cin>>a>>b>>c)
    {
       cnt=0;
       flag2=0;
       for(i=a;i<=b;i++){
            if (i == 1) continue;            
              flag=0;
             for(j=2;j<=sqrt(i);j++)
             {
                 if(i%j==0)
                 {
                    flag=1;
                    break;
                 }
             }
             if(flag==0){
             	cnt++;
             	reg_i=i;
             	cout<<i<<" ";
             	flag2=1;
			 }
             if(cnt==c)
                 break;                
       }//­Ë¹L¨Ó§ä 
      //  cout<<"reg_i"<<reg_i<<i<<endl;
        cnt=0;
       for(i=b;i>reg_i;i--){
         	flag=0;
       	  //  cout<<"i"<<reg_i<<i<<endl;
       		for(j=2;j<=sqrt(i);j++){
                 if(i%j==0){
                    flag=1;
                    break;
                 }
             }
             if(flag==0){
             	cnt++;
             	dq.push_front(i);
             	flag2=1;
             //	cout<<"push"<<i<<endl;
			 }
             if(cnt==c)
                 break;        	
	   }
		while(!dq.empty()){
			cout << dq.front()<<" ";
			dq.pop_front();
		}
           if(flag2==0)
              cout<<"0"<<endl;
         
      //  cout<<cnt<<endl;                  
    }         
    return 0;
    
}

