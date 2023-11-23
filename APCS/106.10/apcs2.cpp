 #include <iostream> 
#include <cctype> //使用字元的檢查需要的標頭檔 
using namespace std; 

int main (void) { 
char ch[100000]; 
int i,k;
int ans,cnt;
int max_ans;
bool flag,w_flag,f_flag;
while(cin>>k){
	cin>>ch;
	i=0;
	cnt=0;
	ans=0;
	max_ans=0;
	flag=0;      //大小寫flag 
	w_flag=0;    //wait flag 
	f_flag=0;    //finish flag
	while(isalpha(ch[i])){
		//cout<<ch[i];
		if(i==0){
		    cnt=1;
		    if (isupper(ch[0]))
		       flag=1;
		    else
		       flag=0;
		}else if(isupper(ch[i]) && w_flag==1){   //大寫且等待的也是大寫 
			cnt++;
			flag=1;
			f_flag=0;
		//	cout<<"s1";
		}else if(islower(ch[i]) && w_flag==0){        //小寫且等待的也是小寫 
			cnt++;
			flag=0;
			f_flag=0;
		//	cout<<"s2";
		}else if(isupper(ch[i]) && w_flag==0){         //大小寫切換   重新計算 
		//	cout<<"s3";
			if(f_flag==0 || k==1) {
				ans=0;
				w_flag=1;
				cnt=1;
				flag=1;
			}else{
				ans=k;
				w_flag=0;
				cnt=0;
				flag=0;
			}
		}else if(islower(ch[i]) && w_flag==1 ){       //大小寫切換 重新計算 
			
			
		//	cout<<"s4";
			if(f_flag==0 || k==1) {
				ans=0;
				w_flag=0;
				cnt=1;
				flag=0;
			}else{
				ans=k;    //solve    2   aaaAAAaaAA
				w_flag=1;
				cnt=0;
				flag=1;
			}
			   
		}
	//	cout<<"cnt"<<cnt<<w_flag<<f_flag<<endl;
		if(cnt<k){
			if(flag==1)  w_flag=1;
			else w_flag=0;
		}
		else if(cnt==k){
			cnt=0;
			ans=ans+k;
			f_flag=1;
		     if(flag==1)  w_flag=0;
			else w_flag=1;
		}
		
		if(ans>max_ans)
			max_ans=ans; 		
		i++;
	}
    cout<<max_ans<<endl;

}


/*
string  size方法
bitset  方法 

*/
return 0;
}
