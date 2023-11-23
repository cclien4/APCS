#include <iostream>

using namespace std;
bool leap(int Y){
     if(Y%400==0)
       return true;
     else if(Y%100==0)
        return false;
     else if(Y%4==0)
        return true;
     else
         return false;
}


int main(){
    int N;
    int M,Y,D;
    int MD[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum;
    bool L,flag;
    while(cin>>N){
         flag=0;
         cin>>M>>D>>Y;
         sum=0;
         D=D+N;
         
         while(D>28 && flag==0 ){
              if(M==2){ //2月的特別處理 
					L=leap(Y);
                    if(L==1){   //是閏年
                           D=D-29;
                    }else{
                           D=D-28;
                    }
                    M=M+1;
                    if(D<=30)
                      flag=1;   //結束D的運算
                     // cout<<"cccc";
              }else if( D > MD[M-1] ){
                  D=D-MD[M-1];
                  M=M+1;
                 // cout<<"bbbb";
                  if(M>12){
              			Y=Y+1;
              			M=1;
              		//	cout<<"aaaa";
					}
                    if (D < MD[M-1])
                      flag=1;



	// cout<< D<<"/"<<M<<"/"<<Y<<" "   <<endl;
              }else       //注意程式的架構~~~  嚴謹性
				 flag=1;
 		//星座判別
         }
    for(int i=1;i<M;i++)
			    sum=sum+MD[i-1];
			 sum=sum+D;

    	 if(sum>=21  && sum<= 50 )
			cout<< M<<"/"<<D<<"/"<<Y<<" aquarius"<<endl;
		 else if(sum>=51  && sum<= 79 )
			cout<< M<<"/"<<D<<"/"<<Y<<" pisces"<<endl;
		 else if(sum>=80  && sum<= 110 )
			cout<< M<<"/"<<D<<"/"<<Y<<" aries"<<endl;
		 else if(sum>=111  && sum<= 141 )
			cout<< M<<"/"<<D<<"/"<<Y<<" taurus"<<endl;
		 else if(sum>=142  && sum<= 172 )
			cout<< M<<"/"<<D<<"/"<<Y<<" gemini"<<endl;
		 else if(sum>=173  && sum<= 202 )
			cout<< M<<"/"<<D<<"/"<<Y<<" cancer"<<endl;
		 else if(sum>=203  && sum<= 233 )
			cout<< M<<"/"<<D<<"/"<<Y<<" leo"<<endl;
		 else if(sum>=234  && sum<= 266 )
			cout<< M<<"/"<<D<<"/"<<Y<<" virgo"<<endl;
		 else if(sum>=267  && sum<= 296 )
			cout<< M<<"/"<<D<<"/"<<Y<<" libra"<<endl;
		 else if(sum>=297  && sum<= 327 )
			cout<< M<<"/"<<D<<"/"<<Y<<" scorpio"<<endl;
		 else if(sum>=328  && sum<= 356 )
			cout<< M<<"/"<<D<<"/"<<Y<<" sagittarius"<<endl;
		 else
			cout<< M<<"/"<<D<<"/"<<Y<<" capricorn"<<endl;
                  
                  
    }    
    return 0;
}

