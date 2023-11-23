#include <iostream>   // std::cout
#include <string>     // std::string,
#include <sstream>
#include <math.h>
using namespace std;
	string ans;
	long long xin;    
	long long s_xin,ss_xin,a_xin;
string adds(int x){
	string str;
	stringstream ss;
		str="";
		for(int j=1;j<=x;j++){		
			ss << j;
			
		}	
		str = ss.str();
	//	cnt++;
	return str;
}
void output1_str(){
	    ans="";
		ans=adds(a_xin);
		cout<<ans[a_xin-1];
}
void output2_math(){
		if(a_xin < 10 )
			cout<<a_xin;         //﹃10ず 
		else if (a_xin < 190 ){ //ex: (15-9) /2  190邻材计 
			ss_xin=(a_xin-10)/2;
			ss_xin=ss_xin+10;   //ヘ玡计  ss_xin  10.11  ==>  10
			if(a_xin%2==1)//耞緇计∕﹚块 
			     cout<<ss_xin%10;
			else
				cout<<ss_xin/10;
		}else if (a_xin < 2890 ){ //ex: 2889  999ソ兜  2890邻计 
			ss_xin=(a_xin-190)/3;
			ss_xin=ss_xin+100;   //ヘ玡计  ss_xin  10.11  ==>  10
			if(a_xin%3==0)//耞緇计∕﹚块 
			     cout<<ss_xin%10;
			else if(a_xin%3==2)
				cout<<(ss_xin/10)%10;
			else 
				cout<<ss_xin/100;
		}else if (a_xin < 38890 ){
			ss_xin=(a_xin-2890)/4;
			ss_xin=ss_xin+1000;   //ヘ玡计  ss_xin  10.11  ==>  10
			if(a_xin%4==1)//緇计琌1  计 
			     cout<<ss_xin%10;
			else if(a_xin%4==0) //緇计琌1  计  
				cout<<(ss_xin/10)%10; 
			else if(a_xin%4==3) //緇计琌1  计  
				cout<<(ss_xin/100)%10;
			else 
				cout<<ss_xin/1000;
		}else{ //ex: (15-9) /2  
			ss_xin=(a_xin-38890)/5;
			ss_xin=ss_xin+10000;   //ヘ玡计  ss_xin  10.11  ==>  10
			if(a_xin%5==1)//緇计琌1  计 
			    cout<<(ss_xin/1000)%10; 
			else if(a_xin%5==2) //緇计琌1  κ计  
				cout<<(ss_xin/100)%10;
			else if(a_xin%5==3) //緇计琌1  计  
				cout<<(ss_xin/10)%10;
			else if(a_xin%5==4) //緇计琌1  计  
				cout<<ss_xin%10; 
			else 
				cout<<ss_xin/10000;
		} 	
	
}
int main(){
	long long x,i,n,j,k;
	long long digit[5]={0,45,9045,1395495,189414495};
	//1...9  11+...189  192+...2889  2893+...38889  38894
	cin>>n;
	for(j=0;j<n;j++){
		cin>>x;
		i=0;
		while(x>digit[i] && i<=4)
			i++;
		i--;
		s_xin=0;
		ss_xin=0;
		a_xin=0;
		xin=1;
	    if(i==0){
	   	//=====1-9===================//
		while( (pow(xin,2)+xin) < 2*x  )    //n2+n > 2x
			  xin++;
		    for(k=1;k<xin;k++)
			    s_xin=s_xin+k;	    
	    }else if(i==1){
	   	//=====11-99===================//
		while( (2*pow(xin,2)+20*xin) < 2*(x-digit[1])  )    //n2+10n > x-45
			  	xin++;
			  //====comput s_xin======//
			    if(xin>1)
			    s_xin=((22+(xin-2)*2)*(xin-1))/2;   //(2a1+(n-2)*d)*(n-1) /2  玡nぇ㎝ 
			    s_xin=s_xin+digit[1];
			  //====comput s_xin======//
				xin=xin+9;
	    }else if(i==2){
        //=====111-999===================//
		while((3*pow(xin,2)+381*xin) < 2*(x-digit[2])  )    //n2+10n > x-9045
			  	xin++;
			  	//====comput s_xin======//
			    if(xin>1)
			    s_xin=((384+(xin-2)*3)*(xin-1))/2;   //(2a1+(n-2)*d)*(n-1) /2  玡nぇ㎝ 
			    s_xin=s_xin+digit[2];
			  //====comput s_xin======//
				xin=xin+99;
	   }else if(i==3){
	   //=====1111-9999===================//
		while((4*pow(xin,2)+5782*xin) < 2*(x-digit[3])  )    //n2+10n > x-9045
			  	xin++;
			  	//====comput s_xin======//
			    if(xin>1)
			    s_xin=((5786+(xin-2)*4)*(xin-1))/2;   //(2a1+(n-2)*d)*(n-1) /2  玡nぇ㎝ 
			    s_xin=s_xin+digit[3];
			  	//====comput s_xin======//
				xin=xin+999;
		}else if(i==4){
			//=====11111-99999===================//
		while((5*pow(xin,2)+77773*xin) < 2*(x-digit[4])  )    //n2+10n > x-9045
			  	xin++;
			  	//====comput s_xin======//
			    if(xin>1)
			    s_xin=((77778+(xin-2)*5)*(xin-1))/2;   //(2a1+(n-2)*d)*(n-1) /2  玡nぇ㎝ 
			    s_xin=s_xin+digit[4];
			  	//====comput s_xin======//
				xin=xin+9999;			
		}

		//xin琌ヘ玡计
		//s_xin琌ヘ玡 计羆㎝
		//adds块秈眔琌xinヘ玡计﹃
		//祇瞷计癘拘砰岿粇тa_xinTLE
		//ノ计streamぃ︽ 
        
        
        cout<<xin<<endl;
		a_xin=x-s_xin;
		
		output1_str();
		cout<<ans<<endl;
		output2_math();
//				cout<<" ";        
	}
	return 0;
}
